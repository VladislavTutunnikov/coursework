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

    for (int i = 1; i <= countOfStudents; i++)
    {
        cout << "������� ������ � " << i << "-� ��������: " << endl;
        student.inputData();
        printSpacerLine();
        file.write((char*) & student, sizeof student);
    }
    file.clear();
    file.close();
}

#endif