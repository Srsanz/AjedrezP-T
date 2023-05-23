#include "Torre.h"


void Torre::dibuja() {

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


bool Torre::mover(int xInicial, int yInicial, int xFinal, int yFinal, bool ocupado) {
	int x = xFinal - xInicial;
	int y = yFinal - yInicial;

	// Si la reina es blanca
	if (color == 'b') {
		if (x == 0 || y == 0) {
			return true;
		}
	}
	// Si la reina es negra
	if (color == 'n') {
		if (x == 0 || y == 0) {
			return true;
		}
	}

	return false;


}
