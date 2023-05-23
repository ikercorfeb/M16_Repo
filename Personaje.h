#pragma once
#include <iostream>
#include <string>
using namespace std;
class Personaje
{
private:
	int vida;
	string nombre;
	int ataque;
	int posicionX;
	int posicionY;

public:
	// Constructor
	Personaje(int pVida, string pNombre, int pAtaque, int pPosicionX, int pPosicionY);

	// Getters
	int getVida();
	string getNombre();
	int getAtaque();
	int getPosicionX();
	int getPosicionY();

	// Setters
	void setVida(int pVida);
	void setNombre(string pNombre);
	void setAtaque(int pAtaque);
	void setPosicionX(int pPosicionX);
	void setPosicionY(int pPosicionY);

	// Métodos propios
	void printStatus();
};