#ifndef TDATABASE_H
#define TDATABASE_H

#pragma once

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMap>
#include <QVector>
#include <QString>
#include <stdexcept>

class TDatabase
{
private:
    QSqlDatabase db;

public:
    TDatabase(const QString& dbName);
    ~TDatabase();

    bool createCallsTable();
    bool createGroupTable();
    bool createLabTable();
    bool createCriteriaTable();
    bool createPointsTable();

    bool insertCallsFromMap(const QMap<QString, size_t>& calls);
    bool insertLabName(const QString& name);
    bool insertCriteriaName(const QString& criteria_name, const QString& lab_name, int max_point);
    bool insertCriteriaNameFromMap(const QMap<QString, int>& criteriaslimits, const QString& lab_name);
    bool insertGroup(const QString& group_name, int group_id);

    QMap<QString, size_t> readTableToCallsMap();
    QMap<QString, int> selectLabCriteriaLimits(const QString& lab_name);
    QMap<QString, int> selectNamePointsLab(const QString& lab_name, const QString& name);

    bool updateNumbersByName(const QMap<QString, size_t>& newData);
    bool updateGroupByName(const QString& name, int group_id);

    bool isOpen() const { return db.isOpen(); }
    QString lastError() const { return db.lastError().text(); }

private:
    bool executeQuery(const QString& query);
    int getLabIdByName(const QString& lab_name);
};

#endif // TDATABASE_H
