#pragma once
#include "Puzle1.h"
#include "Puzle2.h"
#include "Puzle3.h"


class Puzles
{
public:

	Puzles() { estado = INICIOPUZLES; };
	virtual ~Puzles() {};

	void dibuja();
	void mueve();
	void tecla(unsigned char key);
	void onMouseClick(int button, int state, int x, int y);

protected:

	enum Estado1 { INICIOPUZLES, PUZLE1, PUZLE2, PUZLE3, FIN };
	Estado1 estado;

	Puzle1 tablero1;
	Puzle2 tablero2;
	Puzle3 tablero3;
};