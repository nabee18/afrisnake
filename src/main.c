#include "raylib.h"

int main(void)
{
    const int window = 800;
    int posX= 20, posY= 100;
    int width= 760, height= 680;

    InitWindow(window, window, "afrisnake");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Update


        BeginDrawing();

        ClearBackground(GREEN);
        DrawRectangleLines(posX, posY, width, height, BLACK);

        // Draw

        EndDrawing();
    }

    CloseWindow();

    return 0;
}