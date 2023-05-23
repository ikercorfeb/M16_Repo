#include "FinalEnemy.h"

FinalEnemy::FinalEnemy(int pVida, string pNombre, int pAtaque, int pPuño, int pPatada, int pPosicionX, int pPosicionY) : Personaje(pVida, pNombre, pAtaque, pPosicionX, pPosicionY) {
	puño = pPuño;
	patada = pPatada;
}

// GETTERS AND SETTERS
int FinalEnemy::getPuño() {
	return puño;
}

int FinalEnemy::getPatada() {
	return patada;
}

void FinalEnemy::setPuño(int pPuño) {
	puño = pPuño;
}

void FinalEnemy::setPatada(int pPatada) {
	patada = pPatada;
}

// METODOS PROPIOS
void FinalEnemy::printAllStats() {
	cout << "El nombre del enemigo final es " << getNombre() << ", tiene " << getVida() << " puntos de vida" << endl;
	cout << "El ataque normal del enemigo final es " << getAtaque() << endl;
	cout << "El ataque Puño del enemigo final es " << getPuño() << endl;
	cout << "El ataque de Patada del enemigo final es " << getPatada() << endl;
}
