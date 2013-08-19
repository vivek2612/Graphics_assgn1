#include "fill.h"

fill_t::fill_t(){
	win_width = 512;
	win_height = 512;
	solid = true;
}

fill_t::fill_t(color_t c,bool solid){
	win_width = 512;
	win_height = 512;
	color=c;
	this->solid=solid;
}
// to get color value = 1537*y + x*3 + 0/1/2  (here 1537= win_width*3 + 1)
void fill_t::setFillColor(color_t c){
	color=c;
}

void fill_t::getPixelData(vector<unsigned char>& colorArr){
	glReadPixels(0,0,win_width-1,win_height-1,GL_RGB,GL_UNSIGNED_BYTE,&colorArr[0]);
}

void fill_t::recurse(int x,int y,color_t prevColor){
	
	if(y < win_height && y >= 0 && x >= 0 && x < win_width){

		float r = colorArr[y*(win_width*3+1)+x*3]/255.0;
		float g = colorArr[y*(win_width*3+1)+x*3 + 1]/255.0;
		float b = colorArr[y*(win_width*3+1)+x*3 + 2]/255.0;

		// if the current pixel's color != backGround( prevColor ) color
		if (r!=prevColor.rComp || g!=prevColor.gComp || b!=prevColor.bComp) return;

		colorArr[y*1537+x*3] = color.rComp;
		colorArr[y*1537+x*3 + 1] = color.gComp;
		colorArr[y*1537+x*3 + 2] = color.bComp;

		glVertex2f(x, y);

		recurse(x+1,y,prevColor);
		recurse(x+1,y+1,prevColor);
		recurse(x,y+1,prevColor);
		recurse(x-1,y+1,prevColor);
		recurse(x-1,y,prevColor);
		recurse(x-1,y-1,prevColor);
		recurse(x,y-1,prevColor);
		recurse(x+1,y-1,prevColor);
	}
	return;
}

void fill_t::draw(int x, int y){
	colorArr.assign(win_width*win_height*3,0);
	getPixelData(colorArr);
	glPointSize(1.0f);  
  	glColor3f(color.rComp, color.gComp, color.bComp); 
  	glBegin(GL_POINTS);

  	float r = (float) colorArr[y*(win_width*3+1)+x*3]/ 255.0;
  	float g = (float) colorArr[y*(win_width*3+1)+x*3 + 1]/255.0;
  	float b = (float) colorArr[y*(win_width*3+1)+x*3 + 2]/255.0;
  	color_t prevColor (r, g, b);

	recurse(x,y,prevColor); // prevColor : color before filling the region
	glEnd();
}
