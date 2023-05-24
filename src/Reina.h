#pragma once
#include "Pieza.h"
#include "ETSIDI.h"
#include "freeglut.h"
#include "Tablero.h"
using ETSIDI::SpriteSequence;




class Reina : public Pieza
{
	SpriteSequence sprite1{ "imagenes/reinablanca.png", 1 };
	SpriteSequence sprite2{ "imagenes/reinanegra.png", 1 };
	//int x, y;
	//int numero;

public:
	// AÑADIR VECTOR 2D
	// Vector2D posicion;

	Reina(char _color) {
		color = _color;
		tipo = TipoPieza(reina);
		sprite1.setCenter(-0.5, -0.5); //blancas
		sprite1.setSize(4, 4);
		sprite2.setCenter(-0.5, -0.5);
		sprite2.setSize(4, 4);

	}


	virtual~Reina() {};


	void dibuja() override;


	bool mover(int xInicial, int yInicial, int xFinal, int yFinal, bool ocupado, Tablero& t) override;



};
