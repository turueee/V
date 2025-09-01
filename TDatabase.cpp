#include "TDatabase.h"
#include <QDebug>
#include <QVariant>
#include <QRandomGenerator>

TDatabase::TDatabase(const QString& dbName)
{
    db = QSqlDatabase::addDatabase("QSQLITE", QString::number(QRandomGenerator::global()->generate()));
    db.setDatabaseName(dbName);

    if (!db.open()) {
        throw std::runtime_error("Не удалось открыть базу данных: " +
                                db.lastError().text().toStdString());
    }

    // Устанавливаем практические настройки SQLite
    QSqlQuery pragmaQuery(db);
    pragmaQuery.exec("PRAGMA foreign_keys = ON");
    pragmaQuery.exec("PRAGMA journal_mode = WAL");
    pragmaQuery.exec("PRAGMA synchronous = NORMAL");
}

TDatabase::~TDatabase()
{
    if (db.isOpen()) {
        db.close();
    }
    QSqlDatabase::removeDatabase(db.connectionName());
}

bool TDatabase::createCallsTable()
{
    const QString sql =
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "name TEXT NOT NULL UNIQUE, "
        "call INTEGER NOT NULL DEFAULT 0, "
        "created_at DATETIME DEFAULT CURRENT_TIMESTAMP, "
        "updated_at DATETIME DEFAULT CURRENT_TIMESTAMP);"

        "CREATE TRIGGER IF NOT EXISTS update_timestamp AFTER UPDATE ON users "
        "FOR EACH ROW BEGIN "
        "UPDATE users SET updated_at = CURRENT_TIMESTAMP WHERE id = OLD.id; "
        "END;";

    QSqlQuery query(db);
    if (!query.exec(sql)) {
        qCritical() << "Ошибка создания таблицы:" << query.lastError().text();
        return false;
    }

    return true;
}

bool TDatabase::insertFromMap(const std::map<std::string, size_t>& calls)
{
    if (calls.empty()) {
        return true;
    }

    // Используем INSERT OR REPLACE для избежания дубликатов
    const QString sql =
        "INSERT OR REPLACE INTO users (name, call) "
        "VALUES (:name, :call)";

    QSqlQuery query(db);
    if (!query.prepare(sql)) {
        qCritical() << "Ошибка подготовки запроса:" << query.lastError().text();
        return false;
    }

    if (!db.transaction()) {
        qCritical() << "Не удалось начать транзакцию:" << db.lastError().text();
        return false;
    }

    int successCount = 0;
    for (const auto& pair : calls) {
        QString name = QString::fromStdString(pair.first);
        size_t callCount = pair.second;

        query.bindValue(":name", name);
        query.bindValue(":call", static_cast<int>(callCount));

        if (!query.exec()) {
            qWarning() << "Ошибка вставки для" << name << ":" << query.lastError().text();
            continue;
        }
        successCount++;
    }

    if (!db.commit()) {
        qCritical() << "Ошибка коммита транзакции:" << db.lastError().text();
        db.rollback();
        return false;
    }

    qDebug() << "Успешно добавлено/обновлено записей:" << successCount << "из" << calls.size();
    return successCount > 0;
}

std::map<std::string, size_t> TDatabase::readTableToMap()
{
    std::map<std::string, size_t> resultMap;

    const QString sql = "SELECT name, call FROM users ORDER BY name";
    QSqlQuery query(db);

    if (!query.exec(sql)) {
        qCritical() << "Ошибка выполнения запроса:" << query.lastError().text();
        return resultMap;
    }

    while (query.next()) {
        QString name = query.value("name").toString();
        size_t callCount = query.value("call").toUInt();

        if (!name.isEmpty()) {
            resultMap[name.toStdString()] = callCount;
        }
    }

    return resultMap;
}

bool TDatabase::updateNumbersByName(const std::map<std::string, size_t>& newData)
{
    if (newData.empty()) {
        return true;
    }

    const QString sql = "UPDATE users SET call = :call WHERE name = :name";
    QSqlQuery query(db);

    if (!query.prepare(sql)) {
        qCritical() << "Ошибка подготовки запроса:" << query.lastError().text();
        return false;
    }

    if (!db.transaction()) {
        qCritical() << "Не удалось начать транзакцию:" << db.lastError().text();
        return false;
    }

    int updatedCount = 0;
    int notFoundCount = 0;

    for (const auto& pair : newData) {
        QString name = QString::fromStdString(pair.first);
        size_t callCount = pair.second;

        query.bindValue(":call", static_cast<int>(callCount));
        query.bindValue(":name", name);

        if (!query.exec()) {
            qWarning() << "Ошибка обновления для" << name << ":" << query.lastError().text();
            continue;
        }

        if (query.numRowsAffected() > 0) {
            updatedCount++;
        } else {
            notFoundCount++;
            qWarning() << "Имя не найдено:" << name;
        }
    }

    if (!db.commit()) {
        qCritical() << "Ошибка коммита транзакции:" << db.lastError().text();
        db.rollback();
        return false;
    }

    qInfo() << "Обновлено записей:" << updatedCount << "Не найдено:" << notFoundCount;
    return updatedCount > 0;
}

bool TDatabase::isOpen() const
{
    return db.isOpen();
}

QString TDatabase::lastError() const
{
    return db.lastError().text();
}

int TDatabase::getRecordCount() const
{
    QSqlQuery query(db);
    if (query.exec("SELECT COUNT(*) FROM users") && query.next()) {
        return query.value(0).toInt();
    }
    return -1;
}
