#include<iostream>
#include<GL\glew.h>
#include<GL\glut.h>

float v[] = { -1,-1,-1,  -1,1,-1,  1,1,-1, 
			   1,-1,-1,   -1,-1,1,  -1,1,1,
				1,1,1,  1,-1,1
};

float c[] = { 0,0,0, 1,0,0, 1,1,0, 0,1,0, 0,0,1, 1,0,1, 1,1,1, 0,1,1 };

GLubyte list[] = { 0,1,2,3, 2,3,7,6, 4,5,6,7, 4,5,1,0, 5,6,2,1, 0,3,7,4 };
static GLfloat theta[3] = {0,0,0};
static int axis = 2;
static GLfloat view[3] = { 0,0,5 };
int x = 0, y = 0, z = 1;

void disp() {
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(view[0], view[1], view[2], 0, 0, 0, 0, 1, 0);
	glRotatef(theta[0], 1, 0, 0);
	glRotatef(theta[1], 0, 1, 0);
	glRotatef(theta[2], 0, 0, 1);
	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, list);
	glFlush();
}

void mouse(int btn, int state, int x, int y) {
	if (btn == GLUT_LEFT_BUTTON) axis = 0;
	if (btn == GLUT_RIGHT_BUTTON) axis = 2;
	theta[axis] += 2;
	if (theta[axis] >= 360.0) theta[axis] -= 360.0;
	disp();
}

void keyBrd(unsigned char key, int x, int y) {
	if (key == 'x') view[0] += 1;
	if (key == 'X') view[0] -= 1;

	if (key == 'y') view[1] += 1;
	if (key == 'Y') view[1] -= 1;

	if (key == 'z') view[2] += 1;
	if (key == 'Z') view[2] -= 1;
	disp();
}

void main(int argc, char **argv) {
	glutInit(&argc, argv);

	glutInitWindowSize(700, 700);
	glutCreateWindow("pres");
	glMatrixMode(GL_PROJECTION);
	glFrustum(-2, 2, -2, 2, 2, 20);
	glMatrixMode(GL_MODELVIEW);
	glutDisplayFunc(disp);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, v);
	glColorPointer(3, GL_FLOAT, 0, c);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyBrd);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();


}