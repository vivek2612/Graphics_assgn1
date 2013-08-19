#ifndef FILL_H
#define FILL_H


#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <GL/glut.h>
#include <vector>
#include "color.h"


using namespace std;

class fill_t{
public:
	color_t color;
	int win_width ;
	int win_height ;
	bool solid;
	vector<unsigned char> colorArr;

	fill_t();
	fill_t(color_t c,bool solid=true);
	void setFillColor(color_t c);
	void getPixelData(vector<unsigned char>& colorArr);
	void recurse(int x,int y,color_t prevColor);
	void draw(int x, int y);
};
#endif