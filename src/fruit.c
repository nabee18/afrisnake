#include "fruit.h"
#include<stdlib.h>

void CheckValidity(Snake snake, Vector2 *center, Rectangle field, float radius, 
                   Obstacle obstacle)
{
    bool valid = false;
    while (!valid) {
        center->x = field.x + radius + (rand() % ((int)(field.width - radius*2) / snake.size)) * snake.size;
        center->y = field.y + radius + (rand() % ((int)(field.height - radius*2) / snake.size)) * snake.size;

        valid = true;

        // Check against snake body
        for (int i = 0; i < snake.length; i++) {
            if (CheckCollisionCircleRec(*center, radius, snake.snakeRec[i])) {
                valid = false;
                break;
            }
        }

        // Check against obstacles
        if (valid) {
            for (int j = 0; j < obstacle.num; j++) {
                if (CheckCollisionCircleRec(*center, radius, obstacle.rec[j])) {
                    valid = false;
                    break;
                }
            }
        }
    }
}
