#include <iostream>
#include <string>
#include <map>
#include "tdatabase.h"

class TCriteriaLimit
{
private:
    QString lab_name;
    QMap <QString, int> limit_point; // <crit_name, max_point>

public:
	TCriteriaLimit();
    TCriteriaLimit(TDatabase& db, QString lab_name_);

	~TCriteriaLimit();

    int GetMaxPoint(QString crit_name_);
    QString GetLabName();

    void SetMaxPoint(QString crit_name_, int max_point_); //edit criteria
    void SetCriteria(QString crit_name_, int max_point_); //creat new criteria
};



