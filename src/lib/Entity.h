#ifndef ENTITY_H
#define ENTITY_H

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>


class Entity {
    public:
        virtual void    drawObj() = 0;
        double mX;
        double mY;
};



class Player : public Entity {
    public:
                        Player(float x, float y);
        virtual void    drawObj();
    private:
        double health;
};



class Enemy : public Entity {
    public:
                        Enemy(float x, float y);
        virtual void    drawObj();
};



class Projectile : public Entity {
    public:
        virtual void    drawObj();
};

#endif
