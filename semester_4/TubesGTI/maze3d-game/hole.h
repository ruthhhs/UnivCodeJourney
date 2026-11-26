// ========================================================
// HOLE
// ========================================================
#ifndef HOLE_H_INCLUDED
#define HOLE_H_INCLUDED

#include "cammove.h"

#define MAX_HOLES 50

typedef struct {
    float minX, maxX;
    float minY, maxY;
    float minZ, maxZ;
} Hole;

extern Hole holes[MAX_HOLES];
extern int holeCount;

void addHole(float x1, float y1, float z1, float x2, float y2, float z2);
int checkHole(float px, float py, float pz);
void drawHole(float cx, float cz, float radius);

#endif
