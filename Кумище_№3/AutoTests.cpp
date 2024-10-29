#include "AutoTests.h"
#include <iostream>
#include <iomanip>

using namespace std;

void getPointsInLine_TEST()
{
	cout << "Тестовые сценарии: " << endl;
	cout << "int getPointsInLine(Point * points, int size, int** indices)" << endl;
	cout << setw(20) << setfill('-') << "" << endl;

	const int n = 5;
	Point p[n];
	int* indices = nullptr;
	int res = -1;
	int c = -1;

	{
		cout << "Тест 1" << endl;
		for (int i = 0; i < n; i++)
		{
			p[i] = Point(i, i * 2);
			cout << "Точка " << i + 1 << ": (" << p[i].x << "; " << p[i].y << ")" << endl;
		}
		res = getPointsInLine(p, n, &indices);
		c = 5;
		cout << "Верный ответ: " << c << endl;
		cout << "Ответ функции: " << res << endl;
		Check(res, c);
		cout << setw(20) << setfill('-') << "" << endl;
	}

	{
		cout << "Тест 2" << endl;
		for (int i = 0; i < n; i++)
		{
			p[i] = Point(i * (-1), i * i);
			cout << "Точка " << i + 1 << ": (" << p[i].x << "; " << p[i].y << ")" << endl;
		}
		res = getPointsInLine(p, n, &indices);
		c = 2;
		cout << "Верный ответ: " << c << endl;
		cout << "Ответ функции: " << res << endl;
		Check(res, c);
		cout << setw(20) << setfill('-') << "" << endl;
	}

	{
		cout << "Тест 3" << endl;
		for (int i = 0; i < n; i++)
		{
			p[i] = Point(0, 0);
			cout << "Точка " << i + 1 << ": (" << p[i].x << "; " << p[i].y << ")" << endl;
		}
		res = getPointsInLine(p, n, &indices);
		c = 5;
		cout << "Верный ответ: " << c << endl;
		cout << "Ответ функции: " << res << endl;
		Check(res, c);
		cout << setw(20) << setfill('-') << "" << endl;
	}

	{
		cout << "Тест 4" << endl;
		for (int i = 0; i < n; i++)
		{
			p[i] = Point(0, i * (-i) * 3.14);
			cout << "Точка " << i + 1 << ": (" << p[i].x << "; " << p[i].y << ")" << endl;
		}
		res = getPointsInLine(p, n, &indices);
		c = 5;
		cout << "Верный ответ: " << c << endl;
		cout << "Ответ функции: " << res << endl;
		Check(res, c);
		cout << setw(20) << setfill('-') << "" << endl;
	}

	{
		cout << "Тест 5" << endl;
		for (int i = 0; i < n; i++)
		{
			p[i] = Point(i * pow(-1, i), i * pow(-1, i + 1));
			cout << "Точка " << i + 1 << ": (" << p[i].x << "; " << p[i].y << ")" << endl;
		}
		res = getPointsInLine(p, n, &indices);
		c = 5;
		cout << "Верный ответ: " << c << endl;
		cout << "Ответ функции: " << res << endl;
		Check(res, c);
		cout << setw(20) << setfill('-') << "" << endl;
	}

	cout << setw(40) << setfill('=') << "" << endl;
	delete[] indices;
}

void getFarestPoint_TEST()
{
	cout << "Тестовые сценарии: " << endl;
	cout << "Point getFarestPoint(Point* points, int size)" << endl;
	cout << setw(40) << setfill('=') << "" << endl;
	cout << endl;

	const int n = 5;
	Point p[n];
	Point res;
	Point c;

	{
		cout << "Тест 1" << endl;
		for (int i = 0; i < n; i++)
		{
			p[i] = Point(i, i * 2);
			cout << "Точка " << i + 1 << ": (" << p[i].x << "; " << p[i].y << ")" << endl;
		}
		res = getFarestPoint(p, n);
		c = Point(0, 0);
		cout << "Верный ответ: ";
		c.Print();
		cout << endl;
		cout << "Ответ функции: ";
		res.Print(); 
		cout << endl;
		Check(res, c);
		cout << setw(20) << setfill('-') << "" << endl;
	}

	{
		cout << "Тест 2" << endl;
		for (int i = 0; i < n; i++)
		{
			p[i] = Point(i*(-1), i * i);
			cout << "Точка " << i + 1 << ": (" << p[i].x << "; " << p[i].y << ")" << endl;
		}
		res = getFarestPoint(p, n);
		c = Point(-4, 16);
		cout << "Верный ответ: ";
		c.Print();
		cout << endl;
		cout << "Ответ функции: ";
		res.Print();
		cout << endl;
		Check(res, c);
		cout << setw(20) << setfill('-') << "" << endl;
	}

	{
		cout << "Тест 3" << endl;
		for (int i = 0; i < n; i++)
		{
			p[i] = Point(0, 0);
			cout << "Точка " << i + 1 << ": (" << p[i].x << "; " << p[i].y << ")" << endl;
		}
		res = getFarestPoint(p, n);
		c = Point(0, 0);
		cout << "Верный ответ: ";
		c.Print();
		cout << endl;
		cout << "Ответ функции: ";
		res.Print();
		cout << endl;
		Check(res, c);
		cout << setw(20) << setfill('-') << "" << endl;
	}

	{
		cout << "Тест 4" << endl;
		for (int i = 0; i < n; i++)
		{
			p[i] = Point(i*(0.001), i*(-i)*3.14);
			cout << "Точка " << i + 1 << ": (" << p[i].x << "; " << p[i].y << ")" << endl;
		}
		res = getFarestPoint(p, n);
		c = Point(0.004, -50.24);
		cout << "Верный ответ: ";
		c.Print();
		cout << endl;
		cout << "Ответ функции: ";
		res.Print();
		cout << endl;
		Check(res, c);
		cout << setw(20) << setfill('-') << "" << endl;
	}

	{
		cout << "Тест 5" << endl;
		for (int i = 0; i < n; i++)
		{
			p[i] = Point(i*pow(-1, i), i*pow(-1,i+1));
			cout << "Точка " << i + 1 << ": (" << p[i].x << "; " << p[i].y << ")" << endl;
		}
		res = getFarestPoint(p, n);
		c = Point(4, -4);
		cout << "Верный ответ: ";
		c.Print();
		cout << endl;
		cout << "Ответ функции: ";
		res.Print();
		cout << endl;
		Check(res, c);
		cout << setw(20) << setfill('-') << "" << endl;
	}

	cout << setw(40) << setfill('=') << "" << endl;
}

