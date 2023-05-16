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
	void tecla(unsigned char key);   // Cambiar por codigo del raton
	void mueve();

private:
	// Creacion matriz de piezas
	Pieza* board[8][8];

	// Creacion de las piezas
	// Peon peon1;


	float x_ojo;
	float y_ojo;
	float z_ojo;

};

