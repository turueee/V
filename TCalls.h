#ifndef TCALLS_H
#define TCALLS_H
#include <map>
#include <vector>
#include <string>
#include <ctime>
#include "TDatabase.h"

class TCalls{
protected:
    std::map<std::string, size_t> calls;
    std::vector<std::string> missings;
public:

    TCalls();
    TCalls(TDatabase& db,const std::vector<std::string> missings_ = std::vector<std::string>());
    std::vector<std::string> getNames();
    std::vector<std::string> getNamesWithoutMissings();
    size_t getMinimumOfCalls();
    size_t getCallsSize();
    std::map<std::string, size_t> getCalls();
    void setCalls(std::map<std::string, size_t> calls_);
    std::vector<std::string> getNamesKDoske(size_t stud);
    void setCallsByName(std::string name, size_t points);
    void setMissings(std::string missings_);
    size_t getPoints(std::string name);
};

void delete_missing(std::vector<std::string>& _names, const std::vector<std::string>& missing);
#endif // TCALLS_H
