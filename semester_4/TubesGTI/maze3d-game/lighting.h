// ============================================================
// Lighting
// ============================================================
#ifndef LIGHTING_H_INCLUDED
#define LIGHTING_H_INCLUDED

void initLighting();
void disableLighting();
void enableLighting();

void drawFakeShadow(float x, float z, float size);
void drawShadowBox(float x1, float z1, float x2, float z2);
void drawCircleShadow(float x, float z, float r);

#endif
