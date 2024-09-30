#include <iostream>
#include <math.h>
#include "Functions.h"

using namespace std;


//Ќахождение максимальной группы точек, которые лежат на одной пр€мой(нет другой
//	группы, состо€щей из большего количества точек, которые лежат на одной пр€мой).
//	–езультирующее значение - количество точек в найденной группе, массив indices -
//	индексы найденных точек.
//int getPointsInLine(Point* points, int size, int** indices)
//{
//
//}


//Ќайти такую точку, сумма рассто€ний от которой до остальных точек множества максимальна.
Point getFarestPoint(Point* points, int size)
{
	Point max_point = Point();
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

//Ќайти три точки, образующие треугольник наибольшего периметра
//Triangle getMaxLengthTriangle(Point* points, int size)
//{
//	//Triangle tr;
//
//	for (int i = 0; i < size; i++)
//	{
//		//if
//	}
//}