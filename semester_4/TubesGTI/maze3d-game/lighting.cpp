#include <math.h>
#include <GL/glut.h>
#include <stdio.h>

#include "lighting.h"

// ================== LIGHTING ==================
void initLighting()
{
    const GLfloat light_ambient[]  = { 0.08f, 0.08f, 0.10f, 1.0f };
    const GLfloat light_diffuse[]  = { 1.0f, 0.95f, 0.85f, 1.0f };
    const GLfloat light_specular[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    const GLfloat light_position[] = { 0.0f, 20.0f, 10.0f, 1.0f };

    const GLfloat mat_ambient[]    = { 0.3f, 0.3f, 0.3f, 1.0f };
    const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
    const GLfloat mat_specular[]   = { 0.9f, 0.9f, 0.9f, 1.0f };
    const GLfloat high_shininess[] = { 100.0f };

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

// Matikan lighting sementara (misal untuk grid/HUD)
void disableLighting() { glDisable(GL_LIGHTING); }
void enableLighting()  { glEnable(GL_LIGHTING);  }


// ================== SHADOW ==================
float shadowDirX = 0.6f;
float shadowDirZ = 0.4f;

void drawShadowBox(float x1, float z1, float x2, float z2)
{
    glDisable(GL_LIGHTING);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    int layers = 8;

    for (int i = 0; i < layers; i++)
    {
        float t = (float)i / (layers - 1);

        float dx = shadowDirX * t * 2.5f;
        float dz = shadowDirZ * t * 2.5f;
        float expand = t * 1.8f;

        float a = (1.0f - t);
        a = a * a * 0.4f;

        glColor4f(0, 0, 0, a);
        glBegin(GL_QUADS);
            glVertex3f(x1 + dx - expand, 0.02f, z1 + dz - expand);
            glVertex3f(x2 + dx + expand, 0.02f, z1 + dz - expand);
            glVertex3f(x2 + dx + expand, 0.02f, z2 + dz + expand);
            glVertex3f(x1 + dx - expand, 0.02f, z2 + dz + expand);
        glEnd();
    }

    glDisable(GL_BLEND);
    glEnable(GL_LIGHTING);
}

void drawCircleShadow(float x, float z, float r)
{
    glDisable(GL_LIGHTING);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_POLYGON_OFFSET_FILL);
    glPolygonOffset(-2.0f, -2.0f);

    glDepthMask(GL_FALSE);

    int seg = 32;

    glColor4f(0, 0, 0, 0.20f);

    glBegin(GL_POLYGON);
    for(int i = 0; i < seg; i++)
    {
        float a = i * 2 * M_PI / seg;

        glVertex3f(
            x + cos(a) * r,
            0.01f,
            z + sin(a) * r
        );
    }
    glEnd();

    glDepthMask(GL_TRUE);
    glDisable(GL_POLYGON_OFFSET_FILL);
    glDisable(GL_BLEND);
    glEnable(GL_LIGHTING);
}
