#include <gl/glut.h>
#include <gl/gl.h>
#include <math.h>

#define PI 3.1415926535898 // [cite: 451]
float sudut = 0;
float posisiX = -0.5f;  // posisi awal

void Orbit(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // Bumi
	glPushMatrix();
        glPointSize(50.0f);
        
        glRotated(sudut, 0.0, 0.0, 1.0); 
        
        glBegin(GL_POINTS);
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(0.0, 0.0, 0.0);
        glEnd();
    glPopMatrix();
    
    // Bulan
	glPushMatrix();
        glPointSize(25.0f);
        
    	glRotated(sudut, 0.0, 0.0, 1.0); 
    	glTranslatef(0.5, 0.0, 0.0);
    	
        glBegin(GL_POINTS);
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex3f(0.0, 0.0, 0.0);
        glEnd();
    glPopMatrix();
    
    sudut += 0.1;
    
    glFlush();
}

void gerak() {
    posisiX += 0.1f; // kecepatan gerak

    if(posisiX > 1.0f)
        posisiX = -1.0f; // kembali ke kiri

    glutPostRedisplay();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Animasi Bumi Bulan");
    glutDisplayFunc(Orbit);
    glutIdleFunc(gerak);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutMainLoop();
    return 0;
}
