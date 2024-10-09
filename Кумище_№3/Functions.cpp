#include <iostream>
#include <math.h>
#include "Functions.h"

using namespace std;


//���������� ������������ ������ �����, ������� ����� �� ����� ������(��� ������
//	������, ��������� �� �������� ���������� �����, ������� ����� �� ����� ������).
//	�������������� �������� - ���������� ����� � ��������� ������, ������ indices -
//	������� ��������� �����.
int getPointsInLine(Point* points, int size, int** indices)
{
	return 0;
}


//����� ����� �����, ����� ���������� �� ������� �� ��������� ����� ��������� �����������.
Point getFarestPoint(Point* points, int size)
{
	if (size < 1)
	{
		cout << "�� ������� ����� ���������� �����, ������ �������� �� ���������" << endl;
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


//����� ��� �����, ���������� ����������� ����������� ���������
Triangle getMaxLengthTriangle(Point* points, int size)
{
	Triangle t, res;
	double max_perimeter = 0, perimeter = 0;

	if (size < 1)
	{
		cout << "�� ������� ����� �����, ����� ����������� �� ���������" << endl;
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
		cout << "�� ������� ��������� ����������� �� �������� ������, ����� ����������� �� ���������" << endl;

	return res;
}