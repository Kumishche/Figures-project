#pragma once
#include "point.h"

class Triangle
{
private:
	Point nodes[3];

	double len(Point p1, Point p2);


public:
	Triangle(Point p1 = 0, Point p2 = 0, Point p3 = 0);

	Point getNode(int i);
	void setNode(int i, Point p);
	
	double Square();
	double Perimeter();
};