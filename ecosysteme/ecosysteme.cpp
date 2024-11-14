// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'ex�cution du programme commence et se termine � cet endroit.
//

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

void clear(int obj = 0) {
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
	string bg = "";
	for (size_t i = 0; i < 30; i++)
	{
		cout << "\t\t\t\t\t";
		for (size_t j = 0; j < 90; j++)
		{
			if (board[i][j].iswater) bg = "104";
			else if (board[i][j].issand) bg = "43";
			else bg = "42";

			if (board[i][j].istree) cout << "\033[2;30;" + bg + "mT\033[0m";
			else if (board[i][j].animal.species != 0)
			{
				if (board[i][j].animal.sexe) sexe = "96";
				else sexe = "91";

				switch (board[i][j].animal.species)
				{
				case 1:
					if (board[i][j].animal.isadulte) cout << "\033[1;" + sexe + ";" + bg + "mC\033[0m";
					else cout << "\033[1;" << sexe << ";" + bg + "mc\033[0m";
					break;
				case 2:
					if (board[i][j].animal.isadulte) cout << "\033[1;" << sexe << ";" + bg + "mH\033[0m";
					else cout << "\033[1;" << sexe << ";" + bg + "mh\033[0m";
					break;
				case 3:
					if (board[i][j].animal.isadulte) cout << "\033[1;" << sexe << ";" + bg + "mD\033[0m";
					else cout << "\033[1;" << sexe << ";" + bg + "md\033[0m";
					break;
				default:
					cout << "\033[" + bg + "m \033[0m";
					break;
				}
			}

			else cout << "\033[" + bg + "m \033[0m";

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
		water(x, y - 1, taux - 10);
		water(x, y + 1, taux - 10);
		water(x - 1, y - 1, taux - 10);
		water(x - 1, y, taux - 5);
		water(x - 1, y + 1, taux - 10);
		water(x + 1, y - 1, taux - 10);
		water(x + 1, y, taux - 5);
		water(x + 1, y + 1, taux - 10);
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
		tree(x, y - 1, taux - 20);
		tree(x, y + 1, taux - 20);
		tree(x - 1, y - 1, taux - 20);
		tree(x - 1, y, taux - 10);
		tree(x - 1, y + 1, taux - 20);
		tree(x + 1, y - 1, taux - 20);
		tree(x + 1, y, taux - 10);
		tree(x + 1, y + 1, taux - 20);
	}
}
int main()
{
	board[15][30].animal.species = 1;
	srand(time(0));
	int x;
	while (true)
	{

		system("cls");
		display();
		cin >> x;
		cin.ignore(1000, '\n');
		water(15, 15, 100);
		water(70, 1, 100);
		tree(20, 20, 100);
	}

}

// Ex�cuter le programme�: Ctrl+F5 ou menu D�boguer�> Ex�cuter sans d�bogage
// D�boguer le programme�: F5 ou menu D�boguer�> D�marrer le d�bogage

// Astuces pour bien d�marrer�: 
//   1. Utilisez la fen�tre Explorateur de solutions pour ajouter des fichiers et les g�rer.
//   2. Utilisez la fen�tre Team Explorer pour vous connecter au contr�le de code source.
//   3. Utilisez la fen�tre Sortie pour voir la sortie de la g�n�ration et d'autres messages.
//   4. Utilisez la fen�tre Liste d'erreurs pour voir les erreurs.
//   5. Acc�dez � Projet�> Ajouter un nouvel �l�ment pour cr�er des fichiers de code, ou � Projet�> Ajouter un �l�ment existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, acc�dez � Fichier�> Ouvrir�> Projet et s�lectionnez le fichier .sln.