#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <iomanip>
#include "table.h"
using namespace std;

class Date
{
    int day;
    int mounth;
    int year;

public:
    void inputDate(int y)
    {
        cout << "  .  .";
        gotoxy(24, y);
        cin >> day;
        gotoxy(27, y);
        cin >> mounth;
        gotoxy(30, y);
        cin >> year;
    }

    void printDate()
    {
        cout << "     " << setw(2) << day << "." << setw(2) << mounth << "." << setw(4) << year;
    }
};

#endif DATE_H