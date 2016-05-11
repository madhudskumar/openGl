#include<iostream>
#include<GL\glew.h>
#include<GL\glut.h>

float v[] = { -.5,-.5,-.5,  -.5, .5,-.5,  .5,.5,-.5,
			   .5,-.5,-.5,  -.5,-.5,.5,  -.5,.5, .5,
			   .5, .5, .5,   .5,-.5,.5 };

float c[] = { 0,0,0, 1,0,0, 1,1,0, 0,1,0,  0,0,1, 1,0,1, 1,1,1, 0,1,1 };

GLubyte d[] = { 0,1,2,3, 2,3,7,6, 4,5,6,7, 4,5,1,0, 5,6,2,1, 0,3,7,4 };
int gx = 0, gy = 1, gz = 0;

void disp() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glRotated(.6, gx, gy, gz);
	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, d);
	glFlush();
}


void mouse(int btn, int state, int x, int y){
	if (btn == GLUT_LEFT_BUTTON) {
		gx = 1;
		gy = gz = 0;
	}
	if (btn == GLUT_RIGHT_BUTTON) {
		gy = 1;
		gx = gz = 0;
	}
}

void main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutCreateWindow("cube");
	glutDisplayFunc(disp);
	glutMouseFunc(mouse);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, v);
	glColorPointer(3, GL_FLOAT, 0, c);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}