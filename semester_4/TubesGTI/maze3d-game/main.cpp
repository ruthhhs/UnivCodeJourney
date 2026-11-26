#include <math.h>
#include <GL/glut.h>
#include <stdio.h>

#include "lighting.h"
#include "hud.h"
#include "maze.h"
#include "cammove.h"

// ============================================================
// Init
// ============================================================
void initGL(void)
{
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glShadeModel(GL_SMOOTH);
    glClearColor(skyblue.r, skyblue.g, skyblue.b, 1.00f);
}

// ============================================================
// Display
// ============================================================
void display()
{
    keyboardSpecial();
	updateCamera();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	applyCamera();

    disableLighting();
    drawLantai(texGrass);
    enableLighting();

    resetWalls();
    drawMaze();
    drawHUD();
	if (winGame)
	{
	    updateFirework();
	    drawFirework();
	}

    glutSwapBuffers();
}

// ============================================================
// Main
// ============================================================
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1024, 600);
    glutCreateWindow("Maze 3D");
    
    glutIgnoreKeyRepeat(1);

	// calbacks
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutReshapeFunc(Reshape);

    glutSpecialFunc(pressKey);
    glutSpecialUpFunc(releaseKey);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);

	// inits
    initGL();
    initLighting();
    initRendering();
    
    lastTime = glutGet(GLUT_ELAPSED_TIME);

    glutMainLoop();
    return 0;
}
