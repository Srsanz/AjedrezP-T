#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;


class Caballo
{

	SpriteSequence sprite1{ "imagenes/caballonegro.png", 1 };
	SpriteSequence sprite2{ "imagenes/caballoblanco.png", 1 };
	float x, y;
	char rojo;
	char verde;
	char azul;
public:
	// AÑADIR VECTOR 2D
	// Vector2D posicion;

	Caballo();
	virtual~Caballo() {};

	void setColor(char r, char v, char a);
	void setPos(float ix, float iy);
	float getPosX();
	float getPosY();
	void dibujanegro();
	void dibujablanco();

};

