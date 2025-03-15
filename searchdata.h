#ifndef SEARCHDATA_H
#define SEARCHDATA_H

#include <iostream>
#include <fstream>
#include "student.h"
using namespace std;

class StudentForSearch : public Student
{
private:
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
        int y = 3;
        gotoxy(3, y);
        cin.getline(surname, 25);
        gotoxy(24, y);
        cin.getline(birthday, 15);

        gotoxy(44, y);
        cin >> groupFrom;
        gotoxy(44, y + 1);
        cin >> groupTo;

        gotoxy(55, y);
        cin >> avgScoreFrom;
        gotoxy(55, y + 1);
        cin >> avgScoreTo;

        gotoxy(66, y);
        cin >> scholarshipAmountFrom;
        gotoxy(66, y + 1);
        cin >> scholarshipAmountTo;

        gotoxy(82, y);
        cin >> yearOfEnteredFrom;
        gotoxy(82, y + 1);
        cin >> yearOfEnteredTo;
        cin.get();

        gotoxy(93, y);
        cin.getline(faculty, 25);
        gotoxy(112, y);
        cin.getline(profession, 25);

    }

};

void searchData()
{
    ifstream readFile("student.dat", ios::in);
    ofstream writeFile("tmp.dat", ios::binary);

    char surname[25];
    char birthday[15];

    int groupFrom;
    int groupTo;

    float avgScoreFrom;
    float avgScoreTo;


    float scholarshipAmountFrom;
    float scholarshipAmountTo;

    int yearOfEnteredFrom;
    int yearOfEnteredTo;

    char faculty[25];
    char profession[25];

    
}

#endif