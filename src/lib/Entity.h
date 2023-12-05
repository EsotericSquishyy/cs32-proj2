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
        virtual void    drawObj() = 0;
        virtual void    moveForward() = 0;
        virtual void    moveBack() = 0;
                float   mX;
                float   mY;
                float   rotState; // radians
};



class Projectile : public Entity {
    public:
                        Projectile(float x, float y, float rot) : Entity(x, y, rot){}
        virtual void    moveForward();
        virtual void    moveBack(){}
        virtual void    drawObj();
};



class Player : public Entity {
    public:
                        Player(float x, float y, float rot) : Entity(x, y, rot){}
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
                        Enemy(float x, float y, float rot) : Entity(x, y, rot){}
        virtual void    moveForward();
        virtual void    moveBack();
        virtual void    drawObj();
};


#endif
