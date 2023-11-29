#include <GL/glut.h>
#include <GL/gl.h>
#include "lib/Game.h"


void display();
void timer(int);
Game* gameManager;

int main(int argc, char** argv) {

    // Initializes glut
    glutInit(&argc, argv);
    // Front (displayed) and Back buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    // Setup of window
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Colosseum Game");

    // Set default buffer color
    glClearColor(0,0,0,1);

    gameManager = new Game();

    // Calls display when window needs to be repainted
    glutDisplayFunc(display);
    glutTimerFunc(1000/30, timer, 0);

    // Processes events and doesn't return until program is manually exited
    glutMainLoop();
}







void display() {
    // Resets the frame bugger (defualt color is black)
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity(); // Resets coordinates

    gameManager->drawPlay();

    // Swaps Front and Back buffer
    glutSwapBuffers();
    // glFlush();
}



void timer(int){
    gameManager->updatePlay();

    // Will recall glutDisplayFunc()
    glutPostRedisplay();

    // Calls next frame
    glutTimerFunc(1000/30,timer,0);
}



