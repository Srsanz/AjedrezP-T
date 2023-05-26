#pragma once
#include "Tablero.h"
#include "Puzles.h"


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

	enum Estado { INICIO, PARTIDA, FIN, PUZLES, PAUSA };
	Estado estado;

	Tablero tablero;
	Puzles puzles;
};

