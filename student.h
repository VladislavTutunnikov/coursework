#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <iomanip>
#include <string.h>
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
        strcpy(surname, "������ �. �.");
        strcpy(birthday, "00.00.0000");
        group = 0;
        avgScore = 0.0;
        scholarshipAmount = 0;
        yearOfEntered = 0;
        strcpy(faculty, "-");
        strcpy(profession, "-");
    }

    void inputData() 
    {
        cout << "������� ������� � ��������: ";
        cin.getline(surname, 25);
        cout << "������� ���� ��������: ";
        cin.getline(birthday, 15);
        cout << "������� ������: ";
        cin >> group;
        cout << "������� ������� ����: ";
        cin >> avgScore;
        cout << "������� ����� ���������: ";
        cin >> scholarshipAmount;
        cout << "������� ��� ����������: ";
        cin >> yearOfEntered;
        cin.get();
        cout << "������� ���������: ";
        cin.getline(faculty, 25);
        cout << "������� �������������: ";
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