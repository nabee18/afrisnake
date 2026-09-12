#include "raylib.h"
#include<stdlib.h>
#include<time.h>

int main(void)
{
    int window = 800;
    int posX= 20, posY= 100;
    int width= 760, height= 680;
    
    // walls
    int left=20, top=100;
    int right=20, bottom= 20;
    //====snake
    int snakeSize=20;
    int speed=5;
    int centerX, centerY;
    srand(time(0));
    centerX=posX + (rand() % (width/snakeSize))*snakeSize;
    centerY=posY + (rand() % (height/snakeSize))*snakeSize;


    bool verPossible=true;
    bool horPossible=false;

    // Snake body positions (simple fixed-length snake for now)
    Vector2 snake[100];
    int length =10;  // snake length
    int inc=10;  // increase in length after eating
    for (int i=0; i<length; i++){
        snake[i]=(Vector2){window/2-i*snakeSize, window/2};
    }

    // Movement direction
    int dx=speed, dy=0;

    InitWindow(window, window, "afrisnake");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Change direction with keys
        if (IsKeyPressed(KEY_RIGHT) && horPossible){
            verPossible=true;
            horPossible=false;
            dx=speed;
            dy=0;
        }
        if (IsKeyPressed(KEY_LEFT) && horPossible){
            verPossible=true;
            horPossible=false;
            dx=-speed;
            dy=0; 
        }
        if (IsKeyPressed(KEY_DOWN) && verPossible)  { 
            verPossible=false;
            horPossible=true;
            dx= 0; 
            dy=speed; 
        }
        if (IsKeyPressed(KEY_UP) && verPossible)  { 
            verPossible=false;
            horPossible=true;
            dx=0;
            dy=-speed;
        }

        //=======Move snake: shift body=====//
        //==================================//
        for (int i=length-1; i>0; i--)
        {
            snake[i]=snake[i-1];
        }
        snake[0].x+=dx;
        snake[0].y+=dy;

        //===================================//
        //======Keep snake inside window=====//
        //===================================//
        if (snake[0].x<left) snake[0].x=left;
        if (snake[0].x>window-snakeSize-right) snake[0].x=window-snakeSize-right;
        if (snake[0].y<top) snake[0].y=top;
        if (snake[0].y>window-snakeSize-bottom) snake[0].y=window-snakeSize-bottom;


        // Check collision of head with food
        /*if ((int)snake[0].x == centerX && (int)snake[0].y == centerY) {
            centerX = posX + (rand() % (width/snakeSize)) * snakeSize;
            centerY = posY + (rand() % (height/snakeSize)) * snakeSize;
        }*//*
        if(CheckCollisionPointCircle(snake[0], (Vector2){centerX, centerY}, 10.0f))
        {
            centerX = posX + (rand() % (width/snakeSize)) * snakeSize;
            centerY = posY + (rand() % (height/snakeSize)) * snakeSize;
        }*/

       if(CheckCollisionCircleRec((Vector2){centerX, centerY}, 10.0f, (Rectangle){snake[0].x, snake[0].y, snakeSize, snakeSize}))
       {
            length+=inc;
            for (int i=inc; i>0; i--){
                snake[length-i]=snake[length-i-1];
            }
            centerX = posX + (rand() % (width/snakeSize)) * snakeSize;
            centerY = posY + (rand() % (height/snakeSize)) * snakeSize;
       }

        BeginDrawing();
        ClearBackground(DARKGREEN);
        // Draw snake
        for (int i=0; i<length; i++)
        {
            DrawRectangleV(snake[i], (Vector2){snakeSize, snakeSize}, WHITE);
        }

        DrawRectangleLines(posX, posY, width, height, BLACK);
        DrawCircle(centerX, centerY, 10, WHITE);
        
        // Draw

        EndDrawing();
    }

    CloseWindow();

    return 0;
}