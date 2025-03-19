#ifndef REMOVEDATA_H
#define REMOVEDATA_H

#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

bool isAgree()
{
    char answer;
    cout << "Вы уверены что хотите удалить данные д/н: ";
    cin >> answer;

    if (answer == 'д' || answer == 'Д' || answer == 'y' || answer == 'Y')
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
        cout << "1 - Удалить найденые данные." << endl
             << "2 - Удалить все данные." << endl
             << "0 - Отмена." << endl;

        int userInput;

        cout << "Сделайте выбор: ";
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
