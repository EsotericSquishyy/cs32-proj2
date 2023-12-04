#ifndef ENTITY_H
#define ENTITY_H

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>
#include <cmath>


const float PLAYER_SPEED = 0.02f;   // Speed of player
const float PLAYER_ROT   = 0.02f;   // Speed of player
const float PLAYER_SIZE  = 0.05f;   // Half the width of the player
const float WEAPON_MULT  = 1.5f;    // Relative length of weapon

const float ENEMY_SPEED  = 0.01f;   // Speed of enemy
const float ENEMY_SIZE   = 0.05f;   // Half the width of the enemy

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
        float           rotState = 0; // mod 4, 0 up, 1 left, 2 down, 3 right
        void            moveforward();
        void            moveback();
    private:
        void    drawBody();
        void    drawWeapon();
        void    drawProjectiles();
        double  health;
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
