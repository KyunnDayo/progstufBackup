#include <iostream>
#include <windows.h>
#include <glut.h>
#include <freeglut_ext.h>

using namespace std;

float face_mouth[3] = {1.0, 1.0, 1.0};
float face_lefteye[3] = {0.0, 0.0, 1.0};
float face_righteye[3] = {0.0, 1.0, 0.0};
float face_outline[3] = {1.0, 1.0, 1.0};

int lastMouseButton = -1;

float face_posX = 0.0;
float face_posY = 0.0;

void outline(){
	glColor3fv(face_outline); //White
	glBegin(GL_LINE_LOOP); //Face Outline
		glVertex2f(-0.7 + face_posX, -0.7 + face_posY);
		glVertex2f(0.7 + face_posX, -0.7 + face_posY);
		glVertex2f(0.7 + face_posX, 0.7 + face_posY);
		glVertex2f(-0.7 + face_posX, 0.7 + face_posY);
	glEnd();
}

void righteye(){
	glColor3fv(face_righteye);
	glBegin(GL_QUADS); //Right Eye
		glVertex2f(0.4 + face_posX, 0.1 + face_posY);
		glVertex2f(0.2 + face_posX, 0.1 + face_posY);
		glVertex2f(0.2 + face_posX, 0.3 + face_posY);
		glVertex2f(0.4 + face_posX, 0.3 + face_posY);
	glEnd();
}

void lefteye(){
	glColor3fv(face_lefteye); 
	glBegin(GL_QUADS); //Left Eye
		glVertex2f(-0.4 + face_posX, 0.1 + face_posY);
		glVertex2f(-0.2 + face_posX, 0.1 + face_posY);
		glVertex2f(-0.2 + face_posX, 0.3 + face_posY);
		glVertex2f(-0.4 + face_posX, 0.3 + face_posY);
	glEnd();
}

void mouth(){
	glColor3fv(face_mouth);
	glBegin(GL_LINES); //mouth
		glVertex2f(-0.2 + face_posX, -0.2 + face_posY);
		glVertex2f(0.2 + face_posX, -0.2 + face_posY);
	glEnd();
}

void keyboard(unsigned char key, int x, int y){
	switch(key){
		case 'w':
			face_posY += 0.2;
			break;
		case 'a':
			face_posX -= 0.2;
			break;
		case 's':
			face_posY -= 0.2;
			break;
		case 'd':
			face_posX += 0.2;
			break;
		case 27:
			exit(0);
			break;
	}
	glutPostRedisplay();
}

void mouse(int click, int state, int x, int y) {
  if (click == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    face_lefteye[0] = (float)rand() / RAND_MAX;
    face_lefteye[1] = (float)rand() / RAND_MAX;
    face_lefteye[2] = (float)rand() / RAND_MAX;
    lastMouseButton = GLUT_LEFT_BUTTON;
  } else if (click == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
    face_righteye[0] = (float)rand() / RAND_MAX;
    face_righteye[1] = (float)rand() / RAND_MAX;
    face_righteye[2] = (float)rand() / RAND_MAX;

    lastMouseButton = GLUT_RIGHT_BUTTON;
  }
	glutPostRedisplay();
}

void default_display(){
	glClear(GL_COLOR_BUFFER_BIT);
		
	glPointSize(5.0);
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(2.0);
	
	outline();
	righteye();
	lefteye();
	mouth();
	glFlush();
	
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("LAB6- VertexArray_Converted");
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glutDisplayFunc(default_display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	
	glutMainLoop();
	
	return 0;
}
