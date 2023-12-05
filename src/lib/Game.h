#ifndef GAME_H
#define GAME_H

#include "Entity.h"
#include <vector>
#include <random>
#include <ctime>
#include <iostream>
#include <map>


const int INIT_ENEMIES = 10; // Initial enemy count

class Game {
    
    public:
                Game();
        void    updatePlay();
        void    drawPlay();
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
        void    spawnEnemies(size_t count);
        void    movePlayer();
        void    moveProjs();
        void    moveEnemies();
        void    killOB();
        void    updateEntities();
        Player* mPlayer;
        std::set<Enemy*> mEnemies;
};


#endif
