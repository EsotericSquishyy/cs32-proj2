#include "Entity.h"


void Projectile::moveForward(){
    this->mX += PROJ_MOVSPD * cos(rotState);
    this->mY += PROJ_MOVSPD * sin(rotState);
}



void Projectile::moveBack(){
    this->mX -= PROJ_MOVSPD * cos(rotState);
    this->mY -= PROJ_MOVSPD * sin(rotState);
}



void Projectile::drawObj(){
}






void Player::moveForward(){
    this->mX += PLAYER_MOVSPD * cos(rotState);
    this->mY += PLAYER_MOVSPD * sin(rotState);
}



void Player::moveBack(){
    this->mX -= PLAYER_MOVSPD * cos(rotState);
    this->mY -= PLAYER_MOVSPD * sin(rotState);
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



void Player::drawProjectiles(){
    for(Projectile* cProj : mProjs){
        cProj->drawObj();
    }
}



void Player::createProj(){
    Projectile* cProj = new Projectile(mX, mY);
    mProjs.insert(cProj);
}






void Enemy::moveForward(){
    this->mX += ENEMY_MOVSPD * cos(rotState);
    this->mY += ENEMY_MOVSPD * sin(rotState);
}



void Enemy::moveBack(){
    this->mX -= ENEMY_MOVSPD * cos(rotState);
    this->mY -= ENEMY_MOVSPD * sin(rotState);
}



void Enemy::drawObj(){
    glPushMatrix();
    glTranslatef(mX, mY, 0.0f);

    float degrees = rotState * 180 / M_PI;
    glRotatef(degrees, 0, 0, 1);

    glBegin(GL_QUADS);
        glColor3f(1,0,0);
        glVertex2f(-ENEMY_SIZE, -ENEMY_SIZE);
        glVertex2f(ENEMY_SIZE, -ENEMY_SIZE);
        glVertex2f(ENEMY_SIZE, ENEMY_SIZE);
        glVertex2f(-ENEMY_SIZE, ENEMY_SIZE);
    glEnd();

    glPopMatrix();
}



