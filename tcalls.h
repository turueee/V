#ifndef TCALLS_H
#define TCALLS_H
#include <QMap>
#include <QVector>
#include <QString>
#include <QTime>
#include "tdatabase.h"

class TCalls{
protected:
    QMap<QString, size_t> calls;
    QVector<QString> missings;
public:

    TCalls();
    TCalls(TDatabase& db,const QVector<QString> missings_ = QVector<QString>());
    QVector<QString> getNames();
    QVector<QString> getNamesWithoutMissings();
    size_t getMinimumOfCalls();
    size_t getCallsSize();
    QMap<QString, size_t> getCalls();
    void setCalls(QMap<QString, size_t> calls_);
    QVector<QString> getNamesKDoske(size_t stud);
    void setCallsByName(QString name, size_t points);
    void setMissings(QString missings_);
    size_t getPoints(QString name);
};

void delete_missing(QVector<QString>& _names, const QVector<QString>& missing);
#endif // TCALLS_H
