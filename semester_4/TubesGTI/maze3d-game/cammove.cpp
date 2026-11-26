#include <math.h>
#include <GL/glut.h>
#include <stdio.h>

#include "cammove.h"

// ======= Variables =======
float angle = 0.0;
float deltaAngle = 0.0;
float ratio;
float x = 10.0f, y = 1.75f, z = -16.0f;
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
int h, w;
float menuAngle = 0.0f;

float deltaPitch = 0.0f;
float pitch = 0.0f;

bool keyW = false;
bool keyS = false;
bool keyA = false;
bool keyD = false;

int sprint = 0;
float velocityY = 0.0f;
int isJumping = 0;
const float gravity = 15.0f;
const float jumpPower = 5.0f;
const float groundY = 1.75f;

bool topView = false;
int lastTime = 0;
float deltaTime = 0.0f;

bool gameOver = false;
bool winGame = false;
float respawnTimer = 0.0f;
float startX = x;
float startY = y;
float startZ = z;

bool deadByHole = false;
bool deadBySpike = false;
float damageFlash = 0.0f;

bool developerMode = false;
bool showMainMenu = true;
bool paused = false;

// ======= Rotasi =======
void orientMe(float ang)
{
    lx = -sin(ang) * cos(pitch);
    ly = sin(pitch);
    lz = cos(ang) * cos(pitch);
}

// ======= Set view matrix =======
void applyCamera()
{
    if (topView)
    {
        gluLookAt(
            x, 130.0f, z,   
            x, 0.0f, z,
            0.0f, 0.0f, -1.0f
        );
    }
    else
    {
        gluLookAt(
            x, y, z,
            x + lx, y + ly, z + lz,
            0.0f, 1.0f, 0.0f
        );
    }
}

// ======= Maju / mundur =======
void moveMeFlat(int i)
{
    float baseSpeed = sprint ? 8.0f : 5.0f;
    if (isJumping)
        baseSpeed *= 1.5f;
    float speed = baseSpeed * deltaTime;

    float nextX = x + i * lx * speed;
    float nextZ = z + i * lz * speed;

    if (!checkCollision(nextX, z) &&
        !checkCircleCollision(nextX, z) &&
        !checkSemakCollision(nextX, y, z))
    {
        x = nextX;
    }

    if (!checkCollision(x, nextZ) &&
        !checkCircleCollision(x, nextZ) &&
        !checkSemakCollision(x, y, nextZ))
    {
        z = nextZ;
    }
}
	
// ======= Strafe =======
void strafeMe(int i)
{
    float baseSpeed = sprint ? 7.0f : 4.0f;
    float speed = baseSpeed * deltaTime;

    float nextX = x + i * lz * speed;
    float nextZ = z - i * lx * speed;

    if (!checkCollision(nextX, z) &&
        !checkCircleCollision(nextX, z) &&
		!checkSemakCollision(nextX, y, z))
    {
        x = nextX;
    }

    if (!checkCollision(x, nextZ) &&
        !checkCircleCollision(x, nextZ) &&
        !checkSemakCollision(x, y, nextZ))
    {
        z = nextZ;
    }
}

// ======= Reshape =======
void Reshape(int w1, int h1)
{
    if (h1 == 0) h1 = 1;

    w = w1;
    h = h1;
    ratio = 1.0f * w / h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45, ratio, 0.1, 1000);

    glMatrixMode(GL_MODELVIEW);
}

// ======= Idle =======
void idle()
{
    if (showMainMenu)
    {
        menuAngle += 0.0005f;

        if (menuAngle > 2.0f * M_PI)
            menuAngle -= 2.0f * M_PI;
    }
    glutPostRedisplay();
}

// ======= Respawn =======
void respawnPoint()
{	
    // posisi awal
    x = startX;
    y = startY;
    z = startZ;

    // rotasi awal
    angle = 0.0f;
    pitch = 0.0f;

    deltaAngle = 0.0f;
    deltaPitch = 0.0f;

    // arah kamera reset
    lx = 0.0f;
    ly = 0.0f;
    lz = -1.0f;

    // movement reset
    keyW = keyS = keyA = keyD = false;
    sprint = 0;

    // jump reset
    velocityY = 0.0f;
    isJumping = 0;

    // state reset
    gameOver = false;
    winGame = false;
    paused = false;
    topView = false;

    deadByHole = false;
    deadBySpike = false;

    damageFlash = 0.0f;
    respawnTimer = 0.0f;
}

// ======= WIN POINT =======
bool checkWinPoint(float targetX, float targetZ, float radius)
{
    float dx = x - targetX;
    float dz = z - targetZ;

    float distance = sqrtf(dx * dx + dz * dz);

    return distance < radius;
}

// ======= RESET KEYS ASWD =======
void resetKeys()
{
    keyW = false;
    keyS = false;
    keyA = false;
    keyD = false;

    deltaAngle = 0.0f;
    deltaPitch = 0.0f;

    sprint = 0;
}

