#ifndef OBSTACLES_H
#define OBSTACLES_H

#include "raylib.h"

typedef struct Obstacle{
    Rectangle rec[20];
    int num;
}Obstacle;

void InitObstacles(Obstacle *obstacle, Rectangle field, int size);
#endif