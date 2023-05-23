#pragma once
#include "Pieza.h"
#include "ETSIDI.h"
#include "freeglut.h"
using ETSIDI::SpriteSequence;

class Torre :public Pieza
{
	SpriteSequence sprite1{ "imagenes/torreblanca.png", 1 };
	SpriteSequence sprite2{ "imagenes/torrenegra.png", 1 };
public:
	Torre(char _color) {
		color = _color;
		tipo = TipoPieza(torre);
		sprite1.setCenter(-0.5, -0.5); //blancas
		sprite1.setSize(4, 4);
		sprite2.setCenter(-0.5, -0.5);
		sprite2.setSize(4, 4);

	}


	virtual~Torre() {};



	void dibuja() override;

	// PRUBEBA
	bool mover(int xInicial, int yInicial, int xFinal, int yFinal, bool ocupado) override;

};


