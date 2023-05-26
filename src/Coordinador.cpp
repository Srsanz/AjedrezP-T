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
		ETSIDI::printxy("Ajedrez", -5, 15);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -10, 9);
		ETSIDI::printxy("PULSE LA TECLA -P- PARA IR A LOS PUZLES", -10, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -10, 5);
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
		
		gluLookAt(0, 0, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		switch (tablero.contadorblanco) {
		case 1:
			
			ETSIDI::printxy("1", -1, 10);
			break;
		case 2:
			
			ETSIDI::printxy("2", -1, 10);
			break;
		case 3:
			
			ETSIDI::printxy("3", -1, 10);
			break;
		case 4:
			
			ETSIDI::printxy("4", -1, 10);
			break;
		case 5:
			
			ETSIDI::printxy("5", -1, 10);
			break;
		case 0:
			
			ETSIDI::printxy("0", -1, 10);
			break;
		default:
			
			ETSIDI::printxy("5", -1, 10);
			break;
		}

		switch (tablero.contadornegro) {
		case 1:
			ETSIDI::printxy("1", 1, 10);
			break;
		case 2:
			ETSIDI::printxy("2", 1, 10);
			break;
		case 3:
			ETSIDI::printxy("3", 1, 10);
			break;
		case 4:
			ETSIDI::printxy("4", 1, 10);
			break;
		case 5:
			ETSIDI::printxy("5", 1, 10);
			break;
		case 0:
			ETSIDI::printxy("0", 1, 10);
			break;
		default:
			ETSIDI::printxy("5", 1, 10);
			break;

		}
			

		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("¿JAQUE MATE?", -10, 13);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::printxy("BLANCAS", -10, 10);
		ETSIDI::printxy("NEGRAS", 3, 10);
		
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Pulsa <p> para continuar la partida", -10, 5);
		ETSIDI::printxy("Pulsa <s> para terminar la partida", -10, 3);

	}
	else if (estado == FIN)
	{
		gluLookAt(0, 0, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		
		ETSIDI::setTextColor(1, 1, 0);
		
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("FINAL DE LA PARTIDA", -10, 13);

		if ((tablero.turno % 2) != 0) {
			ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
			ETSIDI::printxy("LAS NEGRAS GANAN", -10, 9);
			ETSIDI::play("sonidos/vnegras.wav");
		}
		else if ((tablero.turno % 2) == 0) {
			ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
			ETSIDI::printxy("LAS BLANCAS GANAN", -10, 9);
			ETSIDI::play("sonidos/vblancas.wav");
		}
		

		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("FIN de la partida, GRACIAS POR JUGAR", -10, 5);
		ETSIDI::printxy("Pulsa -C- para continuar", -10, 3);
	}
	else if (estado == INSTRUCCIONES) {
		gluLookAt(0, 0, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)

		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("INSTRUCCIONES", -5, 15);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("En partida, pulsa sobre la pieza que", -15, 9);
		ETSIDI::printxy("quieras mover y despues su posici�n final.", -15, 7);
		ETSIDI::printxy("Cuando estes en Jaque Mate, pulsa <P>", -15, 5);
		ETSIDI::printxy("Cuando hayas hecho 5 Jaques habras ganado, pulsa <F>", -15, 3);
		ETSIDI::printxy("A disfrutar!", -5, -3);
		ETSIDI::printxy("Pulsa <E> para empezar", -5, -5);
	}

}

void Coordinador::tecla(unsigned char key)
{
	if (estado == INICIO)
	{
		if (key == 'e'||key=='E')
		{
			estado = INSTRUCCIONES;
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
		if (key == 'p') {
			estado = PAUSA;
		}
		if (key == 'f' && tablero.fin) {
			estado = FIN;
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
		if (key == 's')
			estado = INICIO;
	}
	else if (estado == PUZLES) {
		puzles.tecla(key);
		if (key == 'c')
			estado = INICIO;
	}
	else if (estado == INSTRUCCIONES)
	{
		if (key == 'e' || key == 'E')
		{
			tablero.dibuja();
			tablero.inicializa();
			estado = PARTIDA;
		}
		
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
