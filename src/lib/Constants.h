#ifndef CONSTANTS_H
#define CONSTANTS_H

const unsigned int  DELTA_TIME      = 1000/30;  // Time in ms between updates

const int           PROJ_HP         = 1;        // HP of Projectile
const float         PROJ_MOVSPD     = 0.05f;    // Speed of player projectiles
const float         PROJ_SIZE       = 0.01f;    // Half the width of player projectile

const int           PLAYER_HP       = 5;        // HP of Player
const int           PLAYER_ATT      = 500;      // Cooldown, in milliseconds, to attack
const float         PLAYER_MOVSPD   = 0.02f;    // Speed of player
const float         PLAYER_ROTSPD   = 0.02f;    // Rotation speed of player
const float         PLAYER_SIZE     = 0.05f;    // Half the width of the player
const float         WEAPON_MULT     = 1.5f;     // Relative length of weapon

const int           ENEMY_HP        = 1;        // HP of Enemy
const float         ENEMY_MINMOVSPD = 0.001f;   // Speed of enemy
const float         ENEMY_MAXMOVSPD = 0.01f;    // Speed of enemy
const float         ENEMY_SIZE      = 0.05f;    // Half the width of the enemy
const int           ENEMY_COUNT     = 3;        // Initial enemy count
const float         SPAWN_MAXTIME   = 7000;     // Max time in milliseconds between enemy spawns
const float         SPAWN_MINTIME   = 500;      // Min time in milliseconds between enemy spawns
const float         SPAWN_DECAYTIME = 0.05f;    // Rate of decay for spawn time in milliseconds per millisecond of time elapsed

const float         REPEL_RNG_MULT  = 10.0f;    // More dramatic change in repulsion based on lower range
const float         REPEL_MULT      = 0.5f;     // Overall multiplier for effect of repulsion
const float         REPEL_RNG       = 0.1f;     // Higher peak repulsion for lower value

const int           WIDTH           = 600;      // Window width
const int           HEIGHT          = 600;      // Window height

#endif
