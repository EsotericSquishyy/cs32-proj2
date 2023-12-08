#include "Game.h"



Game::Game(){
    mPlayer = new Player(0,0,M_PI/2);
}



void Game::drawPlay(){
    mPlayer->drawObj();
    for(Enemy* cEnemy : mEnemies){
        cEnemy->drawObj();
    }
}



void Game::drawUI(){
    glColor3f(0,0,1);

    std::string scoreT = "Score: " + std::to_string(getScore());
    glRasterPos3f(0.6f,0.9f,0);
    for (size_t i = 0; i < scoreT.size(); i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, scoreT.at(i));
    }

    std::string healthT = "Health: " + std::to_string(mPlayer->mHealth);
    glRasterPos3f(-0.9f,0.9f,0);
    for (size_t i = 0; i < healthT.size(); i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, healthT.at(i));
    }
}



int Game::getScore() const{
    return mScore;
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
        float xVec = mPlayer->mX - cEnemy->mX;
        float yVec = mPlayer->mY - cEnemy->mY;

        for(Enemy* cOther : mEnemies){
            if(cEnemy == cOther){
                // skip interaction with self
                continue;
            }

            float xDisp = cOther->mX - cEnemy->mX;
            float yDisp = cOther->mY - cEnemy->mY;
            float dist  = std::sqrt(xDisp * xDisp + yDisp * yDisp);
            xDisp /= dist;
            yDisp /= dist;

            float repulsion = REPEL_MULT / (std::pow(REPEL_RNG_MULT * dist, 2) + REPEL_RNG);
            xVec -= xDisp * repulsion;
            yVec -= yDisp * repulsion;
        }


        float angle = 0;
        if(xVec > 0){
            angle = std::atan(yVec / xVec);
        } else {
            angle = M_PI + std::atan(yVec / xVec);
        }
        cEnemy->rotState = fmod(angle + 2*M_PI, 2*M_PI);
        cEnemy->moveForward();
    }
}



void Game::updatePlay(){
    mTime += DELTA_TIME;
    mScore = (mTime - (mTime % 1000)) / 10;

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

    // Check if projectile collides with enemy
    for(auto it1 = mEnemies.begin(); it1 != mEnemies.end();){
        bool    deleted = false;
        Entity* cEnemy = *it1;
        for(auto it2 = mPlayer->mProjs.begin(); it2 != mPlayer->mProjs.end();){
            Entity* cProj = *it2;

            if(checkCollide(cEnemy, cProj)){
                if(--cEnemy->mHealth <= 0){
                    mEnemies.erase(it1++);
                    delete cEnemy;
                }

                if(--cProj->mHealth <= 0){
                    mPlayer->mProjs.erase(it2++);
                    delete cProj;
                }

                deleted = true;
                break;
            }
            else{
                ++it2;
            }
        }

        if(!deleted){
            ++it1;
        }
    }

    // Check if projectile is overlapping with enemy
    for(auto it = mEnemies.begin(); it != mEnemies.end();){
        Entity* cEnemy = *it;
        if(checkCollide(mPlayer, cEnemy)){
            if(--mPlayer->mHealth <= 0){
                endGame();
            }

            mEnemies.erase(it++);
            delete cEnemy;
        }
        else{
            ++it;
        }
    }

    killOB();

    spawnTime += DELTA_TIME;
    if(maxSpawnTime > SPAWN_MINTIME){
        maxSpawnTime -= DELTA_TIME * SPAWN_DECAYTIME;
    }
    else{
        maxSpawnTime = SPAWN_MINTIME;
    }
    if(spawnTime >= maxSpawnTime){
        spawnTime = 0;
        spawnEnemies(ENEMY_COUNT);
    }
}



bool Game::checkCollide(Entity* obj1, Entity* obj2) const{

    float xDisp     = obj1->mX - obj2->mX;
    float yDisp     = obj1->mY - obj2->mY;
    float realDisp  = sqrt(pow(xDisp, 2) + pow(yDisp, 2));
    float maxDisp   = obj1->mSize + obj2->mSize;

    return (realDisp <= maxDisp);
}



void Game::killOB(){
    if(mPlayer->mX - mPlayer->mSize > 1 || mPlayer->mX + mPlayer->mSize < -1 ||
       mPlayer->mY - mPlayer->mSize > 1 || mPlayer->mX + mPlayer->mSize < -1){
        endGame();
    }

    for(auto it = mEnemies.begin(); it != mEnemies.end();){
        Entity* cEnemy = *it;
        if(cEnemy->mX - cEnemy->mSize > 1 || cEnemy->mX + cEnemy->mSize < -1 ||
           cEnemy->mY - cEnemy->mSize > 1 || cEnemy->mY + cEnemy->mSize < -1){

            mEnemies.erase(it++);
            delete cEnemy;
        }
        else{
            ++it;
        }
    }

    for(auto it = mPlayer->mProjs.begin(); it != mPlayer->mProjs.end();){
        Entity* cProj = *it;
        if(cProj->mX - cProj->mSize > 1 || cProj->mX + cProj->mSize < -1 ||
           cProj->mY - cProj->mSize > 1 || cProj->mY + cProj->mSize < -1){

            mPlayer->mProjs.erase(it++);
            delete cProj;
        }
        else{
            ++it;
        }
    }
}



void Game::spawnEnemies(size_t count){
    srand(time(nullptr));
    for(size_t i = 0; i < count; i++){
        float rLoc = 8 * float(rand()) / float(RAND_MAX);
        Enemy* cEnemy;
        float rSpeed = (ENEMY_MAXMOVSPD-ENEMY_MINMOVSPD) * float(rand()) / float(RAND_MAX) + ENEMY_MINMOVSPD;
        if(rLoc>= 0.0f && rLoc<= 2.0f){
            cEnemy = new Enemy(1.0f - rLoc, 1.0f, 0, rSpeed);
        }
        else if (rLoc> 2.0f && rLoc<= 4.0f){
            cEnemy = new Enemy(1.0f, 1.0f - (rLoc- 2.0f), 0, rSpeed);
        }
        else if (rLoc> 4.0f && rLoc<= 6.0f){
            cEnemy = new Enemy(1.0f - (rLoc- 4.0f), -1.0f, 0, rSpeed);
        }
        else{
            cEnemy = new Enemy(-1.0f, 1.0f - (rLoc- 6.0f), 0, rSpeed);
        }
        mEnemies.insert(cEnemy);
    }
}



void Game::endGame(){
    throw std::runtime_error("Ended game!");
}



