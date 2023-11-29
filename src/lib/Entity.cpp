#include "Entity.h"



Player::Player(float x, float y){
   mX = x;
   mY = y;
}


void Player::drawObj(){
    glBegin(GL_POLYGON);
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
        glVertex2f(mX - 0.1, mY - 0.1);
        glVertex2f(mX + 0.1, mY - 0.1);
        glVertex2f(mX + 0.1, mY + 0.1);
        glVertex2f(mX - 0.1, mY + 0.1);
    glEnd();
}
