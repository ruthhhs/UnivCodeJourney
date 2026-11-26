#include <math.h>
#include <GL/glut.h>
#include <stdio.h>

#include "coltex.h"

// ================== WARNA ==================
Color merah = {1.0f, 0.0f, 0.0f};
Color hijau = {0.0f, 1.0f, 0.0f};
Color biru  = {0.0f, 0.0f, 1.0f};
Color putih = {1.0f, 1.0f, 1.0f};
Color abu   = {0.5f, 0.5f, 0.5f};
Color kuning= {1.0f, 1.0f, 0.0f};

Color skyblue= {0.65f, 0.65f, 1.0f};
Color daun 	= {0.18f, 0.52f, 0.10f};
Color batang= {0.35f, 0.20f, 0.07f};

// ================== TEXTURE ==================
GLuint loadTexture(Image* image)
{
    GLuint textureId;
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGB,
        image->width,
        image->height,
        0,
        GL_RGB,
        GL_UNSIGNED_BYTE,
        image->pixels
    );

    return textureId;
}

#define TEX_PATH "tex/"
GLuint texWall;
GLuint texGrass;

void initRendering()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_TEXTURE_2D);

    // masukin img ke kamus texture
    Image* img;

	img = loadBMP(TEX_PATH "leaves.bmp");
	texWall = loadTexture(img);
	printf("texWall = %d\n", texWall);
	
	img = loadBMP(TEX_PATH "grass.bmp");
	texGrass = loadTexture(img);
	printf("texGrass = %d\n", texGrass);
	delete img;	
}

void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);
}

