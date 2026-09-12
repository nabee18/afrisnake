#include "raylib.h"
#include "game.h"
#include<stdlib.h>
#include<time.h>

static int window;
static int posX, posY;
static int width, height;

// walls
static int left, top;
static int right, bottom;

//====snake
static int snakeSize;
static int speed;
static int centerX, centerY;
static bool verPossible;
static bool horPossible;

// Snake body positions (simple fixed-length snake for now) 
//static Vector2 snake[100000];
static Rectangle snake[10000];
static int length;  // snake length
static int inc;  // increase in length after eating

// ===============================//
// ====== Movement direction =====//
static int dx, dy;

static bool gameOver;

static bool gameStarted;

static int score;

void InitGame(){
    window = 800;
    posX= 20;
    posY= 100;
    width= 760;
    height= 680;
    
    // walls
    left=20;
    top=100;
    right=20;
    bottom= 20;
    //====snake
    snakeSize=20;
    length =10;  // snake length
    speed=5;
    centerX, centerY;
    srand(time(0));
    centerX=posX + (rand() % (width/snakeSize))*snakeSize;
    centerY=posY + (rand() % (height/snakeSize))*snakeSize;


    verPossible=true;
    horPossible=false;

    inc=10;  // increase in length after eating
    for (int i=0; i<length; i++){
        //snake[i]=(Vector2){window/2-i*snakeSize, window/2};
        snake[i].x= window/2 - i*snakeSize;
        snake[i].y= window/2;
        snake[i].width= snakeSize;
        snake[i].height= snakeSize;
    }

    // ===============================//
    // ====== Movement direction =====//
    dx=speed;
    dy=0;

    gameOver=false;

    gameStarted=false;

    score=0;

}

void UpdateGame(){
    if(gameOver)
        return;

    if(!gameStarted)
        return;
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

    //====================================//
    //====== Keep snake inside window =====//
    //=====================================//
    if (snake[0].x<left) snake[0].x=left;
    if (snake[0].x>window-snakeSize-right) snake[0].x=window-snakeSize-right;
    if (snake[0].y<top) snake[0].y=top;
    if (snake[0].y>window-snakeSize-bottom) snake[0].y=window-snakeSize-bottom;

    //Colision with fruit
    if(CheckCollisionCircleRec((Vector2){centerX, centerY}, 10.0f, snake[0]))
    {
        score++;
        length+=inc;
        for (int i=inc; i>0; i--){
            snake[length-i]=snake[length-i-1];
        }
        centerX = posX + (rand() % (width/snakeSize)) * snakeSize;
        centerY = posY + (rand() % (height/snakeSize)) * snakeSize;
    }

    //collision with wall
    if(((snake[0].x >=window -snakeSize -left && dx>0) || (snake[0].x <=left && dx<0)) ||
       ((snake[0].y >=window -snakeSize - left && dy>0) || (snake[0].y <= top && dy<0))
    ){
        gameOver=true;
    }

    //Detect collision with body//Detect collission with body
    for(int i=7; i<length; i++)
    {
        if(CheckCollisionRecs(snake[0], snake[i]))
        {
            gameOver=true;
            //printf("Hello");
        }
    }

}

void DrawGame(){
    // Draw snake
    for (int i=0; i<length; i++)
    {
        DrawRectangleRec(snake[i], WHITE);
    }

    DrawRectangleLines(posX, posY, width, height, BLACK);
    DrawCircle(centerX, centerY, 10, WHITE);

    if(gameOver)
    {
        //if(GetTime()-ExitTime >1.0)
        //    gameOver=false;

        DrawText("Game Over", window/5, window/5, 100, WHITE);
        DrawText("Press R to Restart", window/5, window/3, 50, WHITE);
        
        if(IsKeyPressed(KEY_R)){
            InitGame();
        }
    }

    if(!gameStarted){
        DrawText("Press Enter to start", window/4, window/5, 30, WHITE);
        if(IsKeyPressed(KEY_ENTER))
            gameStarted=true;
    }
    DrawText(TextFormat("Score %d", score), 10, 20, 50, WHITE);

}

void CloseGame(){

}
