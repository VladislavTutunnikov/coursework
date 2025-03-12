#ifndef READFILE_H
#define READFILE_H

#include <iostream>
#include <fstream>
#include "student.h"
#include "table.h"
using namespace std;

void readFile()
{
    ifstream file("student.dat", ios::in);
    Student student;

    printHeadForTable();
    while(file.read((char*) & student, sizeof student))
    {
        student.printData();
        printLineForTable();
    }
}

#endif