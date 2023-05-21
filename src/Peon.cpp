#include "Peon.h"
#include "freeglut.h"

void Peon:: dibuja() {

	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	if (color == 'b') {
		sprite1.draw(); //blancas
	}
	else if (color == 'n') {
		sprite2.draw(); //negras
	}
	glPopMatrix();
}


void Peon::mover() {
	

}



/*
void Peon::setPos(float ix, float iy)
{
	x = ix;
	y = iy;
}



float Peon::getPosX() {
	return x;
}
float Peon::getPosY() {
	return y;
}


void Peon::mover() {
	setPos(getPosX(), getPosY() + 2);
}

*/