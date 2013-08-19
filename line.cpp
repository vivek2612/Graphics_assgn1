#include "line.h"

		
line_t::line_t(point_t p1,point_t p2){
	this->p1=p1;
	this->p2=p2;
	color_t c(1.0,0.0,0.0);
	setColor(c);
}
void line_t::setColor(color_t c){
	this->color=c;
}


void line_t::drawLine(float linewidth){
	bool steep = abs(p2.y - p1.y) > abs(p2.x - p1.x);
	if (steep){
	  swap(p1.x, p1.y);
	  swap(p2.x, p2.y);
	}
	if (p1.x > p2.x){
	  swap(p1.x, p2.x);
	  swap(p1.y, p2.y);
	}
	int deltax = p2.x - p1.x;
	int deltay = abs(p2.y - p1.y);

	float error = 0.0;
	float deltaerr = (float)deltay / (float)deltax;

	int ystep;
	int y = p1.y;

	if (p1.y < p2.y) ystep = 1; else ystep = -1;
	for (int x=p1.x; x < p2.x; x++){
		point_t p;
	  	if (steep){
	  		p.x = y;
	  		p.y = x;	
	  	} 
		else{
			p.x = x;
			p.y = y;
		}
		p.drawPoint(color,linewidth);
		error = error + deltaerr;
		if (error >= 0.5){
			y = y + ystep;
	  		error = error - 1.0;
		}
	}
}

void line_t::swap (int &x, int &y){
	int temp = x;
	x = y; y = temp;
}
