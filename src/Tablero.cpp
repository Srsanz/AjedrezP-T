#include "Tablero.h"
#include "Peon.h"
#include "Pieza.h"
#include "Caballo.h"
#include "Reina.h"
#include "Torre.h"
#include "Rey.h"
#include "Alfil.h"

Tablero::~Tablero()
{
	//pieza.destruirContenido();

	// Liberar memoria de las piezas
	/*
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			delete tablero[x][y];
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
				glColor3ub(93, 155, 155); // Color oscurito
			}
			else {
				glColor3ub(156, 208, 224); // Color clarito
			}
			glBegin(GL_QUADS);
			glVertex2i(x * cellSize, y * cellSize);
			glVertex2i((x + 1) * cellSize, y * cellSize);
			glVertex2i((x + 1) * cellSize, (y + 1) * cellSize);
			glVertex2i(x * cellSize, (y + 1) * cellSize);
			glEnd();

			// Dibujar la pieza en la casilla
			if (tablero[x][y] != nullptr) {
				glPushMatrix();
				glTranslatef(x * cellSize, y * cellSize, 0.1);
				tablero[x][y]->dibuja();
				glPopMatrix();
			}
		}
	}



}

void Tablero::inicializa() {


	x_ojo = 20;
	y_ojo = 20;
	z_ojo = 30; // habria q mirarlo bien


	

	
	tablero[1][0] = new Caballo('b');
	tablero[6][0] = new Caballo('b');
	tablero[1][7] = new Caballo('n');
	tablero[6][7] = new Caballo('n');
	tablero[3][0] = new Reina('b');
	tablero[3][7] = new Reina('n');
	tablero[0][0] = new Torre('b');
	tablero[7][0] = new Torre('b');
	tablero[0][7] = new Torre('n');
	tablero[7][7] = new Torre('n');
	tablero[4][0] = new Rey('b');
	tablero[4][7] = new Rey('n');
	tablero[2][0] = new Alfil('b');
	tablero[5][0] = new Alfil('b');
	tablero[2][7] = new Alfil('n');
	tablero[5][7] = new Alfil('n');

	for (int i = 0; i < 8; i++) {
		tablero[i][1] = new Peon('b'); //peones blancos en toda la fila 1
		tablero[i][6] = new Peon('n'); //peones negros en toda la fila 6
	}
}

int xInicial = -1, yInicial = -1;
int xFinal = -1, yFinal = -1;

void Tablero::onMouseClick(int button, int state, int x, int y) {
	
	//JAQUE MATE
	if (!estaReyEnJaqueMate(*this, turno)) {
		cout << "jaque mate" << endl;
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		// Calcular la posición del clic en términos de celdas del tablero
		int casillaX = x / 75;
		int casillaY = (600 - y) / 75;  // Convertir la coordenada y


		if (xInicial == -1 && yInicial == -1) {
			// Establecer la posición inicial del peón
			xInicial = casillaX;
			yInicial = casillaY;

			if (tablero[xInicial][yInicial] == nullptr) { //La casilla incial no tiene pieza
				xInicial = -1;
				yInicial = -1;
			}
			else if(tablero[xInicial][yInicial] != nullptr){
				if (turno % 2 != 0 && tablero[xInicial][yInicial]->obtenerColor() != 'b') {
					xInicial = -1;
					yInicial = -1;
				}

				if (turno % 2 == 0 && tablero[xInicial][yInicial]->obtenerColor() != 'n') {
					xInicial = -1;
					yInicial = -1;
				}

			}	
		}

		else {				
			xFinal = casillaX;
			yFinal = casillaY;
			char color = tablero[xInicial][yInicial]->obtenerColor();
			TipoPieza tipo= tablero[xInicial][yInicial]->obtenerTipo();
			

			
			

			//if para ver si la casilla está ocupada
			bool ocupado;
			int x = xFinal - xInicial;
			int y = yFinal - yInicial;
			int xI = xInicial, yI = yInicial;

			if (tablero[xFinal][yFinal] == nullptr) {
				ocupado = 0;
			}
			else if (tablero[xFinal][yFinal] != nullptr) {
				ocupado = 1;
				char color2 = tablero[xFinal][yFinal]->obtenerColor();
				if (color == color2) return;
			}

			if (!tablero[xInicial][yInicial]->mover(xInicial, yInicial, xFinal, yFinal, ocupado, *this)) {
				// Movimiento inválido, salir de la función
				xInicial = -1;
				yInicial = -1;
				xFinal = -1;
				yFinal = -1;
				return;
			}

			bool propio = evitarJaquePropio(*this, xInicial, yInicial, xFinal, yFinal);
			//if para ver si lo dejas en jaque a tu propio rey
			if (propio) {
				cout << "TE ESTAS PONIENDO EN JAQUE\n";
				xInicial = -1;
				yInicial = -1;
				xFinal = -1;
				yFinal = -1;
				return;
			}

			else { // La casilla está vacía
				// Mover el peón a la posición final
				delete tablero[xFinal][yFinal];
				tablero[xFinal][yFinal] = nullptr; // Eliminar la pieza de la posición final si existe
				delete tablero[xInicial][yInicial];
				tablero[xInicial][yInicial] = nullptr; // Establecer la posición inicial como vacía

				if (tipo == peon) {
					tablero[xFinal][yFinal] = new Peon(color);
				}
				else if (tipo == caballo) {
					tablero[xFinal][yFinal] = new Caballo(color);
				}
				else if (tipo == reina) {
					tablero[xFinal][yFinal] = new Reina(color);
				}
				else if (tipo == torre) {
					tablero[xFinal][yFinal] = new Torre(color);
				}
				else if (tipo == rey) {
					tablero[xFinal][yFinal] = new Rey(color);
				}

				else if (tipo == alfil) {
					tablero[xFinal][yFinal] = new Alfil(color);
				}

				bool reyenjaque = estaReyEnJaque(*this, color, ocupado);
				if (reyenjaque) {
					//cout << "JAQUE";
				}
				bool fin=JM(reyenjaque, propio);
				if (fin == true) {
					cout << "Fin" << endl;
				}
				else if (fin == false) {
					cout << "AA" << endl;
				}

				// Reiniciar las posiciones inicial y final del peón
				xInicial = -1;
				yInicial = -1;
				xFinal = -1;
				yFinal = -1;
				turno++;
				
				

				glutPostRedisplay(); // Redibujar el tablero con el peón movido

			}

			
		}
	}
}


bool Tablero::estaReyEnJaque(Tablero& t, char colorpieza, bool ocupado) {
	int yRey = -1;
	int xRey = -1;

	// Encontrar la posición del rey del color dado en el tablero
	for (int columna = 0; columna < 8; ++columna) {
		for (int fila = 0; fila < 8; ++fila) {
			if (t.tablero[columna][fila] != nullptr) {
				if (t.tablero[columna][fila]->obtenerTipo() == rey && t.tablero[columna][fila]->obtenerColor() != colorpieza) {
					yRey = fila;
					xRey = columna;
					break;

				}
			}
		}
	}

	// Verificar si alguna pieza enemiga amenaza al rey
	for (int fila = 0; fila < 8; ++fila) {
		for (int columna = 0; columna < 8; ++columna) {
			if (t.tablero[columna][fila] != nullptr) {
				Pieza* pieza = t.tablero[columna][fila];

				if (pieza->color == colorpieza) {
					// Verificar si la pieza puede capturar al rey
					bool capturaPosible = false;
					switch (pieza->tipo) {
					case peon:
											

						if (colorpieza == 'n') {
							// Movimiento válido: captura diagonal a la derecha e izuqierda
							if (yRey == fila - 1 && (xRey == columna + 1 || xRey == columna - 1)) {
								cout << "Jaque peon negro\n";
								return true;
							}
						}
						// Si el peón es negro
						else if (colorpieza == 'b') {
							// Movimiento válido: captura diagonal a la izquierda y derecha
							if (yRey == fila + 1 && (xRey == columna + 1 || xRey == columna - 1)) {
								cout << "Jaque peon blanco\n";
								return true;
							}
						}
						break;

					case caballo:
							if (tablero[columna][fila]->mover(columna, fila, xRey, yRey, ocupado, t)) {
								cout << "Jaque caballo\n";
								return true;
							}
						break;
					case alfil:
						if (tablero[columna][fila]->mover(columna, fila, xRey, yRey, ocupado, t)) {
							cout << "Jaque alfil\n";
							return true;
						}
						break;
					case torre:
						if (tablero[columna][fila]->mover(columna, fila, xRey, yRey, ocupado, t)) {
							cout << "Jaque torre\n";
							return true;
						}
						break;
					case reina:
						if (tablero[columna][fila]->mover(columna, fila, xRey, yRey, ocupado, t)) {
							cout << "Jaque reina\n";
							return true;
						}
						break;
					case rey:
						// No debería haber otro rey en el tablero
						break;
					default:
						break;
					}

					if (capturaPosible) {
						// El rey está en jaque
						return true;
					}
				}
			}
		}
	}

	// El rey no está en jaque
	return false;
}


bool Tablero::evitarJaquePropio(Tablero& t, int xInicial, int yInicial, int xFinal, int yFinal) {

	int x1 = xInicial, y1 = yInicial;
	TipoPieza tipoPieza = tablero[xInicial][yInicial]->obtenerTipo();
	char color = tablero[xInicial][yInicial]->obtenerColor();

	bool variable = false;

	char colorRey;

	TipoPieza tipoFinal = None;
	char colorFinal = 'a';

	if (color == 'b') colorRey = 'n';
	else colorRey = 'b';


	if (tablero[xFinal][yFinal] != nullptr) {
		tipoFinal = tablero[xFinal][yFinal]->obtenerTipo();
		colorFinal = tablero[xFinal][yFinal]->obtenerColor();
	}

	delete tablero[x1][y1];
	tablero[x1][y1] = nullptr;

	switch (tipoPieza) {
	case(peon):
		tablero[xFinal][yFinal] = new Peon(color);
		variable = estaReyEnJaque(*this, colorRey, 1);
		if (variable == true) {
			delete tablero[xFinal][yFinal];
			tablero[xFinal][yFinal] = nullptr;
			tablero[xInicial][yInicial] = new Peon(color);
			if (color != 'a')
				dibujaPiezaBorrad(*this, tipoFinal, xFinal, yFinal, colorFinal);
			return true;
		}
		break;

	case(caballo):
		tablero[xFinal][yFinal] = new Caballo(color);
		variable = estaReyEnJaque(*this, colorRey, 1);
		if (variable == true) {
			delete tablero[xFinal][yFinal];
			tablero[xFinal][yFinal] = nullptr;
			tablero[xInicial][yInicial] = new Caballo(color);
			if (color != 'a')
				dibujaPiezaBorrad(*this, tipoFinal, xFinal, yFinal, colorFinal);
			return true;
		}
		break;

	case(torre):
		tablero[xFinal][yFinal] = new Torre(color);
		variable = estaReyEnJaque(*this, colorRey, 1);
		if (variable == true) {
			delete tablero[xFinal][yFinal];
			tablero[xFinal][yFinal] = nullptr;
			tablero[xInicial][yInicial] = new Torre(color);
			if (color != 'a')
				dibujaPiezaBorrad(*this, tipoFinal, xFinal, yFinal, colorFinal);
			return true;
		}
		break;

	case(alfil):
		tablero[xFinal][yFinal] = new Alfil(color);
		variable = estaReyEnJaque(*this, colorRey, 1);
		if (variable == true) {
			delete tablero[xFinal][yFinal];
			tablero[xFinal][yFinal] = nullptr;
			tablero[xInicial][yInicial] = new Alfil(color);
			if (color != 'a')
				dibujaPiezaBorrad(*this, tipoFinal, xFinal, yFinal, colorFinal);
			return true;
		}
		break;


	case(reina):
		tablero[xFinal][yFinal] = new Reina(color);
		variable = estaReyEnJaque(*this, colorRey, 1);
		if (variable == true) {
			delete tablero[xFinal][yFinal];
			tablero[xFinal][yFinal] = nullptr;
			tablero[xInicial][yInicial] = new Reina(color);
			if (color != 'a')
				dibujaPiezaBorrad(*this, tipoFinal, xFinal, yFinal, colorFinal);
			return true;
		}

		break;

	case(rey):
		tablero[xFinal][yFinal] = new Rey(color);
		variable = estaReyEnJaque(*this, colorRey, 1);
		if (variable == true) {
			delete tablero[xFinal][yFinal];
			tablero[xFinal][yFinal] = nullptr;
			tablero[xInicial][yInicial] = new Rey(color);
			if (color != 'a')
				dibujaPiezaBorrad(*this, tipoFinal, xFinal, yFinal, colorFinal);
			return true;
		}

		break;

	}


}





void Tablero::dibujaPiezaBorrad(Tablero& t, TipoPieza tipoFinal, int xFinal, int yFinal, char colorFinal) {
	switch (tipoFinal) {
	case(peon):
		tablero[xFinal][yFinal] = new Peon(colorFinal);
		break;

	case(caballo):
		tablero[xFinal][yFinal] = new Caballo(colorFinal);
		break;

	case(torre):
		tablero[xFinal][yFinal] = new Torre(colorFinal);
		break;

	case(alfil):
		tablero[xFinal][yFinal] = new Alfil(colorFinal);
		break;

	case(reina):
		tablero[xFinal][yFinal] = new Reina(colorFinal);
		break;

	case(rey):
		tablero[xFinal][yFinal] = new Rey(colorFinal);
		break;
	}



}

bool Tablero::JM(bool rj, bool prop) {
	if (rj && !prop) {
		return true;
	}
	else return false;
}

bool Tablero::estaReyEnJaqueMate(const Tablero& t, int turno) {
	char color;

	if (turno % 2 != 0) {
		color = 'b';
	}

	if (turno % 2 == 0) {
		color = 'n';
	}


	for (int xInicial = 0; xInicial < 8; xInicial++) {
		for (int yInicial = 0; yInicial < 8; yInicial++) {
			for (int xFinal = 0; xFinal < 8; xFinal++) {
				for (int yFinal = 0; yFinal < 8; yFinal++) {
					if (tablero[xInicial][yInicial] != nullptr) {
						//if (tablero[xInicial][yInicial]->obtenerColor() == color) {
							if (evitarJaquePropio(*this, xInicial, yInicial, xFinal, yFinal)) {
								cout << "mov invalido" << endl;
								// mov invalido
							}
							if (!evitarJaquePropio(*this, xInicial, yInicial, xFinal, yFinal)) {
								cout << "mov valido" << endl;
								return true;
								// mov valido
							}
						//}
					}
									
				}
			}
		}
	}

	return false;
}
