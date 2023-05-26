#pragma once
#include "Tablero.h"
#include "Puzles.h"


class Coordinador
{
public:

	Coordinador() { estado = INICIO; };
	virtual ~Coordinador() {};

	void dibuja();
	void tecla(unsigned char key);
	void onMouseClick(int button, int state, int x, int y);
	
	friend class Tablero;


protected:

	enum Estado { INICIO, PARTIDA, FIN, PUZLES, PAUSA, INSTRUCCIONES};
	Estado estado;

	Tablero tablero;
	Puzles puzles;

	
};

