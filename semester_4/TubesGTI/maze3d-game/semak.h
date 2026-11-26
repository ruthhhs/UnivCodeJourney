#ifndef SEMAK_H
#define SEMAK_H

#define MAX_WALLS 100

//#include "lighting.h"
#include "cammove.h"

typedef struct
{
    float x, z;
    float radius;
    float jumpHeight;
} SemakWall;

// array collision
extern SemakWall semakWalls[MAX_WALLS];
extern int semakWallCount;

// dari player/camera
extern float playerRadius;

// collision
void addSemakWall(float x,
                  float z,
                  float radius,
                  float jumpHeight);

bool checkSemakCollision(float newX,
                         float newY,
                         float newZ);

// draw
void drawSemak(float tx, float tz);

#endif
