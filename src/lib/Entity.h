#ifndef ENTITY_H
#define ENTITY_H

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>
#include <cmath>
#include <set>
#include "Constants.h"


class Entity {
    public:
                        Entity(float x, float y, float rot): mX(x), mY(y), rotState(rot){}
        virtual         ~Entity(){}
        virtual void    drawObj() = 0;
                void    moveForward();
                void    moveBack();
                float   mX;
                float   mY;
                float   rotState; // radians
                float   mSize;
                float   mSpeed;
                int     mHealth;
};



class Projectile : public Entity {
    public:
                        Projectile(float x, float y, float rot) : Entity(x, y, rot){
                            mSize   = PROJ_SIZE;
                            mSpeed  = PROJ_MOVSPD;
                            mHealth = PROJ_HP;
                        }
        virtual         ~Projectile(){};
        virtual void    drawObj();
};



class Player : public Entity {
    public:
                        Player(float x, float y, float rot) : Entity(x, y, rot){
                            mSize   = PLAYER_SIZE;
                            mSpeed  = PLAYER_MOVSPD;
                            mHealth = PLAYER_HP;
                        }
        virtual         ~Player(){};
        virtual void    drawObj();
                float   attackTime  = 0;
                std::set<Projectile*> mProjs;
                void    createProj();
    private:
                void    drawBody();
                void    drawWeapon();
                void    drawProjectiles();
};



class Enemy : public Entity {
    public:
                        Enemy(float x, float y, float rot) : Entity(x, y, rot){
                            mSize   = ENEMY_SIZE;
                            mSpeed  = ENEMY_MOVSPD;
                            mHealth = ENEMY_HP;
                        }
        virtual         ~Enemy(){};
        virtual void    drawObj();
};


#endif
