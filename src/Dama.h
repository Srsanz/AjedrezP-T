#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;


class Dama
{

	SpriteSequence sprite1{ "imagenes/reinanegra.png", 1 };
	SpriteSequence sprite2{ "imagenes/reinablanca.png", 1 };
	float x, y;
	char rojo;
	char verde;
	char azul;
public:
	// AÑADIR VECTOR 2D
	// Vector2D posicion;

	Dama();
	virtual~Dama() {};

	void setColor(char r, char v, char a);
	void setPos(float ix, float iy);
	float getPosX();
	float getPosY();
	void dibujanegro();
	void dibujablanco();

};


