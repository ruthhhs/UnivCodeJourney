#include <GL/glut.h>

void Jendela(void)
{
    // membersihkan layar
    glClear(GL_COLOR_BUFFER_BIT);

    // memastikan semua perintah dijalankan
    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("biru");
    glutDisplayFunc(Jendela);

    // warna background: R, G, B, Alpha
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    glutMainLoop();
    return 0;
}
