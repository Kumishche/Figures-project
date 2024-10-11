#pragma once
#include <iostream>

struct Point
{
	double x;
	double y;
	
	Point(double X = 0, double Y = 0)
	{
		x = X; y = Y;
	}

	void Print()
	{
		std::cout << "(" << x << "; " << y << ")";
	}

	bool operator ==(const Point& other) const
	{
		return x == other.x && y == other.y;
	}
};