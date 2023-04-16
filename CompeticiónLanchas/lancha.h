#pragma once
#include <iostream>
using namespace std;

class Lancha {
private:
	string name;
	int vel;
	int dist;
	int nitro;

public:
	//contructor
	Lancha(string pName, int pVel, int pDist, int pNitro);
	//getters
	string getName();
	int getVel();
	int getDist();
	int getNitro();
	//setters
	void setName(string pName);
	void setVel(int pVel);
	void setDist(int pDist);
	void setNitro(int pNitro);
	//metodos propios
	void turnoJugador();
	void turnoIA();
};
