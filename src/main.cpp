#include <GL/glut.h>
#include <GL/gl.h>
#include "lib/Game.h"


void initPlay(){
    // Player player = new Player();
}



void drawArena(){
    glBegin(GL_POLYGON);
        glColor3f(1, 0, 0); glVertex3f(-.5, -0.5, 0);
        glColor3f(1, 0, 0); glVertex3f(-.5, .5, 0);
        glColor3f(0, 1, 0); glVertex3f(0.5, .5, 0);
        glColor3f(0, 0, 1); glVertex3f(0.5, -.5, 0);
    glEnd();
}



void display() {
    // Set every pixel in the frame buffer to the current clear color.
    glClear(GL_COLOR_BUFFER_BIT);

    drawArena();

    // Flush drawing command buffer to make drawing happen as soon as possible.
    glFlush();
}



int main(int argc, char** argv) {

    // Use a single buffered window in RGB mode (as opposed to a double-buffered
    // window or color-index mode).
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Position window at (80,80)-(480,380) and give it a title.
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(600, 600);
    glutCreateWindow("A Simple Triangle");

    // Tell GLUT that whenever the main window needs to be repainted that it
    // should call the function display().
    glutDisplayFunc(display);

    // Tell GLUT to start reading and processing events.  This function
    // never returns; the program only exits when the user closes the main
    // window or kills the process.
    glutMainLoop();
}

