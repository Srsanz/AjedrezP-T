#include <freeglut.h>
#include <iostream>

// Tamaño de la ventana --> Ancho=600 y Altura=600

// Tamaño del tablero de ajedrez --> 8

// Tamaño de cada casilla --> 600/8 =75


// Clase base de una pieza
class Piece {
public:
    virtual void draw() const {}
};


// Matriz del tablero de ajedrez
Piece* board[8][8];


//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void Ondraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void initBoard();


int main(int argc, char* argv[]) {

    //Inicializar el gestor de ventanas GLUT
    //y crear la ventana
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Ajedrez");

    //habilitar luces y definir perspectiva
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(0, 600, 600, 0);


    //Registrar los callbacks
    glutDisplayFunc(Ondraw);
    //glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
    glutKeyboardFunc(OnKeyboardDown);

    initBoard();

    //pasarle el control a GLUT,que llamara a los callbacks
    glutMainLoop();


    return 0;
}


// Inicializar el tablero de ajedrez
void initBoard() {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            board[x][y] = nullptr;
        }
    }
}


// Función de dibujo
void Ondraw() {

    //Borrado de la pantalla
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

 
    gluOrtho2D(0, 600, 600, 0);

    // Dibujar el tablero de ajedrez
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if ((x + y) % 2 == 0) {
                glColor3ub(156, 208, 224); // Color clarito
            }
            else {
                glColor3ub(93, 155, 155); // Color oscurito
            }
            glBegin(GL_QUADS);
            glVertex2i(x * 75, y * 75);
            glVertex2i((x + 1) * 75, y * 75);
            glVertex2i((x + 1) * 75, (y + 1) * 75);
            glVertex2i(x * 75, (y + 1) * 75);
            glEnd();
  
        }
    }

    //no borrar esta linea ni poner nada despues
    glutSwapBuffers();
}


void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
    //poner aqui el código de teclado


    glutPostRedisplay();
}


void OnTimer(int value)
{
    //poner aqui el código de animacion


    //no borrar estas lineas
    glutTimerFunc(25, OnTimer, 0);
    glutPostRedisplay();
}


