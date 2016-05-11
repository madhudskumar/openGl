#include<iostream>
#include<GL\glew.h>
#include<GL\glut.h>

float x1, y1, x2, y2, x3, y3, x4, y4;

void scanLine(float x1, float y1, float x2, float y2, int *le, int *re) {
	float mx, x, temp;
	if (y2 > y1) {
		temp = y2;
		y2 = y1;
		y1 = temp;

		temp = x2;
		x2 = x1;
		x1 = temp;
	}

	if ((y2 - y1) > 0)
		mx = (x2 - x1) / (y2 - y1);
	else mx = x2 - x1;

	x = x1;

	for (int i = y1; i < y2; i++)
	{
		if (x < (float)le[i]) le[i] = x;
		if (x > (float)re[i]) re[i] = x;
		x += mx;
	}
}

void 