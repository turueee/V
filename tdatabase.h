#ifndef TDATABASE_H
#define TDATABASE_H

#pragma once

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMap>
#include <QVector>
#include <QString>

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
    bool insertLabName(const QString& name,const QString& group_name);
    bool insertCriteriaName(const QString& criteria_name, const QString& lab_name, int max_point);
    bool insertCriteriaNameFromMap(const QMap<QString, int>& criteriaslimits, const QString& lab_name);
    bool insertGroup(const QString& group_name, int group_id);
    bool insertCriteriaPoint(const QString& criteria_name, const QString& name,const QString& lab_name);


    QMap<QString, size_t> readTableToCallsMap();
    QMap<QString,int> selectPointForCriteriaAndLabAndGroup(const QString& group_name, const QString& lab_name,const QString& criteria_name);
    QMap<QString, int> selectLabCriteriaLimits(const QString& lab_name);
    QMap<QString, int> selectNamePointsLab(const QString& lab_name, const QString& name);
    QVector<int> selectNamesIdByGroup(const QString& group_name);
    QVector<QString> selectNamesByGroup(const QString& group_name);
    QVector<QString> selectLabsNameForGroup(const QString& group_name);
    QMap<QString, int> selectPointsForLab(const QString& group_name, const QString& lab_name);


    bool updateNumbersByName(const QMap<QString, size_t>& newData);
    bool updateGroupByName(const QString& name, int group_id);
    bool updateLabNames (const QVector<QString>& lab_names,const QString& group_name);
    bool updateCriterias (const QMap<QString,int>& criterias, const QString& lab_name);
    bool updateLabName(const QString& old_name,const QString& new_name);
    bool updateCriteriaName(const QString& lab_name,const QString& old_name,const QString& new_name);
    bool updateCriteriaMaxPoint(const QString& lab_name,const QString& criteria_name,int new_max_point);
    bool updatePointByCriteriaAndName(const QString& lab_name,const QString& name,const QString& criteria_name,int point);

    bool deleteCriteriasForLab(const QString& lab_name);
    bool deleteLab(const QString& lab_name, const QString& group_name);
    bool deleteCriteria(const QString& lab_name, const QString& criteria_name);

    bool isOpen() const { return db.isOpen(); }
    QString lastError() const { return db.lastError().text(); }
private:
    bool executeQuery(const QString& query);
    int getIdByName(const QString& name);
    int getLabIdByName(const QString& lab_name);
    int getGroupIdByName(const QString& group_name);
    int getCriteriaIdByName(const QString& criteria_name,const QString& lab_name);
    int getMaxPointForCriteria(const QString& lab_name,const QString& criteria_name);
};

#endif // TDATABASE_H
