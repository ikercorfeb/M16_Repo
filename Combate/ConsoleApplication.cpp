#include <iostream>
#include <cstdlib>
#include <clocale>
using namespace std;
int enemyToAttack = 0;
int attack = 0;
int enemyHP;
string enemyName;
bool enemyIsAlive = true;
int enemy2HP;
string enemy2Name;
bool enemy2IsAlive = true;
string heroName;
bool heroIsAlive = true;
int heroHP = 200;
int swordInTheChest = 75;
int swordInTheChest_powerPoints = 2;
int headbuttInStomach = 45;
int headbuttInStomach_powerPoints = 4;
int rightHandCrochet = 30;
int rightHandCrochet_powerPoints = 3;
void names() {
    cout << "Como se llama el Heroe?\n";
    cin >> heroName;
    cout << "El nombre que has escogido es " << heroName << ".\n";
    cout << "Como se llama el primer enemigo?\n";
    cin >> enemyName;
    cout << "Como se llama el segundo enemigo?\n";
    cin >> enemy2Name;
    enemy2HP = 100 + (rand() % 200);
    enemyHP = 100 + (rand() % 200);
    cout << "El enemigo " << enemyName << " ha aparecido!\n";
    cout << "El enemigo " << enemy2Name << " ha aparecido!\n";
}
int whoAttack() {
    if (swordInTheChest_powerPoints == 0 && headbuttInStomach_powerPoints == 0 && rightHandCrochet_powerPoints == 0) {
        cout << "Te has quedado sin ataques...\n";
        cout << heroName << " se ha retirado por falta de ataques.\n";
        exit(0);
    }
    do {
        cout << "A que enemigo quieres atacar [1] " << enemyName << " (" << enemyHP << "hp) o [2] " << enemy2Name << " (" << enemy2HP << "hp)?\n";
        cin >> enemyToAttack;
    } while (enemyToAttack != 1 && enemyToAttack != 2);
    return enemyToAttack;
}
void toAttackEnemies(int& hp, string& enName) {
    while (attack != 1 && attack != 2 && attack != 3){
        cout << "Que ataque quieres usar? ";
        if (swordInTheChest_powerPoints > 0) {
            cout << "[1] swordInTheChest ";
        }
        if (headbuttInStomach_powerPoints > 0) {
            cout << "[2] headbuttInStomach ";
        }
        if (rightHandCrochet_powerPoints > 0) {
            cout << "[3] right_handCrochet";
        }
        cout << ":\n";
        cin >> attack;
    }
    if (attack == 1 && swordInTheChest_powerPoints > 0) {
        cout << "A " << enName << " le haces " << swordInTheChest << " puntos de danyo.\n";
        swordInTheChest_powerPoints--;
        hp = hp - swordInTheChest;
    }else if (attack == 2 && headbuttInStomach_powerPoints > 0) {
        cout << "A " << enName << " le haces " << headbuttInStomach << " puntos de danyo.\n";
        headbuttInStomach_powerPoints--;
        hp = hp - headbuttInStomach;
    }else if (attack == 3 && rightHandCrochet_powerPoints > 0) {
        cout << "A " << enName << " le haces " << rightHandCrochet << " puntos de danyo.\n";
        rightHandCrochet_powerPoints--;
        hp = hp - rightHandCrochet;
     }
    attack = 0;
}
void attackEnemies(int& hHP, string& enName) {
    if (heroIsAlive)    {
        int enDmg = (rand() % 50);
        cout << enName << " te ataca quitandote " << enDmg << " puntos de vida.\n";
        hHP = hHP - enDmg;
    }
}
void isAlive(int& hp, string& name, bool& live) {
    if (hp <= 0) {
        cout << name << " a muerto.\n";
        live = false;
    }
    else {
        cout << "A " << name << " le quedan " << hp << " puntos de vida.\n";
        live = true;
    }
}
void win() {
    cout << "Has ganado campeon.\n";
    exit(0);
}
void gameOver() {
    if (!heroIsAlive) {
        cout << "El heroe " << heroName << " ha muerto...\n";
        exit(0);
    }
}
void oneEnemy(int& hHp, int& eHp,string& hName, string& eName,bool& hLive, bool& eLive) {
    attackEnemies(hHp, eName);
    isAlive(hHp, hName, hLive);
    if (heroIsAlive) {
        toAttackEnemies(eHp, eName);
        isAlive(eHp, eName, eLive);
    }
    if (!enemyIsAlive && !enemy2IsAlive) {
        win();
    }
    gameOver();
}
int main() {
    setlocale(LC_ALL, "");
    srand(time(nullptr));
    names();
    while (enemyIsAlive && enemy2IsAlive) {
        enemyToAttack = whoAttack();
        if (enemyToAttack == 1) {
            toAttackEnemies(enemyHP, enemyName);
            isAlive(enemyHP, enemyName, enemyIsAlive);
            if (enemyIsAlive) {
                attackEnemies(heroHP, enemyName);
                isAlive(heroHP, heroName, heroIsAlive);
                gameOver();
            }
            if (heroIsAlive) {
               attackEnemies(heroHP, enemy2Name);
               isAlive(heroHP, heroName, heroIsAlive);
               gameOver();
            }
        }
        if (enemyToAttack == 2) {
            toAttackEnemies(enemy2HP,enemy2Name);
            isAlive(enemy2HP, enemy2Name, enemy2IsAlive);
            if (enemy2IsAlive) {
                attackEnemies(heroHP, enemy2Name);
                isAlive(heroHP, heroName, heroIsAlive);
                gameOver();
            }
            if (heroIsAlive) {
               attackEnemies(heroHP, enemyName);
               isAlive(heroHP, heroName, heroIsAlive);
               gameOver();
            }
        }
    }
    while (enemyIsAlive && !enemy2IsAlive) {
        oneEnemy(heroHP, enemyHP, heroName, enemyName, heroIsAlive, enemyIsAlive);
    }
    while (!enemyIsAlive && enemy2IsAlive) {
        oneEnemy(heroHP, enemy2HP, heroName, enemy2Name, heroIsAlive, enemy2IsAlive);
    }
}