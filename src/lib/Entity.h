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
                        Entity(float x, float y): mX(x), mY(y){}
        virtual void    drawObj() = 0;
        virtual void    moveForward() = 0;
        virtual void    moveBack() = 0;
                float   mX;
                float   mY;
                float   rotState    = M_PI/2; // radians
};



class Projectile : public Entity {
    public:
                        Projectile(float x, float y) : Entity(x, y){}
        virtual void    moveForward();
        virtual void    moveBack();
        virtual void    drawObj();
};



class Player : public Entity {
    public:
                        Player(float x, float y) : Entity(x, y){}
        virtual void    drawObj();
        virtual void    moveForward();
        virtual void    moveBack();
                float   attackTime  = 0;
                int     health      = PLAYER_HP;
                std::set<Projectile*> mProjs;
                void    createProj();
    private:
                void    drawBody();
                void    drawWeapon();
                void    drawProjectiles();
};



class Enemy : public Entity {
    public:
                        Enemy(float x, float y) : Entity(x,y){}
        virtual void    moveForward();
        virtual void    moveBack();
        virtual void    drawObj();
};


#endif
