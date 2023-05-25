#pragma once

class Tablero;

enum TipoPieza {
    None,
    caballo,
    peon,
    torre,
    rey,
    reina,
    alfil
};


class Pieza
{
public:
    TipoPieza tipo;
    int tipoFigura;
    int x, y;
    bool is_white = 0;
    char color;
    Pieza() : tipo(TipoPieza::None), x(0), y(0) {};

   virtual void dibuja() {};
   virtual bool mover(int xInicial, int yInicial, int xFinal, int yFinal,bool ocupado, Tablero& t){
       return true;
   };
   char obtenerColor() const;
   TipoPieza obtenerTipo();

};



