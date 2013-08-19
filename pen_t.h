#ifndef _PEN_H_
#define _PEN_H_

#include "color.h"
#include "point.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <GL/glut.h>

class pen_t{

public:
	int size;
	color_t color;
	color_t background;
	bool mode;				// true for normal and false for eraser
	pen_t(color_t c);
	pen_t(color_t c, color_t b);
	void toggleMode();
	void changeColor(color_t c);
	void changeBackground(color_t b);
	void changeSize(int s);
};
#endif