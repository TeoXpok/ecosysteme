// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#pragma once
#include <iostream>
using namespace std;


struct animal {
	int species = 0; // 0 = pas d'animal / 1 = Capybara / 2 = Hippopotame / 3 = Dragon
	bool sexe = true; // true = male / false = female
	bool isadulte = true;
};


struct cell
{
	bool issand = false;
	bool iswater = false;
	bool istree = false;
	int fruits = 0;
	int timer = 0;
	animal animal;

};

cell board[30][90];

void clear() {
	for (size_t i = 0; i < 30; i++)
	{
		for (size_t j = 0; j < 90; j++)
		{
			if (board[i][j].animal.species != 0)
				board[i][j].animal.species = 0;
		}
	}
}

void display() {
	cout << endl;
	string sexe = "";
	int bg = 0;
	for (size_t i = 0; i < 29; i++)
	{
		cout << "\t\t\t\t\t\t\t";
		for (size_t j = 0; j < 89; j++)
		{
			if (board[i][j].iswater) bg = 104;
			else if (board[i][j].issand) bg = 103;
			else bg = 102;

			if (board[i][j].istree) cout << "\033[2;30;" << (bg - 60) << "mT\033[0m";
			else if (board[i][j].animal.species != 0)
			{
				if (board[i][j].animal.sexe) sexe = "96";
				else sexe = "31";

				switch (board[i][j].animal.species)
				{
				case 1:
					if (board[i][j].animal.isadulte) cout << "\033[2;" + sexe + ";" << bg << "mC\033[0m";
					else cout << "\033[1;" << sexe << ";" << bg << "mc\033[0m";
					break;
				case 2:
					if (board[i][j].animal.isadulte) cout << "\033[1;" << sexe << ";" << bg << "mH\033[0m";
					else cout << "\033[1;" << sexe << ";" << bg << "mh\033[0m";
					break;
				case 3:
					if (board[i][j].animal.isadulte) cout << "\033[1;" << sexe << ";" << bg << "mD\033[0m";
					else cout << "\033[1;" << sexe << ";" << bg << "md\033[0m";
					break;
				default:
					cout << "\033[" << bg << "m \033[0m";
					break;
				}
			}

			else cout << "\033[" << bg << "m \033[0m";

		}
		cout << endl;
	}
}

void water(int x, int y, int taux) {
	if (x < 0 || y < 0 || x > 89 || y > 29 || board[y][x].iswater) return;

	int chance = rand() % 100;
	if (chance <= taux)
	{
		board[y][x].iswater = true;
		water(x, y - 1, taux - 8);
		water(x, y + 1, taux - 8);
		water(x - 1, y - 1, taux - 8);
		water(x - 1, y, taux - 3);
		water(x - 1, y + 1, taux - 8);
		water(x + 1, y - 1, taux - 8);
		water(x + 1, y, taux - 3);
		water(x + 1, y + 1, taux - 8);
	}
	else
		board[y][x].issand = true;

}

void tree(int x, int y, int taux) {
	if (x < 0 || y < 0 || x > 89 || y > 29 || board[y][x].iswater || board[y][x].istree) return;

	int chance = rand() % 100;
	if (chance <= taux)
	{
		board[y][x].istree = true;
		tree(x, y - 1, taux - 25);
		tree(x, y + 1, taux - 25);
		tree(x - 1, y - 1, taux - 25);
		tree(x - 1, y, taux - 15);
		tree(x - 1, y + 1, taux - 25);
		tree(x + 1, y - 1, taux - 25);
		tree(x + 1, y, taux - 15);
		tree(x + 1, y + 1, taux - 25);
	}
}

void generate() {

	int x;
	int y;

	for (size_t i = 0; i < 3; i++)
	{
		x = rand() % 89;
		y = rand() % 29;
		if (board[y][x].iswater) i--;
		else water(x, y, 100);
	}

}

int main()
{
	board[15][30].animal.species = 1;
	srand(time(0));
	int x;
	generate();
	tree(20, 20, 100);
	while (true)
	{

		system("cls");
		display();
		cin >> x;
		if (x == 0)break;
		cin.ignore(1000, '\n');


	}

}