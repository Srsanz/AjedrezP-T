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


bool Caballo::mover(int xInicial, int yInicial, int xFinal, int yFinal,bool ocupado) {
	// Verificar si el movimiento es válido para un caballo

//unsigned int x = xFinal - xInicial;
	int x = xFinal - xInicial;
	int y = yFinal - yInicial;

	if (x < 0) {
		x = xInicial - xFinal;
	}

	if (y < 0) {
		y = yInicial - yFinal;
	}


	// Si el caballo es blanco
	if (color == 'b') {
		if (((x + y) == 3) && (x != 3) && (y != 3)) {
			return true;
		}
	}
	// Si el caballo es negro
	if (color == 'n') {
		if (((x + y) == 3) && (x != 3) && (y != 3)) {
			return true;
		}
	}

	return false;
}