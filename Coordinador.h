#pragma once
#include "Tablero.h"


class Coordinador
{
public:

	Coordinador() { estado = INICIO; };
	virtual ~Coordinador() {};

	void dibuja();
	void mueve();
	void tecla(unsigned char key);

protected:

	enum Estado { INICIO, PARTIDA, FIN };
	Estado estado;

	Tablero tablero;
};

