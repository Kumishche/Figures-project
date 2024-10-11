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

 
void Triangle::Print()
{
	std::cout << "(" << nodes[0].x << "; " << nodes[0].y << "), " <<
		"(" << nodes[1].x << "; " << nodes[1].y << "), " <<
		"(" << nodes[2].x << "; " << nodes[2].y << ").";
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


bool Triangle::operator == (Triangle& other) const
{
	Point p;
	bool flag = false;
	int id[3] = {-1, -1, -1};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			p = other.getNode(j + 1);
			if (this->nodes[i].x == p.x && this->nodes[i].y == p.y &&
				id[0] != j && id[1] != j)
			{
				flag = true;
				id[i] = j;
				break;
			}
		}

		if (!flag)
			return false;
		flag = false;
	}

	return true;
}
