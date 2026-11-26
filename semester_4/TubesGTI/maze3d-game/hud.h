// ========================================================
// HUD
// Display text and game ui
// ========================================================
#ifndef HUD_H_INCLUDED
#define HUD_H_INCLUDED

#include "cammove.h"
#include "coltex.h"
#include "firework.h"

extern char countdown;
extern int sisa;

void renderChar(char c);
void renderText(int screenX, int screenY, const char *text);

void drawOverlay(float alpha);
void displayMainMenu();
void displayGameOver();
void drawHUD();
void drawWinText();;
#endif
