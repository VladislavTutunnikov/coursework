#include <iostream>
#include <windows.h>
#include "writefile.h"
#include "readfile.h"
#include "addfile.h"
#include "searchdata.h" 
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    bool isOpen = true;

    while (isOpen)
    {
        int userInput;

        cout << "1 - ���������� �����." << endl
             << "2 - �������� �����." << endl
             << "3 - �������� ������ � ����." << endl
             << "4 - ����� ������." << endl
             << "5 - ��������." << endl
             << "0 - ����� �� ���������." << endl;
        cout << "�������� �����: ";
        cin >> userInput;
        cin.get();

        switch (userInput)
        {
        case 1:
        {
            writeFile();
            break;
        }
        case 2:
        {
            readFile();
            break;
        }
        case 3:
        {
            addFile();
            break;
        }
        case 4:
        {
            searchData();
            break;
        }
        case 0:
        {
            isOpen = false;
            break;
        }
        default:
        {
            cout << "�������� ����!";
            break;
        }
        }
        system("pause");
        system("cls");
    }

    return 0;
}