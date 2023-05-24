#include "Rey.h"
#include "freeglut.h"


void Rey::dibuja() {

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


bool Rey::mover(int xInicial, int yInicial, int xFinal, int yFinal, bool ocupado, Tablero& t) {

	int posx = xFinal - xInicial;
	int posy = yFinal - yInicial;

	if (color == 'b') {
		if (posy == 0 && (posx == 1 || posx == -1)) {
			return true;
		}
		else if (posx == 0 && (posy == 1 || posy == -1)) {
			return true;
		}
		else if ((posx == 1 && posy == 1) || (posx == 1 && posy == -1) || (posx == -1 && posy == 1) || (posx == -1 && posy == -1)) {
			return true;
		}
	}

	if (color == 'n') {
		if (posy == 0 && (posx == 1 || posx == -1)) {
			return true;
		}
		else if (posx == 0 && (posy == 1 || posy == -1)) {
			return true;
		}
		else if ((posx == 1 && posy == 1) || (posx == 1 && posy == -1) || (posx == -1 && posy == 1) || (posx == -1 && posy == -1)) {
			return true;
		}
	}

	return false;
}
