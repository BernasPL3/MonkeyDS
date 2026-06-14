#ifndef ENEMY_H
#define ENEMY_H

typedef struct
{
    float x;
    float y;

    float width;
    float height;

    float speed;

    float leftLimit;
    float rightLimit;

    int active;
} Enemy;

void Enemy_Init(Enemy* e,
                float x,
               
