#include <math.h>
#include <GL/glut.h>
#include <stdio.h>

#include "hole.h"

// ==================== LUBANG ====================
Hole holes[MAX_HOLES];
int holeCount = 0;

void addHole(float x1, float y1, float z1, float x2, float y2, float z2) {
    if (holeCount >= MAX_HOLES)
        return;
        
    holes[holeCount].minX = x1 < x2 ? x1 : x2;
    holes[holeCount].maxX = x1 > x2 ? x1 : x2;

    holes[holeCount].minY = y1 < y2 ? y1 : y2;
    holes[holeCount].maxY = y1 > y2 ? y1 : y2;

    holes[holeCount].minZ = z1 < z2 ? z1 : z2;
    holes[holeCount].maxZ = z1 > z2 ? z1 : z2;

    holeCount++;
}

int checkHole(float px, float py, float pz) {
	if (developerMode) return 0;
	
    for (int i = 0; i < holeCount; i++) {

        if (
            px > holes[i].minX &&
            px < holes[i].maxX &&

            py > holes[i].minY &&
            py < holes[i].maxY &&

            pz > holes[i].minZ &&
            pz < holes[i].maxZ
        )
        {
            return 1;
        }
    }
    return 0;
}

void drawHole(float cx, float cz, float radius) {
	addHole(
	    cx - radius, 0.0f, cz - radius,
	    cx + radius, 2.0f, cz + radius
	);
    
    glColor3f(0.15f, 0.15f, 0.15f); // warna lubang
    glBegin(GL_TRIANGLE_FAN);

    glVertex3f(cx, 0.05f, cz);		// titik tengah

    // lingkaran
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159f / 180.0f;
        float x = cx + cos(angle) * radius;
        float z = cz + sin(angle) * radius;
        glVertex3f(x, 0.05f, z);
    }
    glEnd();
}
