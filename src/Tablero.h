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
	void onMouseClick(int button, int state, int x, int y); //Obtiene la posicion del raton y mueve pieza
	void mueve(char letra);

	
private:
	Pieza* board[8][8];
	// Creacion matriz de piezas
	

	// Creacion de las piezas
	// Peon peon1;


	float x_ojo;
	float y_ojo;
	float z_ojo;

};

