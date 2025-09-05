#ifndef TDATABASE_H
#define TDATABASE_H

#pragma once


#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <string>
#include <map>
#include <vector>
#include <stdexcept>
#include <iostream>

class TDatabase
{
private:
    QSqlDatabase db;

public:
    TDatabase(const std::string& dbName);
    ~TDatabase();

    bool createCallsTable();
    bool createGroupTable();
    bool createLabTable();
    bool createCriteriaTable();
    bool createPointsTable();

    bool insertFromMap(const std::map<std::string, size_t>& calls);
    std::map<std::string, size_t> readTableToMap();

    bool updateNumbersByName(const std::map<std::string, size_t>& newData);
    bool updateGroupByName(const std::string& name, int group_id);

    bool insertGroup(const std::string& group_name, int group_id);

    bool isOpen() const { return db.isOpen(); }
    std::string lastError() const { return db.lastError().text().toStdString(); }

private:
    bool executeQuery(const std::string& query);
};

#endif // TDATABASE_H
