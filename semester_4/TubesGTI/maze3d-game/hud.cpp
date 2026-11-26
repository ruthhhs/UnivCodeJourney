#include <math.h>
#include <GL/glut.h>
#include <stdio.h>

#include "hud.h"

// ================== TEXT ==================
void renderChar(char c)
{
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
}

void renderText(int screenX, int screenY, const char *text)
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);

    glRasterPos2i(screenX, screenY);

    for (int i = 0; text[i] != '\0'; i++)
    {
        renderChar(text[i]);
    }

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

// ================== OVERLAY HITAM ==================
void drawOverlay(float alpha)
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glColor4f(0.0f, 0.0f, 0.0f, alpha);
    glBegin(GL_QUADS);
        glVertex2i(0, 0);
        glVertex2i(w, 0);
        glVertex2i(w, h);
        glVertex2i(0, h);
    glEnd();

    glDisable(GL_BLEND);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

// ================== DISPLAYS ==================
// main menu
void displayMainMenu()
{
    drawOverlay(0.4f);

    glColor3f(kuning.r, kuning.g, kuning.b);

    renderText(w/2 - 60, h/2 + 100, "MAZE 3D GAME");
    
    renderText(w/2 - 90, h/2 + 40,	"[1] Play as Player");
    renderText(w/2 - 90, h/2,		"[2] Play as Developer");
    renderText(w/2 - 90, h/2 - 40,	"[3] Exit");
}

// pause
void displayPauseMenu()
{
    drawOverlay(0.6f);

    glColor3f(kuning.r, kuning.g, kuning.b);

    renderText(w/2 - 50, h/2 + 80, "PAUSED");

	renderText(w/2 - 100, h/2 + 40,	"[1] Return to Play");
    renderText(w/2 - 100, h/2,		"[2] Restart Game");
    renderText(w/2 - 100, h/2 - 40,	"[3] Back to Main Menu");
}

// game over
void displayGameOver()
{
    drawOverlay(0.5f);

    glColor3f(merah.r, merah.g, merah.b);
    renderText(w/2 - 40, h/2 + 100, "GAME OVER");

    char countdown[64];
    int sisa = (int)ceil(3.0f - respawnTimer);

    glColor3f(kuning.r, kuning.g, kuning.b);
    sprintf(countdown, "Restart in %d", sisa);
    renderText(w/2 - 50, h/2 + 80, countdown);
}

// goal
void displayWinGame()
{
	drawOverlay(0.2f);
	
	glColor3f(kuning.r, kuning.g, kuning.b);
    renderText(w/2 - 50, h/2 + 100, "GAME FINISHED !");
    
    renderText(w/2 - 100, h/2,		"[1] Play Again");
    renderText(w/2 - 100, h/2 - 40,	"[2] Back to Main Menu");
}

// ================== DISPLAY HUD ==================
void drawHUD()
{
    char buf[128];
    
	if (showMainMenu)	{ displayMainMenu();	return;}
	if (paused)			{ displayPauseMenu();	return;}
	if (gameOver)		{ displayGameOver();	}
	if (winGame)		{ displayWinGame();		}
	
	glColor3f(kuning.r, kuning.g, kuning.b);
	renderText(w/2, h/2, "+");
    
	if (developerMode)
	{
		float angleDeg = angle * (180.0f / 3.14159265f);
	    sprintf(buf, "X: %.2f  Y: %.2f  Z: %.2f", x, y, z);	renderText(10, h - 20, buf);
	    sprintf(buf, "Angle: %.1f deg", angleDeg);			renderText(10, h - 40, buf);
	    sprintf(buf, "View: %s", topView ? "TOP" : "FPS");	renderText(10, h - 60, buf);
	    
		renderText(10, 30, "WASD: Move | Arrow: Rotate | Space: Jump | Shift: Sprint | T: Toggle View");
	}
	else
	{
		renderText(10, h - 20, "ESC to pause game");
		renderText(10, 30, "WASD: Move | Arrow: Rotate | Space: Jump | Shift: Sprint");
	}
}



