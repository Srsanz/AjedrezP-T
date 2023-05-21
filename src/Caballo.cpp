#include "freeglut.h"
#include "Caballo.h"

void Caballo::dibuja() {

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


bool Caballo::mover(int xInicial, int yInicial, int xFinal, int yFinal) {
	return true;
}