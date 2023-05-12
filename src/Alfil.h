#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;


class Alfil
{

	SpriteSequence sprite1{ "imagenes/alfilnegro.png", 1 };
	SpriteSequence sprite2{ "imagenes/alfilblanco.png", 1 };
	float x, y;
	char rojo;
	char verde;
	char azul;
public:
	// AÑADIR VECTOR 2D
	// Vector2D posicion;

	Alfil();
	virtual~Alfil() {};

	void setColor(char r, char v, char a);
	void setPos(float ix, float iy);
	float getPosX();
	float getPosY();
	void dibujanegro();
	void dibujablanco();

};
