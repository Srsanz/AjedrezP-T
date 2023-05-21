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



	// Inicializacion de las piezas
	/*
	for (int i = 0; i < 8; i++)
	{
		board[i][1] = new Peon(i, 1);
	}
	*/

	//Cnd consigamos la seleccion de piezas con el raton el numero se puede quitar
	//y poner solo una variable que sea el color

	/*
	//PEONES BLANCOS
	board[0][1] = new Peon(1);
	board[1][1] = new Peon(2);
	board[2][1] = new Peon(3);
	board[3][1] = new Peon(4);
	board[4][1] = new Peon(5);
	board[5][1] = new Peon(6);
	board[6][1] = new Peon(7);
	board[7][1] = new Peon(8);

	//PEONES NEGROS
	board[0][6] = new Peon(9);
	board[1][6] = new Peon(10);
	board[2][6] = new Peon(11);
	board[3][6] = new Peon(12);
	board[4][6] = new Peon(13);
	board[5][6] = new Peon(14);
	board[6][6] = new Peon(15);
	board[7][6] = new Peon(16);
	*/

	//lo he hecho con un for para ahorrar lineas
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
			if (board[xFinal][yFinal] != nullptr) { // La casilla de destino está ocupada
				return;
			}
			else { //si la casilla esta vacia

				char colorPeon = board[xInicial][yInicial]->obtenerColor();
				// Mover el peón a la posición final
				delete board[xFinal][yFinal];
				board[xFinal][yFinal] = nullptr; // Eliminar la pieza de la posición final si existe
				delete board[xInicial][yInicial];
				board[xInicial][yInicial] = nullptr; // Establecer la posición inicial como vacía
				board[xFinal][yFinal] = new Peon(colorPeon);

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


void Tablero::mueve(char letra) {

}

