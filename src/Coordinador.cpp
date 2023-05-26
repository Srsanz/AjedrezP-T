#include "Coordinador.h"
#include "freeglut.h"
#include <math.h>
#include "ETSIDI.h"

void Coordinador::dibuja()
{
	if (estado == INICIO) {
		gluLookAt(0, 0, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)

		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Ajedrez", -5, 9);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -10, 7);
		ETSIDI::printxy("PULSE LA TECLA -P- PARA IR A LOS PUZLES", -10, 5);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -10, 3);
		ETSIDI::printxy("P&T Ajedrez", 2, 1);
	}
	else if (estado == PARTIDA)
	{
		tablero.dibuja();
	}
	else if (estado == PUZLES)
	{
		puzles.dibuja();
	}
	else if (estado == PAUSA)
	{
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("PAUSA", -5, 0);
	}
	else if (estado == FIN)
	{
		tablero.dibuja();
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("FIN de la partida, GRACIAS POR JUGAR", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
	}


}

void Coordinador::tecla(unsigned char key)
{
	if (estado == INICIO)
	{
		if (key == 'e'||key=='E')
		{
			tablero.inicializa();
			estado = PARTIDA;
		}
		if (key == 's')
			exit(0);
		if (key == 'p')
		{
			puzles.dibuja();
			estado = PUZLES;
		}
	}
	else if (estado == PARTIDA)
	{
		if (key == 'c')
			estado = INICIO;
		if (key == 'p') {
			estado = PAUSA;
		}
	}
	else if (estado == FIN)
	{
		if (key == 'c')
			estado = INICIO;
	}
	else if (estado == PAUSA)
	{
		if (key == 'p')
			estado = PARTIDA;
	}
	else if (estado == PUZLES) {
		puzles.tecla(key);
	}
	if (key == 'c')
	{
		estado = INICIO;
	}	
	

}

void Coordinador:: onMouseClick(int button, int state, int x, int y) {
	if (estado == PARTIDA) {
		tablero.onMouseClick(button, state, x, y);
	}
	if (estado == PUZLES) {
		puzles.onMouseClick(button, state, x, y);
	}


	glutPostRedisplay();
}

void Coordinador::mueve()
{
	if (estado == PARTIDA) {

		//tablero.mueve();
		// METER MOVIMINETO DE LA PARTIDA
	}
}
