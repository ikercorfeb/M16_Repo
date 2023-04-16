#include "lancha.h"
#include <iostream>
using namespace std;
//contructor
Lancha::Lancha(string pName, int pVel, int pDist, int pNitro) {
	name = pName;
	vel = pVel;
	dist = pDist;
	nitro = pNitro;
}
//getters
string Lancha::getName() {
	return name;
}
int Lancha::getVel() {
	return vel;
}
int Lancha::getDist() {
	return dist;
}
int Lancha::getNitro() {
	return nitro;
}
//setters
void Lancha::setName(string pName) {
	name = pName;
}
void Lancha::setVel(int pVel) {
	vel = pVel;
}
void Lancha::setDist(int pDist) {
	dist = pDist;
}
void Lancha::setNitro(int pNitro) {
	nitro = pNitro;
}
//metodos
void Lancha::turnoJugador() {
    setlocale(LC_ALL, "");
    srand(time(nullptr));
    int puntos = rand() % 6 + 1;
    vel += puntos;
    cout << " ha sacado un " << puntos << "\n";
    cout << "Velocidad de la lancha es: " << vel << "\n";
    if (nitro == 1) {
        char siono;
        cout << "Quieres usar el nitro? (S)i o (N)o ";
        cin >> siono;
        if (siono == 's' || siono == 'S') {
            cout << "La lancha ha usado el nitro\n";
            setNitro(0);
            int random = rand() % 2;
            if (random == 0) {
                cout << "La velocidad baja a 1/2" << "\n";
                vel /= 2;
            }else {
                cout << "La velocidad se hace un x2" << "\n";
                vel *= 2;
            }
        }
    }
    int distancia = vel * 100;
    dist += distancia;
    cout << "Distancia total: " << dist << "\n";
    cout << "\n";
}
void Lancha::turnoIA() {
    setlocale(LC_ALL, "");
    srand(time(nullptr));
    int puntos = rand() % 6 + 1;
    vel += puntos;
    cout << " ha sacado un " << puntos << "\n";
    cout << "Velocidad de la lancha es: " << vel << "\n";
    if (nitro == 1){
        int cont = 4;
        if (rand() % cont + 1 == 1) {
            cout << "La lancha ha usado el nitro\n";
            setNitro(0);
            int random = rand() % 2;
            if (random == 0) {
                cout << "La velocidad baja a 1/2" << "\n";
                vel /= 2;
            }
            else {
                cout << "La velocidad se hace un x2" << "\n";
                vel *= 2;
            }
        }
        cont--;
    }
    int distancia = vel * 100;
    dist += distancia;
    cout << "Distancia total: " << dist << "\n";
    cout << "\n";
}
