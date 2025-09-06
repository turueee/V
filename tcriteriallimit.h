#include <iostream>
#include <string>
#include <map>
#include "tdatabase.h"

class TCriteriaLimit
{
private:
	std::string lab_name;
	std::map <std::string, int> limit_point; // <crit_name, max_point>

public:
	TCriteriaLimit();
	TCriteriaLimit(TDatabase& db, std::string lab_name_);

	~TCriteriaLimit();

	int GetMaxPoint(std::string crit_name_);
	std::string GetLabName();

	void SetMaxPoint(std::string crit_name_, int max_point_); //edit criteria
	void SetCriteria(std::string crit_name_, int max_point_); //creat new criteria
};



