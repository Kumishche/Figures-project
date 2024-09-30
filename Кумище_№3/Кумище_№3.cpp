// Кумище_№3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "point.h"
#include "triangle.h"
#include "Functions.h"

using namespace std;

int main()
{
    int V = (int('K') + int('R')) % 12;
    cout << V << endl;
    cout << setw(20) << setfill('=') << "" << endl;
    cout << endl;

    Point p[5];
    p[0] = Point(0, 0);
    p[1] = Point(1, 1);
    p[2] = Point(-10, 10);
    p[3] = Point(-1, -1);
    p[4] = Point(1, -1);

    Point res = getFarestPoint(p, 5);
    cout << res.x << " " << res.y;

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
