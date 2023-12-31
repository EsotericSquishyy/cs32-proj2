#ifndef GAME_H
#define GAME_H

#include "Entity.h"
#include <vector>
#include <random>
#include <ctime>
#include <iostream>
#include <map>



class Game {

    public:
                Game();
        void    updatePlay();
        void    drawPlay();
        void    drawUI();
        int     getScore() const;
        std::map<unsigned char, bool> pressedKeys {
            {'w', false}, // Move up
            {'a', false}, // Move left
            {'s', false}, // Move down
            {'d', false}, // Move right
            {'q', false}, // Rotate left
            {'e', false}, // Rotate right
            {' ', false}, // Shoot (NOT IMPLEMENTED)
        };

    private:
        void    movePlayer();
        void    moveProjs();
        void    moveEnemies();
        void    updateEntities();
        bool    checkCollide(Entity* obj1, Entity* obj2) const;
        void    killOB();
        void    spawnEnemies(size_t count);
        void    endGame();
        float   maxSpawnTime = SPAWN_MAXTIME; // Interval between enemy spawns
        float   spawnTime = SPAWN_MAXTIME;
        int     mTime  = 0;
        int     mScore = 0;
        Player* mPlayer;
        std::set<Enemy*> mEnemies;
};


#endif
