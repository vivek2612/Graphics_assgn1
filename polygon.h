#ifndef PLY_H
#define PLY_H

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <GL/glut.h>
#include "point.h"
#include "color.h"
#include "line.h"
using namespace std;

class polygon_t{
public:
	point_t* points;
	color_t borderColor;
	color_t fillColor;
	bool filled;
	int npoints;

	polygon_t(int n,point_t arr[],bool filled=false);
	void setBorderColor(color_t c);
	void setFillColor(color_t c);
	void setFilled(bool filled);
	void drawPolygon();

};
#endif