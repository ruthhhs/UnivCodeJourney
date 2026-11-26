#include <math.h>
#include <GL/glut.h>
#include <stdio.h>

#include "semak.h"

// ================== COLLISION SEMAK ==================
SemakWall semakWalls[MAX_WALLS];
int semakWallCount = 0;

void addSemakWall(float x, float z,
                  float radius,
                  float jumpHeight)
{
    if (semakWallCount >= MAX_WALLS) return;

    semakWalls[semakWallCount].x = x;
    semakWalls[semakWallCount].z = z;
    semakWalls[semakWallCount].radius = radius;
    semakWalls[semakWallCount].jumpHeight = jumpHeight;

    semakWallCount++;
}

bool checkSemakCollision(float newX,
                         float newY,
                         float newZ)
{
	if (developerMode) return false;
	
    for (int i = 0; i < semakWallCount; i++)
    {
        float dx = newX - semakWalls[i].x;
        float dz = newZ - semakWalls[i].z;

        float distSq = dx * dx + dz * dz;

        float totalRadius =
            playerRadius + semakWalls[i].radius;

        // tabrakan horizontal
        if (distSq < totalRadius * totalRadius)
        {
            // kalau player belum cukup tinggi
            // berarti masih nabrak semak
            if (newY < semakWalls[i].jumpHeight)
            {
                return true;
            }
        }
    }

    return false;
}

// ==================== SEMAK ====================
void drawSemak(float tx, float tz)
{
    drawCircleShadow(tx, tz, 0.85f);	// shadow
    addSemakWall(tx, tz, 1.0f, 2.0f);	// collision

    // daun bawah kiri
    glColor3f(0.10f, 0.40f, 0.08f);
    glPushMatrix();
    glTranslatef(tx - 0.6, 0.22f, tz);
    glutSolidSphere(0.45f, 12, 12);
    glPopMatrix();

    // daun bawah kanan
    glColor3f(0.10f, 0.40f, 0.08f);
    glPushMatrix();
    glTranslatef(tx + 0.6, 0.22f, tz);
    glutSolidSphere(0.45f, 12, 12);
    glPopMatrix();

    // daun tengah
    glColor3f(0.14f, 0.52f, 0.11f);
    glPushMatrix();
    glTranslatef(tx, 0.42f, tz);
    glutSolidSphere(0.72f, 12, 12);
    glPopMatrix();
}
