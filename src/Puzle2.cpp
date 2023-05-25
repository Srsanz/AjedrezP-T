#include "Peon.h"
#include "Pieza.h"
#include "Reina.h"
#include "Rey.h"
#include "Puzle2.h"
#include <math.h>
#include "ETSIDI.h"
#include <iostream>
using namespace std;

Puzle2::~Puzle2() {

}

void Puzle2::dibuja() {

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
			glVertex2i(x * cellSize3, y * cellSize3);
			glVertex2i((x + 1) * cellSize3, y * cellSize3);
			glVertex2i((x + 1) * cellSize3, (y + 1) * cellSize3);
			glVertex2i(x * cellSize3, (y + 1) * cellSize3);
			glEnd();

			// Dibujar la pieza en la casilla
			if (tablero2[x][y] != nullptr) {
				glPushMatrix();
				glTranslatef(x * cellSize3, y * cellSize3, 0.1);
				tablero2[x][y]->dibuja();
				glPopMatrix();
			}
		}
	}



}

void Puzle2::inicializa() {


	x_ojo = 20;
	y_ojo = 20;
	z_ojo = 30; // habria q mirarlo bien


	// Inicializacion del tablero	
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			tablero2[x][y] = nullptr;
		}
	}

	tablero2[0][6] = new Peon('n');
	tablero2[0][1] = new Reina('b');
	tablero2[5][7] = new Rey('n');
	tablero2[5][5] = new Rey('b');


}

int xinicial1 = -1, yinicial1 = -1;
int xfinal1 = -1, yfinal1 = -1;

void Puzle2::onMouseClick(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		// Calcular la posición del clic en términos de celdas del tablero
		int casillaX = x / 75;
		int casillaY = (600 - y) / 75;  // Convertir la coordenada y

		if (xinicial1 == -1 && yinicial1 == -1) {
			// Establecer la posición inicial del peón
			xinicial1 = casillaX;
			yinicial1 = casillaY;
			if (tablero2[xinicial1][yinicial1] == nullptr) { //La casilla incial no tiene pieza
				xinicial1 = -1;
				yinicial1 = -1;
			}
		}
		else {
			xfinal1 = casillaX;
			yfinal1 = casillaY;

			char color = tablero2[xinicial1][yinicial1]->obtenerColor();
			TipoPieza tipo = tablero2[xinicial1][yinicial1]->obtenerTipo();


			if (!tablero2[xinicial1][yinicial1] /*->mover(xInicial, yInicial, xFinal, yFinal) */) {
				//return; // Movimiento inválido, salir de la función
				xinicial1 = -1;
				yinicial1 = -1;
				xfinal1 = -1;
				yfinal1 = -1;
			}
			else {

				if (tipo == reina && color == 'b' && xfinal1 == 5 && yfinal1 == 6) {
					cout << "Has ganado" << endl;
					heganado = true;

					tablero2[xfinal1][yfinal1] = new Reina('b');
					delete tablero2[xinicial1][yinicial1];
					tablero2[xinicial1][yinicial1] = nullptr;
				}
				else {
					cout << "error" << endl;
					errorcruz = true;

				}


				// Reiniciar las posiciones inicial y final del peón
				xinicial1 = -1;
				yinicial1 = -1;
				xfinal1 = -1;
				yfinal1 = -1;

				// Redibujar el tablero con el peón movido
				glutPostRedisplay();
			}
		}
	}
}