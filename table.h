#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <windows.h>
using namespace std;

void printLineForTable()
{
    cout << "+--------------------+---------------+------+--------+---------------+--------------+---------------+---------------+" << endl;
}

void printTableCells()
{
    cout << "|                    |               |      |        |               |              |               |               |" << endl;
    cout << "+--------------------+---------------+------+--------+---------------+--------------+---------------+---------------+" << endl;
}

void gotoxy(int x, int y)                                                                                                                                                                                               
{                                                                                                                                                                                                                                              
    COORD coord;                                                                                                                                                                                                        
    coord.X = x;                                                                                                                                                                                                        
    coord.Y = y;                                                                                                                                                                                                        
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);                                                                                                                                                   
}                                                                                                                                                                                                                       

void printHeadForTable()
{
    cout << "+--------------------+---------------+------+--------+---------------+--------------+---------------+---------------+" << endl;
    cout << "|         ФИО        | Дата рождения |Группа|Ср. балл|Сумма стипендии|Год зачисления|   Факультет   | Специальность |" << endl;
    cout << "+--------------------+---------------+------+--------+---------------+--------------+---------------+---------------+" << endl;
}
#endif