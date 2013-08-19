#ifndef PT_H
#define PT_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <GL/glut.h>
#include "color.h"
using namespace std;


class point_t{
public:
	int x;
	int y;
	point_t();
	point_t(int x,int y);
	void drawPoint();
	void drawPoint(color_t color,float size=1.0);
	void operator=(point_t p1);
};

#endif