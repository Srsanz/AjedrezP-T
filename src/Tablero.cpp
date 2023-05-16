#include "Tablero.h"
#include"freeglut.h"

void Tablero::dibujaTablero() {
  
  //Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
	gluLookAt(0.0, 0, 30,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    


	

	//aqui es donde hay que poner el código de dibujo

	//-------------------------------------------------------
	
	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(-2.0f, -2.0f, 0.0f);
	glVertex3f(-2.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -2.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, -2.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(2.0f, 0.0f, 0.0f);
	glVertex3f(2.0f, -2.0f, 0.0f);
	glEnd();

	//---------------------------------------------

	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 2.0f, 0.0f);
	glVertex3f(2.0f, 2.0f, 0.0f);
	glVertex3f(2.0f, 0.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(-2.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f, 2.0f, 0.0f);
	glVertex3f(0.0f, 2.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glEnd();


	//-------------------------------------------


	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(-2.0f, 2.0f, 0.0f);
	glVertex3f(-2.0f, 4.0f, 0.0f);
	glVertex3f(0.0f, 4.0f, 0.0f);
	glVertex3f(0.0f, 2.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, 2.0f, 0.0f);
	glVertex3f(0.0f, 4.0f, 0.0f);
	glVertex3f(2.0f, 4.0f, 0.0f);
	glVertex3f(2.0f, 2.0f, 0.0f);
	glEnd();


	//-------------------------------------------------------

	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, -4.0f, 0.0f);
	glVertex3f(0.0f, -2.0f, 0.0f);
	glVertex3f(2.0f, -2.0f, 0.0f);
	glVertex3f(2.0f, -4.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(-2.0f, -4.0f, 0.0f);
	glVertex3f(-2.0f, -2.0f, 0.0f);
	glVertex3f(0.0f, -2.0f, 0.0f);
	glVertex3f(0.0f, -4.0f, 0.0f);
	glEnd();

	//---------------------------------------------


	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(-4.0f, -4.0f, 0.0f);
	glVertex3f(-4.0f, -2.0f, 0.0f);
	glVertex3f(-2.0f, -2.0f, 0.0f);
	glVertex3f(-2.0f, -4.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(-4.0f, -2.0f, 0.0f);
	glVertex3f(-4.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f, -2.0f, 0.0f);
	glEnd();

	//---------------------------------------------



	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(-4.0f, 0.0f, 0.0f);
	glVertex3f(-4.0f, 2.0f, 0.0f);
	glVertex3f(-2.0f, 2.0f, 0.0f);
	glVertex3f(-2.0f, 0.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(-4.0f, 2.0f, 0.0f);
	glVertex3f(-4.0f, 4.0f, 0.0f);
	glVertex3f(-2.0f, 4.0f, 0.0f);
	glVertex3f(-2.0f, 2.0f, 0.0f);
	glEnd();

	//---------------------------------------------



	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(2.0f, 2.0f, 0.0f);
	glVertex3f(2.0f, 4.0f, 0.0f);
	glVertex3f(4.0f, 4.0f, 0.0f);
	glVertex3f(4.0f, 2.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(2.0f, 0.0f, 0.0f);
	glVertex3f(2.0f, 2.0f, 0.0f);
	glVertex3f(4.0f, 2.0f, 0.0f);
	glVertex3f(4.0f, 0.0f, 0.0f);
	glEnd();

	//---------------------------------------------



	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(2.0f, -2.0f, 0.0f);
	glVertex3f(2.0f, 0.0f, 0.0f);
	glVertex3f(4.0f, 0.0f, 0.0f);
	glVertex3f(4.0f, -2.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(2.0f, -4.0f, 0.0f);
	glVertex3f(2.0f, -2.0f, 0.0f);
	glVertex3f(4.0f, -2.0f, 0.0f);
	glVertex3f(4.0f, -4.0f, 0.0f);
	glEnd();

	//---------------------------------------------
	


	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(-4.0f, -8.0f, 0.0f);
	glVertex3f(-4.0f, -6.0f, 0.0f);
	glVertex3f(-2.0f, -6.0f, 0.0f);
	glVertex3f(-2.0f, -8.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(-4.0f, -6.0f, 0.0f);
	glVertex3f(-4.0f, -4.0f, 0.0f);
	glVertex3f(-2.0f, -4.0f, 0.0f);
	glVertex3f(-2.0f, -6.0f, 0.0f);
	glEnd();

	//---------------------------------------------
	


	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(-2.0f, -6.0f, 0.0f);
	glVertex3f(-2.0f, -4.0f, 0.0f);
	glVertex3f(0.0f, -4.0f, 0.0f);
	glVertex3f(0.0f, -6.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(-2.0f, -8.0f, 0.0f);
	glVertex3f(-2.0f, -6.0f, 0.0f);
	glVertex3f(0.0f, -6.0f, 0.0f);
	glVertex3f(0.0f, -8.0f, 0.0f);
	glEnd();

	//---------------------------------------------



	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(-4.0f, 4.0f, 0.0f);
	glVertex3f(-4.0f, 6.0f, 0.0f);
	glVertex3f(-2.0f, 6.0f, 0.0f);
	glVertex3f(-2.0f, 4.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(-4.0f, 6.0f, 0.0f);
	glVertex3f(-4.0f, 8.0f, 0.0f);
	glVertex3f(-2.0f, 8.0f, 0.0f);
	glVertex3f(-2.0f, 6.0f, 0.0f);
	glEnd();

	//---------------------------------------------




	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(-2.0f, 6.0f, 0.0f);
	glVertex3f(-2.0f, 8.0f, 0.0f);
	glVertex3f(0.0f, 8.0f, 0.0f);
	glVertex3f(0.0f, 6.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(-2.0f, 4.0f, 0.0f);
	glVertex3f(-2.0f, 6.0f, 0.0f);
	glVertex3f(0.0f, 6.0f, 0.0f);
	glVertex3f(0.0f, 4.0f, 0.0f);
	glEnd();

	//---------------------------------------------



	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, 4.0f, 0.0f);
	glVertex3f(0.0f, 6.0f, 0.0f);
	glVertex3f(2.0f, 6.0f, 0.0f);
	glVertex3f(2.0f, 4.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, 6.0f, 0.0f);
	glVertex3f(0.0f, 8.0f, 0.0f);
	glVertex3f(2.0f, 8.0f, 0.0f);
	glVertex3f(2.0f, 6.0f, 0.0f);
	glEnd();

	//---------------------------------------------



	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(2.0f, 6.0f, 0.0f);
	glVertex3f(2.0f, 8.0f, 0.0f);
	glVertex3f(4.0f, 8.0f, 0.0f);
	glVertex3f(4.0f, 6.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(2.0f, 4.0f, 0.0f);
	glVertex3f(2.0f, 6.0f, 0.0f);
	glVertex3f(4.0f, 6.0f, 0.0f);
	glVertex3f(4.0f, 4.0f, 0.0f);
	glEnd();

	//---------------------------------------------



	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, -8.0f, 0.0f);
	glVertex3f(0.0f, -6.0f, 0.0f);
	glVertex3f(2.0f, -6.0f, 0.0f);
	glVertex3f(2.0f, -8.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, -6.0f, 0.0f);
	glVertex3f(0.0f, -4.0f, 0.0f);
	glVertex3f(2.0f, -4.0f, 0.0f);
	glVertex3f(2.0f, -6.0f, 0.0f);
	glEnd();

	//---------------------------------------------




	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(2.0f, -6.0f, 0.0f);
	glVertex3f(2.0f, -4.0f, 0.0f);
	glVertex3f(4.0f, -4.0f, 0.0f);
	glVertex3f(4.0f, -6.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(2.0f, -8.0f, 0.0f);
	glVertex3f(2.0f, -6.0f, 0.0f);
	glVertex3f(4.0f, -6.0f, 0.0f);
	glVertex3f(4.0f, -8.0f, 0.0f);
	glEnd();

	//---------------------------------------------



	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(4.0f, -8.0f, 0.0f);
	glVertex3f(4.0f, -6.0f, 0.0f);
	glVertex3f(6.0f, -6.0f, 0.0f);
	glVertex3f(6.0f, -8.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(4.0f, -6.0f, 0.0f);
	glVertex3f(4.0f, -4.0f, 0.0f);
	glVertex3f(6.0f, -4.0f, 0.0f);
	glVertex3f(6.0f, -6.0f, 0.0f);
	glEnd();

	//---------------------------------------------



	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(4.0f, -4.0f, 0.0f);
	glVertex3f(4.0f, -2.0f, 0.0f);
	glVertex3f(6.0f, -2.0f, 0.0f);
	glVertex3f(6.0f, -4.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(4.0f, -2.0f, 0.0f);
	glVertex3f(4.0f, 0.0f, 0.0f);
	glVertex3f(6.0f, 0.0f, 0.0f);
	glVertex3f(6.0f, -2.0f, 0.0f);
	glEnd();

	//---------------------------------------------




	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(4.0f, 0.0f, 0.0f);
	glVertex3f(4.0f, 2.0f, 0.0f);
	glVertex3f(6.0f, 2.0f, 0.0f);
	glVertex3f(6.0f, 0.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(4.0f, 2.0f, 0.0f);
	glVertex3f(4.0f, 4.0f, 0.0f);
	glVertex3f(6.0f, 4.0f, 0.0f);
	glVertex3f(6.0f, 2.0f, 0.0f);
	glEnd();

	//---------------------------------------------



	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(4.0f, 4.0f, 0.0f);
	glVertex3f(4.0f, 6.0f, 0.0f);
	glVertex3f(6.0f, 6.0f, 0.0f);
	glVertex3f(6.0f, 4.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(4.0f, 6.0f, 0.0f);
	glVertex3f(4.0f, 8.0f, 0.0f);
	glVertex3f(6.0f, 8.0f, 0.0f);
	glVertex3f(6.0f, 6.0f, 0.0f);
	glEnd();

	//---------------------------------------------



	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(6.0f, 6.0f, 0.0f);
	glVertex3f(6.0f, 8.0f, 0.0f);
	glVertex3f(8.0f, 8.0f, 0.0f);
	glVertex3f(8.0f, 6.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(6.0f, 4.0f, 0.0f);
	glVertex3f(6.0f, 6.0f, 0.0f);
	glVertex3f(8.0f, 6.0f, 0.0f);
	glVertex3f(8.0f, 4.0f, 0.0f);
	glEnd();

	//---------------------------------------------




	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(6.0f, 2.0f, 0.0f);
	glVertex3f(6.0f, 4.0f, 0.0f);
	glVertex3f(8.0f, 4.0f, 0.0f);
	glVertex3f(8.0f, 2.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(6.0f, 0.0f, 0.0f);
	glVertex3f(6.0f, 2.0f, 0.0f);
	glVertex3f(8.0f, 2.0f, 0.0f);
	glVertex3f(8.0f, 0.0f, 0.0f);
	glEnd();

	//---------------------------------------------





	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(6.0f, -2.0f, 0.0f);
	glVertex3f(6.0f, 0.0f, 0.0f);
	glVertex3f(8.0f, 0.0f, 0.0f);
	glVertex3f(8.0f, -2.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(6.0f, -4.0f, 0.0f);
	glVertex3f(6.0f, -2.0f, 0.0f);
	glVertex3f(8.0f, -2.0f, 0.0f);
	glVertex3f(8.0f, -4.0f, 0.0f);
	glEnd();

	//---------------------------------------------




	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(6.0f, -6.0f, 0.0f);
	glVertex3f(6.0f, -4.0f, 0.0f);
	glVertex3f(8.0f, -4.0f, 0.0f);
	glVertex3f(8.0f, -6.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(6.0f, -8.0f, 0.0f);
	glVertex3f(6.0f, -6.0f, 0.0f);
	glVertex3f(8.0f, -6.0f, 0.0f);
	glVertex3f(8.0f, -8.0f, 0.0f);
	glEnd();

	//---------------------------------------------




	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(-6.0f, 6.0f, 0.0f);
	glVertex3f(-6.0f, 8.0f, 0.0f);
	glVertex3f(-4.0f, 8.0f, 0.0f);
	glVertex3f(-4.0f, 6.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(-6.0f, 4.0f, 0.0f);
	glVertex3f(-6.0f, 6.0f, 0.0f);
	glVertex3f(-4.0f, 6.0f, 0.0f);
	glVertex3f(-4.0f, 4.0f, 0.0f);
	glEnd();

	//---------------------------------------------




	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(-6.0f, 2.0f, 0.0f);
	glVertex3f(-6.0f, 4.0f, 0.0f);
	glVertex3f(-4.0f, 4.0f, 0.0f);
	glVertex3f(-4.0f, 2.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(-6.0f, 0.0f, 0.0f);
	glVertex3f(-6.0f, 2.0f, 0.0f);
	glVertex3f(-4.0f, 2.0f, 0.0f);
	glVertex3f(-4.0f, 0.0f, 0.0f);
	glEnd();

	//---------------------------------------------

	


	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(-6.0f, -2.0f, 0.0f);
	glVertex3f(-6.0f, 0.0f, 0.0f);
	glVertex3f(-4.0f, 0.0f, 0.0f);
	glVertex3f(-4.0f, -2.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(-6.0f, -4.0f, 0.0f);
	glVertex3f(-6.0f, -2.0f, 0.0f);
	glVertex3f(-4.0f, -2.0f, 0.0f);
	glVertex3f(-4.0f, -4.0f, 0.0f);
	glEnd();

	//---------------------------------------------




	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(-6.0f, -6.0f, 0.0f);
	glVertex3f(-6.0f, -4.0f, 0.0f);
	glVertex3f(-4.0f, -4.0f, 0.0f);
	glVertex3f(-4.0f, -6.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(-6.0f, -8.0f, 0.0f);
	glVertex3f(-6.0f, -6.0f, 0.0f);
	glVertex3f(-4.0f, -6.0f, 0.0f);
	glVertex3f(-4.0f, -8.0f, 0.0f);
	glEnd();

	//---------------------------------------------

		


	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(-8.0f, -8.0f, 0.0f);
	glVertex3f(-8.0f, -6.0f, 0.0f);
	glVertex3f(-6.0f, -6.0f, 0.0f);
	glVertex3f(-6.0f, -8.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(-8.0f, -6.0f, 0.0f);
	glVertex3f(-8.0f, -4.0f, 0.0f);
	glVertex3f(-6.0f, -4.0f, 0.0f);
	glVertex3f(-6.0f, -6.0f, 0.0f);
	glEnd();

	//---------------------------------------------



	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(-8.0f, -4.0f, 0.0f);
	glVertex3f(-8.0f, -2.0f, 0.0f);
	glVertex3f(-6.0f, -2.0f, 0.0f);
	glVertex3f(-6.0f, -4.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(-8.0f, -2.0f, 0.0f);
	glVertex3f(-8.0f, 0.0f, 0.0f);
	glVertex3f(-6.0f, 0.0f, 0.0f);
	glVertex3f(-6.0f, -2.0f, 0.0f);
	glEnd();

	//---------------------------------------------



	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(-8.0f, 0.0f, 0.0f);
	glVertex3f(-8.0f, 2.0f, 0.0f);
	glVertex3f(-6.0f, 2.0f, 0.0f);
	glVertex3f(-6.0f, 0.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(-8.0f, 2.0f, 0.0f);
	glVertex3f(-8.0f, 4.0f, 0.0f);
	glVertex3f(-6.0f, 4.0f, 0.0f);
	glVertex3f(-6.0f, 2.0f, 0.0f);
	glEnd();

	//---------------------------------------------



	//Cuadrado oscuro
	glColor3ub(93, 155, 155);
	glBegin(GL_POLYGON);
	glVertex3f(-8.0f, 4.0f, 0.0f);
	glVertex3f(-8.0f, 6.0f, 0.0f);
	glVertex3f(-6.0f, 6.0f, 0.0f);
	glVertex3f(-6.0f, 4.0f, 0.0f);
	glEnd();


	//Cuadrado claro
	glColor3ub(156, 208, 224);
	glBegin(GL_POLYGON);
	glVertex3f(-8.0f, 6.0f, 0.0f);
	glVertex3f(-8.0f, 8.0f, 0.0f);
	glVertex3f(-6.0f, 8.0f, 0.0f);
	glVertex3f(-6.0f, 6.0f, 0.0f);
	glEnd();

	//---------------------------------------------

	//Cuadrado gris esquina

	glColor3ub(71, 75, 78);
	glBegin(GL_POLYGON);
	glVertex3f(8.0f, 8.0f, 0.0f);
	glVertex3f(8.0f, 9.0f, 0.0f);
	glVertex3f(9.0f, 9.0f, 0.0f);
	glVertex3f(9.0f, 8.0f, 0.0f);
	glEnd();

	//---------------------------------------------

	//Cuadrado gris esquina

	glColor3ub(71, 75, 78);
	glBegin(GL_POLYGON);
	glVertex3f(-9.0f, 8.0f, 0.0f);
	glVertex3f(-9.0f, 9.0f, 0.0f);
	glVertex3f(-8.0f, 9.0f, 0.0f);
	glVertex3f(-8.0f, 8.0f, 0.0f);
	glEnd();

	//---------------------------------------------

	//Cuadrado gris esquina

	glColor3ub(71, 75, 78);
	glBegin(GL_POLYGON);
	glVertex3f(-9.0f, -9.0f, 0.0f);
	glVertex3f(-9.0f, -8.0f, 0.0f);
	glVertex3f(-8.0f, -8.0f, 0.0f);
	glVertex3f(-8.0f, -9.0f, 0.0f);
	glEnd();

	//---------------------------------------------

	//Cuadrado gris esquina

	glColor3ub(71, 75, 78);
	glBegin(GL_POLYGON);
	glVertex3f(8.0f, -9.0f, 0.0f);
	glVertex3f(8.0f, -8.0f, 0.0f);
	glVertex3f(9.0f, -8.0f, 0.0f);
	glVertex3f(9.0f, -9.0f, 0.0f);
	glEnd();

	//---------------------------------------------

	//Borde gris

	glColor3ub(71, 75, 78);
	glBegin(GL_POLYGON);
	glVertex3f(-9.0f, -8.0f, 0.0f);
	glVertex3f(-9.0f, 8.0f, 0.0f);
	glVertex3f(-8.0f, 8.0f, 0.0f);
	glVertex3f(-8.0f, -8.0f, 0.0f);
	glEnd();

	//---------------------------------------------

	//Borde gris

	glColor3ub(71, 75, 78);
	glBegin(GL_POLYGON);
	glVertex3f(-8.0f, 8.0f, 0.0f);
	glVertex3f(-8.0f, 9.0f, 0.0f);
	glVertex3f(8.0f, 9.0f, 0.0f);
	glVertex3f(8.0f, 8.0f, 0.0f);
	glEnd();

	//---------------------------------------------

	//Borde gris

	glColor3ub(71, 75, 78);
	glBegin(GL_POLYGON);
	glVertex3f(8.0f, -8.0f, 0.0f);
	glVertex3f(8.0f, 8.0f, 0.0f);
	glVertex3f(9.0f, 8.0f, 0.0f);
	glVertex3f(9.0f, -8.0f, 0.0f);
	glEnd();

	//---------------------------------------------

	//Borde gris

	glColor3ub(71, 75, 78);
	glBegin(GL_POLYGON);
	glVertex3f(-8.0f, -9.0f, 0.0f);
	glVertex3f(-8.0f, -8.0f, 0.0f);
	glVertex3f(8.0f, -8.0f, 0.0f);
	glVertex3f(8.0f, -9.0f, 0.0f);
	glEnd();

	//---------------------------------------------
	//no borrar esta linea ni poner nada despues ah sgdhagdhsagdjwhfdgj
	glutSwapBuffers();
}
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{

}

void OnTimer(int value)
{
	
}


