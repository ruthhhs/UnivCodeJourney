#include <math.h>
#include <GL/glut.h>
#include <stdio.h>

#include "geometri.h"

// ================== LANTAI ==================
void Grid()
{
    double i;
    const float Z_MIN = -LUAS_LANTAI;
    const float Z_MAX = LUAS_LANTAI;
    const float X_MIN = -LUAS_LANTAI;
    const float X_MAX = LUAS_LANTAI;
    const float gap = 2;

    glColor3f(0.5, 0.5, 0.5);

    glBegin(GL_LINES);
    for (float i = X_MIN; i <= X_MAX; i += 1.5)
    {
        glVertex3f(i, 0, -LUAS_LANTAI);
        glVertex3f(i, 0, LUAS_LANTAI);

        glVertex3f(-LUAS_LANTAI, 0, i);
        glVertex3f(LUAS_LANTAI, 0, i);
    }
    glEnd();
}

void lantaiTex(GLuint tex)
{
    float repeat = LUAS_LANTAI / 4.0f;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex);

    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);
        glNormal3f(0,1,0);
        glTexCoord2f(0,0);			glVertex3f(-LUAS_LANTAI, -0.01, -LUAS_LANTAI);
        glTexCoord2f(repeat,0);		glVertex3f( LUAS_LANTAI, -0.01, -LUAS_LANTAI);
        glTexCoord2f(repeat,repeat);glVertex3f( LUAS_LANTAI, -0.01,  LUAS_LANTAI);
        glTexCoord2f(0,repeat);		glVertex3f(-LUAS_LANTAI, -0.01,  LUAS_LANTAI);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void drawLantai(GLuint tex)
{
	if(developerMode){
		Grid();
	}
	else
	{
		lantaiTex(tex);
	}
}

// ================== COLLISION WALL ==================
Box walls[MAX_WALLS];

int wallCount = 0;
float playerRadius = 0.4f;

void resetWalls()
{
    wallCount = 0;
}

void addWallFromPoints(float x1, float z1, float x2, float z2)
{
    if (wallCount >= MAX_WALLS) return;

    float minX = x1 < x2 ? x1 : x2;
    float maxX = x1 > x2 ? x1 : x2;
    float minZ = z1 < z2 ? z1 : z2;
    float maxZ = z1 > z2 ? z1 : z2;

    walls[wallCount].minX = minX;
    walls[wallCount].maxX = maxX;
    walls[wallCount].minZ = minZ;
    walls[wallCount].maxZ = maxZ;
    wallCount++;
}

int checkCollision(float nextX, float nextZ)
{
	if (developerMode) return false;
	
    for (int i = 0; i < wallCount; i++)
    {
        if (nextX + playerRadius > walls[i].minX &&
            nextX - playerRadius < walls[i].maxX &&
            nextZ + playerRadius > walls[i].minZ &&
            nextZ - playerRadius < walls[i].maxZ)
        {
            return 1;
        }
    }
    return 0;
}

