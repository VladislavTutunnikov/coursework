#ifndef WRITEFILE_H
#define WRITEFILE_H

#include<iostream>
#include <fstream>
#include "student.h"
#include "table.h"
using namespace std;

void writeFile()
{
    ofstream file("student.dat", ios::binary);
    
    Student student;
    int countOfStudents;

    cout << "������� ���-�� ���������: ";
    cin >> countOfStudents;
    cin.get();

    system("cls");
    printHeadForTable();
    int y = 3;
    for (int i = 1; i <= countOfStudents; i++)
    {
        printTableCells();
        student.inputData(y);
        file.write((char*) & student, sizeof student);
        y += 2;
        gotoxy(0, y);
    }
    file.close();
    file.clear();
    cout << endl;
}

#endif