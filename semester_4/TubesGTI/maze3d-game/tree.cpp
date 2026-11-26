#include <math.h>
#include <GL/glut.h>
#include <stdio.h>

#include "tree.h"

// ================== COLLISION POHON ==================
CircleWall circleWalls[MAX_WALLS];
int circleWallCount = 0;

void addCircleWall(float x, float z, float radius)
{
    if (circleWallCount >= MAX_WALLS) return;

    circleWalls[circleWallCount].x = x;
    circleWalls[circleWallCount].z = z;
    circleWalls[circleWallCount].radius = radius;

    circleWallCount++;
}

bool checkCircleCollision(float newX, float newZ)
{
	if (developerMode) return false;
	
    for (int i = 0; i < circleWallCount; i++)
    {
        float dx = newX - circleWalls[i].x;
        float dz = newZ - circleWalls[i].z;
        float distSq = dx * dx + dz * dz;
        float totalRadius =
            playerRadius + circleWalls[i].radius;
        if (distSq < totalRadius * totalRadius)
        {
            return true;
        }
    }

    return false;
}


// ==================== POHON BESAR ====================
void drawTree(float tx, float tz) {
	drawCircleShadow(tx, tz, 3.0f);			//shadow
	addCircleWall(tx - 0.2, tz + 0.2, 3.0f);//collision
	
    // batang
    glColor3f(batang.r, batang.g, batang.b);
    glPushMatrix();
    glTranslatef(tx, 0, tz);
    glRotatef(-90, 1, 0, 0);
    GLUquadric* q = gluNewQuadric();
    gluCylinder(q, 0.35f, 0.25f, 4.0f, 8, 4);
    gluDeleteQuadric(q);
    glPopMatrix();

    // daun
    float leafColors[3][3] = {
        {0.15f, 0.50f, 0.08f},
        {0.20f, 0.58f, 0.12f},
        {0.25f, 0.65f, 0.15f}
    };
    float layerY[3] = {3.0f, 5.0f, 7.0f};
    float layerRad[3] = {2.3f, 1.7f, 1.2f};

    for (int i = 0; i < 3; i++) {
        glColor3f(
            leafColors[i][0],
            leafColors[i][1],
            leafColors[i][2]
        );
        glPushMatrix();
        glTranslatef(tx, layerY[i], tz);
        glutSolidSphere(layerRad[i], 10, 8);
        glPopMatrix();
    }
}

// ==================== POHON KECIL ====================
void drawSmallTree(float tx, float tz) {
	drawCircleShadow(tx, tz, 1.0f);			//shadow
	addCircleWall(tx - 0.2, tz + 0.2, 0.9f);//collision

    // batang
    glColor3f(batang.r, batang.g, batang.b);
    glPushMatrix();
    glTranslatef(tx, 0, tz);
    glRotatef(-90, 1, 0, 0);
    GLUquadric* q = gluNewQuadric();
    gluCylinder(q, 0.10f, 0.05f, 1.5f, 4, 3);
    gluDeleteQuadric(q);
    glPopMatrix();

    // daun
    glColor3f(daun.r, daun.g, daun.b);
    glPushMatrix();
    glTranslatef(tx, 2.0f, tz);
    glutSolidSphere(1.2f, 8, 7);
    glPopMatrix();
}
