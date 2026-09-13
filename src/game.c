#include "raylib.h"
#include "game.h"
#include "collision.h"
#include "fruit.h"
#include "game_check.h"
#include "obstacles.h"

static int window;

// Field rectangle
static Rectangle field;

static Texture2D fieldTexure;

// walls
static int left;
static int top, bottom;

// Fruit
static Vector2 center;
static float radius;

//====snake
static Snake snake;
static int bodyStart;
static Texture2D snakeHead;

static bool gameOver;
static bool gameStarted;

static int score;

double elapsed, startTime;
int minutes, seconds;

// Obstacles
static Obstacle obstacle;

void InitGame(){
    window = 800;
    
    field.x=20;
    field.y=100;
    field.width=760;
    field.height=680;

    fieldTexure=LoadTexture("assets/textures/background.png");

    // walls
    left=20;
    top=100;
    bottom= 20;
    
    radius=10.0f;

    //=====Snake======//
    InitSnake(&snake, window);
    bodyStart=7;
    snakeHead= LoadTexture("assets/textures/snake.png");

    gameOver=false;
    gameStarted=false;

    score=0;

    obstacle.num = 0;

    // Check Validity of fruit position
    //CheckValidity(snake, &center, field, radius, obstacle);
    //CheckValidity(snake, &center, field, radius);

}

void UpdateGame(){
    if(gameOver)
        return;

    if(!gameStarted)
        return;

    // Change direction with keys
    UpdateSnake(&snake, KEY_LEFT, KEY_RIGHT,
                KEY_UP, KEY_DOWN);

    //=======Move snake: shift body=====//
    MoveSnake(&snake);

    //====== Keep snake inside window =====//
    // No need as gameover
    
    //Colision with fruit
    SnakeFruit(&snake, &center, radius, &score, field, obstacle);

    //collision with wall, pass address for consistency, tho not needed
    SnakeWall(&snake, left, top, bottom, window, &gameOver);

    //Detect collision with body//Detect collission with body
    SnakeBody(&snake, &gameOver, bodyStart);

    SnakeObstacle(&snake, obstacle, &gameOver);

    elapsed = GetTime() - startTime;

    minutes= (int)((elapsed) / 60);
    seconds= (int)(elapsed) % 60;

    //GameCheck(&snake, &gameStarted, window, &startTime,
    //&obstacle.num, &obstacle, field, &center, radius);

}

void DrawGame(){

    DrawTexture(fieldTexure, 0, 0, WHITE);
    // Draw snake
    DrawSnake(&snake);

    //DrawRectangleLines(posX, posY, width, height, BLACK);
    DrawRectangleLinesEx(field, 2.0f, WHITE);
    DrawCircle(center.x, center.y, radius, WHITE);
    // CheckGame
    if(gameOver)
    {

        DrawText("Game Over", window/5, window/5, 100, WHITE);
        DrawText("Press R to Restart", window/5, window/3, 50, WHITE);

        if(IsKeyPressed(KEY_R)){
            startTime=GetTime();
            InitGame();
        }
    }

    if(!gameStarted)
    GameCheck(&snake, &gameStarted, window, &startTime,
    &obstacle.num, &obstacle, field, &center, radius);

    /*if(!gameStarted)
    {
        init=1;
        GameCheck(&snake, &gameStarted, window, &startTime, &obstacle.num);
    }
    else if(init)
    {
        init=0;
        InitObstacles(&obstacle, field, snake.size);
    }*/
    DrawText(TextFormat("Score %d", score), 10, 20, 50, WHITE);

    DrawText(TextFormat("Time %02d:%02d",minutes, seconds), 10, 80, 40, WHITE);

    for (int i = 0; i < obstacle.num; i++) {
        
        DrawRectangleRec(obstacle.rec[i], RED);
        
    }
}

void CloseGame(){
    UnloadTexture(fieldTexure);
    UnloadTexture(snakeHead);

}
