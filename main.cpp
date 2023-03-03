#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <stdio.h>
using namespace std;

void Inicio(void){
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,640.0,0.0,480.0);
}
void PintarPixel(int x, int y){
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

void MetodoDirecto(float x1,float x2,float y1,float y2){
	
	int rep;
	//ordenada de origen
	float b;
	float m;
	double inte;

	m = (y2-y1)/(x2-x1);
	
	//y=mx+b
	//b=y-(m*x)
	b= y1-(m*x1);
	
	rep=x2-x1;
	
	
	for(int i=0;i<=rep;i++){
		
		inte=lround(m*(x1)+(b));
		PintarPixel(x1,inte);
		
		x1=x1+1;
	}
}

void display(){
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glPointSize(5);
	MetodoDirecto(2,7,2,8);
	glFlush();
}


int main(int argc, char** argv) {
	glutInit(&argc,argv);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Demo 1");
	Inicio();		
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
