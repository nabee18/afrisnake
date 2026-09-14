#include "raylib.h"
#include "game.h"
#include<stdlib.h>
#include<time.h>

int main()
{
    int window = 800;

    InitWindow(window, window, "afrisnake");
    
    InitGame();

    SetTargetFPS(50);
    
    srand(time(0));

    while (!WindowShouldClose())
    {
        UpdateGame();

        BeginDrawing();

        DrawGame();

        ClearBackground(DARKGREEN);

        EndDrawing();
    }

    CloseGame();

    CloseWindow();

    return 0;
}