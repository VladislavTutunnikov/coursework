#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <iomanip>
#include <string.h>
#include "table.h"
#include "date.h"
using namespace std;

class Student
{
protected:
    char surname[25];
    Date birthday;
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
        //strcpy(birthday, "00.00.0000");
        group = 0;
        avgScore = 0.0;
        scholarshipAmount = 0;
        yearOfEntered = 0;
        strcpy(faculty, "-");
        strcpy(profession, "-");
    }

    virtual void inputData(int y)
    {
        gotoxy(3, y);
        cin.getline(surname, 25);
        gotoxy(24, y);
        birthday.inputDate(24, 27, 30, y);
        gotoxy(43, y);
        cin >> group;
        gotoxy(54, y);
        cin >> avgScore;
        gotoxy(65, y);
        cin >> scholarshipAmount;
        gotoxy(81, y);
        cin >> yearOfEntered;
        cin.get();
        gotoxy(96, y);
        cin.getline(faculty, 25);
        gotoxy(115, y);
        cin.getline(profession, 25);
    }

    void printData()
    {
        cout << "|" << setw(20) << surname
             << "|"; 
             birthday.printDate();
             cout << "|" << setw(10) << group
             << "|" << setw(10) << avgScore
             << "|" << setw(15) << scholarshipAmount
             << "|" << setw(14) << yearOfEntered
             << "|" << setw(18) << faculty
             << "|" << setw(21) << profession
             << "|" << endl;
    }

    char *getSurname()
    {
        return surname;
    }

    Date getBirthday()
    {
        return birthday;
    }

    int getGroup()
    {
        return group;
    }

    float getAvgScore()
    {
        return avgScore;
    }

    float getScholarshipAmount()
    {
        return scholarshipAmount;
    }

    int getYearOfEntered()
    {
        return yearOfEntered;
    }

    char *getFaculty()
    {
        return faculty;
    }

    char *getProfession()
    {
        return profession;
    }

};

#endif