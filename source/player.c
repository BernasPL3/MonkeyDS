#include <3ds.h>
#include <citro2d.h>

#include "player.h"

#define GRAVITY 0.35f
#define JUMP_FORCE -6.5f
#define MOVE_SPEED 2.0f
#define GROUND_Y 200.0f

void Player_Init(Player* p)
{
    p->x = 40;
    p->y = 100;

    p->width = 16;
    p->height = 16;

    p->velX = 0;
    p->velY = 0;

    p->onGround = false;

    p->bananas = 0;
    p->lives = 3;
}

void Player_Update(Player* p, u32 keysDown, u32 keysHeld)
{
    if(keysHeld & KEY_LEFT)
        p->x -= MOVE_SPEED;

    if(keysHeld & KEY_RIGHT)
        p->x += MOVE_SPEED;

    if((keysDown & KEY_A) && p->onGround)
    {
        p->velY = JUMP_FORCE;
        p->onGround = false;
    }

    p->velY += GRAVITY;
    p->y += p->velY;

    if(p->y + p->height >= GROUND_Y)
    {
        p->y = GROUND_Y - p->height;
        p->velY = 0;
        p->onGround = true;
    }

    if(p->x < 0)
        p->x = 0;

    if(p->x + p->width > 400)
        p->x = 400 - p->width;
}

void Player_Draw(Player* p)
{
    C2D_DrawRectSolid(
        p->x,
        p->y,
        0.5f,
        p->width,
        p->height,
        C2D_Color32(255, 200, 50, 255)
    );
}
