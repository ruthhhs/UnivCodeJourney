// ========================================================
// TREE
// ========================================================
#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include "geometri.h"
#include "lighting.h"

#define MAX_WALLS 200

struct CircleWall {
    float x, z;
    float radius;
};

extern CircleWall circleWalls[MAX_WALLS];
extern int circleWallCount;
extern float playerRadius;

void addCircleWall(float x, float z, float radius);
bool checkCircleCollision(float newX, float newZ);
void initTreeCollision();
void drawTree(float tx, float tz);
void drawSmallTree(float tx, float tz);

#endif
