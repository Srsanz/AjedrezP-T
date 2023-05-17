#include "Tablero.h"
#include "Peon.h"



Tablero::~Tablero()
{
	//pieza.destruirContenido();

	// Liberar memoria de las piezas
	/*
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			delete board[x][y];
		}
	}
	*/
}



void Tablero::dibuja() {

	gluLookAt(x_ojo, y_ojo, z_ojo, // posicion del ojo
		x_ojo, y_ojo, 0.0, // hacia que punto mira (0,0,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)


	// dibujo del tablero
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if ((x + y) % 2 == 0) {
				glColor3f(1.0, 1.0, 1.0); // Color blanco
			}
			else {
				glColor3f(0.7, 0.7, 0.7); // Color gris claro
			}
			glBegin(GL_QUADS);
			glVertex2i(x * cellSize, y * cellSize);
			glVertex2i((x + 1) * cellSize, y * cellSize);
			glVertex2i((x + 1) * cellSize, (y + 1) * cellSize);
			glVertex2i(x * cellSize, (y + 1) * cellSize);
			glEnd();

			// Dibujar la pieza en la casilla
			if (board[x][y] != nullptr) {
				glPushMatrix();
				glTranslatef(x * cellSize, y * cellSize, 0.1);
				board[x][y]->dibuja();
				glPopMatrix();
			}
		}
	}



}

void Tablero::inicializa() {


	x_ojo = 20;
	y_ojo = 20;
	z_ojo = 30; // habria q mirarlo bien


	// Inicializacion del tablero	
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			board[x][y] = nullptr;
		}
	}



	// Inicializacion de las piezas
	/*
	for (int i = 0; i < 8; i++)
	{
		board[i][1] = new Peon(i, 1);
	}
	*/

	board[0][1] = new Peon(1);
	board[1][1] = new Peon(2);
	board[2][1] = new Peon(3);
	board[3][1] = new Peon(4);
	board[4][1] = new Peon(5);
	board[5][1] = new Peon(6);
	board[6][1] = new Peon(7);
	board[7][1] = new Peon(8);

}

void Tablero::tecla(unsigned char key) {



}

void Tablero::mueve() {



}
