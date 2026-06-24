#include <GL/glut.h> 


static int shoulder = 0;
static int elbow = 0;
static int wrist = 0;
static int finger1 = 0;
static int finger2 = 0;
static int finger3 = 0;
static int thumb = 0;

void init(void) {
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
}
void display(void) {
    glClear (GL_COLOR_BUFFER_BIT);
    
    glPushMatrix();
    
	// Lengan Atas
    glTranslatef (-1.0, 0.0, 0.0);
    glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);
    glTranslatef (1.0, 0.0, 0.0); 
	
		glPushMatrix();
	    glScalef (2.0, 0.4, 1.0);
	    glutWireCube (1.0); 
		glPopMatrix();
	
	// Lengan Bawah
    glTranslatef (1.0, 0.0, 0.0);
    glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
    glTranslatef (1.0, 0.0, 0.0); 
	
		glPushMatrix();
	    glScalef (2.0, 0.4, 1.0);
	    glutWireCube (1.0);    
	    glPopMatrix(); 
	    
	// Telapak Tangan
    glTranslatef (1.0, 0.0, 0.0);
    glRotatef ((GLfloat) wrist, 0.0, 0.0, 1.0);
    glTranslatef (0.5, 0.0, 0.0); 
	
		glPushMatrix();
	    glScalef (1.0, 0.3, 1.0);
	    glutWireCube (1.0);    
	    glPopMatrix(); 
	    
	// Jari 1
	glPushMatrix();
	glTranslatef(0.5, 0.0, 0.4);
	glRotatef((GLfloat) finger1, 0.0, 0.0, 1.0);
	glTranslatef(0.3, 0.0, 0.0);
	glScalef(0.7, 0.2, 0.2);
	glutWireCube(1.0);
	glPopMatrix();
	
	// Jari 2
	glPushMatrix();
	glTranslatef(0.5, 0.0, 0.0);
	glRotatef((GLfloat) finger2, 0.0, 0.0, 1.0);
	glTranslatef(0.3, 0.0, 0.0);
	glScalef(0.7, 0.2, 0.2);
	glutWireCube(1.0);
	glPopMatrix();
	
	// Jari 3
	glPushMatrix();
	glTranslatef(0.5, 0.0, -0.4);
	glRotatef((GLfloat) finger3, 0.0, 0.0, 1.0);
	glTranslatef(0.3, 0.0, 0.0);
	glScalef(0.7, 0.2, 0.2);
	glutWireCube(1.0);
	glPopMatrix();
	
	// Jempol
	glPushMatrix();
	glTranslatef(-0.2, 0.0, 0.5);
	glRotatef(40, 0.0, 0.0, 1.0);
	glTranslatef(0.25, 0.0, 0.0);
	glRotatef((GLfloat) thumb, 0.0, 1.0, 0.0);
	glTranslatef(0.25, 0.0, 0.0);	
	glScalef(0.5, 0.3, 0.3);
	glutWireCube(1.0);
	glPopMatrix();

	glPopMatrix();
	
    glutSwapBuffers();
}
void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
    gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
    glTranslatef (0.0, 0.0, -5.0);
}
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 's': shoulder = (shoulder + 5) % 360;
            glutPostRedisplay(); break;
        case 'S': shoulder = (shoulder - 5) % 360;
            glutPostRedisplay(); break;
        case 'e': elbow = (elbow + 5) % 360;
            glutPostRedisplay(); break;
        case 'E': elbow = (elbow - 5) % 360;
            glutPostRedisplay(); break;
        case 'w': wrist = (wrist + 5) % 360;
            glutPostRedisplay(); break;
        case 'W': wrist = (wrist - 5) % 360;
            glutPostRedisplay(); break;
        case '1': finger1 = (finger1 + 5) % 360;
		    glutPostRedisplay(); break;
		case '!': finger1 = (finger1 - 5) % 360;
		    glutPostRedisplay(); break;
		case '2': finger2 = (finger2 + 5) % 360;
		    glutPostRedisplay(); break;
		case '@': finger2 = (finger2 - 5) % 360;
		    glutPostRedisplay(); break;
		case '3': finger3 = (finger3 + 5) % 360;
		    glutPostRedisplay(); break;
		case '#': finger3 = (finger3 - 5) % 360;
		    glutPostRedisplay(); break;
		case 'q': thumb = (thumb - 5) % 360;
		    glutPostRedisplay(); break;
		case 'Q': thumb = (thumb + 5) % 360;
		    glutPostRedisplay(); break;
        case 27: exit(0); break;
        default: break;
        }
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (700, 600);
    glutInitWindowPosition (100, 100);
     glutCreateWindow("Tugas Lengan Jari");
	
	init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    
    glutMainLoop(); 
	return 0;
}
