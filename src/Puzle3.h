#pragma once
#include "Peon.h"
#include "ETSIDI.h"
#include "freeglut.h"
#include "Pieza.h"
using ETSIDI::SpriteSequence;

const int piezeSize4 = 1;
const int cellSize4 = 5;

class Puzle3
{
	SpriteSequence copa{ "imagenes/copa.png", 1 };
	SpriteSequence error{ "imagenes/error.png", 1 };

public:
	Puzle3() {
		copa.setCenter(-15, -15); //blancas
		copa.setSize(10, 10);
		error.setCenter(-15, -15);
		error.setSize(10, 10);
		// Inicializacion del tablero	
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				tablero3[x][y] = nullptr;
			}
		}
	};
	~Puzle3();
	bool heganado = false, errorcruz = false;
	void dibujacopa() {
		glPushMatrix();
		glColor3f(1.0f, 0.0f, 0.0f);
		copa.draw(); //blanca
		glPopMatrix();
	}
	void dibujaerror() {
		glPushMatrix();
		glColor3f(1.0f, 0.0f, 0.0f);
		error.draw(); //blanca
		glPopMatrix();
	}
	void dibuja();
	void inicializa();
	void onMouseClick(int button, int state, int x, int y); //Obtiene la posicion del raton y mueve pieza

	friend class Peon;
	friend class Reina;
	friend class Rey;
	friend class Torre;
	friend class Alfil;
	friend class Caballo;
	friend class Pieza;

private:
	Pieza* tablero3[8][8];
	// Creacion matriz de piezas


	// Creacion de las piezas
	// Peon peon1;


	float x_ojo;
	float y_ojo;
	float z_ojo;

};