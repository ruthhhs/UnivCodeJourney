#include <iostream>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "imageloader.h"

using namespace std;

const float BOX_SIZE = 7.0f; //Panjang tiap sisi kubus
float _angle = 0;            //Rotasi terhadap box

GLuint _textureId1;
GLuint _textureId2;
GLuint _textureId3;
GLuint _textureId4;
GLuint _textureId5;
GLuint _textureId6;

void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 27: //Tekan Escape untuk EXIT
            exit(0);
    }
}

//Membuat gambar menjadi tekstur kemudian berikan ID pada tekstur
GLuint loadTexture(Image* image) {
    GLuint textureId;
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexImage2D(GL_TEXTURE_2D, 
                 0, 
                 GL_RGB, 
                 image->width, 
                 image->height, 
                 0, 
                 GL_RGB, 
                 GL_UNSIGNED_BYTE, 
                 image->pixels);
    return textureId;
}

void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    
    Image* image = loadBMP("tex/bg.bmp");
    _textureId1 = loadTexture(image);
    delete image;
    
    image = loadBMP("tex/wood.bmp");
    _textureId2 = loadTexture(image);
    delete image;
    
    image = loadBMP("tex/daun.bmp");
    _textureId3 = loadTexture(image);
    delete image;
    
    image = loadBMP("tex/grass.bmp");
    _textureId4 = loadTexture(image);
    delete image;
    
    image = loadBMP("tex/leaves.bmp");
    _textureId5 = loadTexture(image);
    delete image;
    
    image = loadBMP("tex/grass-with-path.bmp");
    _textureId6 = loadTexture(image);
    delete image;
}

void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);
}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -20.0f);

    GLfloat ambientLight[] = {0.3f, 0.3f, 0.3f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
    
    GLfloat lightColor[] = {0.7f, 0.7f, 0.7f, 1.0f};
    GLfloat lightPos[] = {-2 * BOX_SIZE, BOX_SIZE, 4 * BOX_SIZE, 1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    
    glRotatef(-_angle, 1.0f, 1.0f, 0.0f);
    
    glEnable(GL_TEXTURE_2D);
    
    //Sisi atas
	glBindTexture(GL_TEXTURE_2D, _textureId1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	glColor3f(1.0f, 1.0f, 1.0f); // putih
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0f, 0.0f);
    glTexCoord2f(0,0); glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
    glTexCoord2f(1,0); glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
    glTexCoord2f(1,1); glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
    glTexCoord2f(0,1); glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
    glEnd();
    
    //Sisi bawah
    glBindTexture(GL_TEXTURE_2D, _textureId2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	glColor3f(1.0f, 1.0f, 1.0f); // putih
    glBegin(GL_QUADS);
    glNormal3f(0.0, -1.0f, 0.0f);
    glTexCoord2f(0,0); glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
    glTexCoord2f(1,0); glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
    glTexCoord2f(1,1); glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
    glTexCoord2f(0,1); glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
    glEnd();
    
    //Sisi kiri
    glBindTexture(GL_TEXTURE_2D, _textureId3);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	glColor3f(1.0f, 1.0f, 1.0f); // putih
    glBegin(GL_QUADS);
    glNormal3f(-1.0, 0.0f, 0.0f);
    glTexCoord2f(0,0); glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
    glTexCoord2f(1,0); glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
    glTexCoord2f(1,1); glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
    glTexCoord2f(0,1); glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
    glEnd();
    
    //Sisi kanan
    glBindTexture(GL_TEXTURE_2D, _textureId4);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	glColor3f(1.0f, 1.0f, 1.0f); // putih
    glBegin(GL_QUADS);
    glNormal3f(1.0, 0.0f, 0.0f);
    glTexCoord2f(0,0); glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
    glTexCoord2f(1,0); glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
    glTexCoord2f(1,1); glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
    glTexCoord2f(0,1); glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
    glEnd();
    
    //Sisi depan
    glBindTexture(GL_TEXTURE_2D, _textureId5);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	glColor3f(1.0f, 1.0f, 1.0f); // putih
    glBegin(GL_QUADS);
    glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0,0); glVertex3f(-BOX_SIZE/2,-BOX_SIZE/2, BOX_SIZE/2);
	glTexCoord2f(1,0); glVertex3f( BOX_SIZE/2,-BOX_SIZE/2, BOX_SIZE/2);
	glTexCoord2f(1,1); glVertex3f( BOX_SIZE/2, BOX_SIZE/2, BOX_SIZE/2);
	glTexCoord2f(0,1); glVertex3f(-BOX_SIZE/2, BOX_SIZE/2, BOX_SIZE/2);
	glEnd();
    
    //Sisi belakang
    glBindTexture(GL_TEXTURE_2D, _textureId6);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	glColor3f(1.0f, 1.0f, 1.0f); // putih
    glBegin(GL_QUADS);
	glTexCoord2f(0,0); glVertex3f( BOX_SIZE/2,-BOX_SIZE/2,-BOX_SIZE/2);
	glTexCoord2f(1,0); glVertex3f(-BOX_SIZE/2,-BOX_SIZE/2,-BOX_SIZE/2);
	glTexCoord2f(1,1); glVertex3f(-BOX_SIZE/2, BOX_SIZE/2,-BOX_SIZE/2);
	glTexCoord2f(0,1); glVertex3f( BOX_SIZE/2, BOX_SIZE/2,-BOX_SIZE/2);
	glEnd();
    
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

//Panggil setiap 25ms
void update(int value) {
    _angle += 1.0f;
    if (_angle > 360) {
        _angle -= 360;
    }
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Texture With Image");
    initRendering();
    glClearColor(0.5f, 0.5f, 1.0f, 1.0f);
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
    glutReshapeFunc(handleResize);
    glutTimerFunc(25, update, 0);
    glutMainLoop();
    return 0;
}