// ================== BALOK ==================
static void _drawBalokFaces(
    float x1, float y1, float z1,
    float x2, float y2, float z2)
{
    float minX = x1 < x2 ? x1 : x2;
    float maxX = x1 > x2 ? x1 : x2;
    float minY = y1 < y2 ? y1 : y2;
    float maxY = y1 > y2 ? y1 : y2;
    float minZ = z1 < z2 ? z1 : z2;
    float maxZ = z1 > z2 ? z1 : z2;

    float sizeX = fabs(maxX - minX);
    float sizeY = fabs(maxY - minY);
    float sizeZ = fabs(maxZ - minZ);

    // skala repeat (ubah angka 2.0 sesuai kebutuhan)
    float repX = sizeX / 2.0f;
    float repY = sizeY / 2.0f;
    float repZ = sizeZ / 2.0f;

    glBegin(GL_QUADS);

    // DEPAN (+Z) -> pakai X,Y
    glNormal3f(0,0,1);
    glTexCoord2f(0,0);         glVertex3f(minX,minY,maxZ);
    glTexCoord2f(repX,0);      glVertex3f(maxX,minY,maxZ);
    glTexCoord2f(repX,repY);   glVertex3f(maxX,maxY,maxZ);
    glTexCoord2f(0,repY);      glVertex3f(minX,maxY,maxZ);

    // BELAKANG (-Z) -> pakai X,Y
    glNormal3f(0,0,-1);
    glTexCoord2f(0,0);         glVertex3f(minX,minY,minZ);
    glTexCoord2f(repX,0);      glVertex3f(maxX,minY,minZ);
    glTexCoord2f(repX,repY);   glVertex3f(maxX,maxY,minZ);
    glTexCoord2f(0,repY);      glVertex3f(minX,maxY,minZ);

    // ATAS (+Y) -> pakai X,Z
    glNormal3f(0,1,0);
    glTexCoord2f(0,0);         glVertex3f(minX,maxY,minZ);
    glTexCoord2f(repX,0);      glVertex3f(maxX,maxY,minZ);
    glTexCoord2f(repX,repZ);   glVertex3f(maxX,maxY,maxZ);
    glTexCoord2f(0,repZ);      glVertex3f(minX,maxY,maxZ);

    // BAWAH (-Y) -> pakai X,Z
    glNormal3f(0,-1,0);
    glTexCoord2f(0,0);         glVertex3f(minX,minY,minZ);
    glTexCoord2f(repX,0);      glVertex3f(maxX,minY,minZ);
    glTexCoord2f(repX,repZ);   glVertex3f(maxX,minY,maxZ);
    glTexCoord2f(0,repZ);      glVertex3f(minX,minY,maxZ);

    // KANAN (+X) -> pakai Z,Y
    glNormal3f(1,0,0);
    glTexCoord2f(0,0);         glVertex3f(maxX,minY,minZ);
    glTexCoord2f(repZ,0);      glVertex3f(maxX,minY,maxZ);
    glTexCoord2f(repZ,repY);   glVertex3f(maxX,maxY,maxZ);
    glTexCoord2f(0,repY);      glVertex3f(maxX,maxY,minZ);

    // KIRI (-X) -> pakai Z,Y
    glNormal3f(-1,0,0);
    glTexCoord2f(0,0);         glVertex3f(minX,minY,minZ);
    glTexCoord2f(repZ,0);      glVertex3f(minX,minY,maxZ);
    glTexCoord2f(repZ,repY);   glVertex3f(minX,maxY,maxZ);
    glTexCoord2f(0,repY);      glVertex3f(minX,maxY,minZ);

    glEnd();
}

// ================== BALOK WARNA & TEXTURE ==================
void BalokWarna(
    float x1, float y1, float z1,
    float x2, float y2, float z2,
    Color c)
{
    glDisable(GL_TEXTURE_2D);
    glColor3f(c.r, c.g, c.b);
    _drawBalokFaces(x1, y1, z1, x2, y2, z2);
}

void BalokTex(
    float x1, float y1, float z1,
    float x2, float y2, float z2,
    GLuint tex)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex);

    glColor3f(1,1,1); // putih
    _drawBalokFaces(x1, y1, z1, x2, y2, z2);

    glDisable(GL_TEXTURE_2D);
}

// ================== DINDING WARNA & TEXTURE ==================
static void Wall(
    float x1, float y1, float z1,
    float x2, float y2, float z2,
    Color c)
{
	drawShadowBox(x1, z1, x2, z2);
    BalokWarna(x1, y1, z1, x2, y2, z2, c);
    addWallFromPoints(x1, z1, x2, z2);
}

void WallTex(
    float x1, float y1, float z1,
    float x2, float y2, float z2,
    GLuint tex)
{
	drawShadowBox(x1, z1, x2, z2);
    BalokTex(x1, y1, z1, x2, y2, z2, tex);
    addWallFromPoints(x1, z1, x2, z2);
}

// ================== GOAL AREA ==================
GoalArea goals[MAX_GOALS];
int goalCount = 0;
bool gameFinished = false;

void addGoal(float minX, float maxX,
             float minZ, float maxZ)
{
    goals[goalCount].minX = minX;
    goals[goalCount].maxX = maxX;
    goals[goalCount].minZ = minZ;
    goals[goalCount].maxZ = maxZ;
    goalCount++;
}

int checkGoal(float playerX, float playerZ)
{
	if (developerMode) return 0;
	
	printf("goalCount = %d\n", goalCount);
	
    for (int i = 0; i < goalCount; i++)
    {
    	printf("checking goal %d\n", i);
        if (playerX + playerRadius > goals[i].minX &&
            playerX - playerRadius < goals[i].maxX &&
            playerZ + playerRadius > goals[i].minZ &&
            playerZ - playerRadius < goals[i].maxZ)
        {
            return 1;
        }
    }
    return 0;
}
