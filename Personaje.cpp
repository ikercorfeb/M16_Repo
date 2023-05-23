#include "Personaje.h"
using namespace std;

Personaje::Personaje(int pVida, string pNombre, int pAtaque, int pPosicionX, int pPosicionY) {
	vida = pVida;
	nombre = pNombre;
	ataque = pAtaque;
	posicionX = pPosicionX;
	posicionY = pPosicionY;
}

// Getters
int Personaje::getVida(){
	return vida;
}

string Personaje::getNombre(){
	return nombre;
}

int Personaje::getAtaque(){
	return ataque;
}

int Personaje::getPosicionX(){
	return posicionX;
}

int Personaje::getPosicionY(){
	return posicionY;
}

// Setters
void Personaje::setVida(int pVida){
	vida = pVida;
}

void Personaje::setNombre(string pNombre){
	nombre = pNombre;
}

void Personaje::setAtaque(int pAtaque){
	ataque = pAtaque;
}

void Personaje::setPosicionX(int pPosicionX){
	posicionX = pPosicionX;
}

void Personaje::setPosicionY(int pPosicionY){
	posicionY = pPosicionY;
}

// Métodos propios
void Personaje::printStatus() {
	cout << "Name: " << nombre << endl;
	cout << "HP: " << vida << endl;
	cout << "Position: (X:" << posicionX << " Y:" << posicionY << ")" << endl;
	cout << "Attack: " << ataque << endl;
}
