#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <GL/glut.h>
#include <cstdio>
#include "color.h"
#include "point.h"
#include "line.h"
#include "polygon.h"
using namespace std;

int win_width = 512;
int win_height = 512;


void reshape( int w, int h ){
 	if  ( h == 0 ) h = 1;
  	glMatrixMode( GL_PROJECTION );
  	glLoadIdentity();
  	glOrtho( 0.0, (GLdouble)w, 0.0, (GLdouble)h, -1., 1. );
  	glViewport( 0, 0, w, h );
  	win_width = w;
  	win_height = h;
  	glutPostRedisplay();
}
void mouse(int button, int state, int x, int y){

}

void keyboard(unsigned char key, int x, int y){

}
void display( void ){
	glClear( GL_COLOR_BUFFER_BIT );
	// testing the drawing of points
	color_t color(0.0,0.0,0.5);
	point_t p1(30,60);
	p1.drawPoint(color,30);
	point_t p2(400,400);
	p2.drawPoint();

	line_t l1(p1,p2);
	// l1.setColor(color);
	l1.drawLine(2); // width of the line

	point_t sqr[]={point_t(100,100),point_t(200,100),point_t(200,200),point_t(100,200)};
	polygon_t sq(4,sqr);
	sq.setBorderColor(color);
	sq.drawPolygon();
	glutSwapBuffers();

	
}

int main(int argc, char *argv[]){	
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
	glutInitWindowSize( win_width, win_height );
	glutCreateWindow( "Drawing" );
	glutDisplayFunc( display );
	glutReshapeFunc( reshape );
	glutKeyboardFunc( keyboard );
	glutMouseFunc( mouse );
	glutMainLoop();
}