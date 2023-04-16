#include "lancha.h"
#include <iostream>
using namespace std;
int main() {
	srand(time(nullptr));
	setlocale(LC_ALL, "");
	Lancha lancha1("", 0,0, 1);
	Lancha lancha2("Misteriosa", 0, 0, 1);
	string name;
	int dist1 = lancha1.getDist();
	int dist2 = lancha2.getDist();
	int jugar = 1;
	cout << "Que nombre quieres que tenga tu lancha?\n";
	cin >> name;
	lancha1.setName(name);
	for (int i = 1; i < 6; i++){
		cout << "Turno " << i << "\n";
		cout << "<=====>\n";
		cout << "La lancha " << lancha1.getName();
		lancha1.turnoJugador();
		cout << "La lancha " << lancha2.getName();
		lancha2.turnoIA();
	}
	if (dist1 > dist2) {
		cout << "Ha ganado la lancha " << lancha1.getName() << " con una distancia total de: " << lancha1.getDist() << "!";
	}
	else if (dist1 == dist2) {
		cout << "Ha habido un empate entre las 2 lanchas!";
	}
	else {
		cout << "Ha ganado la lancha " << lancha2.getName() << " con una distancia total de: " << lancha2.getDist() << "!";
	}
}
