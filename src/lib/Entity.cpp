#include "Entity.h"


void Entity::moveForward(){
    mX += mSpeed * cos(rotState);
    mY += mSpeed * sin(rotState);
}



void Entity::moveBack(){
    mX -= mSpeed * cos(rotState);
    mY -= mSpeed * sin(rotState);
}



void Projectile::drawObj(){
    glPushMatrix();
    glTranslatef(mX, mY, 0.0f);

    float degrees = rotState * 180 / M_PI;
    glRotatef(degrees, 0, 0, 1);

    glBegin(GL_QUADS);
        glColor3f(0,1,0);
        glVertex2f(-mSize, -mSize);
        glVertex2f(mSize, -mSize);
        glVertex2f(mSize, mSize);
        glVertex2f(-mSize, mSize);
    glEnd();

    glPopMatrix();
}






void Player::drawObj(){
    glPushMatrix();
    glTranslatef(mX, mY, 0.0f);

    float degrees = rotState * 180 / M_PI;
    glRotatef(degrees, 0, 0, 1);

    drawBody();
    drawWeapon();

    glPopMatrix();
    drawProjectiles();
}



void Player::drawBody(){
    glBegin(GL_QUADS);
        glColor3f(0,1,0);
        glVertex2f(-mSize, -mSize);
        glVertex2f(mSize, -mSize);
        glVertex2f(mSize, mSize);
        glVertex2f(-mSize, mSize);
    glEnd();
}



void Player::drawWeapon(){
    glBegin(GL_TRIANGLES);
        glColor3f(0.5,1,0);
        glVertex2f(mSize * WEAPON_MULT, 0);
        glVertex2f(mSize, -mSize);
        glVertex2f(mSize, mSize);
    glEnd();
}



void Player::drawProjectiles(){
    for(Projectile* cProj : mProjs){
        cProj->drawObj();
    }
}



void Player::createProj(){
    Projectile* cProj = new Projectile(mX, mY, rotState);
    mProjs.insert(cProj);
}






void Enemy::drawObj(){
    glPushMatrix();
    glTranslatef(mX, mY, 0.0f);

    float degrees = rotState * 180 / M_PI;
    glRotatef(degrees, 0, 0, 1);

    glBegin(GL_QUADS);
        glColor3f(1,0,0);
        glVertex2f(-mSize, -mSize);
        glVertex2f(mSize, -mSize);
        glVertex2f(mSize, mSize);
        glVertex2f(-mSize, mSize);
    glEnd();

    glPopMatrix();
}



