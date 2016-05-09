#include<GL\glew.h>
#include<GL\glut.h>

float r = 3, c = 3.3;

void draw(int a, int b, int ch = 0) {
	for (float i = 0; i < a; i += .05)
	{
		glBegin(GL_LINE_STRIP);
		for (float j = 0; j < b; j += .05)
			if (ch)
			{
				glVertex2f(i - .9, j - .9);
			}
			else {
				glVertex2f(j - .9, i - .9);
			}

		glEnd();
	}
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	draw(r, c, 1);
	draw(c, r);
	glFlush();
}

void main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow("mesh");
	glutDisplayFunc(display);
	glutMainLoop();
}