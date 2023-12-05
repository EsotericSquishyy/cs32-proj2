#include "Game.h"



Game::Game(){
    mPlayer = new Player(0,0,M_PI/2);
    spawnEnemies(INIT_ENEMIES);
}



void Game::drawPlay(){
    mPlayer->drawObj();
    for(Enemy* cEnemy : mEnemies){
        cEnemy->drawObj();
    }
}



void Game::movePlayer(){
    if(pressedKeys['w']){
        mPlayer->moveForward();
    }
    if(pressedKeys['s']){
        mPlayer->moveBack();
    }
    if(pressedKeys['a']){
        mPlayer->rotState = fmod(mPlayer->rotState + PLAYER_ROTSPD*2*M_PI + 2*M_PI, 2*M_PI);
    }
    if(pressedKeys['d']){
        mPlayer->rotState = fmod(mPlayer->rotState - PLAYER_ROTSPD*2*M_PI + 2*M_PI, 2*M_PI);
    }

    moveProjs();
}



void Game::moveProjs(){
    for(Projectile* cProj : mPlayer->mProjs){
        cProj->moveForward();
    }
}



void Game::moveEnemies(){
    for (Enemy* cEnemy : mEnemies){
        float xDisp = mPlayer->mX - cEnemy->mX;
        float yDisp = mPlayer->mY - cEnemy->mY;
        float angle = 0;
        if(xDisp > 0){
            angle = std::atan(yDisp / xDisp);
        } else {
            angle = M_PI + std::atan(yDisp / xDisp);
        }
        cEnemy->rotState = fmod(angle + 2*M_PI, 2*M_PI);
        cEnemy->moveForward();
    }
}



void Game::updatePlay(){
    movePlayer();
    moveEnemies();

    updateEntities();
}



void Game::updateEntities(){
    mPlayer->attackTime -= DELTA_TIME;
    if(pressedKeys[' '] && mPlayer->attackTime <= 0.0f){
        mPlayer->attackTime = PLAYER_ATT; 
        mPlayer->createProj();
    }

    // Check if overlapping with enemy

    // Check if projectile is overlapping with enemy

    killOB();
}



void Game::killOB(){
    if(mPlayer->mX - PLAYER_SIZE > 1 || mPlayer->mX + PLAYER_SIZE < -1 ||
       mPlayer->mY - PLAYER_SIZE > 1 || mPlayer->mX + PLAYER_SIZE < -1){
        // Game over function to handle cleanups and endscreen
        return;
    }

    // Killing enemies

    for(Projectile* cProj : mPlayer->mProjs){
        if(cProj->mX - PLAYER_SIZE > 1 || cProj->mX + PLAYER_SIZE < -1 ||
           cProj->mY - PLAYER_SIZE > 1 || cProj->mX + PLAYER_SIZE < -1){
            // kill projectile
            return;
        }
    }
}



void Game::spawnEnemies(size_t count){
    srand(time(nullptr));
    for(size_t i = 0; i < count; i++){
        float r = 8 * static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        Enemy* cEnemy;

        if(r >= 0.0f && r <= 2.0f){
            cEnemy = new Enemy(1.0f - r, 1.0f, 0);
        }
        else if (r > 2.0f && r <= 4.0f){
            cEnemy = new Enemy(1.0f, 1.0f - (r - 2.0f), 0);
        }
        else if (r > 4.0f && r <= 6.0f){
            cEnemy = new Enemy(1.0f - (r - 4.0f), -1.0f, 0);
        }
        else{
            cEnemy = new Enemy(-1.0f, 1.0f - (r - 6.0f), 0);
        }
        mEnemies.insert(cEnemy);
    }
}



