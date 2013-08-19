#include "color.h"
	
color_t::color_t(){}

color_t::color_t(float r,float g,float b){
	rComp=r;
	gComp=g;
	bComp=b;
}
void color_t::operator=(const color_t c){
	this->rComp=c.rComp;
	this->gComp=c.gComp;
	this->bComp=c.bComp;
}