// ======= Main Camera Update =======
void updateCamera()
{
    int currentTime = glutGet(GLUT_ELAPSED_TIME);
    deltaTime = (currentTime - lastTime) / 1000.0f;
    lastTime = currentTime;

    angle += deltaAngle * deltaTime;
    pitch += deltaPitch * deltaTime;
    
    if (pitch > 1.5f) pitch = 1.5f;
	if (pitch < -1.5f) pitch = -1.5f;
    orientMe(angle);

    // movement
	if (keyW) moveMeFlat( 2);
	if (keyS) moveMeFlat(-2);
	if (keyA) strafeMe( 2);
	if (keyD) strafeMe(-2);

	// jump physics
    if (isJumping){
        velocityY -= gravity * deltaTime;
        y += velocityY * deltaTime;

        if (y <= groundY)
        {
            y = groundY;
            velocityY = 0;
            isJumping = 0;
        }
    }

	// masuk hole
	if (!gameOver)
	{
	    if (checkHole(x, y, z))
	    {
	        gameOver = true;
	        resetKeys();
	        deadByHole = true;
	        deadBySpike = false;
	
	        respawnTimer = 0.0f;
	    }
	
	    else if (checkSpikeCollision(x, y, z))
	    {
	        gameOver = true;
	        resetKeys();
	        deadBySpike = true;
	        deadByHole = false;
	        damageFlash = 0.5f;
	
	        respawnTimer = 0.0f;
	    }
	}

	// game over
	if (gameOver) {
		// hole -> jatuh
	    if (deadByHole) {
	        y -= 5.0f * deltaTime;
	        if (y <= -3.0f) {
	            y = -3.0f;
	        }
	    }
	
	    // spike -> gelap
	    if (deadBySpike) {
			damageFlash -= deltaTime;		
			if (damageFlash < 0.0f)
			    damageFlash = 0.0f;
	    }

	    respawnTimer += deltaTime;
	    if (respawnTimer >= 3.0f) {
	        respawnPoint();
	    }
	}
	
	// cek menang
	if (!winGame) 
	{
	    if (checkWinPoint(65.0f, -9.5f, 1.5f) ||
	        checkWinPoint(-40.5f, -10.0f, 2.5f) ||
	        checkWinPoint(10.0f, -59.0f, 2.5f) ||
	        checkWinPoint(16.5f, 49.5f, 3.5f))
	    {
	        winGame = true;
	        resetKeys();
	    }
	}

	// main menu
	if (showMainMenu){
	    float radius = 20.0f;
	
	    x = startX + cos(menuAngle) * radius;
	    z = startZ + sin(menuAngle) * radius;
	    y = startY + 7.0f;
	    pitch = -0.2f;
	
	    angle = menuAngle + M_PI;
	    orientMe(angle);
	}
}

// ======= Keyboard Press =======
void pressKey(int key, int xx, int yy)
{
    switch (key)
    {
        case GLUT_KEY_LEFT:
            deltaAngle = -2.0f;
            break;

        case GLUT_KEY_RIGHT:
            deltaAngle = 2.0f;
            break;

        case GLUT_KEY_UP:
            deltaPitch = 2.0f;
            break;

        case GLUT_KEY_DOWN:
            deltaPitch = -2.0f;
            break;
    }
}

void releaseKey(int key, int xx, int yy)
{
    switch (key)
    {
        case GLUT_KEY_LEFT:
        case GLUT_KEY_RIGHT: deltaAngle = 0.0f; break;
        
        case GLUT_KEY_UP:
        case GLUT_KEY_DOWN:
            deltaPitch = 0.0f;
            break;
    }
}


// ======= Keyboard Input =======
void keyboard(unsigned char key, int xx, int yy)
{
    if (gameOver) return;

    if (showMainMenu){
        switch(key)
        {
            case '1':	developerMode = false; 	showMainMenu = false; respawnPoint();	break;
            case '2':	developerMode = true; 	showMainMenu = false; respawnPoint();	break;
            case '3':	exit(0);break;
        }
        return;}

    if (paused){
        switch(key)
        {
            case '1':	paused = false;	break;
            case '2':	paused = false;	respawnPoint();	break;
            case '3':	paused = false;	respawnPoint(); showMainMenu = true; developerMode = false;	break;
        }
        return;}
        
    if (winGame){
        switch(key)
        {
            case '1':	paused = false;	respawnPoint();	break;
            case '2':	paused = false;	respawnPoint(); showMainMenu = true; developerMode = false;	break;
        }
        return;}

    if (key == 27) {paused = true;}
    
    switch (key)
    {
        case 'w': case 'W': keyW = true; break;
        case 's': case 'S': keyS = true; break;
        case 'a': case 'A': keyA = true; break;
        case 'd': case 'D': keyD = true; break;
        
        case ' ':
            if (!isJumping)
            {
                isJumping = 1;
                velocityY = jumpPower;
            }
            break;
        
        case 't': case 'T':
			if (developerMode) 
			{
				topView = !topView;
			} break;
    }
}

void keyboardUp(unsigned char key, int xx, int yy) {
    switch (key) {
        case 'w': case 'W': keyW = false; break;
        case 's': case 'S': keyS = false; break;
        case 'a': case 'A': keyA = false; break;
        case 'd': case 'D': keyD = false; break;
    }
}

void keyboardSpecial()
{
    int mod = glutGetModifiers();

    if (mod & GLUT_ACTIVE_SHIFT)
        sprint = 1;
    else
        sprint = 0;
}

