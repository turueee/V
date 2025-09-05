#include "TDatabase.h"
#include <QDebug>
#include <QVariant>
#include <QRandomGenerator>

TDatabase::TDatabase(const std::string& dbName)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QString::fromStdString(dbName));

    if (!db.open()) {
        throw std::runtime_error("Не удалось открыть базу данных: " + db.lastError().text().toStdString());
    }

    QSqlQuery query(db);
    query.exec("PRAGMA encoding = 'UTF-8'");
    query.exec("PRAGMA foreign_keys = ON");
}

TDatabase::~TDatabase()
{
    if (db.isOpen()) {
        db.close();
    }
}

bool TDatabase::executeQuery(const std::string& query)
{
    QSqlQuery sqlQuery(db);
    return sqlQuery.exec(QString::fromStdString(query));
}

bool TDatabase::createCallsTable()
{
    std::string query =
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "name TEXT NOT NULL, "
        "group_id INTEGER, "
        "calls INTEGER DEFAULT 0, "
        "points INTEGER DEFAULT 0);";

    return executeQuery(query);
}

bool TDatabase::createGroupTable()
{
    std::string query =
        "CREATE TABLE IF NOT EXISTS groups ("
        "group_id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "group_name TEXT NOT NULL);";

    return executeQuery(query);
}

bool TDatabase::createLabTable()
{
    std::string query =
        "CREATE TABLE IF NOT EXISTS labs ("
        "lab_id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "lab_name TEXT NOT NULL);";

    return executeQuery(query);
}

bool TDatabase::createCriteriaTable()
{
    std::string query =
        "CREATE TABLE IF NOT EXISTS criterias ("
        "criteria_id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "criteria_name TEXT NOT NULL,"
        "lab_id INTEGER,"
        "max_points INTEGER);";

    return executeQuery(query);
}

bool TDatabase::createPointsTable()
{
    std::string query =
        "CREATE TABLE IF NOT EXISTS points ("
        "point_id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "name_id INTEGER, "
        "lab_id INTEGER,"
        "criteria_id INTEGER,"
        "point INTEGER);";

    return executeQuery(query);
}

bool TDatabase::insertFromMap(const std::map<std::string, size_t>& calls)
{
    if (calls.empty()) {
        return false;
    }

    QSqlQuery query(db);
    if (!query.prepare("INSERT INTO users (name, calls) VALUES (?, ?)")) {
        return false;
    }

    if (!db.transaction()) {
        return false;
    }

    int successCount = 0;
    for (const auto& pair : calls) {
        query.addBindValue(QString::fromStdString(pair.first));
        query.addBindValue(static_cast<int>(pair.second));

        if (query.exec()) {
            successCount++;
        }

        query.finish();
    }

    if (!db.commit()) {
        db.rollback();
        return false;
    }

    return successCount == static_cast<int>(calls.size());
}

std::map<std::string, size_t> TDatabase::readTableToMap()
{
    std::map<std::string, size_t> resultMap;

    QSqlQuery query("SELECT name, calls FROM users", db);

    if (!query.exec()) {
        return resultMap;
    }

    while (query.next()) {
        std::string name = query.value(0).toString().toStdString();
        size_t calls = static_cast<size_t>(query.value(1).toUInt());
        resultMap[name] = calls;
    }

    return resultMap;
}

bool TDatabase::updateNumbersByName(const std::map<std::string, size_t>& newData)
{
    if (!db.isOpen() || newData.empty()) {
        return false;
    }

    QSqlQuery query(db);
    if (!query.prepare("UPDATE users SET calls = ? WHERE name = ?")) {
        return false;
    }

    if (!db.transaction()) {
        return false;
    }

    int updatedCount = 0;
    for (const auto& pair : newData) {
        query.addBindValue(static_cast<int>(pair.second));
        query.addBindValue(QString::fromStdString(pair.first));

        if (query.exec() && query.numRowsAffected() > 0) {
            updatedCount++;
        }

        query.finish();
    }

    if (!db.commit()) {
        db.rollback();
        return false;
    }

    return updatedCount > 0;
}

bool TDatabase::updateGroupByName(const std::string& name, int group_id)
{
    if (!db.isOpen() || name.empty()) {
        return false;
    }

    QSqlQuery query(db);
    if (!query.prepare("UPDATE users SET group_id = ? WHERE name = ?")) {
        return false;
    }

    query.addBindValue(group_id);
    query.addBindValue(QString::fromStdString(name));

    return query.exec() && query.numRowsAffected() > 0;
}

bool TDatabase::insertGroup(const std::string& group_name, int group_id)
{
    QSqlQuery query(db);
    if (!query.prepare("INSERT INTO groups (group_name, group_id) VALUES (?, ?)")) {
        return false;
    }

    query.addBindValue(QString::fromStdString(group_name));
    query.addBindValue(group_id);

    return query.exec();
}
