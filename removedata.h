#ifndef REMOVEDATA_H
#define REMOVEDATA_H

#include <iostream>
#include <string.h>
#include <fstream>
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

void removeData()
{
    system("cls");

    bool isOpen = true;

    while (isOpen)
    {
        cout << "1 - ������� �������� ������." << endl
             << "2 - ������� ��� ������." << endl
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
            
        }

        default:
            break;
        }
    }
}

#endif
