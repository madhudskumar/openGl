#include<GL/glew.h>
#include<GL/glut.h>
#include<math.h>

void obj(float cx, float cy, float r, int num) {
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < num; i++)
	{
		float theta = 2.0 * 3.14 * i / num;
		float x = r*cosf(theta);
		float y = r*sinf(theta);
		glVertex2f(x + cx, y + cy);
	}
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, 0.0);
	glEnd();
}

void disp() {
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 700, 700);
	glTranslated(0, 0, 0);
	for (int i = 0; i < 30; i++) {
		glTranslated(.01, 0.01, 0.01);
		obj(.4, -.7, .3, 30);
	}
	glFlush();
	glLoadIdentity();
}

void main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(700, 700);
	glutCreateWindow("cylinder");
	glutDisplayFunc(disp);
	glutMainLoop();

}