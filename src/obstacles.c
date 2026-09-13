#include "obstacles.h"
#include <stdlib.h>

/*void InitObstacles(Obstacle *obstacle, Rectangle field, int size) {
    for (int i = 0; i < obstacle->num; i++) {
        obstacle->rec[i].x = field.x + 20 + (rand() % (((int)field.width - 2*20) / size)) * size;
        obstacle->rec[i].y = field.y + 20 + (rand() % (((int)field.height - 2*20) / size)) * size;
        obstacle->rec[i].width = size * 2;
        obstacle->rec[i].height = size * 2;
    }
}*/

// Prevent Obstacle overlap
void InitObstacles(Obstacle *obstacle, Rectangle field, int size)
{
    for (int i = 0; i < obstacle->num; i++)
    {
        bool valid = false;

        while (!valid)
        {
            obstacle->rec[i].x =
                field.x + 20 +
                (rand() % (((int)field.width - 40) / size)) * size;

            obstacle->rec[i].y =
                field.y + 20 +
                (rand() % (((int)field.height - 40) / size)) * size;

            obstacle->rec[i].width = size * 2;
            obstacle->rec[i].height = size * 2;

            valid = true;

            // Check against previously generated obstacles
            for (int j = 0; j < i; j++)
            {
                if (CheckCollisionRecs(obstacle->rec[i], obstacle->rec[j]))
                {
                    valid = false;
                    break;
                }
            }
        }
    }
}

