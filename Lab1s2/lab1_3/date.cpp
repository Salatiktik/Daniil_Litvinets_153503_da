#include "date.h"

int months [12]={31, 28,31,30,31,30,31,31,30,31,30,31};

Date::Date(int day, int month, int year)
{
    this->day=day;
    this->month=month;
    this->year=year;
}

bool Date::isLeap()
{
    if((this->year%4==0&&this->year%100!=0)||(this->year%100==0&&this->year%400==0))
    {
        return true;
    }
    else
        return false;
}

Date Date::nextDay()
{
    if(isLeap())
    {
        months[1]=29;
    }
    else
    {
        months[1]=28;
    }
    int day=this->day,month=this->month,year=this->year;
    if(day==months[month-1])
    {
        day=1;
        year+=(month+1)/12;
        month=(month+1)%12;
        month==0?month=12:month=month;
    }
    else
    {
        day+=1;
    }
 
    return Date(day, month,year);
}

Date Date::previousDay()
{
    if(isLeap())
    {
        months[1]=29;
    }
    else
    {
        months[1]=28;
    }
    int day=this->day,month=this->month,year=this->year;
    if(day==1)
    {
        day=months[((month-2)+12)%12];
        month=(month-1+12)%12;
        month==0?year-=1:year=year;
        month==0?month=12:month=month;
    }
    else
    {
        day-=1;
    }
    return Date(day, month,year);
}

int Date::daysTillYourBirthDay(Date birthDay)
{
    birthDay.year=this->year;
    return duration(birthDay);
}

int Date::duration(Date date)
{
    int days = 0;

    if((date.year>this->year)||(date.year==this->year&&date.month>this->month)||(date.year==this->year&&date.month==this->month&&date.day>this->day))
    {
        for(int i = this->year+1;i<date.year;i++)
        {
            if((i%4==0&&i%100!=0)||(i%100==0&&i%400==0))
                days+=366;
            else
                days+=365;
        }
        if(this->year!=date.year)
        {
            if(isLeap())
            {
                months[1]=29;
            }
            else
            {
                months[1]=28;
            }
            for(int i = this->month+1;i<=12;i++)
            {

                days+=months[i-1];
            }
            days+=months[this->month-1]-this->day;
            if(date.isLeap())
            {
                months[1]=29;
            }
            else
            {
                months[1]=28;
            }
            for(int i = 1;i<date.month;i++)
            {
                days+=months[i-1];
            }
            days+=date.day;
        }
        else
        {
            if(this->month!=date.month)
            {
                if(isLeap())
                {
                    months[1]=29;
                }
                else
                {
                    months[1]=28;
                }
                for(int i=this->month+1;i<date.month;i++)
                {
                    days+=months[i-1];
                }
                days+=months[this->month-1]-this->day;
                days+=date.day;
            }
            else
            {
                days+=date.day-this->day;
            }
        }

    }
    else if ((date.year<this->year)||(date.year==this->year&&date.month<this->month)||(date.year==this->year&&date.month==this->month&&date.day<this->day))
    {
        for(int i = date.year+1;i<this->year;i++)
        {
            if((i%4==0&&i%100!=0)||(i%100==0&&i%400==0))
                days+=366;
            else
                days+=365;
        }
        if(this->year!=date.year)
        {
            if(date.isLeap())
            {
                months[1]=29;
            }
            else
            {
                months[1]=28;
            }
            for(int i = date.month+1;i<=12;i++)
            {

                days+=months[i-1];
            }
            days+=months[date.month-1]-date.day;
            if(isLeap())
            {
                months[1]=29;
            }
            else
            {
                months[1]=28;
            }
            for(int i = 1;i<this->month;i++)
            {
                days+=months[i-1];
            }
            days+=this->day;

        }
        else
        {
            if(this->month!=date.month)
            {
                if(date.isLeap())
                {
                    months[1]=29;
                }
                else
                {
                    months[1]=28;
                }
                for(int i=date.month+1;i<this->month;i++)
                {
                    days+=months[i-1];
                }
                days+=this->day;
                days+=months[date.month-1]-date.day;
            }
            else
            {
                days+=-date.day+this->day;
            }


        }
    }
    else
    {
        return 0;
    }

    return days;
}

short Date::weekNumber()
{
    int days=0;
    if(isLeap())
    {
        months[1]=29;
    }
    else
    {
        months[1]=28;
    }
    for(int i = 1; i< this->month;i++)
    {
        days+=months[i-1];
    }
    days+=this->day;
    if(days%7!=0)
    {
        return days/7+1;
    }
    else
    {
        return days/7;
    }
}

QString Date::str()
{

    return QString::fromStdString(std::to_string(this->day/10)+std::to_string(this->day%10)+"."+std::to_string(this->month/10)+std::to_string(this->month%10)+"."+std::to_string(this->year/1000)+std::to_string(-(this->year/1000)*10+(this->year/100))+std::to_string(-(this->year/100)*10+(this->year/10))+std::to_string(this->year%10));
}
