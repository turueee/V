#include "tdatabase.h"
#include <QDebug>
#include <QFile>
#include <QVariant>
#include <QTextCodec>

TDatabase::TDatabase(const QString& dbName)
{
    // Устанавливаем кодировку UTF-8 для поддержки русского языка
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);

    qDebug() << "Путь к базе данных:" << dbName;
    qDebug() << "База данных существует:" << QFile::exists(dbName);

    if (!db.open()) {
        qDebug() << "Ошибка открытия:" << db.lastError().text();
        throw std::runtime_error("Не удалось открыть базу данных");
    }

    // Устанавливаем кодировку UTF-8 для базы данных
    QSqlQuery query(db);
    query.exec("PRAGMA encoding = 'UTF-8'");
    query.exec("PRAGMA foreign_keys = ON");

    qDebug() << "База данных успешно открыта";
}

TDatabase::~TDatabase()
{
    if (db.isOpen()) {
        db.close();
    }
}

bool TDatabase::executeQuery(const QString& query)
{
    QSqlQuery sqlQuery(db);
    return sqlQuery.exec(query);
}

bool TDatabase::createCallsTable()
{
    QString query =
        "CREATE TABLE IF NOT EXISTS users ("
        "user_id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "name TEXT NOT NULL, "
        "group_id INTEGER, "
        "calls INTEGER DEFAULT 0, "
        "all_points INTEGER DEFAULT 0);";

    return executeQuery(query);
}

bool TDatabase::createGroupTable()
{
    QString query =
        "CREATE TABLE IF NOT EXISTS groups ("
        "group_id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "group_name TEXT NOT NULL);";

    return executeQuery(query);
}

bool TDatabase::createLabTable()
{
    QString query =
        "CREATE TABLE IF NOT EXISTS labs ("
        "lab_id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "lab_name TEXT NOT NULL);";

    return executeQuery(query);
}

bool TDatabase::createCriteriaTable()
{
    QString query =
        "CREATE TABLE IF NOT EXISTS criterias ("
        "criteria_id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "criteria_name TEXT NOT NULL,"
        "lab_id INTEGER,"
        "max_points INTEGER);";

    return executeQuery(query);
}

bool TDatabase::createPointsTable()
{
    QString query =
        "CREATE TABLE IF NOT EXISTS points ("
        "point_id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "id INTEGER, "
        "criteria_id INTEGER,"
        "point INTEGER);";

    return executeQuery(query);
}

