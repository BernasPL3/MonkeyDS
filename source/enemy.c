#include <citro2d.h>
#include "enemy.h"

void Enemy_Init(Enemy* e,
                float x,
                float y,
                float leftLimit,
                float rightLimit)
{
    e->x = x;
    e->y = y;

    e->width = 16.0f;
    e->height = 16.0f;

    e->speed = 1.0f;

    e->leftLimit = leftLimit;
    e->rightLimit = rightLimit;

    e->active = 1;
}

void Enemy_Update(Enemy* e)
{
    if(!e->active)
        return;

    e->x += e->speed;

    if(e->x <= e->leftLimit)
        e->speed = 1.0f;

    if(e->x + e->width >= e->rightLimit)
        e->speed = -1.0f;
}

void Enemy_Draw(Enemy* e)
{
    if(!e->active)
        return;

    C2D_DrawRectSolid(
        e->x,
        e->y,
        0.5f,
        e->width,
        e->height,
        C2D_Color32(255, 0, 0, 255)
    );
}

int Enemy_CheckCollision(Enemy* e,
                         float px,
                         float py,
                         float pw,
                         float ph)
{
    if(!e->active)
        return 0;

    return (
        px < e->x + e->width &&
        px + pw > e->x &&
        py < e->y + e->height &&
        py + ph > e->y
    );
}
