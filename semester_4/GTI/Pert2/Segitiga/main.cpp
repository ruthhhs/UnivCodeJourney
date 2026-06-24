#include <GL/glut.h>

void Segitiga(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);

        glColor3f(1.0f, 0.0f, 0.0f);      // merah
        glVertex3f(-0.10f, -0.10f, 0.0f);

        glColor3f(0.0f, 1.0f, 0.0f);      // hijau
        glVertex3f(0.10f, -0.10f, 0.0f);

        glColor3f(0.0f, 0.0f, 1.0f);      // biru
        glVertex3f(0.00f, 0.10f, 0.0f);

    glEnd();

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Membuat Segitiga");

    glutDisplayFunc(Segitiga);

    // warna background
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    glutMainLoop();
    return 0;
}
