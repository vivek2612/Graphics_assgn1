#ifndef L_H
#define L_H

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <GL/glut.h>
#include "point.h"
#include "color.h"
using namespace std;

class line_t{
public:
	point_t p1;
	point_t p2;
	color_t color;

	line_t(point_t p1,point_t p2);
	void setColor(color_t c);
	void drawLine(float linewidth=1.0);
	void swap (int &x, int &y);
};
#endif