#ifndef CONSTANTS_H
#define CONSTANTS_H

const unsigned int  DELTA_TIME      = 1000/30; // Time in ms between updates

const float         PROJ_MOVSPD     = 0.05f;   // Speed of player projectiles
const float         PROJ_SIZE       = 0.01f;   // Half the width of player projectile

const int           PLAYER_HP       = 5;       // HP of Player
const int           PLAYER_ATT      = 1000;    // Cooldown, in milliseconds, to attack
const float         PLAYER_MOVSPD   = 0.02f;   // Speed of player
const float         PLAYER_ROTSPD   = 0.05f;   // Rotation speed of player
const float         PLAYER_SIZE     = 0.05f;   // Half the width of the player
const float         WEAPON_MULT     = 1.5f;    // Relative length of weapon

const float         ENEMY_MOVSPD    = 0.01f;   // Speed of enemy
const float         ENEMY_SIZE      = 0.05f;   // Half the width of the enemy

const int           WIDTH           = 600;
const int           HEIGHT          = 600;

#endif
