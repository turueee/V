#include "tcriteriallimit.h"
#include <QDebug>

TCriteriaLimit::TCriteriaLimit()
    : lab_name("")
    , limit_point()
{
    // Пустой конструктор
}

TCriteriaLimit::TCriteriaLimit(TDatabase& db, QString lab_name_)
    : lab_name(lab_name_)
    , limit_point(db.selectLabCriteriaLimits(lab_name_))
{
    // Конструктор с загрузкой из БД
}

TCriteriaLimit::~TCriteriaLimit()
{
    // Деструктор - автоматическое очищение QMap и QString
}

int TCriteriaLimit::GetMaxPoint(QString crit_name_)
{
    // Безопасный доступ с проверкой
    return limit_point.value(crit_name_, -1); // -1 если не найдено
}

QString TCriteriaLimit::GetLabName()
{
    return lab_name;
}

void TCriteriaLimit::SetMaxPoint(QString crit_name_, int max_point_)
{
    limit_point[crit_name_] = max_point_;
}

void TCriteriaLimit::SetCriteria(QString crit_name_, int max_point_)
{
    limit_point.insert(crit_name_, max_point_);
}



