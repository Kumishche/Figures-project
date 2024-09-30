#pragma once
#include "point.h"

class Triangle
{
	Point nodes[3];

	Triangle(Point p1, Point p2, Point p3)
	{
		nodes[0] = p1; nodes[1] = p2; nodes[2] = p3;
	}
};