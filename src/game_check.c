#include "game_check.h"
#include "obstacles.h"
#include "fruit.h"

//void GameCheck(Snake *snake, bool *gameStarted, int window, double *startTime, int *number)
void GameCheck(
    Snake *snake,
    bool *gameStarted,
    int window,
    double *startTime,
    int *number,
    Obstacle *obstacle,
    Rectangle field,
    Vector2 *center,
    float radius
)
{
    DrawText("Select Mode:", window/4, window/5, 30, WHITE);
    DrawText("Press 1 for Easy", window/4, window/5 + 40, 30, WHITE);
    DrawText("Press 2 for Medium", window/4, window/5 + 80, 30, WHITE);
    DrawText("Press 3 for Hard", window/4, window/5 + 120, 30, WHITE);
    if (IsKeyPressed(KEY_ONE) || IsKeyPressed(KEY_TWO) || IsKeyPressed(KEY_THREE)){
        if (IsKeyPressed(KEY_ONE)) { snake->speed = 5; snake->length=10; snake->inc = 5; *number=3;}
        if (IsKeyPressed(KEY_TWO)) { snake->speed = 6; snake->length=10; snake->inc = 10; *number=5;}
        if (IsKeyPressed(KEY_THREE)) { snake->speed = 7;snake->length=10; snake->inc = 15; *number=7;}
        
        *gameStarted = true;
        *startTime = GetTime();

        //StartGame(snake, obstacle, field, center, radius);

        InitObstacles(obstacle, field, snake->size);

        CheckValidity(*snake, center, field, radius, *obstacle);

    }

    snake->vel.x=snake->speed;

}