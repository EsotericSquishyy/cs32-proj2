#ifndef ENTITY_H
#define ENTITY_H


class Entity {
    public:
        virtual void    drawObj() = 0;
                double  getX();
                double  getY();
    private:
        double x;
        double y;
};



class Player : public Entity {
    public:
        virtual void    drawObj();
    private:
        double health;
};



class Enemy : public Entity {
    public:
        virtual void    drawObj();
};



class Projectile : public Entity {
    public:
        virtual void    drawObj();
};

#endif
