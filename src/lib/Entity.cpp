#include "Entity.h"



Player::Player(float x, float y){
   mX = x;
   mY = y;
}


void Player::drawObj(){
    glBegin(GL_QUADS);
        glColor3f(0,1,0);
        glVertex2f(mX - PLAYER_SIZE, mY - PLAYER_SIZE);
        glVertex2f(mX + PLAYER_SIZE, mY - PLAYER_SIZE);
        glVertex2f(mX + PLAYER_SIZE, mY + PLAYER_SIZE);
        glVertex2f(mX - PLAYER_SIZE, mY + PLAYER_SIZE);
    glEnd();

    drawWeapon();

    drawProjectiles();
}



void Player::drawWeapon(){
    switch(rotState){
        case 0:
            glBegin(GL_TRIANGLES);
                glColor3f(0.5,1,0);
                glVertex2f(mX, mY + PLAYER_SIZE * WEAPON_MULT);
                glVertex2f(mX - PLAYER_SIZE, mY + PLAYER_SIZE);
                glVertex2f(mX + PLAYER_SIZE, mY + PLAYER_SIZE);
            glEnd();
            break;
        case 1:
            glBegin(GL_TRIANGLES);
                glColor3f(0.5,1,0);
                glVertex2f(mX - PLAYER_SIZE * WEAPON_MULT, mY);
                glVertex2f(mX - PLAYER_SIZE, mY - PLAYER_SIZE);
                glVertex2f(mX - PLAYER_SIZE, mY + PLAYER_SIZE);
            glEnd();
            break;
        case 2:
            glBegin(GL_TRIANGLES);
                glColor3f(0.5,1,0);
                glVertex2f(mX, mY - PLAYER_SIZE * WEAPON_MULT);
                glVertex2f(mX + PLAYER_SIZE, mY - PLAYER_SIZE);
                glVertex2f(mX - PLAYER_SIZE, mY - PLAYER_SIZE);
            glEnd();
            break;
        case 3:
            glBegin(GL_TRIANGLES);
                glColor3f(0.5,1,0);
                glVertex2f(mX + PLAYER_SIZE * WEAPON_MULT, mY);
                glVertex2f(mX + PLAYER_SIZE, mY + PLAYER_SIZE);
                glVertex2f(mX + PLAYER_SIZE, mY - PLAYER_SIZE);
            glEnd();
            break;
    }
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



