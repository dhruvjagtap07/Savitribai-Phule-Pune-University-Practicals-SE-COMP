// Practical 2: 3D Cube Transformation
#include <GL/glut.h>
#include <iostream>
using namespace std;

//b) Write C++ program to draw 3-D cube and perform following transformations on it using
//OpenGL i) Scaling ii) Translation iii) Rotation about an axis (X/Y/Z).

float translateX = 0.0, translateY = 0.0, translateZ = 0.0;
float scaleX = 1.0, scaleY = 1.0, scaleZ = 1.0;
float rotateAngle = 0.0;
char rotationAxis;
int transformationChoice;

void drawCube(bool transformed) {
    if (transformed)
        glColor3f(0.0, 1.0, 0.0); // Transformed cube in green
    else
        glColor3f(1.0, 0.0, 0.0); // Original cube in red

    glutWireCube(1.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Draw original cube in red
    glPushMatrix();
    glTranslatef(-2.0, 0.0, -7.0);
    drawCube(false);
    glPopMatrix();

    // Draw transformed cube in green
    glPushMatrix();
    glTranslatef(2.0, 0.0, -7.0);

    switch (transformationChoice) {
        case 1: // Translation
            glTranslatef(translateX, translateY, translateZ);
            break;
        case 2: // Scaling
            glScalef(scaleX, scaleY, scaleZ);
            break;
        case 3: // Rotation
            glRotatef(rotateAngle, rotationAxis == 'x', rotationAxis == 'y', rotationAxis == 'z');
            break;
    }

    drawCube(true);
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)w / (float)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void getUserInput() {
    cout << "Enter the type of transformation:\n";
    cout << "1. Translation\n";
    cout << "2. Scaling\n";
    cout << "3. Rotation\n";
    cin >> transformationChoice;

    switch (transformationChoice) {
        case 1:
            cout << "Enter translation factors (x, y, z): ";
            cin >> translateX >> translateY >> translateZ;
            break;
        case 2:
            cout << "Enter scaling factors (x, y, z): ";
            cin >> scaleX >> scaleY >> scaleZ;
            break;
        case 3:
            cout << "Enter rotation angle (degrees): ";
            cin >> rotateAngle;
            cout << "Enter rotation axis (x, y, z): ";
            cin >> rotationAxis;
            break;
        default:
            cout << "Invalid choice!\n";
            exit(0);
    }
}

int main(int argc, char** argv) {
    getUserInput();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Cube Transformation");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
