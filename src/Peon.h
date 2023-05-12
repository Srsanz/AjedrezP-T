#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;


class Peon
{

	SpriteSequence sprite1{ "imagenes/peonnegro.png", 1 };
	SpriteSequence sprite2{ "imagenes/peonblanco.png", 1 };
	float x, y;
	char rojo;
	char verde;
	char azul;
public:
	// AÑADIR VECTOR 2D
	// Vector2D posicion;
	
	Peon();
	virtual~Peon(){};

	void setColor(char r, char v, char a);
	void setPos(float ix, float iy);
	float getPosX();
	float getPosY();
	void mover();
	void dibujablanco();
	void dibujanegro();

};
