// Nama	: Ruth Septriana Sipangkar
// NIM	: 24060124120024
// Lab	: GTI C2

#include <gl/glut.h>
#include <gl/gl.h>
#include <math.h>

#define PI 3.1415926535898
float rban = 0.12f;
GLint ban_points = 10;

float sudut = 0;
float posisiX = -0.5f;
float speed = 0.005f;

void Ban(float x, float y) {
	glPushMatrix();
		glTranslatef(x, y, 0.0f);
    	glRotatef(sudut, 0.0f, 0.0f, 1.0f);
    	
        glBegin(GL_TRIANGLE_FAN);
        	glColor3f(0.0f, 0.0f, 0.0f);
        	glVertex2f(0.0f, 0.0f);

            for (int i = 0; i <= ban_points; i++) {
                float angle = 2 * PI * i / ban_points;
                glVertex2f(rban * cos(angle),rban * sin(angle));
            }
            
        glEnd();
    glPopMatrix();
}

void Mobil(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // OBJEK UTAMA : Mobil
    glPushMatrix(); 
    	glTranslatef(posisiX, 0.0, 0.0);
    	
    	// OBJEK BAGIAN 1 : Badan Mobil Atas
        glBegin(GL_QUADS);
        	glColor3f(0.3f, 0.3f, 0.7f);
        	
	        glVertex3f(-0.3f, 0.2f, 0.0f);
	        glVertex3f(0.3f, 0.2f, 0.0f);
	        glVertex3f(0.4f, -0.2f, 0.0f);
	        glVertex3f(-0.4f, -0.2f, 0.0f);	        
	        
    	glEnd();
    	
    	// OBJEK BAGIAN  2 : Badan Mobil Bawah
    	glBegin(GL_QUADS);
        	glColor3f(0.3f, 0.3f, 0.7f);
        	
	        glVertex3f(-0.45f, 0.03f, 0.0f);
	        glVertex3f(0.45f, 0.03f, 0.0f);
	        glVertex3f(0.45f, -0.20f, 0.0f);
	        glVertex3f(-0.45f, -0.20f, 0.0f);	        
	        
    	glEnd();
    	
    	 // OBJEK BAGIAN 3: Ban Depan
	    glPushMatrix();
	    	float ax = 0.2f;
			float ay = -0.2f;
			
			glTranslatef(ax, ay, 0.0);
	    	glRotatef(sudut, 0.0f, 0.0f, 1.0f);
	    
	        glBegin(GL_TRIANGLE_FAN);
	        	glColor3f(0.0f, 0.0f, 0.0f);        	
	            for (int i = 0; i <= ban_points; i++) {
	                float angle = 2 * PI * i / ban_points;
	                glVertex2f(rban * cos(angle), rban * sin(angle));
	            }
	    		
	        glEnd();
	    glPopMatrix();
	    
	    // OBJEK BAGIAN 4: Ban Belakang
	    glPushMatrix();
	    	float bx = -0.2f;
			float by = -0.2f;
			
			glTranslatef(bx, by, 0.0);
	    	glRotatef(sudut, 0.0f, 0.0f, 1.0f);
	    	
	        glBegin(GL_TRIANGLE_FAN);
	        	glColor3f(0.0f, 0.0f, 0.0f);
	
	            for (int i = 0; i <= ban_points; i++) {
	                float angle = 2 * PI * i / ban_points;
	                glVertex2f(rban * cos(angle), rban * sin(angle));
	            }
	
	        glEnd();
	    glPopMatrix();
	    
	    // OBJEK BAGIAN  5 : Jendela Belakang
    	glBegin(GL_QUADS);
        	glColor3f(0.9f, 0.9f, 0.9f);
        	
	        glVertex3f(-0.2f, 0.15f, 0.0f);
	        glVertex3f(-0.03f, 0.15f, 0.0f);
	        glVertex3f(-0.03f, 0.0f, 0.0f);
	        glVertex3f(-0.22f, 0.0f, 0.0f);	        
	        
    	glEnd();
    	
    	// OBJEK BAGIAN  6 : Jendela Depan
    	glBegin(GL_QUADS);
        	glColor3f(0.9f, 0.9f, 0.9f);
        	
	        glVertex3f(0.2f, 0.15f, 0.0f);
	        glVertex3f(0.03f, 0.15f, 0.0f);
	        glVertex3f(0.03f, 0.0f, 0.0f);
	        glVertex3f(0.22f, 0.0f, 0.0f);	        
	        
    	glEnd();
    	
    glPopMatrix();

    glFlush();
}

void gerak() {
    posisiX += speed;

    if(posisiX > 1.2f)
        posisiX = -1.2f;
        
    sudut -= (speed/rban) * 57.3;
}

void timer(int value) {
    gerak();                    
    glutPostRedisplay();        
    glutTimerFunc(16, timer, 0);
}


int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Mobil");
    
    glutDisplayFunc(Mobil);
    glutTimerFunc(16, timer, 0);
    
    glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
    glutMainLoop();
    return 0;
}
