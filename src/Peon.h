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
	SpriteSequence sprite1{ "imagenes/peonblanco.png", 1 };
	SpriteSequence sprite2{ "imagenes/peonnegro.png", 1 };
	//int x, y;
	int numero;

public:
	// AÑADIR VECTOR 2D
	// Vector2D posicion;

	Peon(int num) {
		numero = num;
		tipo = TipoPieza::Peon;
		sprite1.setCenter(-0.5, -0.5);
		sprite1.setSize(4, 4);
		sprite2.setCenter(-0.5, -0.5);
		sprite2.setSize(4, 4);
		altura = 1.8f;
	}

	virtual~Peon(){};

	float altura;

	void dibuja() override ;
	void mover() override ;

	// FUNCIONES DEL PEON
	/*
	void setPos(float ix, float iy);
	float getPosX();
	float getPosY();
	void mover();

	*/

};