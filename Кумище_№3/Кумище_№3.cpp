// Кумище_№3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "point.h"
#include "triangle.h"
#include "Functions.h"

using namespace std;

void setPoints(Point*& points, int& size);
void getPoints(Point* points, int size);
void setTriangle(Triangle& tr);
void getTriangle(Triangle& tr);
void Check(int& var);

int main()
{
    SetConsoleCP(1251); SetConsoleOutputCP(1251);

    //------------------
    int V = (int('K') + int('R')) % 12;
    cout << V << endl;
    cout << setw(20) << setfill('=') << "" << endl;
    cout << endl;
    //------------------

    int s;
    int size = 0;
    Point* points = nullptr;
    Point res;
    Triangle triangle;
    int* indices = nullptr;

    while (true)
    {
        cout << "1 - int getPointsInLine(Point* points, int size, int** indices)" << endl;
        cout << "2 - Point getFarestPoint(Point* points, int size)" << endl;
        cout << "3 - Triangle getMaxLengthTriangle(Point* points, int size)" << endl;
        cout << setw(20) << setfill('-') << "" << endl;
        cout << "4 - ввести массив точек" << endl;
        cout << "5 - ввести треугольник" << endl;
        cout << "6 - вывести массив точек" << endl;
        cout << "7 - вывести треугольник" << endl;
        cout << setw(20) << setfill('-') << "" << endl;
        cout << "8 - выход" << endl;
        cout << setw(40) << setfill('=') << "" << endl;
        cout << endl;

        cout << "Введите символ: ";
        cin >> s;
        Check(s);

        switch (s)
        {
        case 1:
            cout << "Ответ: " << getPointsInLine(points, size, &indices) << endl;
            break;

        case 2:
            res = getFarestPoint(points, size);
            cout << "Ответ: (" << res.x << "; " << res.y << ")" << endl;
            break;

        case 3:
            triangle = getMaxLengthTriangle(points, size);
            getTriangle(triangle);
            break;

        case 4:
            setPoints(points, size);
            break;

        case 5:
            setTriangle(triangle);
            break;

        case 6:
            getPoints(points, size);
            break;

        case 7:
            getTriangle(triangle);
            break;

        case 8:
            return 0;

        default:
            cout << "Некорректный ввод" << endl;
        }

        cout << setw(40) << setfill('=') << "" << endl;
        cout << endl;
    }
}


void setPoints(Point*& points, int& size)
{
    delete[] points;

    cout << "Введите размер массива: ";
    cin >> size;
    Check(size);
    while (size < 1)
    {
        cout << "Некорректный ввод" << endl;
        cout << "Повторите ввод: ";
        cin >> size;
        Check(size);
    }

    points = new Point[size];

    cout << "Ввод точек: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Введите точку " << i + 1 << ": ";
        cin >> points[i].x >> points[i].y;
        while (cin.fail() || cin.get() != '\n')
        {
            cin.clear(); cin.ignore(256, '\n');
            cout << "Некорректный ввод" << endl;
            cout << "Повторите ввод: ";
            cin >> points[i].x >> points[i].y;
        }
    }

    cout << "Массив точек записан" << endl;
}


void getPoints(Point* points, int size)
{
    if (size < 1)
    {
        cout << "Точки не введены" << endl;
        return;
    }

    cout << "Массив точек: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << ": (" << points[i].x << "; " << points[i].y << ")" << endl;
    }
}


void setTriangle(Triangle& tr)
{
    Point p;
    for (int i = 0; i < 3; i++)
    {
        cout << "Введите точку " << i + 1 << ": ";
        cin >> p.x >> p.y;
        while (cin.fail() || cin.get() != '\n')
        {
            cin.clear(); cin.ignore(256, '\n');
            cout << "Некорректный ввод" << endl;
            cout << "Повторите ввод: ";
            cin >> p.x >> p.y;
        }
        tr.setNode(i + 1, p);
    }

    cout << "Треугольник введен" << endl;
}


void getTriangle(Triangle& tr)
{
    Point p;
    Triangle t;

    if (tr == t)
    {
        cout << "Треугольник не введен" << endl;
        return;
    }
    
    cout << "Вывод треугольника: " << endl;
    for (int i = 0; i < 3; i++)
    {
        p = tr.getNode(i+1);
        cout << i+1 << ": (" << p.x << "; " << p.y << ")" << endl;
    }
}


void Check(int& var)
{
    while (cin.fail() || cin.get() != '\n')
    {
        cin.clear(); cin.ignore(256, '\n');
        cout << "Некорректный ввод" << endl;
        cout << "Повторите ввод: ";
        cin >> var;
    }
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
