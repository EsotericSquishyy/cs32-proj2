#ifndef GAME_H
#define GAME_H

#include "Entity.h"
#include <vector>
#include <random>
#include <ctime>
#include <iostream>


class Game {
    
    public:
                Game();
        Player* player;
        std::vector<Enemy*> enemies;
    private:
        void spawnEnemies(size_t count);
};


#endif
