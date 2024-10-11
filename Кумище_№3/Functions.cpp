#include <iostream>
#include <math.h>
#include "Functions.h"

using namespace std;


//Нахождение максимальной группы точек, которые лежат на одной прямой(нет другой
//	группы, состоящей из большего количества точек, которые лежат на одной прямой).
//	Результирующее значение - количество точек в найденной группе, массив indices -
//	индексы найденных точек.
int getPointsInLine(Point* points, int size, int** indices)
{
	int num = 2;
	int max_num = 2;
	double k;
	int id;
	int* indexes = new int[size];

	for (int i = 0; i < size - 1; i++)
	{
		indexes[0] = i;
		id = 1;

		for (int w = i + 1; w < size; w++)
		{
			if (points[i].x - points[w].x == 0) continue;
			k = (points[i].y - points[w].y) / (points[i].x - points[w].x);
			indexes[id] = w;
			id++;

			for (int j = 0; j < size; j++)
			{
				if (points[i].x - points[j].x == 0) continue;

				if (j != i && j != w &&
					k == (points[i].y - points[j].y) / (points[i].x - points[j].x))
				{
					num++;
					indexes[id] = j;
					id++;
				}
			}

			if (num > max_num)
			{
				delete[] *indices;
				max_num = num;
				*indices = new int[num];
				for (int q = 0; q < num; q++)
				{
					(*indices)[q] = indexes[q];
				}
			}

			id = 1;
			num = 2;
		}
	}

	id = 0;
	num = 1;

	for (int i = 0; i < size-1; i++)
	{
		indexes[id] = i;
		id++;

		for (int j = i + 1; j < size; j++)
		{
			if (points[i].x - points[j].x == 0)
			{
				num++;
				indexes[id] = j;
				id++;
			}
		}

		if (num > max_num)
		{
			delete[] *indices;
			max_num = num;
			*indices = new int[num];
			for (int q = 0; q < num; q++)
			{
				(*indices)[q] = indexes[q];
			}
		}

		id = 0;
		num = 1;
	}

	delete[] indexes;
	return max_num;
}


//Найти такую точку, сумма расстояний от которой до остальных точек множества максимальна.
Point getFarestPoint(Point* points, int size)
{
	if (size < 1)
	{
		cout << "Не удалось найти подходящую точку, выдано значение по умолчанию" << endl;
		return Point();
	}

	Point max_point = points[0];
	double sum = 0, max_sum = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			sum += sqrt(pow(points[i].x - points[j].x, 2) + 
				pow(points[i].y - points[j].y, 2));
		}

		if (sum > max_sum)
		{
			max_sum = sum;
			max_point = points[i];
		}

		sum = 0;
	}

	return max_point;
}


//Найти три точки, образующие треугольник наибольшего периметра
Triangle getMaxLengthTriangle(Point* points, int size)
{
	Triangle t, res;
	double max_perimeter = 0, perimeter = 0;

	if (size < 1)
	{
		cout << "Не удалось найти точки, выдан треугольник по умолчанию" << endl;
		return Triangle();
	}

	Point p1 = getFarestPoint(points, size);
	for (int i = 0; i < size; i++)
	{
		if (points[i].x == p1.x && points[i].y == p1.y) continue;
		for (int j = 0; j < size; j++)
		{
			if (points[j].x == p1.x && points[j].y == p1.y) continue;
			if (points[j].x == points[i].x && points[j].y == points[i].y) continue;
			if (abs(p1.y - points[i].y) / abs(p1.x - points[i].x) ==
				abs(p1.y - points[j].y) / abs(p1.x - points[j].x)) continue;

			t = Triangle(p1, points[i], points[j]);
			perimeter = t.Perimeter();
			if (perimeter > max_perimeter)
			{
				max_perimeter = perimeter;
				res = t;
			}
		}
	}

	Triangle n;
	if (res == n)
		cout << "Не удалось вычислить треугольник по заданным точкам, выдан треугольник по умолчанию" << endl;

	return res;
}