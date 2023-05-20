#pragma once
#include "Peon.h"
#include "Pieza.h"




class Tablero
{

public:
	// Constructor en blanco
	//Tablero() {};
	~Tablero();

	void dibuja();
	void inicializa();
	void mueve(char letra);
	void onMouseClick(int button, int state, int x, int y); //Obtiene la posicion del raton y mueve pieza
	static void confirmaMouse(int button, int state, int x, int y, Tablero* tablero)
	{
		tablero->onMouseClick(button, state, x, y);
	}
	
private:
	Pieza* board[8][8];
	// Creacion matriz de piezas
	

	// Creacion de las piezas
	// Peon peon1;


	float x_ojo;
	float y_ojo;
	float z_ojo;

};

