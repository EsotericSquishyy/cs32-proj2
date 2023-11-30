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
        void    updatePlay();
        void    drawPlay();
        Player* mPlayer;
        std::vector<Enemy*> mEnemies;
    private:
        void spawnEnemies(size_t count);
};


#endif
