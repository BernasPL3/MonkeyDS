#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>

typedef struct
{
    float x;
    float y;

    float width;
    float height;

    float velX;
    float velY;

    bool onGround;

    int bananas;
    int lives;
} Player;

void Player_Init(Player* p);
void Player_Update(Player* p, u32 keysDown, u32 keysHeld);
void Player_Draw(Player* p);

#endif
