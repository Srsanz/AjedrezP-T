#pragma once
#include "Pieza.h"
#include "ETSIDI.h"
#include "freeglut.h"
using ETSIDI::SpriteSequence;




class Caballo : public Pieza
{
	SpriteSequence sprite1{ "imagenes/caballoblanco.png", 1 };
	SpriteSequence sprite2{ "imagenes/caballonegro.png", 1 };
	//int x, y;
	//int numero;

public:
	// AÑADIR VECTOR 2D
	// Vector2D posicion;

	Caballo(char _color) {
		color = _color;
		tipo = TipoPieza::caballo;
		sprite1.setCenter(-0.5, -0.5); //blancas
		sprite1.setSize(4, 4);
		sprite2.setCenter(-0.5, -0.5);
		sprite2.setSize(4, 4);

	}


	virtual~Caballo() {};


	void dibuja() override;

	
	bool mover(int xInicial, int yInicial, int xFinal, int yFinal) override;

	

};
