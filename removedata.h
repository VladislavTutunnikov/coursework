#ifndef REMOVEDATA_H
#define REMOVEDATA_H

#include <iostream>
#include <fstream>
#include "searchdata.h"
using namespace std;

bool isAgree()
{
    char answer;
    cout << "�� ������� ��� ������ ������� ������ �/�: ";
    cin >> answer;

    if (answer == '�' || answer == '�' || answer == 'y' || answer == 'Y')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void searchAndRemoveData()
{
    ifstream file("student.dat", ios::in);

    Student student;
    StudentForSearch studentForSearch;

    system("cls");
    cout << "������� ������ ��� ������ (����� ���������� ���� ������� 0): " << endl;

    searchHeader();
    studentForSearch.inputData();
    gotoxy(0, 7);
    cout << endl;

    ofstream tmpFile("tmp.dat", ios::binary);

    while (file.read((char *)&student, sizeof student))
    {
        if (studentForSearch.isSearchMetched(student))
        {
            student.printData();
        }
        else
        {
            tmpFile.write((char *)&student, sizeof student);
        }
    }
    file.close();
    file.clear();
    tmpFile.close();
    tmpFile.clear();

    if (isAgree())
    {
        remove("student.dat");
        rename("tmp.dat", "student.dat");
    }
}

void removeData()
{
    system("cls");

    bool isOpen = true;

    while (isOpen)
    {
        cout << "1 - ������� ��� ������." << endl
             << "2 - ������� �������� ������." << endl
             << "0 - ������." << endl;

        int userInput;

        cout << "�������� �����: ";
        cin >> userInput;
        cin.get();

        switch (userInput)
        {
        case 1:
        {
            if (isAgree())
            {
                remove("student.dat");
                isOpen = false;
            }
            break;
        }
        case 2:
        {
            searchAndRemoveData();
            system("pause");
            break;
        }
        case 0:
        {
            isOpen = false;
            break;
        }

        default:
        {
            cout << "�������� �����!" << endl;
            break;
        }
        }
        system("cls");
    }
}

#endif
