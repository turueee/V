#include "tcriteriallimit.h"

TCriteriaLimit::TCriteriaLimit()
{
	lab_name = {};
	limit_point = {};
}

TCriteriaLimit::TCriteriaLimit(TDatabase& db, std::string lab_name_)
{
	lab_name = lab_name_;
    limit_point = db.selectLabCriteriaLimits(lab_name);
}


TCriteriaLimit::~TCriteriaLimit()
{
	lab_name = nullptr;
	limit_point = {};
}

int TCriteriaLimit::GetMaxPoint(std::string crit_name_)
{
	return limit_point[crit_name_];
}

std::string TCriteriaLimit::GetLabName()
{
	return lab_name;
}

void TCriteriaLimit::SetMaxPoint(std::string crit_name_, int max_point_)
{
	limit_point[crit_name_] = max_point_;
}

void TCriteriaLimit::SetCriteria(std::string crit_name_, int max_point_)
{
	limit_point.insert( { crit_name_ ,  max_point_ } );
}



