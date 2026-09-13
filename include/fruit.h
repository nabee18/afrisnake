#ifndef FRUIT_H
#define FRUIT_H

#include "raylib.h"
#include "snake.h"
#include "obstacles.h"

void CheckValidity(Snake snake, Vector2 *center, Rectangle field, float radius, Obstacle obstacle);

#endif