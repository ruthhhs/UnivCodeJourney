#include <gl/glut.h>

void Segitiga(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glTranslatef(0.25, -0.25, 0); // Pindahkan posisi [cite: 388]
    // Rotasi 60 derajat terhadap sumbu Z (0,0,1) [cite: 389, 412]
    glRotated(60.0, 0.0, 0.0, 1.0); 
    
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f); // Merah
        glVertex3f(-0.05, -0.05, 0.00);
        
        glColor3f(0.0f, 1.0f, 0.0f); // Hijau
        glVertex3f(0.15, -0.05, 0.00);
        
        glColor3f(0.0f, 0.0f, 1.0f); // Biru
        glVertex3f(-0.05, 0.05, 0.00);
    glEnd();
    
    glFlush();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        glutPostRedisplay(); // redraw saat layar diklik
    }
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Rotasi Segitiga");
    glutDisplayFunc(Segitiga);
    glutMouseFunc(mouse); // deteksi klik mouse
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}
