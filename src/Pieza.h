#pragma once
#include <iostream>
#include "freeglut.h"
using namespace std;

class Pieza {
private:
	int posX;
	int posY;
	char color;
	string icono;
public:
	Pieza(int _posX,int _posY,char _color, string _icono) {
		posX = _posX;
		posY = _posY;
		color = _color;
		icono = _icono;
	}
	Pieza() = default;
	~Pieza();
};
