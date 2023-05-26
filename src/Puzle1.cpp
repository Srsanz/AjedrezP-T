#include "Peon.h"
#include "Pieza.h"
#include "Reina.h"
#include "Rey.h"
#include "Puzle1.h"
#include <math.h>
#include "ETSIDI.h"
#include <iostream>
using namespace std;

Puzle1::~Puzle1() {

}

void Puzle1::dibuja() {

	gluLookAt(x_ojo, y_ojo, z_ojo, // posicion del ojo
		x_ojo, y_ojo, 0.0, // hacia que punto mira (0,0,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)

	if (heganado == true) {
		errorcruz = false;
		dibujacopa();
	}
	if (errorcruz == true) {
		heganado = false;
		dibujaerror();
		
	}

	// dibujo del tablero
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if ((x + y) % 2 == 0) {
				glColor3ub(219, 187, 166); // Color clarito
			}
			else {
				glColor3ub(153, 93, 45); // Color oscurito
			}
			glBegin(GL_QUADS);
			glVertex2i(x * cellSize2, y * cellSize2);
			glVertex2i((x + 1) * cellSize2, y * cellSize2);
			glVertex2i((x + 1) * cellSize2, (y + 1) * cellSize2);
			glVertex2i(x * cellSize2, (y + 1) * cellSize2);
			glEnd();

			// Dibujar la pieza en la casilla
			if (tablero1[x][y] != nullptr) {
				glPushMatrix();
				glTranslatef(x * cellSize2, y * cellSize2, 0.1);
				tablero1[x][y]->dibuja();
				glPopMatrix();
			}
		}
	}



}

void Puzle1::inicializa() {


	x_ojo = 20;
	y_ojo = 20;
	z_ojo = 30; // habria q mirarlo bien



	// Inicializacion del tablero	
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			tablero1[x][y] = nullptr;
		}
	}

	tablero1[0][6] = new Peon('n');
	tablero1[0][1] = new Reina('b');
	tablero1[5][7] = new Rey('n');
	tablero1[5][5] = new Rey('b');


}

int xinicial = -1, yinicial = -1;
int xfinal = -1, yfinal = -1;

void Puzle1::onMouseClick(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		// Calcular la posición del clic en términos de celdas del tablero
		int casillaX = x / 75;
		int casillaY = (600 - y) / 75;  // Convertir la coordenada y

		if (xinicial == -1 && yinicial == -1) {
			// Establecer la posición inicial del peón
			xinicial = casillaX;
			yinicial = casillaY;
			if (tablero1[xinicial][yinicial] == nullptr) { //La casilla incial no tiene pieza
				xinicial = -1;
				yinicial = -1;
			}
		}
		else {
			xfinal = casillaX;
			yfinal = casillaY;

			char color = tablero1[xinicial][yinicial]->obtenerColor();
			TipoPieza tipo = tablero1[xinicial][yinicial]->obtenerTipo();


			if (!tablero1[xinicial][yinicial] /*->mover(xInicial, yInicial, xFinal, yFinal) */ ) {
				//return; // Movimiento inválido, salir de la función
				xinicial = -1;
				yinicial = -1;
				xfinal = -1;
				yfinal = -1;
			}
			else {

				if (tipo == reina && color == 'b' && xfinal == 5 && yfinal == 6) {
					cout << "Has ganado" << endl;
					heganado = true;

					tablero1[xfinal][yfinal] = new Reina('b');
					delete tablero1[xinicial][yinicial];
					tablero1[xinicial][yinicial] = nullptr;
				}
				else {
					cout << "error" << endl;
					errorcruz = true;

				}


				// Reiniciar las posiciones inicial y final del peón
				xinicial = -1;
				yinicial = -1;
				xfinal = -1;
				yfinal = -1;

				// Redibujar el tablero con el peón movido
				glutPostRedisplay();
			}
		}
	}
}