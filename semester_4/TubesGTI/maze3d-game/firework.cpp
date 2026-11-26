#include <cmath>
#include <GL/glut.h>
#include "firework.h"

Firework fireworks[MAX_FIREWORKS];
int fireworkCount = 0;
bool showFirework = false;

// ================= INIT PARTIKEL =================
static void initParticles(Firework& fw)
{
    float speed = 0.12f;

    for (int i = 0; i < MAX_PARTICLES; i++)
    {
        float angle  = (2.0f * 3.14159f * i) / MAX_PARTICLES;
        float spread = (i % 5) * 0.012f;

        fw.particles[i].x = fw.rocketX;
        fw.particles[i].y = fw.rocketY;
        fw.particles[i].z = fw.rocketZ;

        fw.particles[i].vx = cosf(angle) * (speed + spread);
        fw.particles[i].vz = sinf(angle) * (speed + spread);
        fw.particles[i].vy = 0.05f + (i % 8) * 0.01f;

        fw.particles[i].life = 1.0f;
    }
}

// ================= UPDATE =================
void updateFirework()
{
    if (!showFirework) return;

    for (int i = 0; i < fireworkCount; i++)
    {
        Firework& fw = fireworks[i];

        // ===== Delay sebelum tembak =====
        if (!fw.fired)
        {
            fw.delayTimer++;

            if (fw.delayTimer >= fw.delay)
            {
                fw.fired = true;
                fw.rocketActive = true;
                fw.rocketY = 0.5f;
            }

            continue;
        }

        // ===== Roket naik =====
        if (fw.rocketActive)
        {
            fw.rocketY += 0.08f;
            if (fw.rocketY >= fw.targetY)
            {
                fw.rocketActive = false;
                initParticles(fw);
                fw.repeatTimer = 0;
            }
            continue;
        }

        // ===== Update partikel =====
        for (int j = 0; j < MAX_PARTICLES; j++)
        {
            Particle& p = fw.particles[j];

            if (p.life > 0.0f)
            {
                p.x += p.vx;
                p.y += p.vy;
                p.z += p.vz;

                p.vy -= 0.004f;

                p.life -= 0.005f + (1.0f - p.life) * 0.003f;

                p.vx *= 0.98f;
                p.vz *= 0.98f;
            }
        }

        // ===== Auto repeat =====
        fw.repeatTimer++;

        if (fw.repeatTimer > 150)
        {
            fw.fired = true;
            fw.rocketActive = true;
            fw.rocketY = 0.5f;

            fw.repeatTimer = 0;
        }
    }
}

// ================= DRAW =================
void drawFirework()
{
    if (!showFirework) return;

    for (int i = 0; i < fireworkCount; i++)
    {
        Firework& fw = fireworks[i];

        // ===== Roket =====
        if (fw.rocketActive)
        {
            glLineWidth(3.0f);
            glBegin(GL_LINES);
            glColor3f(1.0f, 1.0f, 0.0f);
            glVertex3f(fw.rocketX, fw.rocketY, fw.rocketZ);
            glColor3f(1.0f, 0.3f, 0.0f);
            glVertex3f(fw.rocketX, fw.rocketY - 0.4f, fw.rocketZ);
            glEnd();
            glPointSize(8.0f);
            glBegin(GL_POINTS);
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex3f(fw.rocketX, fw.rocketY, fw.rocketZ);
            glEnd();
        }

        // ===== Partikel =====
        glPointSize(6.0f);
        glBegin(GL_POINTS);

        for (int j = 0; j < MAX_PARTICLES; j++)
        {
            Particle& p = fw.particles[j];
            if (p.life > 0.0f)
            {
                float l = p.life;
                if (j % 3 == 0)
                    glColor3f(1.0f, 0.2f * l, 0.2f * l);
                else if (j % 3 == 1)
                    glColor3f(1.0f, 1.0f * l, 0.2f * l);
                else
                    glColor3f(0.2f * l, 1.0f, 1.0f * l);
                glVertex3f(p.x, p.y, p.z);
            }
        }
        glEnd();
    }
}

// ================= TRIGGER =================
void firework(float targetX, float targetZ, float maxHeight, int delay)
{
    if (fireworkCount >= MAX_FIREWORKS)
        return;

    // ===== Cek firework sudah ada =====
    for (int i = 0; i < fireworkCount; i++)
    {
        if (fireworks[i].rocketX == targetX &&
            fireworks[i].rocketZ == targetZ)
        {
            return;
        }
    }

    Firework& fw = fireworks[fireworkCount++];

    fw.rocketX = targetX;
    fw.rocketY = 0.5f;
    fw.rocketZ = targetZ;

    fw.targetY = maxHeight;

    fw.rocketActive = false;
    fw.fired = false;

    fw.delay = delay;
    fw.delayTimer = 0;
    fw.repeatTimer = 0;

    showFirework = true;
}
