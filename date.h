#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <iomanip>
#include "table.h"
using namespace std;

class Date
{
    int day;
    int month;
    int year;

public:
    Date()
    {
        day = 0;
        month = 0;
        year = 0;
    }

    void inputDate(int x1, int x2, int x3, int y) //24 27 30
    {
        cout << "  .  .";
        gotoxy(x1, y);
        cin >> day;
        gotoxy(x2, y);
        cin >> month;
        gotoxy(x3, y);
        cin >> year;
    }

    void printDate()
    {
        cout << "     " << setw(2) << day << "." << setw(2) << month << "." << setw(4) << year;
    }

    int getDay()
    {
        return day;
    }
    int getMonth()
    {
        return month;
    }
    int getYear()
    {
        return year;
    }

    bool isZero()
    {
        if (day == 0 && month == 0 && year == 0)
            return true;
        else
            return false;
    }

    bool isInRange(Date dateFrom, Date dateTo)
    {
        if (year < dateFrom.getYear() || year > dateTo.getYear())
            return false;
        
        if (year == dateFrom.getYear())
            if (month < dateFrom.getMonth() || (month == dateFrom.getMonth() && day < dateFrom.getDay()))
                return false;
        
        if (year == dateTo.getYear())
            if (month > dateTo.getMonth() || (month == dateTo.getMonth() && day > dateTo.getDay()))
                return false;
        
        return true;
    }

    bool isGreater(Date otherDate)
    {
        if (year != otherDate.getYear()) return year > otherDate.getYear();
        if (month != otherDate.getMonth()) return month > otherDate.getMonth();
        return day > otherDate.day;
    }
};

#endif DATE_H