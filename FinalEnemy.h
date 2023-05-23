#pragma once
#include "Personaje.h"
#include <iostream>
using namespace std;

class FinalEnemy : public Personaje{
private:
	int puño;
	int patada;

public:
	//CONSTRUCTOR CON ELEMENTOS DE LA CLASE PADRE Y PROPIA
	FinalEnemy(int pVida,
		string pNombre,
		int pAtaque,
		int pPuño,
		int pPatada,
		int pPosicionX, 
		int pPosicionY);

	//GETTERS AND SETTERS
	int getPuño();
	int getPatada();

	void setPuño(int pPuño);
	void setPatada(int pPatada);

	//METODOS PROPIOS
	void printAllStats();
};
