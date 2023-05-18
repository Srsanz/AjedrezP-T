#pragma once


enum class TipoPieza {
    None,
    Caballo,
    Peon
};


class Pieza
{
public:
    TipoPieza tipo;
    int x, y;
    bool is_white = 0;

    Pieza() : tipo(TipoPieza::None), x(0), y(0) {};

    virtual void dibuja() {};

};



