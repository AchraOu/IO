#ifndef CURSORS_LINE_H
#define CURSORS_LINE_H
#pragma once

#include "Point.h"

struct Line {
	Point from;
	Point to;

	Line(){}
	Line(const Point &from, const Point &to) : from(from), to(to){}
};


#endif