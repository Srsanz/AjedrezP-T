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
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 5);
		ETSIDI::printxy("P&T Ajedrez", 2, 1);
	}
	else if (estado == PARTIDA)
	{
		tablero.dibuja();
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
		if (key == 'e')
		{
			tablero.inicializa();
			estado = PARTIDA;
		}
		if (key == 's')
			exit(0);
	}
	else if (estado == PARTIDA)
	{
		/*glutMouseFunc([](int button, int state, int x, int y) {
			Tablero::confirmaMouse(button, state, x, y, tablero);
			});*/
	}
	else if (estado == FIN)
	{
		if (key == 'c')
			estado = INICIO;
	}
	
	if (estado == PARTIDA && key == 'w') {
		tablero.mueve('w');
	}

}

void Coordinador:: onMouseClick(int button, int state, int x, int y) {

	tablero.onMouseClick(button, state,x,y);

	glutPostRedisplay();
}
void Coordinador::mueve()
{
	if (estado == PARTIDA) {

		//tablero.mueve();
		// METER MOVIMINETO DE LA PARTIDA
	}
}