bool TDatabase::insertCallsFromMap(const QMap<QString, size_t>& calls)
{
    if (calls.isEmpty()) {
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
    for (auto it = calls.constBegin(); it != calls.constEnd(); ++it) {
        query.addBindValue(it.key());
        query.addBindValue(static_cast<int>(it.value()));

        if (query.exec()) {
            successCount++;
        }
        query.finish();
    }

    if (!db.commit()) {
        db.rollback();
        return false;
    }

    return successCount == calls.size();
}

bool TDatabase::insertLabName(const QString& name,const QString& group_name)
{
    if (name.isEmpty()) {
        return false;
    }
    int group_id = getLabIdByName(group_name);

    QSqlQuery query(db);
    if (!query.prepare("INSERT INTO labs (lab_name,group_id) VALUES (?,?)")) {
        return false;
    }

    query.addBindValue(name);
    query.addBindValue(group_id);
    return query.exec() && query.numRowsAffected() > 0;
}

int TDatabase::getLabIdByName(const QString& lab_name)
{
    QSqlQuery query(db);
    query.prepare("SELECT lab_id FROM labs WHERE lab_name = ?");
    query.addBindValue(lab_name);
<<<<<<< HEAD
=======
    return query.value(0).toInt();
}

int TDatabase::getGroupIdByName(const QString& group_name)
{
    QSqlQuery query(db);
    query.prepare("SELECT group_id FROM groups WHERE group_name = ?");
    query.addBindValue(group_name);
>>>>>>> fd6247086d558667c12579306955fc0ed63639e8
    return query.value(0).toInt();
}



bool TDatabase::insertCriteriaName(const QString& criteria_name, const QString& lab_name, int max_point)
{
    int lab_id = getLabIdByName(lab_name);
    if (lab_id == -1) {
        return false;
    }

    QSqlQuery query(db);
    if (!query.prepare("INSERT INTO criterias (criteria_name, max_points, lab_id) VALUES (?, ?, ?)")) {
        return false;
    }

    query.addBindValue(criteria_name);
    query.addBindValue(max_point);
    query.addBindValue(lab_id);

    return query.exec() && query.numRowsAffected() > 0;
}

bool TDatabase::insertCriteriaNameFromMap(const QMap<QString, int>& criteriaslimits, const QString& lab_name)
{
    if (criteriaslimits.isEmpty()) {
        return false;
    }

    int lab_id = getLabIdByName(lab_name);
    if (lab_id == -1) {
        return false;
    }

    QSqlQuery query(db);
    if (!query.prepare("INSERT INTO criterias (criteria_name, max_points, lab_id) VALUES (?, ?, ?)")) {
        return false;
    }

    if (!db.transaction()) {
        return false;
    }

    int successCount = 0;
    for (auto it = criteriaslimits.constBegin(); it != criteriaslimits.constEnd(); ++it) {
        query.addBindValue(it.key());
        query.addBindValue(it.value());
        query.addBindValue(lab_id);

        if (query.exec()) {
            successCount++;
        }
        query.finish();
    }

    if (!db.commit()) {
        db.rollback();
        return false;
    }

    return successCount == criteriaslimits.size();
}

QMap<QString, size_t> TDatabase::readTableToCallsMap()
{
    QMap<QString, size_t> resultMap;

    QSqlQuery query("SELECT name, calls FROM users", db);

    if (query.exec()) {
        while (query.next()) {
            QString name = query.value(0).toString();
            size_t calls = static_cast<size_t>(query.value(1).toUInt());
            resultMap[name] = calls;
        }
    }

    return resultMap;
}

QMap<QString, int> TDatabase::selectLabCriteriaLimits(const QString& lab_name)
{
    QMap<QString, int> resultMap;

    int lab_id = getLabIdByName(lab_name);
    if (lab_id == -1) {
        return resultMap;
    }

    QSqlQuery query(db);
    query.prepare("SELECT criteria_name, max_points FROM criterias WHERE lab_id = ?");
    query.addBindValue(lab_id);

    if (query.exec()) {
        while (query.next()) {
            QString criteria_name = query.value(0).toString();
            int max_points = query.value(1).toInt();
            resultMap[criteria_name] = max_points;
        }
    }

    return resultMap;
}

QVector<QString> TDatabase::selectLabsNameForGroup(const QString& group_name)
{
    QSqlQuery query(db);
    QVector<QString> labs;

    query.prepare("SELECT group_id FROM groups WHERE group_name = ?");
    query.addBindValue(group_name);

    if (!query.exec()) {
        qDebug() << "Ошибка выполнения запроса group_id:" << query.lastError().text();
        return labs;
    }

    if (!query.next()) {
        qDebug() << "Группа не найдена:" << group_name;
        return labs;
    }

    int group_id = query.value(0).toInt();

    query.prepare("SELECT lab_name FROM labs WHERE group_id = ?");
    query.addBindValue(group_id);

    if (!query.exec()) {
        qDebug() << "Ошибка выполнения запроса lab_name:" << query.lastError().text();
        return labs;
    }

    while (query.next()) {
        labs.append(query.value(0).toString());
    }

    return labs;
}


QMap<QString, int> TDatabase::selectNamePointsLab(const QString& lab_name, const QString& name)
{
    QMap<QString, int> resultMap;
    QVector<int> criterias;

    // Получаем ID лаборатории
    int lab_id = getLabIdByName(lab_name);
    if (lab_id == -1) {
        return resultMap;
    }

    QSqlQuery criteriaQuery(db);
    criteriaQuery.prepare("SELECT criteria_id, criteria_name FROM criterias WHERE lab_id = ?");
    criteriaQuery.addBindValue(lab_id);

    if (!criteriaQuery.exec()) {
        return resultMap;
    }

    QSqlQuery userQuery(db);
    userQuery.prepare("SELECT user_id FROM users WHERE name = ?");
    userQuery.addBindValue(name);

    if (!userQuery.exec() || !userQuery.next()) {
        return resultMap;
    }
    int user_id = userQuery.value(0).toInt();

    QSqlQuery pointsQuery(db);
    pointsQuery.prepare("SELECT point FROM points WHERE id = ? AND criteria_id = ?");

    while (criteriaQuery.next()) {
        int criteria_id = criteriaQuery.value(0).toInt();
        QString criteria_name = criteriaQuery.value(1).toString();

        pointsQuery.addBindValue(user_id);
        pointsQuery.addBindValue(criteria_id);

        if (pointsQuery.exec() && pointsQuery.next()) {
            int points = pointsQuery.value(0).toInt();
            resultMap[criteria_name] = points;
        }
        pointsQuery.finish();
    }

    return resultMap;
}

QVector<QString> TDatabase::selectLabsNameForGroup(const QString& group_name)
{
    QSqlQuery query(db);
    QVector<QString> labs;

    query.prepare("SELECT group_id FROM groups WHERE group_name = ?");
    query.addBindValue(group_name);

    int group_id = query.value(0).toInt();

    query.prepare("SELECT lab_name FROM labs WHERE group_id = ?");
    query.addBindValue(group_id);


    while (query.next()) {
        labs.append(query.value(0).toString());
    }

    return labs;
}

bool TDatabase::updateNumbersByName(const QMap<QString, size_t>& newData)
{
    if (!db.isOpen() || newData.isEmpty()) {
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
    for (auto it = newData.constBegin(); it != newData.constEnd(); ++it) {
        query.addBindValue(static_cast<int>(it.value()));
        query.addBindValue(it.key());

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

bool TDatabase::updateGroupByName(const QString& name, int group_id)
{
    if (!db.isOpen() || name.isEmpty()) {
        return false;
    }

    QSqlQuery query(db);
    if (!query.prepare("UPDATE users SET group_id = ? WHERE name = ?")) {
        return false;
    }

    query.addBindValue(group_id);
    query.addBindValue(name);

    return query.exec() && query.numRowsAffected() > 0;
}

bool TDatabase::insertGroup(const QString& group_name, int group_id)
{
    QSqlQuery query(db);
    if (!query.prepare("INSERT INTO groups (group_name, group_id) VALUES (?, ?)")) {
        return false;
    }

    query.addBindValue(group_name);
    query.addBindValue(group_id);

    return query.exec();
}

bool TDatabase::updateLabNames (const QVector<QString>& lab_names,const QString& group_name)
{
    QVector<QString> old_names = selectLabsNameForGroup(group_name), new_names(lab_names);

    for (QString old_name: old_names)
        for (QString new_name:new_names)
            if (new_name == old_name)
            {
                old_names.removeAll(new_name);
                new_names.removeAll(old_name);
            }
    int group_id = getGroupIdByName(group_name);
    QSqlQuery query(db);
    for (const QString &old_name : qAsConst(old_names))
    {
        query.prepare("DELETE FROM labs WHERE group_id = ? AND lab_name = ?");
        query.addBindValue(group_id);
        query.addBindValue(old_name);
        deleteCriteriasForLab(old_name);
        if (!query.exec()) {
            qDebug() << "Ошибка удаления записи:" << query.lastError().text();
        }
    }

    for (const QString &new_name : qAsConst(new_names))
    {
        query.prepare("INSERT INTO labs (lab_name, group_id) VALUES (?, ?)");
        query.addBindValue(new_name);
        query.addBindValue(group_id);
        if (!query.exec()) {
            qDebug() << "Ошибка добавления записи:" << query.lastError().text();
        }
    }
    return true;
}

bool TDatabase::deleteCriteriasForLab(const QString& lab_name)
{
    QVector<int> criterias_id;
    QSqlQuery query(db);

    int lab_id = getLabIdByName(lab_name);

    query.prepare("SELECT criteria_id FROM criterias WHERE lab_id = ?");
    query.addBindValue(lab_id);
    query.exec();

    while(query.next())
        criterias_id.append(query.value(0).toInt());

    for (int criteria_id : criterias_id)
    {
        query.prepare("DELETE FROM points WHERE criteria_id = ?");
        query.addBindValue(criteria_id);
        query.exec();
    }

    query.prepare("DELETE FROM criterias WHERE lab_id = ?");
    query.addBindValue(lab_id);
    query.exec();

    return true;
}

bool TDatabase::updateCriterias(const QMap<QString, int>& criterias, const QString& lab_name)
{
    QMap<QString, int> old_criterias = selectLabCriteriaLimits(lab_name);
    QMap<QString, int> new_criterias = criterias;
    QMap<QString, int> update_criterias;

    for (auto it = old_criterias.begin(); it != old_criterias.end(); ++it) {
        QString old_name = it.key();
        if (new_criterias.contains(old_name)) {
            if (it.value() != new_criterias.value(old_name)) {
                update_criterias[old_name] = new_criterias.value(old_name);
            }
            old_criterias.remove(old_name);
            new_criterias.remove(old_name);
        }
    }

    QSqlQuery query(db);
    int lab_id = getLabIdByName(lab_name);
    QVector<int> criterias_id_for_delete;

    for (auto it = old_criterias.begin(); it != old_criterias.end(); ++it)
    {
        query.prepare("SELECT criteria_id FROM criterias WHERE lab_id = ? AND criteria_name = ?");
        query.addBindValue(lab_id);
        query.addBindValue(it.key());
        query.exec();

        if (query.next()) {
            criterias_id_for_delete.append(query.value(0).toInt());
        }
    }

    for (int criteria_id_for_delete : criterias_id_for_delete)
    {
        query.prepare("DELETE FROM points WHERE criteria_id = ?");
        query.addBindValue(criteria_id_for_delete);
        query.exec();

        query.prepare("DELETE FROM criterias WHERE criteria_id = ?");
        query.addBindValue(criteria_id_for_delete);
        query.exec();
    }

    for (auto it = new_criterias.begin(); it != new_criterias.end(); ++it)
    {
        insertCriteriaName(it.key(), lab_name, it.value());
    }

    for (auto it = update_criterias.begin(); it != update_criterias.end(); ++it)
    {
        query.prepare("UPDATE criterias SET max_points = ? WHERE criteria_name = ? AND lab_id = ?");
        query.addBindValue(it.value());
        query.addBindValue(it.key());
        query.addBindValue(lab_id);
        query.exec();
    }

    return true;
}
