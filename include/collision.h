#ifndef COLLISION_H
#define COLLISION_H

#include "raylib.h"
#include "snake.h"
#include "obstacles.h"

void SnakeFruit(Snake *snake, Vector2 *center, float radius, int *score, Rectangle field, Obstacle obstacle);

void SnakeWall(Snake *snake, int left, int top, int bottom, int wimdow, bool *gameOver);

void SnakeBody(Snake *snake, bool *gameOver, int bodyStart);

void SnakeObstacle(Snake *snake, Obstacle obstacle, bool *gameOver);

#endif