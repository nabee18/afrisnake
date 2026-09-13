#ifndef GAME_CHECK_H
#define GAME_CHECK_H

#include "raylib.h"
#include "snake.h"
#include "obstacles.h"
#include<stdbool.h>

//void GameCheck(Snake *snake, bool *gameStarted, int window, double *startTime, int *number);
void GameCheck( Snake *snake, bool *gameStarted, int window, double *startTime, int *number,
    Obstacle *obstacle, Rectangle field, Vector2 *center, float radius);

#endif