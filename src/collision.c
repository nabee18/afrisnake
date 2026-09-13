#include "collision.h"
#include "fruit.h"

void SnakeFruit(Snake *snake, Vector2 *center, float radius, int *score, Rectangle field, Obstacle obstacle)
{
    if(CheckCollisionCircleRec((Vector2){center->x, center->y}, radius, snake->snakeRec[0]))
    {
        snake->eat=true;
        snake->eatTime=GetTime();
        (*score)++;
        snake->length+=snake->inc;
        for (int i=snake->inc; i>0; i--){
            snake->snakeRec[snake->length-i]=snake->snakeRec[snake->length-i-1];
        }

        // Check Validity
        CheckValidity(*snake, center, field, radius, obstacle);
        //CheckValidity(*snake, center, field, radius);
        
    }
}

void SnakeWall(Snake *snake, int left, int top, int bottom, int window, bool *gameOver)
{
    if(((snake->snakeRec[0].x >=window -snake->size -left && snake->vel.x>0) || 
        (snake->snakeRec[0].x <=left && snake->vel.x<0)) ||
        ((snake->snakeRec[0].y >=window -snake->size - bottom && snake->vel.y>0) ||
        (snake->snakeRec[0].y <= top && snake->vel.y<0))
    ){
        *gameOver=true;
    }
}

void SnakeBody(Snake *snake, bool *gameOver, int bodyStart)
{
    for(int i=bodyStart; i<snake->length; i++)
    {
        if(CheckCollisionRecs(snake->snakeRec[0], snake->snakeRec[i]))
        {
            *gameOver=true;
            break;
        }
    }
}

void SnakeObstacle(Snake *snake, Obstacle obstacle, bool *gameOver) {
    for (int i = 0; i < obstacle.num; i++) {
        if (CheckCollisionRecs(snake->snakeRec[0], obstacle.rec[i])) {
            *gameOver = true;
            break;
        }
    }
}
