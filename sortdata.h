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

void resetFile(Student *arrayOfStudents, int countOfStudents)
{
    ofstream file("student.dat", ios::binary);

    for (int i = 0; i < countOfStudents; i++)
    {
        file.write((char*) & arrayOfStudents[i], sizeof arrayOfStudents[i]);
    }
    file.close();
    file.clear();
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
        

        switch (userInput)
        {
        case 1:
        {
            bool flag;
            Student tmpStudent;

            for (int i = countOfStudents - 2; i >= 0; i--)
            {
                flag = false;

                for (int j = 0; j <= i; j++)
                {
                    if (arrayOfStudents[j].getBirthday().isGreater(arrayOfStudents[j + 1].getBirthday()))
                    {
                        tmpStudent = arrayOfStudents[j];
                        arrayOfStudents[j] = arrayOfStudents[j + 1];
                        arrayOfStudents[j + 1] = tmpStudent;
                        flag = true;
                    }
                }
                if (!flag)
                    break;
            }
            
            break;
        }  
        case 2:
        {
            bool flag;
            Student tmpStudent;

            for (int i = countOfStudents - 2; i >= 0; i--)
            {
                flag = false;

                for (int j = 0; j <= i; j++)
                {
                    if (arrayOfStudents[j].getGroup() > arrayOfStudents[j + 1].getGroup())
                    {
                        tmpStudent = arrayOfStudents[j];
                        arrayOfStudents[j] = arrayOfStudents[j + 1];
                        arrayOfStudents[j + 1] = tmpStudent;
                        flag = true;
                    }
                }
                if (!flag)
                    break;
            }
            
            break;
        }
        case 3:
        {
            bool flag;
            Student tmpStudent;

            for (int i = countOfStudents - 2; i >= 0; i--)
            {
                flag = false;

                for (int j = 0; j <= i; j++)
                {
                    if (arrayOfStudents[j].getAvgScore() > arrayOfStudents[j + 1].getAvgScore())
                    {
                        tmpStudent = arrayOfStudents[j];
                        arrayOfStudents[j] = arrayOfStudents[j + 1];
                        arrayOfStudents[j + 1] = tmpStudent;
                        flag = true;
                    }
                }
                if (!flag)
                    break;
            }
            break;
        }
        case 4:
        {
            bool flag;
            Student tmpStudent;

            for (int i = countOfStudents - 2; i >= 0; i--)
            {
                flag = false;

                for (int j = 0; j <= i; j++)
                {
                    if (arrayOfStudents[j].getScholarshipAmount() > arrayOfStudents[j + 1].getScholarshipAmount())
                    {
                        tmpStudent = arrayOfStudents[j];
                        arrayOfStudents[j] = arrayOfStudents[j + 1];
                        arrayOfStudents[j + 1] = tmpStudent;
                        flag = true;
                    }
                }
                if (!flag)
                    break;
            }
            break;
        }
        case 5:
        {
            bool flag;
            Student tmpStudent;

            for (int i = countOfStudents - 2; i >= 0; i--)
            {
                flag = false;

                for (int j = 0; j <= i; j++)
                {
                    if (arrayOfStudents[j].getYearOfEntered() > arrayOfStudents[j + 1].getYearOfEntered())
                    {
                        tmpStudent = arrayOfStudents[j];
                        arrayOfStudents[j] = arrayOfStudents[j + 1];
                        arrayOfStudents[j + 1] = tmpStudent;
                        flag = true;
                    }
                }
                if (!flag)
                    break;
            }
            break;
        }
        case 0:
        {
            isOpen = false;
            break;
        } 
        default:
        {
            cout << "Неверное значение!";
            break;
        }
        }

        isOpen = false;
        resetFile(arrayOfStudents, countOfStudents);
        system("cls");
    }
}

#endif