#include "Tablero.h"
#include "Peon.h"
#include "Pieza.h"
#include "Caballo.h"

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
				glColor3ub(156, 208, 224); // Color clarito
			}
			else {
				glColor3ub(93, 155, 155); // Color oscurito
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


	board[1][0] = new Caballo('b');
	board[6][0] = new Caballo('b');
	board[1][7] = new Caballo('n');
	board[6][7] = new Caballo('n');
	for (int i = 0; i < 8; i++) {
		board[i][1] = new Peon('b'); //peones blancos en toda la fila 1
		board[i][6] = new Peon('n'); //peones negros en toda la fila 6
	}
}

int xInicial = -1, yInicial = -1;
int xFinal = -1, yFinal = -1;

void Tablero::onMouseClick(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		// Calcular la posición del clic en términos de celdas del tablero
		int casillaX = x / 75;
		int casillaY = (600 - y) / 75;  // Convertir la coordenada y

		if (xInicial == -1 && yInicial == -1) {
			// Establecer la posición inicial del peón
			xInicial = casillaX;
			yInicial = casillaY;
			if (board[xInicial][yInicial] == nullptr) { //La casilla incial no tiene pieza
				xInicial = -1;
				yInicial = -1;
			}
		}
		else {
			xFinal = casillaX;
			yFinal = casillaY;
			char color = board[xInicial][yInicial]->obtenerColor();


			if (!board[xInicial][yInicial]->mover(xInicial, yInicial, xFinal, yFinal)) {
				//return; // Movimiento inválido, salir de la función
				xInicial = -1;
				yInicial = -1;
				xFinal = -1;
				yFinal = -1;
			}
			else { // La casilla está vacía
				// Mover el peón a la posición final
				delete board[xFinal][yFinal];
				board[xFinal][yFinal] = nullptr; // Eliminar la pieza de la posición final si existe
				delete board[xInicial][yInicial];
				board[xInicial][yInicial] = nullptr; // Establecer la posición inicial como vacía
				board[xFinal][yFinal] = new Peon(color);
				// Reiniciar las posiciones inicial y final del peón
				xInicial = -1;
				yInicial = -1;
				xFinal = -1;
				yFinal = -1;

				// Redibujar el tablero con el peón movido
				glutPostRedisplay();
			}
		}
	}
}




