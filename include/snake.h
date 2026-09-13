#ifndef SNAKE_H
#define SNAKE_H

#include "raylib.h"
#include<stdbool.h>

typedef struct Snake{
    Rectangle snakeRec[10000];
    Texture2D snakeHead;
    Texture2D snakeHead2;
    bool eat;
    float eatTime;
    float rotation;
    Vector2 vel;
    int length;
    int inc;
    int size;
    int speed;
    bool verPossible;
    bool horPossible;

}Snake;
void InitSnake(Snake *snake, int window) ;

void UpdateSnake(Snake *snake, KeyboardKey left, KeyboardKey right,
                 KeyboardKey up, KeyboardKey down
);

void MoveSnake(Snake *snake);

void DrawSnake(Snake *snake);

#endif