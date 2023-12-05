#include <GL/glut.h>
#include <GL/gl.h>
#include "lib/Game.h"


void display();
void keyDown(unsigned char key, int x, int y);
void keyUp(unsigned char key, int x, int y);
void timer(int);
Game* gameManager;

int main(int argc, char** argv) {

    // Initializes glut
    glutInit(&argc, argv);
    // Front (displayed) and Back buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    // Setup of window
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Colosseum Game");

    // Set default buffer color
    glClearColor(0,0,0,1);

    gameManager = new Game();

    // Calls display when window needs to be repainted
    glutDisplayFunc(display);
    glutKeyboardFunc(keyDown);
    glutKeyboardUpFunc(keyUp);
    glutTimerFunc(DELTA_TIME, timer, 0);

    // Processes events and doesn't return until program is manually exited
    glutMainLoop();
}







void display() {
    // Resets the frame bugger (defualt color is black)
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity(); // Resets coordinates

    gameManager->drawPlay();
    gameManager->drawUI();

    // Swaps Front and Back buffer
    glutSwapBuffers();
}



void keyDown(unsigned char key, int x, int y){
    switch(key){
        case 'w':
        case 'a':
        case 's':
        case 'd':
        case 'q':
        case 'e':
        case ' ':
            gameManager->pressedKeys[key] = true;
            break;
        default:
            break;
    }
}



void keyUp(unsigned char key, int x, int y){
    switch(key){
        case 'w':
        case 'a':
        case 's':
        case 'd':
        case ' ':
            gameManager->pressedKeys[key] = false;
            break;
        default:
            break;
    }
}



void timer(int){
    gameManager->updatePlay();

    // Will recall glutDisplayFunc()
    glutPostRedisplay();

    // Calls next frame
    glutTimerFunc(DELTA_TIME,timer,0);
}



