#include "Game.h"



Game::Game(){
    mPlayer = new Player(0,0);
    spawnEnemies(INIT_ENEMIES);
}



void Game::drawPlay(){
    mPlayer->drawObj();
    for(size_t i = 0; i < mEnemies.size(); i++){
        mEnemies[i]->drawObj();
    }
}



void Game::updatePlay(){
    // Implementation for updating all objects in game
    if(pressedKeys['w']){
        mPlayer->mY += PLAYER_SPEED;
    }
    if(pressedKeys['s']){
        mPlayer->mY -= PLAYER_SPEED;
    }
    if(pressedKeys['a']){
        mPlayer->mX -= PLAYER_SPEED;
    }
    if(pressedKeys['d']){
        mPlayer->mX += PLAYER_SPEED;
    }
    if(pressedKeys['q']){
        pressedKeys['q'] = false;
        mPlayer->rotState = (((mPlayer->rotState + 1) % 4) + 4) % 4;
        std::cout << "Changed rotState to: " << mPlayer->rotState << std::endl;
    }
    if(pressedKeys['e']){
        pressedKeys['e'] = false;
        mPlayer->rotState = (((mPlayer->rotState - 1) % 4) + 4) % 4;
        std::cout << "Changed rotState to: " << mPlayer->rotState << std::endl;
    }
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
        mEnemies.push_back(cEnemy);
    }
}



