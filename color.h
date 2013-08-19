#ifndef CLR_H
#define CLR_H

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class color_t{
public:
	float rComp;
	float gComp;
	float bComp;

	color_t();
	color_t(float r,float g,float b);
	void operator=(const color_t c);
};

#endif