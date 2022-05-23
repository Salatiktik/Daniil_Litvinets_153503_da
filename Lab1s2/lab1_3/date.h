#ifndef DATE_H
#define DATE_H

#include <QString>
#include <QDebug>

class Date
{
public:
    Date(int day=0, int month=0, int year=0);
    Date nextDay();
    Date previousDay();
    int daysTillYourBirthDay(Date birthDay);
    int duration(Date date);
    bool isLeap();
    short weekNumber();
    QString str();
    int year;
    int month;
    int day;

};

#endif // DATE_H
