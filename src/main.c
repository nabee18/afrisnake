#include "raylib.h"

int main(void)
{
    const int window = 800;
    int posX= 20, posY= 100;
    int width= 760, height= 680;
    // walls
    int left=20, top=100;
    int right=20, bottom= 20;
    
    //snake
    int snakeSize=20;
    int speed=5;

    bool verPossible=true;
    bool horPossible=false;

    // Snake body positions (simple fixed-length snake for now)
    Vector2 snake[100];
    int length =10;  // snake length
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

        // Move snake: shift body
        for (int i=length-1; i>0; i--)
        {
            snake[i]=snake[i-1];
        }
        snake[0].x+=dx;
        snake[0].y+=dy;

        // Keep snake inside window
        if (snake[0].x<left) snake[0].x=left;
        if (snake[0].x>window-snakeSize-right) snake[0].x=window-snakeSize-right;
        if (snake[0].y<top) snake[0].y=top;
        if (snake[0].y>window-snakeSize-bottom) snake[0].y=window-snakeSize-bottom;

        BeginDrawing();
        ClearBackground(DARKGREEN);
        // Draw snake
        for (int i=0; i<length; i++)
        {
            DrawRectangleV(snake[i], (Vector2){snakeSize, snakeSize}, WHITE);
        }

        BeginDrawing();

        ClearBackground(DARKGREEN);
        DrawRectangleLines(posX, posY, width, height, BLACK);

        // Draw

        EndDrawing();
    }

    CloseWindow();

    return 0;
}