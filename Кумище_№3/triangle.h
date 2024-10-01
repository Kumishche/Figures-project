#pragma once
#include "point.h"

class Triangle
{
	Point nodes[3];

public:
	Triangle(Point p1 = 0, Point p2 = 0, Point p3 = 0)
	{
		nodes[0] = p1; nodes[1] = p2; nodes[2] = p3;
	}
};