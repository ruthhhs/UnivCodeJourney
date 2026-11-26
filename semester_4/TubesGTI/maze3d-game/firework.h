#ifndef FIREWORK_H
#define FIREWORK_H

#define MAX_PARTICLES 100
#define MAX_FIREWORKS 12

struct Particle
{
    float x, y, z;
    float vx, vy, vz;
    float life;
};

struct Firework
{
    float rocketX, rocketY, rocketZ;
    float targetY;

    bool rocketActive;
    bool fired;

    int delay;
    int delayTimer;
    int repeatTimer;

    Particle particles[MAX_PARTICLES];
};

extern Firework fireworks[MAX_FIREWORKS];
extern int fireworkCount;
extern bool showFirework;

void updateFirework();
void drawFirework();
void firework(float targetX, float targetZ, float maxHeight, int delay);

#endif

