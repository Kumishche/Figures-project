// Кумище_№3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "point.h"
#include "triangle.h"
#include "Functions.h"

using namespace std;

bool setPoints(Point* points, int size);
bool setTriangle(Triangle triangle);

int main()
{
    //------------------
    int V = (int('K') + int('R')) % 12;
    cout << V << endl;
    cout << setw(20) << setfill('=') << "" << endl;
    cout << endl;
    //------------------

    int s;
    const int n = 5;
    Point p[n];
    Point res;
    Triangle triangle = Triangle();
    int** indices = nullptr;


    cout << "1 - int getPointsInLine(Point* points, int size, int** indices)" << endl;
    cout << "2 - Point getFarestPoint(Point* points, int size)" << endl;
    cout << "3 - Triangle getMaxLengthTriangle(Point* points, int size)" << endl;
    cout << setw(20) << setfill('-') << "" << endl;
    cout << "4 - ввести массив точек" << endl;
    cout << "5 - ввести треугольник" << endl;
    cout << setw(20) << setfill('-') << "" << endl;
    cout << "6 - выход" << endl;
    cout << setw(40) << setfill('=') << "" << endl;
    cout << endl;


    cout << "Введите символ: ";
    cin >> s;
    while (cin.fail() || cin.get() != '\n')
    {
        cin.clear(); cin.ignore(256, '\n');
        cout << "Некорректный ввод" << endl;
        cout << "Введите символ: ";
        cin >> s;
    }

    switch (s)
    {
    case 1:
        cout << "Ответ: " << getPointsInLine(p, n, indices) << endl;
        break;
    case 2:
        res = getFarestPoint(p, n);
        cout << "Ответ: " << res.x << " " << res.y << endl;
        break;

    case 3:
        triangle = getMaxLengthTriangle(p, n);
        cout << "Ответ: " << endl;
        break;

    case 4:
        setPoints(p, n);
        break;

    case 5:
        setTriangle(triangle);
        break;

    case 6:
        return 0;

    default:
        cout << "Некорректный ввод" << endl;
    }
}


bool setPoints(Point* points, int size)
{
    return 1;
}


bool setTriangle(Triangle triangle)
{
    return 1;
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
