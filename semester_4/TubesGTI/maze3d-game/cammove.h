// ============================================================
// Camera and Movement
// ============================================================
#ifndef CAMMOVE_H_INCLUDED
#define CAMMOVE_H_INCLUDED

#include "maze.h"
#include "geometri.h"

// ======= Variables =======
extern float angle;
extern float deltaAngle;
extern float ratio;
extern float x, y, z;
extern float lx, ly, lz;
extern int h, w;
extern float menuAngle;

extern int sprint;
extern float velocityY;
extern int isJumping;
extern const float gravity;
extern const float jumpPowe;
extern const float groundY;

extern bool topView;
extern int lastTime;
extern float deltaTime;

extern bool gameOver;
extern bool winGame;
extern float respawnTimer;
extern float startX;
extern float startY;
extern float startZ;

extern bool deadByHole;
extern bool deadBySpike;
extern float damageFlash;

extern bool developerMode;
extern bool showMainMenu;
extern bool paused;

// ======= Camera =======
void orientMe(float ang);
void applyCamera();
void moveMeFlat(int i);
void strafeMe(int i);
void Reshape(int w1, int h1);
void idle();
void respawnPoint();
void updateCamera();

// ======= Input keyboard =======
void pressKey(int key, int xx, int yy);
void releaseKey(int key, int xx, int yy);
void keyboard(unsigned char key, int xx, int yy);
void keyboardUp(unsigned char key, int xx, int yy);
void keyboardSpecial();

#endif
