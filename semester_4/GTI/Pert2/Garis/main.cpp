#include <GL/glut.h>

void Garis(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(5.0f);          // ketebalan garis
    glBegin(GL_LINES);          // mulai menggambar garis

        glColor3f(1.0f, 1.0f, 1.0f);   // warna putih
        glVertex3f(0.00f, 0.20f, 0.0f); // titik awal
        glVertex3f(0.00f, -0.20f, 0.0f); // titik akhir

    glEnd();

    glFlush();                  // menjalankan perintah OpenGL
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Membuat Garis");

    glutDisplayFunc(Garis);

    // warna background (biru)
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    glutMainLoop();
    return 0;
}
