#ifndef CURSORS_POINT_H
#define CURSORS_POINT_H
#pragma once


struct Point {
	int x;
	int y;

	Point(int x = 0, int y = 0){
		this->x = x;
		this->y = y;
	}
};


#endif