void getMaxLengthTriangle_TEST()
{
	cout << "Тестовые сценарии: " << endl;
	cout << "Triangle getMaxLengthTriangle(Point* points, int size)" << endl;
	cout << setw(40) << setfill('=') << "" << endl;
	cout << endl;

	const int n = 6;
	Point p[n];
	Triangle res;
	Triangle c;

	{
		cout << "Тест 1" << endl;
		for (int i = 0; i < n; i++)
		{
			p[i] = Point(i, i*(i-1)+2);
			cout << "Точка " << i + 1 << ": (" << p[i].x << "; " << p[i].y << ")" << endl;
		}
		res = getMaxLengthTriangle(p, n);
		c = Triangle(Point(0,2), Point(1,2), Point(5,22));
		cout << "Верный ответ: ";
		c.Print();
		cout << endl;
		cout << "Ответ функции: ";
		res.Print();
		cout << endl;
		Check(res, c);
		cout << setw(20) << setfill('-') << "" << endl;
	}

	{
		cout << "Тест 2" << endl;
		for (int i = 0; i < n; i++)
		{
			p[i] = Point(i * (-1), i * i);
			cout << "Точка " << i + 1 << ": (" << p[i].x << "; " << p[i].y << ")" << endl;
		}
		res = getMaxLengthTriangle(p, n);
		c = Triangle(Point(0,0), Point(-1,1),Point(-5,25));
		cout << "Верный ответ: ";
		c.Print();
		cout << endl;
		cout << "Ответ функции: ";
		res.Print();
		cout << endl;
		Check(res, c);
		cout << setw(20) << setfill('-') << "" << endl;
	}

	{
		cout << "Тест 3" << endl;
		for (int i = 0; i < n; i++)
		{
			p[i] = Point(0, 0);
			cout << "Точка " << i + 1 << ": (" << p[i].x << "; " << p[i].y << ")" << endl;
		}
		res = getMaxLengthTriangle(p, n);
		c = Triangle();
		cout << "Верный ответ: ";
		c.Print();
		cout << endl;
		cout << "Ответ функции: ";
		res.Print();
		cout << endl;
		Check(res, c);
		cout << setw(20) << setfill('-') << "" << endl;
	}

	{
		cout << "Тест 4" << endl;
		for (int i = 0; i < n; i++)
		{
			p[i] = Point(i * (0.001), i * (-i) * 3.14);
			cout << "Точка " << i + 1 << ": (" << p[i].x << "; " << p[i].y << ")" << endl;
		}
		res = getMaxLengthTriangle(p, n);
		c = Triangle(Point(0,0), Point(0.001, -3.14), Point(0.005, -78.5));
		cout << "Верный ответ: ";
		c.Print();
		cout << endl;
		cout << "Ответ функции: ";
		res.Print();
		cout << endl;
		Check(res, c);
		cout << setw(20) << setfill('-') << "" << endl;
	}

	cout << setw(40) << setfill('=') << "" << endl;
}

void Square_TEST()
{
	float s = -1;
	float res = -1;

	{
		cout << "Тест 1: " << endl;
		cout << "Треугольник: (0, 0), (0, 10), (10, 0)" << endl;
		Triangle tr = Triangle(Point(0, 0), Point(0, 10), Point(10, 0));
		res = tr.Square();
		s = 50;
		cout << "Верный ответ: " << s << endl;
		cout << "Ответ функции: " << res << endl;
		Check(res, s);
		cout << setw(20) << setfill('-') << "" << endl;
	}

	{
		cout << "Тест 2: " << endl;
		cout << "Треугольник: (-1, -1), (1, 1), (-1, 2)" << endl;
		Triangle tr = Triangle(Point(-1, -1), Point(1, 1), Point(-1, 2));
		res = tr.Square();
		s = 3;
		cout << "Верный ответ: " << s << endl;
		cout << "Ответ функции: " << res << endl;
		Check(res, s);
		cout << setw(20) << setfill('-') << "" << endl;
	}

	{
		cout << "Тест 3: " << endl;
		cout << "Треугольник: (-1, -1), (18, 44), (-1, 0)" << endl;
		Triangle tr = Triangle(Point(-1, -1), Point(18, 44), Point(-1, 0));
		res = tr.Square();
		s = 9.5;
		cout << "Верный ответ: " << s << endl;
		cout << "Ответ функции: " << res << endl;
		Check(res, s);
		cout << setw(20) << setfill('-') << "" << endl;
	}
}

template<typename T> void Check(T& res, T& c) 
{
	if (res == c)
		cout << "Вердикт: ВЕРНО" << endl;
	else
		cout << "Вердикт: НЕВЕРНО" << endl;
}