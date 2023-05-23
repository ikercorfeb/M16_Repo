#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Personaje.h"
#include "FinalEnemy.h"
#include <chrono>
#include <thread>
#include <conio.h> 
#include <Windows.h>

using namespace std;
const bool alive = true;
const int y = 6;
const int x = 5;
string tablero[y][x];
Personaje heroe(700, "Iker", 150, 0, 5);
Personaje enemigo1(275, "Ramon", 75, 0, 0);
Personaje enemigo2(275, "Adri", 55, 0, 0);
FinalEnemy enemigoFinal(450, "Jorge", 120, 220, 170, 0, 0);

void intro() {
    cout << "                  _    _ _   _______ _____ __  __                             \n";
    cout << "                 | |  | | | |__   __|_   _|  \\/  |   /\\                       \n";
    cout << "                 | |  | | |    | |    | | | \\  / |  /  \\                      \n";
    cout << "                 | |  | | |    | |    | | | |\\/| | / /\\ \\                     \n";
    cout << "                 | |__| | |____| |   _| |_| |  | |/ ____ \\                    \n";
    cout << "   ____  _____   _\\____/|______|_|__|_____|_|  |_/_/____\\_\\__          _____  \n";
    cout << "  / __ \\|  __ \\ / __ \\|  __ \\__   __| |  | | \\ | |_   _|  __ \\   /\\   |  __ \\ \n";
    cout << " | |  | | |__) | |  | | |__) | | |  | |  | |  \\| | | | | |  | | /  \\  | |  | |\n";
    cout << " | |  | |  ___/| |  | |  _  /  | |  | |  | | . ` | | | | |  | |/ /\\ \\ | |  | |\n";
    cout << " | |__| | |    | |__| | | \\ \\  | |  | |__| | |\\  |_| |_| |__| / ____ \\| |__| |\n";
    cout << "  \\____/|_|     \\____/|_|  \\_\\ |_|   \\____/|_| \\_|_____|_____/_/    \\_\\_____/ \n";
    Sleep(2000);
    system("cls");
}
void sleeep() {
    Sleep(500);
};
void setts() {
    srand(time(0));
    heroe.setPosicionX(rand() % 5);
    enemigo1.setPosicionX(rand() % 5);
    enemigo1.setPosicionY((rand() % 2) + 3);
    enemigo2.setPosicionX(rand() % 5);
    enemigo2.setPosicionY((rand() % 1) + 1);
    enemigoFinal.setPosicionX(rand() % 5);
}

void rellenarTablero(string tablero[y][x]) {
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (tablero[i][j].empty()) {
                int ran = rand() % 7;
                if (ran == 0) {
                    tablero[i][j] = "P";
                }
                else {
                    tablero[i][j] = "*";
                } 
            }
        }
    }
}
void mostrarTablero() {
    cout << "\t \t \t \t \t (w) de frente (d) derecha (a) izquierda (s) atras\n";
    cout << "\t \t \t \t \t \t \t      TABLERO\n";
    cout << "\t \t \t \t \t \t ----------------------------------\n";
    for (int i = 0; i < y; i++) {
        cout << "\t \t \t \t \t \t ";
        for (int j = 0; j < x; j++) {
            cout << "|";
            cout << tablero[i][j] << "|\t";
        }
        cout << "\n";
    }
    cout << "\t \t \t \t \t \t ----------------------------------\n";
}
//acabar
/*
int enfrentarEnemigo(Personaje* enemy,Personaje* hero) {
    srand(time(0));
    bool ganador;
    if (enemy == &enemigo1 || enemy == &enemigo2) {

    }else {
        cout << "Te enfrentas al enemigo final: " << enemy->getNombre() << "\n";
        int ataque = rand() % 1;
        if (ataque == 0) {
            cout << enemy->getNombre() << " ataca\n";
            int eAttack = enemy->getAtaque();
            int hVida = hero->getVida();
            hVida -= eAttack;
            cout << "La vida de " << hero->getNombre() << "es " << hVida << "\n";
        }
        else {
            int super = rand() % 1;
            if (super == 0){

            }else {

            }
        }
        return ganador;
    }
}*/

