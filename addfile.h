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

    cout << "������� ���-�� ��������� ��� ����������: ";
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
    file.close();
    file.clear();
    cout << endl;
}

#endif