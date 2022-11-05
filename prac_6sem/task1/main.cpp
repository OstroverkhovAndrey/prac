
#include <stdio.h>
#include <iostream>
#include <stdarg.h>
#include <math.h>
#include <GL/glut.h>
#include "StackState.hpp"
#include "Coordinate.hpp"
#include "LSystem.hpp"


double rotate_x = 0;
double rotate_y = 0;

LSystem LS;

void display();
void specialKeys();

//void drawLine (const coordinate& point1, const coordinate& point2) {
//    glBegin(GL_LINES);
//    glVertex3f(point1.x, point1.y, point1.z);
//    glVertex3f(point2.x, point2.y, point2.z);
//    glEnd();
//}

void display () {

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0, -0.9, 0.0);

    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);

    glScalef(0.2, 0.2, 0.2);
    
    glColor3f(1.0, 1.0, 1.0);

    LS.draw();
    
    glFlush();
    glutSwapBuffers();
}

void specialKeys (int key, int x, int y) {
    if (key == GLUT_KEY_RIGHT) {
        rotate_y += 5;
    } else if (key == GLUT_KEY_LEFT) {
        rotate_y -= 5;
    } else if (key == GLUT_KEY_UP) {
        rotate_x += 5;
    } else if (key == GLUT_KEY_DOWN) {
        rotate_x -= 5;
    } 
    glutPostRedisplay();
}

int main (int argc, char** argv) {

//    1
//    LS.addRule('F', "F[-F]F[+F][F]", 1.0);
//    LS.buildSystem(2);
//    LS.setScaleLengthCoefficient(0.9);

//2
    LS.addRule('F', "F[-F]^[F]&[+F][F]", 0.7);
    LS.buildSystem(4);

    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("LSystem");
    
    glEnable(GL_DEPTH_TEST);
    
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);

    glutMainLoop();

    return 0;
}
