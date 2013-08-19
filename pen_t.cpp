#include "pen_t.h"

pen_t::pen_t(color_t c){
	size = 1;
	mode = true;
	color = c;
}

pen_t::pen_t(color_t c , color_t b){
	size = 1;
	mode = true;
	background = b;
	color = c;
}

void pen_t::toggleMode(){
	mode = !mode;
}

void pen_t::changeColor(color_t c){
	color = c;
}

void pen_t::changeBackground(color_t b){
	background = b;
}

void changeSize(int s){
	size = s;
}
