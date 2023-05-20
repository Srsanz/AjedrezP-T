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
	void onMouseClick(int button, int state, int x, int y);

protected:

	enum Estado { INICIO, PARTIDA, FIN };
	Estado estado;

	Tablero tablero;
};

