#pragma once
#include "point.h"
#include "triangle.h"

int getPointsInLine(Point* points, int size, int** indices);
Point getFarestPoint(Point* points, int size);
Triangle getMaxLengthTriangle(Point* points, int size);