#include "Entity.h"



Player::Player(float x, float y){
   mX = x;
   mY = y;
   rotState = M_PI/2;
}


void Player::drawObj(){
    glPushMatrix();
    glTranslatef(mX, mY, 0.0f);

    float degrees = rotState * 180 / M_PI;
    glRotatef(degrees, 0, 0, 1);
    glBegin(GL_QUADS);
        glColor3f(0,1,0);
        glVertex2f(-PLAYER_SIZE, -PLAYER_SIZE);
        glVertex2f(PLAYER_SIZE, -PLAYER_SIZE);
        glVertex2f(PLAYER_SIZE, PLAYER_SIZE);
        glVertex2f(-PLAYER_SIZE, PLAYER_SIZE);
    glEnd();

    drawWeapon();

    drawProjectiles();

    glPopMatrix();
}



void Player::drawWeapon(){
    glBegin(GL_TRIANGLES);
        glColor3f(0.5,1,0);
        glVertex2f(PLAYER_SIZE * WEAPON_MULT, 0);
        glVertex2f(PLAYER_SIZE, -PLAYER_SIZE);
        glVertex2f(PLAYER_SIZE, PLAYER_SIZE);
    glEnd();
}

void Player::moveforward(){

    this->mX += PLAYER_SPEED*cos(rotState);
    this->mY += PLAYER_SPEED*sin(rotState);
}
void Player::moveback(){

    this->mX -= PLAYER_SPEED*cos(rotState);
    this->mY -= PLAYER_SPEED*sin(rotState);
}

void Player::drawProjectiles(){
    // Implemented in later checkpoint
}





Enemy::Enemy(float x, float y){
   mX = x;
   mY = y;
}


void Enemy::drawObj(){
    glBegin(GL_QUADS);
        glColor3f(1,0,0);
        glVertex2f(mX - ENEMY_SIZE, mY - ENEMY_SIZE);
        glVertex2f(mX + ENEMY_SIZE, mY - ENEMY_SIZE);
        glVertex2f(mX + ENEMY_SIZE, mY + ENEMY_SIZE);
        glVertex2f(mX - ENEMY_SIZE, mY + ENEMY_SIZE);
    glEnd();
}



