#include "Peon.h"
#include "Pieza.h"
#include "Reina.h"
#include "Rey.h"
#include "Torre.h"
#include "Alfil.h"
#include "Caballo.h"

#include "Puzle3.h"
#include <math.h>
#include "ETSIDI.h"
#include <iostream>
using namespace std;

Puzle3::~Puzle3() {

}

void Puzle3::dibuja() {

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
			glVertex2i(x * cellSize4, y * cellSize4);
			glVertex2i((x + 1) * cellSize4, y * cellSize4);
			glVertex2i((x + 1) * cellSize4, (y + 1) * cellSize4);
			glVertex2i(x * cellSize4, (y + 1) * cellSize4);
			glEnd();

			// Dibujar la pieza en la casilla
			if (tablero3[x][y] != nullptr) {
				glPushMatrix();
				glTranslatef(x * cellSize4, y * cellSize4, 0.1);
				tablero3[x][y]->dibuja();
				glPopMatrix();
			}
		}
	}



}

void Puzle3::inicializa() {


	x_ojo = 20;
	y_ojo = 20;
	z_ojo = 30; // habria q mirarlo bien


	// Inicializacion del tablero	
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			tablero3[x][y] = nullptr;
		}
	}

	tablero3[0][6] = new Peon('n');
	tablero3[1][5] = new Peon('n');
	tablero3[5][6] = new Peon('n');
	tablero3[7][6] = new Peon('n');
	tablero3[6][4] = new Peon('n');
	tablero3[4][5] = new Alfil('n');
	tablero3[4][6] = new Alfil('n');
	tablero3[2][7] = new Torre('n');
	tablero3[5][7] = new Torre('n');
	tablero3[3][6] = new Reina('n');

	tablero3[1][1] = new Peon('b');
	tablero3[6][1] = new Peon('b');
	tablero3[7][1] = new Peon('b');
	tablero3[5][0] = new Torre('b');
	tablero3[5][4] = new Caballo('b');
	tablero3[2][2] = new Alfil('b');

	tablero3[6][7] = new Rey('n');
	tablero3[6][0] = new Rey('b');


}

int xinicial3 = -1, yinicial3 = -1;
int xfinal3 = -1, yfinal3 = -1;

void Puzle3::onMouseClick(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		// Calcular la posición del clic en términos de celdas del tablero
		int casillaX = x / 75;
		int casillaY = (600 - y) / 75;  // Convertir la coordenada y

		if (xinicial3 == -1 && yinicial3 == -1) {
			// Establecer la posición inicial del peón
			xinicial3 = casillaX;
			yinicial3 = casillaY;
			if (tablero3[xinicial3][yinicial3] == nullptr) { //La casilla incial no tiene pieza
				xinicial3 = -1;
				yinicial3 = -1;
			}
		}
		else {
			xfinal3 = casillaX;
			yfinal3 = casillaY;

			char color = tablero3[xinicial3][yinicial3]->obtenerColor();
			TipoPieza tipo = tablero3[xinicial3][yinicial3]->obtenerTipo();


			if (!tablero3[xinicial3][yinicial3] /*->mover(xInicial, yInicial, xFinal, yFinal) */) {
				//return; // Movimiento inválido, salir de la función
				xinicial3 = -1;
				yinicial3 = -1;
				xfinal3 = -1;
				yfinal3 = -1;
			}
			else {

				if (tipo == caballo && color == 'b' && xfinal3 == 7 && yfinal3 == 5) {
					cout << "Buena" << endl;
					heganado = true;

					tablero3[xfinal3][yfinal3] = new Caballo('b');
					delete tablero3[xinicial3][yinicial3];
					tablero3[xinicial3][yinicial3] = nullptr;
					xinicial3 = yinicial3 = xfinal3 = yfinal3 = -1;


				}
				else {
					cout << "error" << endl;
					errorcruz = true;

				}


				// Reiniciar las posiciones inicial y final del peón
				xinicial3 = -1;
				yinicial3 = -1;
				xfinal3 = -1;
				yfinal3 = -1;

				// Redibujar el tablero con el peón movido
				glutPostRedisplay();
			}
		}
	}
}