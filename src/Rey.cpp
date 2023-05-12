#include "Rey.h"
#include "freeglut.h"
#include <iostream>


Rey::Rey() {
	glPushMatrix();
	sprite1.setSize(1.5, 1.5);
	sprite1.setCenter(x + 0.75, y + 0.75);
	sprite1.draw();
	sprite2.setSize(1.5, 1.5);
	sprite2.setCenter(x + 0.75, y + 0.75);
	sprite2.draw();
	glPopMatrix();
}


void Rey::setColor(char r, char v, char a)
{
	rojo = r;
	verde = v;
	azul = a;
}


void Rey::setPos(float ix, float iy)
{
	x = ix;
	y = iy;
}

void Rey::dibujanegro() {

	/*
	glColor3ub(rojo, verde, azul);
	glBegin(GL_POLYGON);
	glVertex3f(x - 0.25, y - 0.25, 0.1f);
	glVertex3f(x - 0.25, y + 0.25, 0.1f);
	glVertex3f(x + 0.25, y + 0.25, 0.1f);
	glVertex3f(x + 0.25, y - 0.25, 0.1f);
	glEnd();
	*/

	glPushMatrix();
	sprite1.setSize(1.5, 1.5);
	sprite1.setCenter(x + 0.75, y + 0.75);
	sprite1.draw();
	glPopMatrix();

}


void Rey::dibujablanco() {

	/*
	glColor3ub(rojo, verde, azul);
	glBegin(GL_POLYGON);
	glVertex3f(x - 0.25, y - 0.25, 0.1f);
	glVertex3f(x - 0.25, y + 0.25, 0.1f);
	glVertex3f(x + 0.25, y + 0.25, 0.1f);
	glVertex3f(x + 0.25, y - 0.25, 0.1f);
	glEnd();
	*/

	glPushMatrix();
	sprite2.setSize(1.5, 1.5);
	sprite2.setCenter(x + 0.75, y + 0.75);
	sprite2.draw();
	glPopMatrix();

}

float Rey::getPosX() {
	return x;
}
float Rey::getPosY() {
	return y;
}