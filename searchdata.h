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
        if (strcmp(surname, "0") == 0)
        {
            ;
        }
        else
        {
            if (strnicmp(student.getSurname(), surname, strlen(surname)) != 0) return false;
        }

        if(birthdayFrom.isZero() && birthdayTo.isZero())
        {
            ;
        }
        else
        {
            if (!student.getBirthday().isInRange(birthdayFrom, birthdayTo)) return false;
        }

        if (groupFrom == 0 && groupTo == 0)
        {
            ;
        }
        else
        {
            if (student.getGroup() < groupFrom || student.getGroup() > groupTo) return false;
        }

        if (avgScoreFrom == 0 && avgScoreTo == 0)
        {
            ;
        }
        else
        {
            if (student.getAvgScore() < avgScoreFrom || student.getAvgScore() > avgScoreTo) return false;
        }

        if (scholarshipAmountFrom == 0 && scholarshipAmountTo == 0)
        {
            ;
        }
        else
        {
            if ()
        }

        return true;
    }
};

void searchData()
{
    ifstream readFile("student.dat", ios::in);
    ofstream writeFile("tmp.dat", ios::binary);

    Student student;
    StudentForSearch studentForSearch;

    system("cls");
    cout << "¬ведите данные дл€ поиска (чтобы пропустить поле введите 0): " << endl;

    searchHeader();
    studentForSearch.inputData();
    gotoxy(0, 7);
    cout << endl;

    while (readFile.read((char *)&student, sizeof student))
    {
        if (strnicmp(student.getSurname(), studentForSearch.getSurname(), strlen(studentForSearch.getSurname())) == 0 || strncmp(studentForSearch.getSurname, "0") == 0)
    }
}

#endif