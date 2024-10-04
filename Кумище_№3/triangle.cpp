#include "triangle.h"
#include <math.h>


Triangle::Triangle(Point p1, Point p2, Point p3)
{
	nodes[0] = p1;
	nodes[1] = p2;
	nodes[2] = p3;
}


double Triangle::len(Point p1, Point p2)
{
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}


Point Triangle::getNode(int i)
{
	if (i >= 1 && i <= 3)
		return nodes[i-1];
}


void Triangle::setNode(int i, Point p)
{
	if (i >= 1 && i <= 3)
		nodes[i-1] = p;
}


double Triangle::Square()
{
	double l1 = len(nodes[0], nodes[1]);
	double l2 = len(nodes[1], nodes[2]);
	double l3 =	len(nodes[0], nodes[2]);
	double p = (l1 + l2 + l3) / 2;
	return p * (p - l1) * (p - l2) * (p - l3);
}

double Triangle::Perimeter()
{
	return len(nodes[0], nodes[1]) + 
		len(nodes[1], nodes[2]) +
		len(nodes[0], nodes[2]);
}
