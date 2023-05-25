#include "Puzles.h"
#include "freeglut.h"
#include <math.h>
#include "ETSIDI.h"

void Puzles::dibuja()
{
	if (estado == INICIOPUZLES) {
		gluLookAt(0, 0, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)

		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Puzles", -5, 9);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -1- PARA IR AL PUZLE 1", -10, 7);
		ETSIDI::printxy("PULSE LA TECLA -2- PARA IR AL PUZLE 2", -10, 5);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -10, 3);
		ETSIDI::printxy("P&T Ajedrez", 2, 0);
	}
	else if (estado == PUZLE1)
	{
		tablero1.dibuja();
	}
	else if (estado == PUZLE2)
	{
		tablero2.dibuja();
	}
	/*else if (estado == PUZLE3)
	{
		tablero3.dibuja();
	}
	else if (estado == FIN)
	{
		tablero.dibuja();
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("FIN de la partida, GRACIAS POR JUGAR", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
	}*/


}

void Puzles::tecla(unsigned char key)
{
	if (estado == INICIOPUZLES)
	{
		if (key == 's')
			exit(0);
		if (key == '1')
		{
			tablero1.inicializa();
			estado = PUZLE1;
		}
		if (key == '2')
		{
			tablero2.inicializa();
			estado = PUZLE2;
		}
		if (key == '3')
		{
			//tablero3.inicializa();
			estado = PUZLE3;
		}
	}
	else if (estado == PUZLE1) {
		if (key == 'x')
		{
			estado = INICIOPUZLES;
		}
	}

}

void Puzles::onMouseClick(int button, int state, int x, int y) {

	if (estado == PUZLE1) {
		tablero1.onMouseClick(button, state, x, y);
	}

	else if (estado == PUZLE2) {
		tablero2.onMouseClick(button, state, x, y);
	}
	else if (estado == PUZLE3) {
		//tablero3.onMouseClick(button, state, x, y);
	}

	glutPostRedisplay();
}

void Puzles::mueve()
{

}