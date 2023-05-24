#include "freeglut.h"
#include "Reina.h"

void Reina::dibuja() {

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


bool Reina::mover(int xInicial, int yInicial, int xFinal, int yFinal, bool ocupado, Tablero& t) {
	
	int x = xFinal - xInicial;
	int y = yFinal - yInicial;
	int xI = xInicial, yI = yInicial;

	if (x == 0) {
		for (++yI; yI < yFinal; yI++) {
			if (t.tablero[xI][yI] != nullptr) return false;
		}
		for (yI -= 2; yI > yFinal; yI--) {
			if (t.tablero[xI][yI] != nullptr) return false;
		}
	}
	else if (y == 0) {
		for (++xI; xI < xFinal; xI++) {
			if (t.tablero[xI][yI] != nullptr) return false;
		}
		for (xI -= 2; xI > xFinal; xI--) {
			if (t.tablero[xI][yI] != nullptr) return false;
		}
	}
	else if (x == y) {
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

	// Si la reina es blanca
	if (color == 'b') {
		if (x == 0 || y == 0 || x == y||x==-y) {
			return true;
		}
	}
	// Si la reina es negra
	if (color == 'n') {
		if (x == 0 || y == 0 || x == y|| x == -y) {
			return true;
		}
	}

	return false;
	
	
}