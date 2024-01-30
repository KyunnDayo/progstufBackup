#include <glut.h>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

float r, g, b, x, y;
bool check = true;
int currentShapeType = 0; 

void drawCircle(float x, float y) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.14159265f / 180.0f;
        glVertex2f(x + 20 * cos(angle), y + 20 * sin(angle)); // Radius 10 for the circle
    }
    glEnd();
}

void drawSquare(float x, float y) {
    glBegin(GL_QUADS);
    glVertex2f(x - 30, y - 30);
    glVertex2f(x + 30, y - 30);
    glVertex2f(x + 30, y + 30);
    glVertex2f(x - 30, y + 30);
    glEnd();
}

void drawRectangle(float x, float y) {
    glBegin(GL_QUADS);
    glVertex2f(x - 45, y - 30); // Adjust the width and height as needed
    glVertex2f(x + 45, y - 30);
    glVertex2f(x + 45, y + 30);
    glVertex2f(x - 45, y + 30);
    glEnd();
}

void drawTriangle(float x, float y) {
    glBegin(GL_TRIANGLES);
    glVertex2f(x, y + 35); // Top vertex
    glVertex2f(x - 35, y - 35); // Bottom-left vertex
    glVertex2f(x + 35, y - 35); // Bottom-right vertex
    glEnd();
}

void mouse(int button, int state, int mousex, int mousey) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        check = true;

        x = mousex;
        y = 480 - mousey;

        r = (float)(rand() % 9) / 8;
        g = (float)(rand() % 9) / 8;
        b = (float)(rand() % 9) / 8;
    } else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        glClearColor(0, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        check = false;
    }
    glutPostRedisplay();
}

void display(void) {
    glColor3f(r, g, b);
    glPointSize(5);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);

    if (check) {
        if (currentShapeType == 0) {
            drawCircle(x, y);
        } else if (currentShapeType == 1) {
            drawSquare(x, y);
        } else if (currentShapeType == 2) {
            drawRectangle(x, y);
        } else if (currentShapeType == 3) {
            drawTriangle(x, y);
        }
    }
    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'q') {
        currentShapeType = 0; // Set to draw a circle
    } else if (key == 'w') {
        currentShapeType = 1; // Set to draw a square
    } else if (key == 'e') {
        currentShapeType = 2; // Set to draw a rectangle
    } else if (key == 'r') {
        currentShapeType = 3; // Set to draw a triangle
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Shape Drawing");
    
    glutMouseFunc(mouse);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    

    return 0;
}

