#include <GL/glut.h>

void point(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glPointSize(25.0f); // ukuran titik
    
    glBegin(GL_POINTS);
        glColor3f(1.0f, 0.0f, 0.0f);   // warna merah
        glVertex3f(0.25f, 0.25f, 0.0f); // posisi titik
    glEnd();
    
    glBegin(GL_POINTS);
        glColor3f(1.0f, 1.0f, 0.0f);   // warna kuning
        glVertex3f(0.0f, 0.25f, 0.0f); // posisi titik
    glEnd();

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Titik");

    glutDisplayFunc(point);

    // warna background (biru)
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    glutMainLoop();
    return 0;
}
