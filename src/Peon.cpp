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


bool Peon::mover(int xInicial, int yInicial, int xFinal, int yFinal, bool ocupado, Tablero& t) {

	// Verificar si el movimiento es válido para un peón
	//bool movimientoValido = false;

	

	// Si el peón es blanco
	if (color == 'b') {
		// Movimiento válido: mover hacia adelante una casilla
		if (yFinal == yInicial + 1 && xFinal == xInicial && !ocupado) {
			return true;
		}
		// Movimiento válido: mover hacia adelante dos casillas desde la posición inicial
		else if (yFinal == yInicial + 2 && xFinal == xInicial && yInicial == 1 && !ocupado) {
			return true;
		}
		// Movimiento válido: captura diagonal a la derecha
		else if (yFinal == yInicial + 1 && (xFinal == xInicial + 1 || xFinal == xInicial - 1) && ocupado) {
			return true;
		}
	}
	// Si el peón es negro
	else if (color == 'n') {
		// Movimiento válido: mover hacia adelante una casilla
		if (yFinal == yInicial - 1 && xFinal == xInicial && !ocupado) {
			return true;
		}
		// Movimiento válido: mover hacia adelante dos casillas desde la posición inicial
		else if (yFinal == yInicial - 2 && xFinal == xInicial && yInicial == 6 && !ocupado) {
			return true;
		}
		// Movimiento válido: captura diagonal a la izquierda
		else if (yFinal == yInicial - 1 && (xFinal == xInicial + 1 || xFinal == xInicial - 1)&&ocupado) {
			return true;
		}
	}

	return false;
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