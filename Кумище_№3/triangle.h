#pragma once
#include <iostream>
#include "point.h"

class Triangle
{
private:
	Point nodes[3];
	double len(Point p1, Point p2);


public:
	Triangle(Point p1 = Point(), Point p2 = Point(), Point p3 = Point());

	Point getNode(int i);
	void setNode(int i, Point p);
	void Print();
	
	double Square();
	double Perimeter();

	bool operator == (Triangle& other) const;
};