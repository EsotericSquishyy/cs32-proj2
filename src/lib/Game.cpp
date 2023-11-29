#include "Game.h"



Game::Game(){
    player = new Player(0,0);
    spawnEnemies(10);
}



void Game::spawnEnemies(size_t count){
    srand(time(nullptr));
    for(size_t i = 0; i < count; i++){
        float r = 8 * static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        Enemy* cEnemy;

        if(r >= 0.0f && r <= 2.0f){
            cEnemy = new Enemy(1.0f - r, 0.8f);
        }
        else if (r > 2.0f && r <= 4.0f){
            cEnemy = new Enemy(0.8f, 1.0f - (r - 2.0f));
        }
        else if (r > 4.0f && r <= 6.0f){
            cEnemy = new Enemy(1.0f - (r - 4.0f), -0.8f);
        }
        else{
            cEnemy = new Enemy(-0.8f, 1.0f - (r - 6.0f));
        }
        enemies.push_back(cEnemy);
    }
}



