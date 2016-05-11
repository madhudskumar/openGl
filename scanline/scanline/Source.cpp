#include<iostream>
#include<GL\glew.h>
#include<GL\glut.h>

#ifdef y_1
#undef y_1
#endif

float x1, y_1, x2, y2, x3, y3, x4, y4;


void edgeDetect(float x1, float y_1, float x2, float y2, int *le, int *re) {
	float mx, x, temp;
	if ((y2 - y_1) <= 0) {
		temp = y2;
		y2 = y_1;
		y_1 = temp;

		temp = x2;
		x2 = x1;
		x1 = temp;
	}

	if ((y2 - y_1) != 0)
		mx = (x2 - x1) / (y2 - y_1);
	else mx = x2 - x1;

	x = x1;

	for (int i = y_1; i < y2; i++)
	{
		if (x < (float)le[i]) le[i] = x;
		if (x > (float)re[i]) re[i] = x;
		x += mx;
	}
}

void drawPixel(int x, int y) {
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void scanLine(float x1, float y_1, float x2, float y2, float x3, float y3, float x4, float y4){
	int le[500],re[500] = { 0 };

	std::fill_n(le, 500, 500);

	for (int i = 0; i < 500; i++) le[i] = 500;

	edgeDetect(x1, y_1, x2, y2, le, re);
	edgeDetect(x2, y2, x3, y3, le, re);
	edgeDetect(x3, y3, x4, y4, le, re);
	edgeDetect(x4, y4, x1, y_1, le, re);

	for (int y = 0; y < 500; y++)
		if(le[y] <= re[y])
			for (int i = (int)le[y]; i < (int)re[y]; i++) drawPixel(i,y);
}

void disp() {
	x1 = y_1 = 200.0;
	x2 = 100.0; y2 = 200.0;
	x3 = 300.0; y3 = 400.0;
	x4 = y4 = 300.0;

	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(0, 0, 1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1, y_1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();

	scanLine(x1, y_1, x2, y2, x3, y3, x4, y4);
	glFlush();
}

void main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(700, 700);
	glutCreateWindow("snLine");
	glutDisplayFunc(disp);
	gluOrtho2D(0, 499, 0, 499);
	glutMainLoop();
}