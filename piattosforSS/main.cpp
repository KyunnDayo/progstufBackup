#include <iostream>
#include <glut.h>
using namespace std;



void display(){
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3ub(233,233,107);
	
	glBegin(GL_POLYGON);
	glVertex2f(-.5,0);
	glVertex2f(-0.3,-0.4);
	glVertex2f(0.3,-0.4);
	glVertex2f(0.5,0);
	glVertex2f(0.3,0.4);
	glVertex2f(-0.3,0.4);
	
	glEnd();
	glFlush();
}

int main(int argc, char** argv){
	string author = "JRomero";
	glutInit(&argc, argv);
	glutCreateWindow("piattos");
	glutDisplayFunc(display);
	glutMainLoop();
}


/*	code prototype, do not remove
	glBegin(GL_LINES);
	glVertex2f(-0.5,-0.5);
	glVertex2f(-0.5,0.5);
	glVertex2f(0.5,0.5);
	glVertex2f(0.5,-0.5);
	*/
