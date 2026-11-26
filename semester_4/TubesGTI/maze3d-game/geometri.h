// ============================================================
// Geometri
// ============================================================
#ifndef GEOMETRI_H_INCLUDED
#define GEOMETRI_H_INCLUDED

#include "coltex.h"
#include "cammove.h"
#include "lighting.h"

// ================== LANTAI ==================
#define LUAS_LANTAI 85
void Grid();
void lantaiTex(GLuint tex);
void drawLantai(GLuint tex);

// ================== COLLISION ==================
#define MAX_WALLS 200

typedef struct {
    float minX, maxX;
    float minZ, maxZ;
} Box;

extern Box walls[MAX_WALLS];
extern int wallCount;
extern float playerRadius;

void resetWalls();
void addWallFromPoints(float x1, float z1, float x2, float z2);
int checkCollision(float nextX, float nextZ);

// ================== BALOK ==================
static void _drawBalokFaces(
    float x1, float y1, float z1,
    float x2, float y2, float z2);
    
void BalokWarna(
    float x1, float y1, float z1,
    float x2, float y2, float z2,
    Color c);

void BalokTex(
    float x1, float y1, float z1,
    float x2, float y2, float z2,
    GLuint tex);
    
static void Wall(
    float x1, float y1, float z1,
    float x2, float y2, float z2,
    Color c);

void WallTex(
    float x1, float y1, float z1,
    float x2, float y2, float z2,
    GLuint tex);

// ================== GOAL AREA ==================
#define MAX_GOALS 10
struct GoalArea
{
    float minX, maxX;
    float minZ, maxZ;
};

extern GoalArea goals[MAX_GOALS];

extern int goalCount;
extern bool gameFinished;

void addGoal(float minX, float maxX, float minZ, float maxZ);
int checkGoal(float playerX, float playerZ);

#endif
