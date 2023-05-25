#pragma once
#include "Peon.h"
#include "Pieza.h"
#include <iostream>
using namespace std;

const int piezeSize = 1;
const int cellSize = 5;


class Tablero
{
private:
	Pieza* tablero[8][8];
	int turno;
	// Creacion matriz de piezas


	// Creacion de las piezas
	// Peon peon1;


	float x_ojo;
	float y_ojo;
	float z_ojo;

public:
	// Constructor en blanco
	Tablero():turno(1){
		// Inicializacion del tablero	
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				tablero[x][y] = nullptr;
			}
		}
	};

	~Tablero();

	void dibuja();
	void inicializa();
	//void mueve(char letra);
	void onMouseClick(int button, int state, int x, int y); //Obtiene la posicion del raton y mueve pieza
	static void confirmaMouse(int button, int state, int x, int y, Tablero& tablero)
	{
		tablero.onMouseClick(button, state, x, y);
	}
	friend class Peon;
	friend class Reina;
	friend class Rey;
	friend class Torre;
	friend class Alfil;
	friend class Caballo;
	friend class Pieza;

	bool estaReyEnJaque(Tablero& t, char colorRey,bool ocupado);
	bool evitarJaquePropio(Tablero& t, int xInicial, int yInicial);
};

