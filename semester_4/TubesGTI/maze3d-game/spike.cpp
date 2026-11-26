#include <math.h>
#include <GL/glut.h>

#include "spike.h"

Spike spikes[MAX_SPIKES];
int spikeCount = 0;

void resetSpikes() {
    spikeCount = 0;
}

void drawSpike(float x, float z) {
    // add spike
    int exists = 0;
    for (int i = 0; i < spikeCount; i++) {
        if (spikes[i].x == x && spikes[i].z == z) {
            exists = 1;	break;	}
    }

    if (!exists && spikeCount < MAX_SPIKES) {
        spikes[spikeCount].x = x;
        spikes[spikeCount].z = z;
        spikeCount++;
    }

    // animasi
    float time = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
    float offset = (x + z) * 0.3f;
    float cycle = fmod(time + offset, 4.0f);
    float y = -1.0f;
    
    if (cycle < 1.0f) {	y = -1.0f + cycle;
    } else if (cycle < 2.5f) {	y = 0.0f;
    } else if (cycle < 3.5f) {	y = 0.0f - (cycle - 2.5f);
    } else {	y = -1.0f;}

    if (y <= -0.95f)	return;

    glPushMatrix();
    glTranslatef(x, y, z);
    glColor3f(0.36f, 0.25f, 0.20f);
    glRotatef(-90, 1, 0, 0);
    glutSolidCone(0.3f, 1.0f, 10, 10);
    glPopMatrix();
}

int checkSpikeCollision(float px, float py, float pz) {
	if (developerMode) return 0;
	
    for (int i = 0; i < spikeCount; i++) {
        float sx = spikes[i].x;
        float sz = spikes[i].z;
        float time = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
        float offset = (i + 1) * 0.3f;
        float cycle = fmod(time + offset, 4.0f);
        float y = -1.0f;

        // posisi animasi spike
        if (cycle < 1.0f) {
			y = -1.0f + cycle;
        } else if (cycle < 2.5f) {
			y = 0.0f;
        } else if (cycle < 3.5f) {
            y = 0.0f - (cycle - 2.5f);
        } else {
		    y = -1.0f;
		}

        float dx = px - sx;
        float dz = pz - sz;
        float dist = sqrt(dx * dx + dz * dz);

        if (dist > 0.8f)
            continue;

		float spikeTop = y + 2.2f;
		
		if (py >= y - 1.0f && py <= spikeTop) {
		    return 1;
		}
    }
    
    return 0;
}
