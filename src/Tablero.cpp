#include "Tablero.h"
#include "Peon.h"
#include "Pieza.h"


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



	for (int i = 0; i < 8; i++) {
		board[i][1] = new Peon('b'); //peones blancos en toda la fila 1
		board[i][6] = new Peon('n'); //peones negros en toda la fila 6
	}
}

int xInicial = -1, yInicial = -1;
int xFinal = -1, yFinal = -1;

void Tablero::onMouseClick(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		// Calcular la posici�n del clic en t�rminos de celdas del tablero
		int casillaX = x / 75;
		int casillaY = (600 - y) / 75;  // Convertir la coordenada y

		if (xInicial == -1 && yInicial == -1) {
			// Establecer la posici�n inicial del pe�n
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
			char colorPeon = board[xInicial][yInicial]->obtenerColor();

			// Verificar si el movimiento es v�lido para un pe�n
			bool movimientoValido = false;

			// Si el pe�n es blanco
			if (colorPeon == 'b') {
				// Movimiento v�lido: mover hacia adelante una casilla
				if (yFinal == yInicial + 1 && xFinal == xInicial) {
					movimientoValido = true;
				}
				// Movimiento v�lido: mover hacia adelante dos casillas desde la posici�n inicial
				else if (yFinal == yInicial + 2 && xFinal == xInicial && yInicial == 1) {
					movimientoValido = true;
				}
				// Movimiento v�lido: captura diagonal a la derecha
				else if (yFinal == yInicial + 1 && (xFinal == xInicial + 1 || xFinal == xInicial - 1)) {
					movimientoValido = true;
				}
			}
			// Si el pe�n es negro
			else if (colorPeon == 'n') {
				// Movimiento v�lido: mover hacia adelante una casilla
				if (yFinal == yInicial - 1 && xFinal == xInicial) {
					movimientoValido = true;
				}
				// Movimiento v�lido: mover hacia adelante dos casillas desde la posici�n inicial
				else if (yFinal == yInicial - 2 && xFinal == xInicial && yInicial == 6) {
					movimientoValido = true;
				}
				// Movimiento v�lido: captura diagonal a la izquierda
				else if (yFinal == yInicial - 1 && (xFinal == xInicial + 1 || xFinal == xInicial - 1)) {
					movimientoValido = true;
				}
			}

			if (!movimientoValido) {
				return; // Movimiento inv�lido, salir de la funci�n
			}

			if ((board[xFinal][yFinal] != nullptr) && (yFinal == (yInicial - 1 || yInicial + 1) && (xFinal == xInicial + 1 || xFinal == xInicial - 1))) { // La casilla de destino est� ocupada y el movimiento no es diagonal
				return;
			}
			else { // La casilla est� vac�a
				// Mover el pe�n a la posici�n final
				delete board[xFinal][yFinal];
				board[xFinal][yFinal] = nullptr; // Eliminar la pieza de la posici�n final si existe
				delete board[xInicial][yInicial];
				board[xInicial][yInicial] = nullptr; // Establecer la posici�n inicial como vac�a
				board[xFinal][yFinal] = new Peon(colorPeon);
				// Reiniciar las posiciones inicial y final del pe�n
				xInicial = -1;
				yInicial = -1;
				xFinal = -1;
				yFinal = -1;

				// Redibujar el tablero con el pe�n movido
				glutPostRedisplay();
			}
		}
	}
}




void Tablero::mueve(char letra) {
	if (letra == 'w') {
		delete board[0][1];
		board[0][1] = nullptr;
	}
}
