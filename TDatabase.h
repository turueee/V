#ifndef TDATABASE_H
#define TDATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <map>
#include <string>
#include <stdexcept>

class TDatabase
{
private:
    QSqlDatabase db;

public:
    TDatabase(const QString& dbName);
    ~TDatabase();

    bool createCallsTable();
    bool insertFromMap(const std::map<std::string, size_t>& calls);
    std::map<std::string, size_t> readTableToMap();
    bool updateNumbersByName(const std::map<std::string, size_t>& newData);

    // Дополнительные полезные методы
    bool isOpen() const;
    QString lastError() const;
    int getRecordCount() const;
};

#endif // TDATABASE_H
