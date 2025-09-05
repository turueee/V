#include "TCalls.h"

TCalls::TCalls() = default;
TCalls::TCalls(TDatabase& db,const std::vector<std::string> missings_)
{
    calls = db.readTableToMap();
    missings = std::move(missings_);
}

std::vector<std::string> TCalls::getNames()
{
    std::vector<std::string> result;
    for (const auto& entry : calls) {
        result.push_back(entry.first);
    }
    return result;
}

void TCalls::setCallsByName(std::string name, size_t points)
{
    if (calls.find(name)!=calls.end())
        calls[name]+=points;
}

std::vector<std::string> TCalls::getNamesWithoutMissings()
{
    std::vector<std::string> names = this->getNames();
    for (std::string absent : missings)
    {
        auto it = std::find(names.begin(), names.end(), absent);
        if (it != names.end()) {
            names.erase(it);
        }
    }
    return std::vector<std::string> (std::move(names));
}

size_t TCalls::getMinimumOfCalls()
{
    size_t min = 1000;
    for (std::pair<std::string, size_t> call : calls)
        min = (min > call.second) ? call.second : min;
    return min;
}

size_t TCalls::getCallsSize()
{
    return calls.size();
}

std::map<std::string, size_t> TCalls::getCalls()
{
    return calls;
}

void TCalls::setCalls(std::map<std::string, size_t> calls_)
{
    calls = std::move(calls_);
}

void TCalls::setMissings(std::string missing)
{
    missings.push_back(missing);
}

size_t TCalls::getPoints(std::string name)
{
    return calls[name];
}

std::vector<std::string> TCalls::getNamesKDoske(size_t stud)
{
    std::srand(std::time(nullptr));
    std::vector<std::string> min_calls, max_calls, nameskdoske;
    size_t minim = this->getMinimumOfCalls(), i = 0;
    for (std::pair<std::string, size_t> call : calls)
    {
        if (call.second == minim)
            min_calls.push_back(call.first);
        else
            max_calls.push_back(call.first);
    }

    delete_missing(min_calls, missings);
    delete_missing(max_calls, missings);

    while (!min_calls.empty() && i < stud)
    {
        int random = std::rand() % min_calls.size();
        nameskdoske.push_back((min_calls[random]));
        calls[min_calls[random]] += 1;
        min_calls.erase(min_calls.begin() + random);
        i++;
    }
    while (!max_calls.empty() && i < stud)
    {
        int random = std::rand() % max_calls.size();
        nameskdoske.push_back((max_calls[random]));
        calls[max_calls[random]] += 1;
        max_calls.erase(max_calls.begin() + random);
        i++;
    }
    return std::vector<std::string> (std::move(nameskdoske));
}

void delete_missing(std::vector<std::string>& _names, const std::vector<std::string>& missing)
{
    for (std::string absent : missing)
    {
        auto it = std::find(_names.begin(), _names.end(), absent);
        if (it != _names.end()) {
            _names.erase(it);
        }
    }
}
