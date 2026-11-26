// ============================================================
// Color and Texture
// ============================================================
#ifndef COLTEX_H_INCLUDED
#define COLTEX_H_INCLUDED

#include "imageloader.h"

// ================== WARNA ==================
typedef struct {
    float r, g, b;
} Color;

extern Color merah;
extern Color hijau;
extern Color biru;
extern Color putih;
extern Color abu;
extern Color kuning;

extern Color skyblue;
extern Color daun;
extern Color batang;

// ================== TEXTURE ==================
extern GLuint texGrass;
extern GLuint texWall;

extern GLuint loadTexture(Image* image);
void initRendering();
void handleResize(int w, int h);

#endif
