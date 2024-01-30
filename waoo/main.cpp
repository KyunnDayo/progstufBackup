#include <glut.h>
#include <cmath>

int windowWidth = 1024;
int windowHeight = 768;

// Function to draw a circle at the specified coordinates
void drawCircle(float x, float y, float radius) {
    int numSegments = 100;
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < numSegments; i++) {
        float theta = 2.0f * M_PI * static_cast<float>(i) / static_cast<float>(numSegments);
        float cx = radius * std::cos(theta);
        float cy = radius * std::sin(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

// Mouse callback function
void onMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Convert window coordinates to OpenGL coordinates
        float glX = static_cast<float>(x) / windowWidth * 2.0f - 1.0f;
        float glY = 1.0f - static_cast<float>(y) / windowHeight * 2.0f;

        // Radius of the circle
        float radius = 0.1;

        // Set the drawing color
        glColor3f(1.0, 0.0, 0.0); // Red

        // Draw a circle at the clicked location
        drawCircle(glX, glY, radius);

        // Request a redraw
        glutPostRedisplay();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    // You can add other drawing code here if needed.
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Draw Circle on Mouse Click");

    glutDisplayFunc(display);
    glutMouseFunc(onMouseClick);

    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white

    glutMainLoop();

    return 0;
}
