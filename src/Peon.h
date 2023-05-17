#pragma once
#include "Pieza.h"
#include "Vector2D.h"
#include "ETSIDI.h"
#include "freeglut.h"
using ETSIDI::SpriteSequence;

const int piezeSize = 1;
const int cellSize = 5;

class Peon : public Pieza
{

	SpriteSequence sprite1{ "imagenes/peonnegro.png", 1 };
	SpriteSequence sprite2{ "imagenes/peonblanco.png", 1 };
	int x, y;

public:
	// AÑADIR VECTOR 2D
	// Vector2D posicion;

	Peon() {
		tipo = TipoPieza::Peon;


	}
	//virtual~Peon(){};

	//void dibuja() const override ;


	void dibuja() const override {

		glColor3f(1.0, 0.0, 0.0); // Color amarillo
		glBegin(GL_QUADS);
		glVertex2i(0, 0);
		glVertex2i(cellSize, 0);
		glVertex2i(cellSize, cellSize);
		glVertex2i(0, cellSize);
		glEnd();


	}

	// FUNCIONES DEL PEON
	/*
	void setPos(float ix, float iy);
	float getPosX();
	float getPosY();
	void mover();

	*/
};