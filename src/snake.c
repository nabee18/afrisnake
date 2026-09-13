#include "snake.h"
#include<stdio.h>
void InitSnake(Snake *snake, int window) {
    snake->snakeHead= LoadTexture("assets/textures/snake1.png");
    snake->snakeHead2=LoadTexture("assets/textures/snakeMouth1.png");

    snake->eat=false;

    snake->rotation=0.0f;
    snake->length = 3;
    snake->size = 20;
    snake->speed=0;
    snake->inc = 5;
    snake->vel = (Vector2){0, 0};
    snake->verPossible = true;
    snake->horPossible = false;

    for (int i = 0; i < snake->length; i++) {
        snake->snakeRec[i] = (Rectangle){
           window/2 - i*snake->size,
           window/2,
           snake->size, 
           snake->size
        };
    }
}

void UpdateSnake(Snake *snake, KeyboardKey left, KeyboardKey right,
                 KeyboardKey up, KeyboardKey down)
{
    if(IsKeyPressed(left) && snake->horPossible)
    {
        snake->vel.x=-snake->speed;
        snake->vel.y=0;
        snake->verPossible=true;
        snake->horPossible=false;
        snake->rotation= 180.0f;
    }

    if(IsKeyPressed(right) && snake->horPossible)
    {
        snake->vel.x=snake->speed;
        snake->vel.y=0;
        snake->verPossible=true;
        snake->horPossible=false;
        snake->rotation= 0.0f;
    }

    if(IsKeyPressed(down) && snake->verPossible)
    {
        snake->vel.x=0;
        snake->vel.y=snake->speed;
        snake->verPossible=false;
        snake->horPossible=true;
        snake->rotation= 90.0f;
    }

    if(IsKeyPressed(up) && snake->verPossible)
    {
        snake->vel.x=0;
        snake->vel.y=-snake->speed;
        snake->verPossible=false;
        snake->horPossible=true;
        snake->rotation= 270.0f;
    }
}

void MoveSnake(Snake *snake) {
    for (int i = snake->length - 1; i > 0; i--) {
        snake->snakeRec[i] = snake->snakeRec[i-1];
    }
    snake->snakeRec[0].x += snake->vel.x;
    snake->snakeRec[0].y += snake->vel.y;
}

void DrawSnake(Snake *snake)
{
    float scale=0.35f;
    //printf("%f\n", 0.011*snake->snakeRec[0].y);
    Vector2 headPos={snake->snakeRec[0].x+snake->size/2, 
        snake->snakeRec[0].y+snake->size/2};

    for(int i=0; i<snake->length; i++)
    {
        DrawRectangleRec(snake->snakeRec[i], ORANGE);
    }
    Texture2D head;
    if(snake->eat){
        head=snake->snakeHead2;
    }
    else head=snake->snakeHead;
    DrawTexturePro(head, (Rectangle){0, 0, snake->snakeHead.width, snake->snakeHead.height},
                    (Rectangle){headPos.x, headPos.y, snake->snakeHead.width*scale, snake->snakeHead.height*scale},
                    (Vector2){snake->snakeHead.width*scale/2, snake->snakeHead.height*scale/2},
                    snake->rotation, WHITE);
    if(snake->eat){
        if(GetTime()-snake->eatTime>0.4f){
            snake->eat=false;
        }
    }
    //DrawTextureEx(snake->snakeHead, headPos, snake->rotation, 0.03f, WHITE);
}