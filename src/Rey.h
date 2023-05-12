#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;


class Rey
{

	SpriteSequence sprite1{ "imagenes/reynegro.png", 1 };
	SpriteSequence sprite2{ "imagenes/reyblanco.png", 1 };
	float x, y;
	char rojo;
	char verde;
	char azul;
public:
	// AÑADIR VECTOR 2D
	// Vector2D posicion;

	Rey();
	virtual~Rey() {};

	void setColor(char r, char v, char a);
	void setPos(float ix, float iy);
	float getPosX();
	float getPosY();
	void dibujablanco();
	void dibujanegro();

};