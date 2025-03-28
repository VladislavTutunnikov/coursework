#include <iostream>
#include <windows.h>
#include "writefile.h"
#include "readfile.h"
#include "addfile.h"
#include "searchdata.h" 
#include "removedata.h"
#include "sortdata.h"
#include "aboutprogram.h"
#include "table.h";
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    system("cls");
    bool isOpen = true;

    while (isOpen)
    {
        int userInput;

        cout << "1 - Заполнение файла." << endl
             << "2 - Просмотр файла." << endl
             << "3 - Добавить данные в файл." << endl
             << "4 - Поиск данных." << endl
             << "5 - Сортировка данных." << endl
             << "6 - Удаление." << endl
             << "7 - О программе." << endl
             << "0 - Выход из программы." << endl;
        cout << "Сделайте выбор: ";
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
        case 5:
        {
            sortData();
            break;
        }
        case 6:
        {
            removeData();
            break;
        }
        case 7:
        {
            aboutProgram();
            break;
        }
        case 0:
        {
            isOpen = false;
            break;
        }
        default:
        {
            cout << "Неверный ввод!";
            break;
        }
        }
        system("pause");
        system("cls");
    }
    return 0;
}