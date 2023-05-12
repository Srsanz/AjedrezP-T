#include "Mundo.h"
#include "freeglut.h"
#include <math.h>

void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

//aqui es donde hay que poner el codigo de dibujo
//esfera.dibuja();
//caja.dibuja();
	tablero.dibujaTablero();
	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
	glEnable(GL_LIGHTING);
}
void Mundo::inicializa()
{
	x_ojo = 0;
	y_ojo = 0;
	z_ojo = 30;
	//y_ojo = -20;
	//z_ojo = 10;
}
void Mundo::tecla(unsigned char key)
{

}
void Mundo::mueve()
{

}
