#include "tcalls.h"

TCalls::TCalls() = default;
TCalls::TCalls(TDatabase& db,const QVector<QString> missings_)
{
    calls = db.readTableToCallsMap();
    missings = missings_;
}

QVector<QString> TCalls::getNames()
{
    QVector<QString> result;
    for (auto it = calls.constBegin(); it != calls.constEnd(); ++it) {
        result.append(it.key());
    }
    return result;
}

void TCalls::setCallsByName(QString name, int points)
{
    if (calls.find(name)!=calls.end())
        calls[name]+=points;
}

QVector<QString> TCalls::getNamesWithoutMissings()
{
    QVector<QString> names = this->getNames();
    for (const auto& absent : qAsConst(missings)) {
        names.removeAll(absent);
    }
    return names;
}

size_t TCalls::getMinimumOfCalls()
{
    size_t min = 1000;
    for (auto it = calls.constBegin(); it != calls.constEnd(); ++it) {
        if (it.value() < min) {
            min = it.value();
        }
    }
    return min;
}

size_t TCalls::getCallsSize()
{
    return calls.size();
}

QMap<QString, size_t> TCalls::getCalls()
{
    return calls;
}

void TCalls::setCalls(QMap<QString, size_t> calls_)
{
    calls = calls_;
}

void TCalls::setMissings(QString missing)
{
    missings.push_back(missing);
}

size_t TCalls::getPoints(QString name)
{
    return calls[name];
}

QVector<QString> TCalls::getNamesKDoske(size_t stud)
{
    qsrand(QTime::currentTime().msec());
    QVector<QString> min_calls, max_calls, nameskdoske;
    size_t minim = this->getMinimumOfCalls();
    size_t i = 0;

    for (auto it = calls.constBegin(); it != calls.constEnd(); ++it) {
        if (it.value() == minim)
            min_calls.append(it.key());
        else
            max_calls.append(it.key());
    }

    delete_missing(min_calls, missings);
    delete_missing(max_calls, missings);

    while (!min_calls.isEmpty() && i < stud)
    {
        int random = qrand() % min_calls.size();
        nameskdoske.append(min_calls[random]);
        calls[min_calls[random]] += 1;
        min_calls.removeAt(random);
        i++;
    }
    while (!max_calls.isEmpty() && i < stud)
    {
        int random = qrand() % max_calls.size();
        nameskdoske.append(max_calls[random]);
        calls[max_calls[random]] += 1;
        max_calls.removeAt(random);
        i++;
    }
    return nameskdoske;
}

void delete_missing(QVector<QString>& names, const QVector<QString>& missings)
{
    for (const auto& absent : qAsConst(missings)) {
        names.removeAll(absent);
    }
}
