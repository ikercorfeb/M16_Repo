#pragma once
#include "Personaje.h"
#include <iostream>
using namespace std;

class FinalEnemy : public Personaje{
private:
	int pu�o;
	int patada;

public:
	//CONSTRUCTOR CON ELEMENTOS DE LA CLASE PADRE Y PROPIA
	FinalEnemy(int pVida,
		string pNombre,
		int pAtaque,
		int pPu�o,
		int pPatada,
		int pPosicionX, 
		int pPosicionY);

	//GETTERS AND SETTERS
	int getPu�o();
	int getPatada();

	void setPu�o(int pPu�o);
	void setPatada(int pPatada);

	//METODOS PROPIOS
	void printAllStats();
};
