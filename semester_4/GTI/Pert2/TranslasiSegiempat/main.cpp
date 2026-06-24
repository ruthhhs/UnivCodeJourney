#include <gl/glut.h>

void SegiEmpat(void) {
    glClear(GL_COLOR_BUFFER_BIT); // Membersihkan layar
    
    // Memindahkan sumbu utama ke koordinat (-0.50, 0.50, 0)
    glTranslatef(-0.50, 0.50, 0); 
    
    glColor3f(1.0f, 0.0f, 0.0f); // Warna merah
    glRectf(-0.18, 0.18, 0.18, -0.18); // Menggambar segiempat
    
    glFlush(); // Memastikan perintah tereksekusi
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
    glutCreateWindow("Segi Empat");
    glutDisplayFunc(SegiEmpat);
    glutMouseFunc(mouse); // deteksi klik mouse
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // Latar belakang biru
    glutMainLoop();
    return 0;
}
