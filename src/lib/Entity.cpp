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

    drawBody();
    drawWeapon();
    drawProjectiles();

    glPopMatrix();
}



void Player::drawBody(){
    glBegin(GL_QUADS);
        glColor3f(0,1,0);
        glVertex2f(-PLAYER_SIZE, -PLAYER_SIZE);
        glVertex2f(PLAYER_SIZE, -PLAYER_SIZE);
        glVertex2f(PLAYER_SIZE, PLAYER_SIZE);
        glVertex2f(-PLAYER_SIZE, PLAYER_SIZE);
    glEnd();
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
    glPushMatrix();
    glTranslatef(mX, mY, 0.0f);

    glBegin(GL_QUADS);
        glColor3f(1,0,0);
        glVertex2f(-ENEMY_SIZE, -ENEMY_SIZE);
        glVertex2f(ENEMY_SIZE, -ENEMY_SIZE);
        glVertex2f(ENEMY_SIZE, ENEMY_SIZE);
        glVertex2f(-ENEMY_SIZE, ENEMY_SIZE);
    glEnd();

    glPopMatrix();
}



