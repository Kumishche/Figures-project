#include <iostream>
#include <math.h>
#include "Functions.h"

using namespace std;


//���������� ������������ ������ �����, ������� ����� �� ����� ������(��� ������
//	������, ��������� �� �������� ���������� �����, ������� ����� �� ����� ������).
//	�������������� �������� - ���������� ����� � ��������� ������, ������ indices -
//	������� ��������� �����.
//int getPointsInLine(Point* points, int size, int** indices)
//{
//
//}


//����� ����� �����, ����� ���������� �� ������� �� ��������� ����� ��������� �����������.
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

//����� ��� �����, ���������� ����������� ����������� ���������
//Triangle getMaxLengthTriangle(Point* points, int size)
//{
//	//Triangle tr;
//
//	for (int i = 0; i < size; i++)
//	{
//		//if
//	}
//}