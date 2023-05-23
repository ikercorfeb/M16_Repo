#include "FinalEnemy.h"

FinalEnemy::FinalEnemy(int pVida, string pNombre, int pAtaque, int pPu�o, int pPatada, int pPosicionX, int pPosicionY) : Personaje(pVida, pNombre, pAtaque, pPosicionX, pPosicionY) {
	pu�o = pPu�o;
	patada = pPatada;
}

// GETTERS AND SETTERS
int FinalEnemy::getPu�o() {
	return pu�o;
}

int FinalEnemy::getPatada() {
	return patada;
}

void FinalEnemy::setPu�o(int pPu�o) {
	pu�o = pPu�o;
}

void FinalEnemy::setPatada(int pPatada) {
	patada = pPatada;
}

// METODOS PROPIOS
void FinalEnemy::printAllStats() {
	cout << "El nombre del enemigo final es " << getNombre() << ", tiene " << getVida() << " puntos de vida" << endl;
	cout << "El ataque normal del enemigo final es " << getAtaque() << endl;
	cout << "El ataque Pu�o del enemigo final es " << getPu�o() << endl;
	cout << "El ataque de Patada del enemigo final es " << getPatada() << endl;
}
