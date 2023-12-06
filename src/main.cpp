#include <GL/glut.h>
#include <GL/gl.h>
#include "lib/Game.h"


void display();
void keyDown(unsigned char key, int x, int y);
void keyUp(unsigned char key, int x, int y);
void timer(int);

void displayStart();
void displayEnd();
void keyDownUI(unsigned char key, int x, int y);
void timerUI(int);

Game* gameManager;



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



void displayStart(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(1,1,1);
    std::string gameT = "Colosseum Game!";
    glRasterPos3f(-0.9f,0.3f,0);
    for (size_t i = 0; i < gameT.size(); i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, gameT.at(i));
    }

    glColor3f(1,1,0.8f);
    std::string exitT = "Press [SPACE] to start.";
    glRasterPos3f(-0.9f,-0.1f,0);
    for (size_t i = 0; i < exitT.size(); i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, exitT.at(i));
    }

    glutSwapBuffers();
}



void displayEnd(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(1,0,1);
    std::string gameT = "Game Over";
    glRasterPos3f(-0.9f,0.3f,0);
    for (size_t i = 0; i < gameT.size(); i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, gameT.at(i));
    }

    std::string scoreT = "Your score: " + std::to_string(gameManager->getScore());
    glRasterPos3f(-0.9f,0.2f,0);
    for (size_t i = 0; i < scoreT.size(); i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, scoreT.at(i));
    }

    glColor3f(1,0,0);
    std::string exitT = "Press [SPACE] to exit.";
    glRasterPos3f(-0.9f,-0.1f,0);
    for (size_t i = 0; i < exitT.size(); i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, exitT.at(i));
    }

    glutSwapBuffers();
}



void keyDownUI(unsigned char key, int x, int y){
    if(key == ' '){
        throw std::runtime_error("Next screen!");
    }
}



void timerUI(int){
    // Will recall glutDisplayFunc()
    glutPostRedisplay();

    // Calls next frame
    glutTimerFunc(DELTA_TIME,timerUI,0);
}






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

    glutDisplayFunc(displayStart);
    glutKeyboardFunc(keyDownUI);
    glutTimerFunc(DELTA_TIME, timerUI, 0);
    try{
        glutMainLoop();
    }
    // Gameplay
    catch(const std::runtime_error& e){
        glutDisplayFunc(display);
        glutKeyboardFunc(keyDown);
        glutKeyboardUpFunc(keyUp);
        glutTimerFunc(DELTA_TIME, timer, 0);
    }
    try{
        glutMainLoop();
    }
    // End Screen
    catch(const std::runtime_error& e){
        glutDisplayFunc(displayEnd);
        glutKeyboardFunc(keyDownUI);
        glutTimerFunc(DELTA_TIME, timerUI, 0);
    }
    try{
        glutMainLoop();
    }
    catch(const std::runtime_error& e){
    }
    return 0;
}



