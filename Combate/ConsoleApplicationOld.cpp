#include <iostream>
#include <cstdlib>
#include <clocale>
using namespace std;
int enemyToAttack = 0;
int attack;
int enemyHP;
string enemyName;
bool enemyIsAlive = true;
int enemy2HP;
string enemy2Name;
bool enemy2IsAlive = true;
string heroName;
bool heroIsAlive = true;
int heroHP = 20;
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
    cout << "El enemigo " << enemyName << " ha aparecido!\n";
    cout << "Como se llama el segundo enemigo?\n";
    cin >> enemy2Name;
    cout << "El enemigo " << enemy2Name << " ha aparecido!\n";
}
void attacksRemain() {
    if (swordInTheChest_powerPoints == 0 && headbuttInStomach_powerPoints == 0 && rightHandCrochet_powerPoints == 0) {
        cout << "Te has quedado sin ataques...\n";
        cout << heroName << " se ha retirado\n";
        exit(0);
    }
}
int whoAttack() {
    cout << "A que enemigo quieres atacar [1] " << enemyName << " (" << enemyHP << "hp) o [2] " << enemy2Name << " (" << enemy2HP << "hp)?\n";
    cin >> enemyToAttack;
    if (enemyToAttack == 1 or enemyToAttack == 2) {
        return enemyToAttack;
    }
    else {
        return whoAttack();
    }
}
void whichAttackUse() {
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
}
int toAttackEnemy() {
    if (attack == 1 && swordInTheChest_powerPoints > 0) {
        cout << "A " << enemyName << " le haces " << swordInTheChest << " puntos de danyo.\n";
        swordInTheChest_powerPoints--;
        return enemyHP - swordInTheChest;
    }
    else if (attack == 2 && headbuttInStomach_powerPoints > 0) {
        cout << "A " << enemyName << " le haces " << headbuttInStomach << " puntos de danyo.\n";
        headbuttInStomach_powerPoints--;
        return enemyHP - headbuttInStomach;
    }
    else if (attack == 3 && rightHandCrochet_powerPoints > 0) {
        cout << "A " << enemyName << " le haces " << rightHandCrochet << " puntos de danyo.\n";
        rightHandCrochet_powerPoints--;
        return enemyHP - rightHandCrochet;
    }
}
int toAttackEnemy2() {
    if (attack == 1 && swordInTheChest_powerPoints > 0) {
        cout << "A " << enemy2Name << " le haces " << swordInTheChest << " puntos de danyo.\n";
        swordInTheChest_powerPoints--;
        return enemy2HP - swordInTheChest;
    }
    else if (attack == 2 && headbuttInStomach_powerPoints > 0) {
        cout << "A " << enemy2Name << " le haces " << headbuttInStomach << " puntos de danyo.\n";
        headbuttInStomach_powerPoints--;
        return enemy2HP - headbuttInStomach;
    }
    else if (attack == 3 && rightHandCrochet_powerPoints > 0) {
        cout << "A " << enemy2Name << " le haces " << rightHandCrochet << " puntos de danyo.\n";
        rightHandCrochet_powerPoints--;
        return enemy2HP - rightHandCrochet;
    }
}
int attackEnemy() {
    int enemyDmg;
    enemyDmg = (rand() % 50);
    cout << enemyName << " te ataca quitandote " << enemyDmg << " puntos de vida.\n";
    return heroHP - enemyDmg;
}
int attackEnemy2() {
    int enemy2Dmg;
    enemy2Dmg = (rand() % 50);
    cout << enemy2Name << " te ataca quitandote " << enemy2Dmg << " puntos de vida.\n";
    return heroHP - enemy2Dmg;
}
bool isHeroAlive() {
    if (heroHP <= 0) {
        cout << "Has Muerto.\n";
        return false;
    }
    else {
        cout << "Te quedan " << heroHP << " puntos de vida.\n";
        return true;
    }
}
bool isEnemyAlive() {
    if (enemyHP <= 0) {
        cout << enemyName << " a muerto.\n";
        return false;
    }
    else {
        cout << "A " << enemyName << " le quedan " << enemyHP << " puntos de vida.\n";
        return true;
    }
}
bool isEnemy2Alive() {
    if (enemy2HP <= 0) {
        cout << enemy2Name << " ha muerto.\n";
        return false;
    }
    else {
        cout << "A " << enemy2Name << " le quedan " << enemy2HP << " puntos de vida.\n";
        return true;
    }
}
void win() {
    if (!enemyIsAlive && !enemy2IsAlive) {
        cout << "Has ganado campeon.\n";
        exit(0);
    }
}
int main() {
    setlocale(LC_ALL, "");
    srand(time(nullptr));
    enemyHP = 50 + (rand() % 200);
    enemy2HP = 50 + (rand() % 200);
    names();
    while (enemyIsAlive && enemy2IsAlive) {
        attacksRemain();
        enemyToAttack = whoAttack();
        if (enemyToAttack == 1) {
            whichAttackUse();
            cin >> attack;
            enemyHP = toAttackEnemy();
            enemyIsAlive = isEnemyAlive();
            if (enemyIsAlive) {
                heroHP = attackEnemy();
                heroIsAlive = isHeroAlive();
                if (!heroIsAlive) {
                    exit(0);
                }
                if (heroIsAlive) {
                    heroHP = attackEnemy2();
                    heroIsAlive = isHeroAlive();
                    if (!heroIsAlive) {
                        exit(0);
                    }
                }
            }
        }
        if (enemyToAttack == 2) {
            whichAttackUse();
            cin >> attack;
            enemy2HP = toAttackEnemy2();
            enemy2IsAlive = isEnemy2Alive();
            if (enemy2IsAlive) {
                heroHP = attackEnemy2();
                heroIsAlive = isHeroAlive();
                if (!heroIsAlive) {
                    exit(0);
                }
                if (heroIsAlive) {
                    heroHP = attackEnemy();
                    heroIsAlive = isHeroAlive();
                    if (!heroIsAlive) {
                        exit(0);
                    }
                }
            }
        }
    }
    while (enemyIsAlive && !enemy2IsAlive) {
        attacksRemain();
        whichAttackUse();
        cin >> attack;
        enemyHP = toAttackEnemy();
        enemyIsAlive = isEnemyAlive();
        if (enemyIsAlive) {
            heroHP = attackEnemy();
            heroIsAlive = isHeroAlive();
            if (!heroIsAlive) {
                exit(0);
            }
        }
        else {
            win();
        }
    }
    while (!enemyIsAlive && enemy2IsAlive) {
        attacksRemain();
        whichAttackUse();
        cin >> attack;
        enemy2HP = toAttackEnemy2();
        enemy2IsAlive = isEnemy2Alive();
        if (enemy2IsAlive) {
            heroHP = attackEnemy2();
            heroIsAlive = isHeroAlive();
            if (!heroIsAlive) {
                exit(0);
            }
        }
        else {
            win();
        }
    }
}