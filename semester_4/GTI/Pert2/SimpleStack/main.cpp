#include <gl/glut.h>
#include <gl/gl.h>
#include <math.h>

#define PI 3.1415926535898 // [cite: 451]

void RenderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // OBJEK 1: Garis Putih
    glPushMatrix(); // Mulai stack [cite: 422]
        glLineWidth(2.0f);
        glBegin(GL_LINES);
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex3f(0.00, 0.20, 0.0);
            glVertex3f(0.00, -0.20, 0.0);
        glEnd();
    glPopMatrix(); // Akhiri stack [cite: 429]

    // OBJEK 2: Titik
    glPushMatrix();
        glPointSize(5.0f);
        glTranslatef(0.35, 0.35, 0.0);
        glBegin(GL_POINTS);
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex3f(0.25, 0.25, 0.0);
        glEnd();
    glPopMatrix();

    // OBJEK 3: Segiempat (Triangle Strip)
    glPushMatrix();
        glTranslatef(0.50, 0.50, 0.00);
        glBegin(GL_TRIANGLE_STRIP);
            glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-0.05, -0.05, 0.00);
            glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(0.15, -0.05, 0.00);
            glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(-0.05, 0.05, 0.00);
            glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(0.15, 0.05, 0.00);
        glEnd();
    glPopMatrix();

    // OBJEK 4: Lingkaran
    glPushMatrix();
        glBegin(GL_LINE_LOOP);
            GLint circle_points = 100;
            for (int i = 0; i < circle_points; i++) {
                float angle = 2 * PI * i / circle_points;
                glVertex2f(cos(angle), sin(angle));
            }
        glEnd();
    glPopMatrix();

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Simple Stack");
    glutDisplayFunc(RenderScene);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}
