#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <iomanip>
#include <string.h>
#include "table.h"
using namespace std;

class Student
{
private:
    char surname[25];
    char birthday[15];
    int group;
    float avgScore;
    float scholarshipAmount;
    int yearOfEntered;
    char faculty[25];
    char profession[25];
public:
    Student()
    {
        strcpy(surname, "Иванов И. И.");
        strcpy(birthday, "00.00.0000");
        group = 0;
        avgScore = 0.0;
        scholarshipAmount = 0;
        yearOfEntered = 0;
        strcpy(faculty, "-");
        strcpy(profession, "-");
    }

    void inputData(int y) 
    {
        gotoxy(2, y);
        cin.getline(surname, 25);
        gotoxy(23, y);
        cin.getline(birthday, 15);
        gotoxy(39, y);
        cin >> group;
        gotoxy(46, y);
        cin >> avgScore;
        gotoxy(55, y);
        cin >> scholarshipAmount;
        gotoxy(71, y);
        cin >> yearOfEntered;
        cin.get();
        gotoxy(86, y);
        cin.getline(faculty, 25);
        gotoxy(102, y);
        cin.getline(profession, 25);
    }

    void printData()
    {
        cout << "|" << setw(20) << surname
        << "|" << setw(15) << birthday
        << "|" << setw(6) << group
        << "|" << setw(8) << avgScore
        << "|" << setw(15) << scholarshipAmount
        << "|" << setw(14) << yearOfEntered
        << "|" << setw(15) << faculty
        << "|" << setw(15) << profession
        << "|" << endl;
    }
};

#endif