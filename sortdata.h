#ifndef SORT_DATA
#define SORT_DATA

#include <iostream>
#include <fstream>
#include "student.h"
using namespace std;

int getCountOfStudents()
{
    ifstream readFile("student.dat", ios::in);
    Student student;

    int countOfStudents = 0;

    while (readFile.read((char *)&student, sizeof student))
    {
        countOfStudents++;
    }
    readFile.close();
    readFile.clear();

    return countOfStudents;
}

void fillArray(Student *array)
{
    ifstream readFile("student.dat", ios::in);
    Student student;

    int i = 0;
    while (readFile.read((char *)&student, sizeof student))
    {
        array[i] = student;
        i++;
    }
    readFile.close();
    readFile.clear();
}

void sortData()
{
    bool isOpen = true;

    while (isOpen)
    {
        cout << "1 - Сортировать по дате рождения." << endl
             << "2 - Сортировать по группе." << endl
             << "3 - Сортировать по среднему баллу." << endl
             << "4 - Сортировать по сумме стипендии." << endl
             << "5 - Сортировать по году зачисления." << endl
             << "0 - Выход." << endl;

        int userInput;
        cout << "Сделайте выбор: ";
        cin >> userInput;
        cin.get();

        int countOfStudents = getCountOfStudents();
        Student *arrayOfStudents = new Student[countOfStudents];
        fillArray(arrayOfStudents);

        

    }
}

#endif