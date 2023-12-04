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



void Game::movePlayer(){
    if(pressedKeys['w']){
        mPlayer->moveforward();
    }
    if(pressedKeys['s']){
        mPlayer->moveback();
    }
    if(pressedKeys['a']){
        mPlayer->rotState = fmod(mPlayer->rotState + .02*2*M_PI, 2*M_PI);
    }
    if(pressedKeys['d']){
        mPlayer->rotState = fmod(mPlayer->rotState + .98*2*M_PI, 2*M_PI);
    }

}



void Game::moveEnemies(){
    float movemultiplier;
    float moveX;
    float moveY;
    for (int i = 0; i<int(mEnemies.size()); i++){
        moveX = mEnemies[i]->mX - mPlayer->mX;
        moveY = mEnemies[i]->mY - mPlayer->mY;
        movemultiplier = sqrt(pow(moveX, 2) + pow(moveY, 2));
        movemultiplier = ENEMY_SPEED/movemultiplier;
        mEnemies[i]->mX -= moveX*movemultiplier;
        mEnemies[i]->mY -= moveY*movemultiplier;
    }
}



void Game::updatePlay(){
    // Implementation for updating all objects in game
    movePlayer();
    moveEnemies();

    // updatePlayer();
    // updateEnemies();

    // killEntities();
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



