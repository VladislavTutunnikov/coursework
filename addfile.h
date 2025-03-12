#ifndef ADDFILE_H
#define ADDFILE_H

#include <iostream>
#include <fstream>
#include "student.h"
#include "table.h"
using namespace std;

void addFile()
{
    ofstream file("student.dat", ios::app);
    Student student;
    int countOfStudents;

    cout << "Введите кол-во студентов для добавления: ";
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
    }
    file.clear();
    file.close();
    cout << endl;
}

#endif