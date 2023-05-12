#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;


class Torre
{

	SpriteSequence sprite1{ "imagenes/torrenegra.png", 1 };
	SpriteSequence sprite2{ "imagenes/torreblanca.png", 1 };
	float x, y;
	char rojo;
	char verde;
	char azul;
public:
	// AÑADIR VECTOR 2D
	// Vector2D posicion;

	Torre();
	virtual~Torre() {};

	void setColor(char r, char v, char a);
	void setPos(float ix, float iy);
	float getPosX();
	float getPosY();
	void dibujablanco();
	void dibujanegro();

};
