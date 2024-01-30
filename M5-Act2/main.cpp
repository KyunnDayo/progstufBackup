#include <iostream>
#include <windows.h>
#include <glut.h>
#include <freeglut_ext.h>
using namespace std;

void drawSquare(int x, int y) {
    glBegin(GL_QUADS);
    glVertex2i(x - 20, y - 20); // Bottom-left vertex
    glVertex2i(x + 20, y - 20); // Bottom-right vertex
    glVertex2i(x + 20, y + 20); // Top-right vertex
    glVertex2i(x - 20, y + 20); // Top-left vertex
    glEnd();
}

void leftMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Replace this with the function you want to call on a left-click
        // For now, we'll print a message to the console.
        drawSquare(x,y);
        std::cout << "Left mouse button clicked at (" << x << ", " << y << ")" << std::endl;
    }
}
/*
void rightMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        // Replace this with the function you want to call on a right-click
        // For now, we'll print a message to the console.
        
        std::cout << "Right mouse button clicked at (" << x << ", " << y << ")" << std::endl;
    }
}

/*
void defaultDisplay(){
glClear(GL_COLOR_BUFFER_BIT);
const unsigned char str[100] = "FEU-TECH";
glColor3f(0.0f,0.0f,1.0f);
glRasterPos2f(px,py);
glutBitmapString(GLUT_BITMAP_HELVETICA_18, str);
glFlush();
glutTimerFunc(1000,animateString,2);
}
*/
void display() {
    // Your OpenGL rendering code
    glClear(GL_COLOR_BUFFER_BIT);
    // ...
    glFlush();
}

int main(int argc, char **argv){
glutInit(&argc, argv);
glutInitWindowSize(1024,768);
glutInitWindowPosition(200,50);
glutCreateWindow("Ihatefeu");
//glutFullScreen();

glutMouseFunc(leftMouseClick);
//glutMouseFunc(rightMouseClick);

glutDisplayFunc(display);

glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white

glutMainLoop();
return 0;
}