void direccion() {
    string dir;
    int actualX, actualY;
    char c = _getch();
    dir = string(1, c);
    Personaje* enemy;
    Personaje* hero;
    hero = &heroe;
    if (dir == "w") {
        actualX = heroe.getPosicionX();
        actualY = heroe.getPosicionY();
        // Limite
        if (actualY == 0) {
            cout << "Has llegado al límite Javi.\n";
            Sleep(1000);
            return;
        }
        // Pared
        if (tablero[actualY - 1][actualX] == "P") {
            cout << "Tienes una pared, no sigas Javi.\n";
            Sleep(1000);
            return;
        }
        // Enemigo
        if (tablero[actualY - 1][actualX] == "1" || tablero[actualY - 1][actualX] == "2" || tablero[actualY - 1][actualX] == "F") {
            if (tablero[actualY - 1][actualX] == "1") {
                enemy = &enemigo1;
            }
            else if (tablero[actualY - 1][actualX] == "2") {
                enemy = &enemigo2;
            }
            else {
                enemy = &enemigoFinal;
            }
            //enfrentarEnemigo(enemy,hero);
            return;
        }
        // No enemigo
        tablero[actualY][actualX] = " ";
        tablero[actualY - 1][actualX] = "H";
        heroe.setPosicionY(actualY - 1);
    }
    else if (dir == "d") {
        actualX = heroe.getPosicionX();
        actualY = heroe.getPosicionY();
        // Limite
        if (actualX == x - 1) {
            cout << "Has llegado al límite Javi.\n";
            Sleep(1000);
            return;
        }
        // Pared
        if (tablero[actualY][actualX + 1] == "P") {
            cout << "Tienes una pared, no sigas Javi.\n";
            Sleep(1000);
            return;
        }
        // Enemigo
        if (tablero[actualY][actualX + 1] == "1" || tablero[actualY][actualX + 1] == "2" || tablero[actualY][actualX + 1] == "F") {
            if (tablero[actualY][actualX + 1] == "1") {
                enemy = &enemigo1;
            }
            else if (tablero[actualY][actualX + 1] == "2") {
                enemy = &enemigo2;
            }
            else {
                enemy = &enemigoFinal;
            }
            //enfrentarEnemigo(enemy, hero);
            return;
        }
        // No enemigo
        tablero[actualY][actualX] = " ";
        tablero[actualY][actualX + 1] = "H";
        heroe.setPosicionX(actualX + 1);
    }
    else if (dir == "a") {
        actualX = heroe.getPosicionX();
        actualY = heroe.getPosicionY();
        // Limite
        if (actualX == 0) {
            cout << "Has llegado al límite Javi.\n";
            Sleep(1000);
            return;
        }
        // Pared
        if (tablero[actualY][actualX - 1] == "P") {
            cout << "Tienes una pared, no sigas Javi.\n";
            Sleep(1000);
            return;
        }
        // Enemigo
        if (tablero[actualY][actualX - 1] == "1" || tablero[actualY][actualX - 1] == "2" || tablero[actualY][actualX - 1] == "F") {
            if (tablero[actualY][actualX - 1] == "1") {
                enemy = &enemigo1;
            }
            else if (tablero[actualY][actualX - 1] == "2") {
                enemy = &enemigo2;
            }
            else {
                enemy = &enemigoFinal;
            }
            //enfrentarEnemigo(enemy, hero);
            return;
        }
        // No enemigo
        tablero[actualY][actualX] = " ";
        tablero[actualY][actualX - 1] = "H";
        heroe.setPosicionX(actualX - 1);
    }
    else if (dir == "s") {
        actualX = heroe.getPosicionX();
        actualY = heroe.getPosicionY();
        // Limite
        if (actualY == y - 1) {
            Sleep(1000);
            cout << "Has llegado al límite Javi.\n";
            return;
        }
        // Pared
        if (tablero[actualY + 1][actualX] == "P") {
            Sleep(1000);
            cout << "Tienes una pared, no sigas Javi.\n";
            return;
        }
        // Enemigo
        if (tablero[actualY + 1][actualX] == "1" || tablero[actualY + 1][actualX] == "2" || tablero[actualY + 1][actualX] == "F") {
            Personaje* enemigo;
            if (tablero[actualY + 1][actualX] == "1") {
                enemy = &enemigo1;
            }
            else if (tablero[actualY + 1][actualX] == "2") {
                enemy = &enemigo2;
            }
            else {
                enemy = &enemigoFinal;
            }
            //enfrentarEnemigo(enemy, hero);
            return;
        }
        // No enemigo
        tablero[actualY][actualX] = " ";
        tablero[actualY + 1][actualX] = "H";
        heroe.setPosicionY(actualY + 1);
    }
    else {
        Sleep(500);
        cout << "Dirección no válida.\n";
        direccion();
    }
}

int main() {
    srand(time(0));
    intro();
    setts();
    //heroe
    tablero[heroe.getPosicionY()][heroe.getPosicionX()] = "H";
    Sleep(1500);
    cout << "Datos Heroe\n";
    heroe.printStatus();
    cout << "\n";
    //enemigo1
    tablero[enemigo1.getPosicionY()][enemigo1.getPosicionX()] = "1";
    Sleep(1500);
    cout << "Datos Enemigo 1\n";
    enemigo1.printStatus();
    cout << "\n";
    //enemigo2
    tablero[enemigo2.getPosicionY()][enemigo2.getPosicionX()] = "2";
    Sleep(1500);
    cout << "Datos Enemigo 2\n";
    enemigo2.printStatus();
    cout << "\n";
    //enemigoFinal
    tablero[enemigoFinal.getPosicionY()][enemigoFinal.getPosicionX()] = "S";
    Sleep(1500);
    cout << "Datos Enemigo Final\n";
    enemigoFinal.printStatus();
    sleeep();
    system("cls");
    rellenarTablero(tablero);
    while (alive){
        mostrarTablero();
        direccion();
        sleeep();
        system("cls");
    }
    return 0;
}
