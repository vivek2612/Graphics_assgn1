#include "polygon.h"

polygon_t::polygon_t(int n,point_t arr[],bool filled){
	points = new point_t[n];
	points = arr;
	this->filled = filled;
	npoints = n;
	borderColor = color_t(1.0,1.0,1.0);
	fillColor = color_t(1.0,1.0,0.0);

}
void polygon_t::setBorderColor(color_t c){
	borderColor = c;
}
void polygon_t::setFillColor(color_t c){
	fillColor = c;
	}
void polygon_t::setFilled(bool filled){
	this->filled = filled;	
}
void polygon_t::drawPolygon(){
	int i=0;
	while(i!=npoints ){
		line_t l(points[i%npoints],points[(i+1)%npoints]);
		l.setColor(borderColor);
		l.drawLine();
		i++;
	}
}