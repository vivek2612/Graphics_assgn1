#include "point.h"


point_t::point_t(){}
point_t::point_t(int x,int y){
	this->x=x;
	this->y=y;
}

void point_t::drawPoint(){
	color_t c(1.0,1.0,1.0);
  	drawPoint(c,10.0f);
}
void point_t::drawPoint(color_t color,float size){
	glPointSize(size);  
  	glColor3f(color.rComp, color.gComp, color.bComp); 
  	glBegin(GL_POINTS);
  	glVertex2f(x, y);
  	glEnd();  
}
void point_t::operator=(point_t p1){
	this->x=p1.x;
	this->y=p1.y;
}


