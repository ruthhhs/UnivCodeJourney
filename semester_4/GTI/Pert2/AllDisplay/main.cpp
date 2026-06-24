#include <GL/glut.h>

void point(void)
{
    glPointSize(5.0f);

    glBegin(GL_POINTS);
        glColor3f(1.0f, 0.0f, 0.0f);   // warna merah
        glVertex3f(0.25f, 0.25f, 0.0f); // posisi titik
    glEnd();
}

void Garis(void)
{
    glLineWidth(2.0f);          // ketebalan garis
    glBegin(GL_LINES);          // mulai menggambar garis

        glColor3f(1.0f, 1.0f, 1.0f);   // warna putih
        glVertex3f(0.00f, 0.20f, 0.0f); // titik awal
        glVertex3f(0.00f, -0.20f, 0.0f); // titik akhir

    glEnd();
}

void Segitiga(void)
{
    glBegin(GL_TRIANGLES);

        glColor3f(1.0f, 0.0f, 0.0f);      // merah
        glVertex3f(-0.10f, -0.10f, 0.0f);

        glColor3f(0.0f, 1.0f, 0.0f);      // hijau
        glVertex3f(0.10f, -0.10f, 0.0f);

        glColor3f(0.0f, 0.0f, 1.0f);      // biru
        glVertex3f(0.00f, 0.10f, 0.0f);

    glEnd();
}

void SegiEmpat(void)
{
    glColor3f(1.0f, 0.0f, 0.0f);   // warna merah
    glRectf(-0.18f, 0.18f, 0.18f, -0.18f);  // segiempat penuh
}

void Display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

    point();
    SegiEmpat();
    Segitiga();
    Garis();

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

    glutCreateWindow("All Display");
    glutDisplayFunc(Display);

    // warna background biru
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    glutMainLoop();
    return 0;
}
