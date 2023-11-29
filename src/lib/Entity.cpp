#include "Entity.h"



Player::Player(float x, float y){
   mX = x;
   mY = y;
}


void Player::drawObj(){
    glBegin(GL_POLYGON);
        glColor3f(0,1,0);
        glVertex2f(mX - 0.1, mY - 0.1);
        glVertex2f(mX + 0.1, mY - 0.1);
        glVertex2f(mX + 0.1, mY + 0.1);
        glVertex2f(mX - 0.1, mY + 0.1);
    glEnd();
}





Enemy::Enemy(float x, float y){
   mX = x;
   mY = y;
}


void Enemy::drawObj(){
    glBegin(GL_POLYGON);
        glColor3f(1,0,0);
        glVertex2f(mX - 0.1, mY - 0.1);
        glVertex2f(mX + 0.1, mY - 0.1);
        glVertex2f(mX + 0.1, mY + 0.1);
        glVertex2f(mX - 0.1, mY + 0.1);
    glEnd();
}
