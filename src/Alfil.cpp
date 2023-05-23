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


bool Alfil::mover(int xInicial, int yInicial, int xFinal, int yFinal, bool ocupado) {

	int posx = xFinal - xInicial;
	int posy = yFinal - yInicial;

	if (color == 'b') {
		if (posy == posx || posy == -posx) {
			return true;
		}
	}

	if (color == 'n') {
		if (posy == posx || posy == -posx) {
			return true;
		}
	}

	return false;
}

