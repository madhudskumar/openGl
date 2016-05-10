#include<GL\glew.h>
#include<GL\glut.h>
#include<iostream>

typedef float point[3];
point v[] = { {0.0,0.0,-1.0}, {0.0,.9,-.3}, { -0.8,-.4,-.3}, { 0.8,-.4,-.5} };
int n;

void tri(point a, point b, point c) {
	glBegin(GL_TRIANGLES);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glEnd();
}

void divide_tri(point a, point b, point c,int m) {
	point v1, v2, v3;

	if(m > 0){
		for (int i = 0; i < 3; i++) {
			v1[i] = (a[i] + b[i]) / 2;
			v2[i] = (a[i] + c[i]) / 2;
			v3[i] = (b[i] + c[i]) / 2;
		}

		divide_tri(a, v1, v2, m-1);
		divide_tri(c, v2, v3, m-1);
		divide_tri(b, v3, v1, m-1);
	}
	else tri(a, b, c);
}

void tetra(int m) {
	glColor3f(1, 0, 0);
	divide_tri(v[0], v[1], v[2], m);

	glColor3f(0, 1, 0);
	divide_tri(v[3], v[2], v[1], m);

	glColor3f(0, 0, 1);
	divide_tri(v[0], v[3], v[1], m);

	glColor3f(0, 0, 0);
	divide_tri(v[0], v[2], v[3], m);
}

void display() {
	glViewport(0, 0, 700, 700);
	glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);

	tetra(n);

	glFlush();
	glLoadIdentity();
}

void main(int argc, char **argv) {
	glutInit(&argc, argv);
	
	std::cout << "Enter no : ";
	std::cin >> n;

	glutInitWindowSize(700, 700);
	glutCreateWindow("tetra");
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glClearColor(1,1,1,1);
	glutMainLoop();
}