#include <iostream>
#include <cstdlib>
#include <clocale>
#include <cctype>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;
int money, bet, mc, num, type, playerCardsValue, croupierCardsValue = 0;
string cards[2][14] = {
	{"1","2","3","4","5","6","7","8","9","10","J","Q","K","A"},
	{"diamons","hearts","spades","clubs"}
};
bool verify[2][14] = { false };
string playerCards, croupierCards;
string player = "player";
string croupier = "croupier";
bool play = true;
void intro() {
	cout << " /$$$$$$$  /$$        /$$$$$$   /$$$$$$  /$$   /$$    /$$$$$  /$$$$$$   /$$$$$$  /$$   /$$\n";
	cout << "| $$__  $$| $$       /$$__  $$ /$$__  $$| $$  /$$/   |__  $$ /$$__  $$ /$$__  $$| $$  /$$/\n";
	cout << "| $$   |$$| $$      | $$   |$$| $$  |__/| $$ /$$/       | $$| $$  | $$| $$  |__/| $$ /$$/ \n";
	cout << "| $$$$$$$ | $$      | $$$$$$$$| $$      | $$$$$/        | $$| $$$$$$$$| $$      | $$$$$/  \n";
	cout << "| $$__  $$| $$      | $$__  $$| $$      | $$  $$   /$$  | $$| $$__  $$| $$      | $$  $$  \n";
	cout << "| $$   |$$| $$      | $$  | $$| $$    $$| $$ | $$ | $$  | $$| $$  | $$| $$    $$| $$ | $$ \n";
	cout << "| $$$$$$$/| $$$$$$$$| $$  | $$|  $$$$$$/| $$ |  $$|  $$$$$$/| $$  | $$|  $$$$$$/| $$ |  $$\n";
	cout << "|_______/ |________/|__/  |__/|_______/ |__/ |__/ |_______/ |__/  |__/|______/  |__/ |___/\n";
	cout << "\n";
	cout << "                          Done by Iker Corpas and Mario Valverde\n";
	cout << "\n";
	cout << "                                  Press any key to start\n";
	while (!_kbhit()) {}
	for (int i = 0; i < 50; i++)
	{
		cout << "\n";
	}
};
void chips(int& m) {
	cout << "How many chips you have to play with?\n";
	cin >> m;
	Sleep(1000);
	cout << "You will play with " << m << " chips!\n";
}
void betting(int& b, int& m) {
	cout << "How much your bet will be?\n";
	cin >> b;
	m = m - b;
	Sleep(1000);
	cout << "You're bet is " << b << " chips!\n";
}
void another(int m) {
	int answ;
	if (m <= 0) {
		cout << "You have no more chips to play :(\n";
		play = false;
	}
	else {
		cout << "Do you want to play another game? (1)yes (2)no";
		cin >> answ;
		if (answ == 2) {
			Sleep(1000);
			cout << "You stop playing Blackjack\n";
			Sleep(1000);
			cout << "Your total chips are " << m << "!\n";
			play = false;
		}
	}
}
void win(int& m, int b) {
	cout << "You win " << (b * 2) << " chips :)\n";
	m = m + b * 2;
	Sleep(1000);
	cout << "You have " << m << " chips in total!\n";
	another(m);
}
void lose(int& b, int& m) {
	cout << "You lose " << b << " chips :(\n";
	b = 0;
	Sleep(1000);
	cout << "You have " << m << " chips in total!\n";
	another(m);
}
void reset(string& playerCards, string& croupierCards, int& playerCardsValue, int& croupierCardsValue) {
	playerCards.clear();
	croupierCards.clear();
	playerCardsValue = 0;
	croupierCardsValue = 0;
}
int cardDeal(int& value, string& dealCards, string name) {
	bool initialized = false;
	int rn, rt;
	if (!initialized) {
		srand(time(nullptr));
		initialized = true;
	}
	do {
		rn = rand() % 13;
		rt = rand() % 4;
	} while (verify[rt][rn]);
	verify[rt][rn] = true;
	cout << "The croupier deal to " << name << " a " << cards[0][rn];
	if (cards[0][rn] == "J" || cards[0][rn] == "Q" || cards[0][rn] == "K") {
		value = value + 10;
	}
	else if (cards[0][rn] == "A") {
		int ace;
		cout << "Do you want this Ace to be a (1) or an (11)?\n";
		cin >> ace;
		if (ace == 1) {
			value = value + 1;
		}
		else if (ace == 11) {
			value = value + 11;
		}
	}
	else {
		value = value + (rn + 1);
	}
	dealCards = dealCards + " " + cards[0][rn] + " of " + cards[1][rt] + ".";
	cout << " of " << cards[1][rt] << ".\n";
	return value;
}
int main() {
	//intro();
	chips(money);
	do {
		reset(playerCards, croupierCards, playerCardsValue, croupierCardsValue);
		betting(bet, money);
		cout << "The croupier starts dealing the cards...\n";
		Sleep(1000);
		playerCardsValue = cardDeal(playerCardsValue, playerCards, player);
		Sleep(1000);
		croupierCardsValue = cardDeal(croupierCardsValue, croupierCards, croupier);
		Sleep(1000);
		playerCardsValue = cardDeal(playerCardsValue, playerCards, player);
		Sleep(1000);
		cout << "You're cards are :" << playerCards << ".\n";
		Sleep(1000);
		cout << "Your cards value is " << playerCardsValue << ".\n";
		Sleep(1000);
		cout << "Croupier cards are :" << croupierCards << ".\n";
		Sleep(1000);
		cout << "Croupier cards value is " << croupierCardsValue << ".\n";
		Sleep(1000);
		if (playerCardsValue == 21) {
			win(money, bet);
		}
		else if (playerCardsValue < 21) {
			int mc = 0;
			while (mc != 2) {
				cout << "Actual Value : " << playerCardsValue << "!\n";
				Sleep(1000);
				cout << "Do you want another card? (1)yes (2)no\n";
				Sleep(1000);
				cin >> mc;
				if (mc == 1) {
					playerCardsValue = cardDeal(playerCardsValue, playerCards, player);
					Sleep(1000);
					cout << "You're cards are :" << playerCards << ".\n";
					Sleep(1000);
					cout << "Your cards value is " << playerCardsValue << ".\n";
					Sleep(1000);
					if (playerCardsValue == 21) {
						win(money, bet);
					}
					else if (playerCardsValue > 21) {
						lose(bet, money);
					}
				}
			}
			while (croupierCardsValue < 17) {
				croupierCardsValue = cardDeal(croupierCardsValue, croupierCards, croupier);
				Sleep(1000);
				cout << "Croupier cards are :" << croupierCards << ".\n";
				Sleep(1000);
				cout << "Croupier cards value is " << croupierCardsValue << ".\n";
				Sleep(1000);
				if (croupierCardsValue == 21) {
					lose(bet, money);
				}
				else if (croupierCardsValue > 21) {
					win(money, bet);
				}
			}
			if (croupierCardsValue >= 17 && croupierCardsValue <= 21) {
				if (croupierCardsValue > playerCardsValue) {
					lose(bet, money);
				}
				else if (croupierCardsValue < playerCardsValue) {
					win(money, bet);
				}
				else {
					lose(bet, money);
				}
			}
		}
	} while (play);
}