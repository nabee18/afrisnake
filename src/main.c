#include "raylib.h"
#include "game.h"

int main(void)
{
    int window = 800;

    InitWindow(window, window, "afrisnake");
    
    InitGame();

    SetTargetFPS(60);

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