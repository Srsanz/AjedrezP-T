#include "Peon.h"
#include "freeglut.h"

void Peon:: dibuja() {

	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	if(numero<=8){
		sprite1.draw();
	}
	if (numero > 8) {
		sprite2.draw();
	}
	glPopMatrix();
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