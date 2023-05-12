#include "Alfil.h"
#include "freeglut.h"
#include <iostream>


Alfil::Alfil() {
	glPushMatrix();
	sprite1.setSize(1.5, 1.5);
	sprite1.setCenter(x + 0.75, y + 0.75);
	sprite1.draw();
	sprite2.setSize(1.5, 1.5);
	sprite2.setCenter(x + 0.75, y + 0.75);
	sprite2.draw();
	glPopMatrix();
}


void Alfil::setColor(char r, char v, char a)
{
	rojo = r;
	verde = v;
	azul = a;
}


void Alfil::setPos(float ix, float iy)
{
	x = ix;
	y = iy;
}

void Alfil::dibujanegro() {

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

void Alfil::dibujablanco() {

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

float Alfil::getPosX() {
	return x;
}
float Alfil::getPosY() {
	return y;
}


