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

    cout << "¬ведите кол-во студентов: ";
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
        gotoxy(0, y + 2);
        y += 2;
    }
    file.clear();
    file.close();
    cout << endl;
}

#endif