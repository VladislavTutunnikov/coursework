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
        cout << "1 - ����������� �� ���� ��������." << endl
             << "2 - ����������� �� ������." << endl
             << "3 - ����������� �� �������� �����." << endl
             << "4 - ����������� �� ����� ���������." << endl
             << "5 - ����������� �� ���� ����������." << endl
             << "0 - �����." << endl;

        int userInput;
        cout << "�������� �����: ";
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
            cout << "�������� ��������!";
            break;
        }
        }

        isOpen = false;
        resetFile(arrayOfStudents, countOfStudents);
        system("cls");
    }
}

#endif