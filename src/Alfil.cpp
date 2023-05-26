#include "Alfil.h"
#include "freeglut.h"


void Alfil::dibuja() {

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


bool Alfil::mover(int xInicial, int yInicial, int xFinal, int yFinal, bool ocupado, Tablero& t) {

	int x = xFinal - xInicial;
	int y = yFinal - yInicial;
	int xI = xInicial, yI = yInicial;

	if (x == y) {
		for (++yI, ++xI; yI < yFinal; yI++, xI++) {
			if (t.tablero[xI][yI] != nullptr) return false;
		}
		for (yI -= 2, xI -= 2; yI > yFinal; yI--, xI--) {
			if (t.tablero[xI][yI] != nullptr) return false;
		}
	}
	else if (x == -y) {
		for (++yI, --xI; yI < yFinal; yI++, xI--) {
			if (t.tablero[xI][yI] != nullptr) return false;
		}
		for (yI -= 2, xI += 2; yI > yFinal; yI--, xI++) {
			if (t.tablero[xI][yI] != nullptr) return false;
		}
	}


	if (color == 'b') {
		if (y == x || y == -x) {
			return true;
		}
	}

	if (color == 'n') {
		if (y == x || y == -x) {
			return true;
		}
	}

	return false;
}

