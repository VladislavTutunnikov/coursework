#ifndef SEARCHDATA_H
#define SEARCHDATA_H

#include <iostream>
#include <fstream>
#include <string.h>
#include "student.h"
#include "table.h"
using namespace std;

class StudentForSearch : public Student
{
private:
    Date birthdayFrom;
    Date birthdayTo;

    int groupFrom;
    int groupTo;

    float avgScoreFrom;
    float avgScoreTo;

    float scholarshipAmountFrom;
    float scholarshipAmountTo;

    int yearOfEnteredFrom;
    int yearOfEnteredTo;

public:
    void inputData()
    {
        int y = 4;
        gotoxy(2, y);
        cin.getline(surname, 25);

        gotoxy(28, y);
        birthdayFrom.inputDate(28, 31, 34, y);
        gotoxy(28, y + 1);
        birthdayTo.inputDate(28, 31, 34, y + 1);

        gotoxy(46, y);
        cin >> groupFrom;
        gotoxy(46, y + 1);
        cin >> groupTo;

        gotoxy(57, y);
        cin >> avgScoreFrom;
        gotoxy(57, y + 1);
        cin >> avgScoreTo;

        gotoxy(68, y);
        cin >> scholarshipAmountFrom;
        gotoxy(68, y + 1);
        cin >> scholarshipAmountTo;

        gotoxy(84, y);
        cin >> yearOfEnteredFrom;
        gotoxy(84, y + 1);
        cin >> yearOfEnteredTo;
        cin.get();

        gotoxy(95, y);
        cin.getline(faculty, 25);
        gotoxy(114, y);
        cin.getline(profession, 25);
    }

    bool isSearchMetched(Student student)
    {
        if (strcmp(surname, "0") == 0 
        && birthdayFrom.isZero() && birthdayTo.isZero() 
        && groupFrom == 0 && groupTo == 0 
        && avgScoreFrom == 0 && avgScoreTo == 0 
        && scholarshipAmountFrom == 0 && scholarshipAmountTo == 0 
        && yearOfEnteredFrom == 0 && yearOfEnteredTo == 0 
        && strcmp(faculty, "0") == 0 
        && strcmp(profession, "0") == 0)
        {
            return false;
        }

        if (strcmp(surname, "0") == 0)
        {
            ;
        }
        else
        {
            if (_strnicmp(student.getSurname(), surname, strlen(surname)) != 0)
                return false;
        }

        if (birthdayFrom.isZero() && birthdayTo.isZero())
        {
            ;
        }
        else
        {
            if (!student.getBirthday().isInRange(birthdayFrom, birthdayTo))
                return false;
        }

        if (groupFrom == 0 && groupTo == 0)
        {
            ;
        }
        else
        {
            if (student.getGroup() < groupFrom || student.getGroup() > groupTo)
                return false;
        }

        if (avgScoreFrom == 0 && avgScoreTo == 0)
        {
            ;
        }
        else
        {
            if (student.getAvgScore() < avgScoreFrom || student.getAvgScore() > avgScoreTo)
                return false;
        }

        if (scholarshipAmountFrom == 0 && scholarshipAmountTo == 0)
        {
            ;
        }
        else
        {
            if (student.getScholarshipAmount() < scholarshipAmountFrom || student.getScholarshipAmount() > scholarshipAmountTo)
                return false;
        }

        if (yearOfEnteredFrom == 0 && yearOfEnteredTo == 0)
        {
            ;
        }
        else
        {
            if (student.getYearOfEntered() < yearOfEnteredFrom || student.getYearOfEntered() > yearOfEnteredTo)
                return false;
        }

        if (strcmp(faculty, "0") == 0)
        {
            ;
        }
        else
        {
            if (_strnicmp(student.getFaculty(), faculty, strlen(faculty)) != 0)
                return false;
        }

        if (strcmp(profession, "0") == 0)
        {
            ;
        }
        else
        {
            if (_strnicmp(student.getProfession(), profession, strlen(profession)) != 0)
                return false;
        }

        return true;
    }
};

void searchData()
{
    ifstream file("student.dat", ios::in);

    Student student;
    StudentForSearch studentForSearch;

    system("cls");
    cout << "Введите данные для поиска (чтобы пропустить поле введите 0): " << endl;

    searchHeader();
    studentForSearch.inputData();
    gotoxy(0, 7);
    cout << endl;

    bool isFound = false;

    while (file.read((char *)&student, sizeof student))
    {
        if (studentForSearch.isSearchMetched(student))
        {
            isFound = true;
            student.printData();
        }
    }

    if (!isFound)
    {
        cout << "Ничего не найдено" << endl;
    }
}
#endif