#include<vector>
#include<iostream>
using namespace std;

// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
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


class Animal
{
protected:
	// nom, sexe, age, faim, soif, race : attributs
	string race;
	int age;
	int maxAge;
	int speed;
	int thirsty;
	int hungry;
	int categorie;
	bool sexe;// true = homme/false = femme
	int aliment;// 1 = carnivore, 2 = herbivore


public:

	Animal(string race, bool s, int e, int a, int c, int h, int x, int y) : race(race), sexe(s), x(x), y(y), speed(e), age(a), categorie(c), thirsty(h), hungry(h) {}

	// reproduction, manger, boire, chasser, deplacer : methodes
	int x, y;
	bool alive = true;

	bool sex()
	{
		int alea = rand() % 1;
		if (alea == 0)
		{
			sexe = true;
		}

		else
		{
			sexe = false;
		}
	}

	Animal(string Race, bool sexe, int e, int a, int c, int h, int x, int y, int l) : race(Race), sexe(sexe), x(x), y(y), speed(e), age(a), categorie(c), thirsty(h), hungry(h), aliment(l) {}

	// reproduction, manger, boire, chasser, deplacer : methodes

	virtual void eat() = 0;
	virtual void drink() = 0;
	virtual void reproduction(Animal& target) = 0;
	virtual void hunt(Animal& target) = 0;
	virtual void talk(Animal& other) = 0;

	void agee()
	{
		int debut = 0;

		if (debut != 1)
		{
			cout << " Choisissez l'age maximum des animaux : " << endl;
			int nbMax;
			cin >> nbMax;
		}

		if (alive)
		{
			age++;
			if (age >= maxAge)
			{
				alive = false;
				cout << getRace() << "  est mort vieillesse." << endl;
			}
		}
	}


	string getRace() const { return race; }
	bool getSexe() const { return sexe; }
	int getAge() const { return age; }
	int getSpeed() const { return speed; }
	int getThirsty() const { return thirsty; }
	int getHungry() const { return hungry; }
	int getCategorie() const { return categorie; }
	int getAliment() const { return aliment; }
};

vector<Animal*> animaux;

class Capybara : public Animal
{
public:

	// bool sexe, int x, int y, int age : pas besoin dans constructeur

	Capybara() : Animal("Capybara", sexe, 1, age, 1, 100, x, y, 1) {}


	void eat() override
	{
		int max = 100;
		if (hungry > 90)
		{
			hungry = 100;
		}
		else
		{
			hungry += 10;
		}
	}

	void drink() override
	{
		int max = 100;
		if (thirsty > 90)
		{
			thirsty = 100;
		}
		else
		{
			thirsty += 10;
		}
	}


	void reproduction(Animal& target) override
	{
		// Vérification des cases adjacentes
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if (i == 0 && j == 0) continue; // Ne pas compter la case elle-même
				int nx = x + i;
				int ny = y + j;

				// Vérification des limites
				if (nx >= 0 && nx < 30 && ny >= 0 && ny < 90)
				{
					if (board[nx][ny].animal.species != 0)
					{
						if (race == target.getRace())
						{
							if (sexe != target.getSexe())
							{
								if (age >= 10 && target.getAge() >= 10)
								{
									animaux.push_back(new Capybara());

									cout << " Un Capybara est né." << endl;
								}
							}
						}
					}
				}
			}
		}
	}


	void hunt(Animal& target) override
	{
		// se deplace en fonction de la position de target : appeler deplacement()

		cout << "Position du personnage : (" << x << ", " << y << ")" << std::endl;

		// si sur la meme case mouru
		if (x == target.x && y == target.y)
		{
			// appel du destructeur 
		}
		cout << race << " chasse " << target.getRace() << " ! " << endl;

		cout << target.getRace() << " est mort, mangé par : " << race << " ! " << endl;
	}

	void talk(Animal& other) override
	{
		// Vérification des cases adjacentes
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if (i == 0 && j == 0) continue; // Ne pas compter la case elle-même
				int nx = x + i;
				int ny = y + j;

				// Vérification des limites
				if (nx >= 0 && nx < 30 && ny >= 0 && ny < 90)
				{
					if (board[nx][ny].animal.species == 1)
					{
						cout << " le " << race << " discute avec " << race << endl;
					}

					if (board[nx][ny].animal.species == 2)
					{
						cout << " le " << race << " discute avec " << race << endl;
					}

					else
					{
						cout << " le " << race << " discute avec " << race << endl;
					}
				}
			}
		}
	}
};

class Hippopotamus : public Animal
{
public:

	Hippopotamus() : Animal("Hippopotamus", sexe, 1, age, 2, 100, x, y, 1) {}

	void eat() override
	{
		int max = 100;
		if (hungry > 90)
		{
			hungry = 100;
		}
		else
		{
			hungry += 10;
		}
	}

	void drink() override
	{
		int max = 100;
		if (thirsty > 90)
		{
			thirsty = 100;
		}
		else
		{
			thirsty += 10;
		}
	}


	void reproduction(Animal& target) override
	{
		if (race == target.getRace())
		{
			if (age == 10 && target.getAge() <= 10)
			{
				animaux.push_back(new Hippopotamus());

				cout << " Un hippopotame est né." << endl;
			}
		}
	}
	void hunt(Animal& target) override
	{
		// se deplace en fonction de la position de target : appeler deplacement()

		cout << "Position du personnage : (" << x << ", " << y << ")" << std::endl;

		if (x == target.x && y == target.y) // si sur la meme case mouru
		{
			// appel du destructeur 
		}
		cout << race << " chasse " << target.getRace() << " ! " << endl;

		cout << target.getRace() << " est mort, mangé par : " << race << " ! " << endl;
	}

	void talk(Animal& other) override
	{
		// Vérification des cases adjacentes
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if (i == 0 && j == 0) continue; // Ne pas compter la case elle-même
				int nx = x + i;
				int ny = y + j;

				// Vérification des limites
				if (nx >= 0 && nx < 30 && ny >= 0 && ny < 90)
				{
					if (board[nx][ny].animal.species == 1)
					{
						cout << " le " << race << " discute avec " << race << endl;
					}

					if (board[nx][ny].animal.species == 2)
					{
						cout << " le " << race << " discute avec " << race << endl;
					}

					else
					{
						cout << " le " << race << " discute avec " << race << endl;
					}
				}
			}
		}
	}
};

class Dragon : public Animal
{
public:

	Dragon() : Animal("Dragon", sexe, 1, age, 3, 100, x, y, 2) {}

	void eat() override
	{
		int max = 100;
		if (hungry > 90)
		{
			hungry = 100;
		}
		else
		{
			hungry += 10;
		}
	}

	void drink() override
	{
		int max = 100;
		if (thirsty > 90)
		{
			thirsty = 100;
		}
		else
		{
			thirsty += 10;
		}
	}

	void reproduction(Animal& target) override
	{
		if (race == target.getRace())
		{
			if (age == 10 && target.getAge() <= 10)
			{
				animaux.push_back(new Dragon());

				cout << " Un dragon est né." << endl;
			}
		}
	}

	void hunt(Animal& target) override
	{
		// se deplace en fonction de la position de target : appeler deplacement()

		cout << "Position du personnage : (" << x << ", " << y << ")" << std::endl;

		// si sur la meme case mouru
		if (x == target.x && y == target.y)
		{
			// appel du destructeur 
		}
		cout << race << " chasse " << target.getRace() << " ! " << endl;

		cout << target.getRace() << " est mort, mangé par : " << race << " ! " << endl;
	}

	void talk(Animal& other) override
	{
		// Vérification des cases adjacentes
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if (i == 0 && j == 0) continue; // Ne pas compter la case elle-même
				int nx = x + i;
				int ny = y + j;

				// Vérification des limites
				if (nx >= 0 && nx < 30 && ny >= 0 && ny < 90)
				{
					if (board[nx][ny].animal.species == 1)
					{
						cout << " le " << race << " discute avec " << race << endl;
					}

					if (board[nx][ny].animal.species == 2)
					{
						cout << " le " << race << " discute avec " << race << endl;
					}

					else
					{
						cout << " le " << race << " discute avec " << race << endl;
					}
				}
			}
		}
	}
};

// instaurer un temps de presence aux animaux si un animal meurt un autre spawn


int nbAnimaux; // besoin de ca si qq1 bouge le programme de fichier ca initialise la variables pour la suite du code : dans main ?

// quand nb animaux sur map < au nombre dans la variable : creer un nouvel animal


class Jeu
{
public:

	~Jeu()
	{
		for (auto animal : animaux)
			delete animal;
	}

	void NbAnimaux()
	{
		cout << " voulez choisir un nb d'animaux ? " << endl << " oui : 1, non : 0 " << endl; // demander au joueur si il veut donner un nb d'animaux precis ou un nb predefinit 
		int choix;
		cin >> choix;
		switch (choix)
		{
		case 0:
			nbAnimaux = 10;
			break;
		case 1:
			cout << " Choissisez le nb d'animaux : " << endl;
			int nb;
			cin >> nb;
			nbAnimaux = nb;
		}
	}

	void init(int nombreAniamux)
	{
		srand(time(0));
		for (int i = 0; i < nbAnimaux; ++i)
		{
			int classe = rand() % 3;
			switch (classe)
			{
			case 0: animaux.push_back(new Capybara()); break;
			case 1: animaux.push_back(new Hippopotamus()); break;
			case 2: animaux.push_back(new Dragon()); break;
			}
		}
	}
};



// 0 = pas d'animal / 1 = Capybara / 2 = Hippopotame / 3 = Dragon
// ajouter position animal pour suivre déplacement
// animal (int posX, int posY) : x(posX), y(posY){}


int researchx, researchy, nbCase;
int besoin;
int posx, posy;
int nbCasex;
int nbCasey;
int valeur;


// rajouter une consommation // se déplacer (*2) ou ne rien faire consomme de l'énergie et de la faim
void research(int valeur, const Animal& target) {
	int min = 30 * 90;


	for (int researchy = 0; researchy < 30; researchy++)
	{
		for (int researchx = 0; researchx < 90; researchx++)
		{
			switch (valeur)// recherche proie = 1 , recherche arbre = 2 , recherche eau =3
			{
			case 1:
				if (board[researchy][researchx].animal.species > target.getCategorie())
				{
					if (researchx - target.x > 0)
					{
						nbCasex = researchx - target.x;
					}
					else
					{
						nbCasex = target.x - researchx;
					}

					if (researchy - target.y > 0)
					{
						researchx - target.x;
					}
					else
					{
						researchx - target.x;
					}
					nbCase = nbCasex + nbCasey;

					if (nbCase < min)
					{
						min = nbCase;
						posx = researchx;
						posy = researchy;
					}
				}
				break;

			case 2:
				if (board[researchy][researchx].istree == true)
				{
					if (researchx - target.x > 0)
					{
						nbCasex = researchx - target.x;
					}
					else
					{
						nbCasex = target.x - researchx;
					}

					if (researchy - target.y > 0)
					{
						researchx - target.x;
					}
					else
					{
						researchx - target.x;
					}
					nbCase = nbCasex + nbCasey;

					if (nbCase < min)
					{
						min = nbCase;
						posx = researchx;
						posy = researchy;
					}
				}
				break;

			case 3:
				if (board[researchy][researchx].iswater == true)
				{
					if (researchx - target.x > 0)
					{
						nbCasex = researchx - target.x;
					}
					else
					{
						nbCasex = target.x - researchx;
					}

					if (researchy - target.y > 0)
					{
						researchx - target.x;
					}
					else
					{
						researchx - target.x;
					}
					nbCase = nbCasex + nbCasey;

					if (nbCase < min)
					{
						min = nbCase;
						posx = researchx;
						posy = researchy;
					}
				}
				break;
			default:
				break;
			}
		}
	}
}

void suppr(int x, int y, Animal& target) {// supprimer l'élément
	if (target.getHungry() < target.getThirsty())
	{
		if (target.getAliment() == 1)
		{
			target.alive = false;
		}
		else
		{
			board[10][10].fruits--;
		}
	}
	else
	{
		//boire mais ne se passera rien
	}

}

bool check(int x, int y, Animal& target) {
	if (x >= 0 || x < 30 || y >= 0 || y < 90) { return false; }
	if (board[y][x].animal.species > target.getCategorie())// voir pour categorie 3 pour arbre
	{
		suppr(x, y, target);
		return true;
	}
}

void choix(Animal& target)
{
	if (target.getHungry() < target.getThirsty())
	{
		//======================CARNIVORE=======================
		if (target.getAliment() == 1)
		{
			void hungryanimal(Animal & target);
			{
				if (target.getHungry() < 50)
				{
					valeur = 1;
					research(valeur, target);
				}
				if (target.x < posx)
				{
					target.x++;
					target.getThirsty() - 2;
					target.getHungry() - 4;
				}
				else if (target.x > posx)
				{
					target.x--;
					target.getThirsty() - 2;
					target.getHungry() - 4;
				}

				if (target.y < posy)
				{
					target.y++;
					target.getThirsty() - 2;
					target.getHungry() - 4;
				}
				else if (target.y > posy)
				{
					target.y--;
					target.getThirsty() - 2;
					target.getHungry() - 4;
				}

				if (check(target.x - 1, target.y - 1, target) ||
					check(target.x - 1, target.y, target) ||
					check(target.x - 1, target.y + 1, target) ||
					check(target.x, target.y + 1, target) ||
					check(target.x, target.y - 1, target) ||
					check(target.x + 1, target.y - 1, target) ||
					check(target.x + 1, target.y, target) ||
					check(target.x + 1, target.y + 1, target))
				{
					target.getHungry() + 50;
					return;
				}
			}
			//=======================HERBIVORE=============================
			if (target.getAliment() == 2)
			{
				void hungryanimal(Animal & target); {

					if (target.getHungry() < 50)
					{
						valeur = 2;
						research(valeur, target);
					}
					if (target.x < posx)
					{
						target.x++;
						target.getThirsty() - 2;
						target.getHungry() - 4;
					}
					else if (target.x > posx)
					{
						target.x--;
						target.getThirsty() - 2;
						target.getHungry() - 4;
					}

					if (target.y < posy)
					{
						target.y++;
						target.getThirsty() - 2;
						target.getHungry() - 4;
					}
					else if (target.y > posy)
					{
						target.y--;
						target.getThirsty() - 2;
						target.getHungry() - 4;
					}

					if (
						check(target.x - 1, target.y - 1, target) ||
						check(target.x - 1, target.y, target) ||
						check(target.x - 1, target.y + 1, target) ||
						check(target.x, target.y + 1, target) ||
						check(target.x, target.y - 1, target) ||
						check(target.x + 1, target.y - 1, target) ||
						check(target.x + 1, target.y, target) ||
						check(target.x + 1, target.y + 1, target))
					{
						target.getHungry() + 50;
						return;
					}


				}
			}
		}
		//========================SOIF=============================
		else
		{
			void thirstyanimal(Animal & target);
			{
				if (target.getThirsty() < 50)
				{
					valeur = 3;
					research(valeur, target);
				}
				if (target.x < posx)
				{
					target.x++;
					target.getThirsty() - 2;
					target.getHungry() - 4;
				}
				else if (target.x > posx)
				{
					target.x--;
					target.getThirsty() - 2;
					target.getHungry() - 4;
				}

				if (target.y < posy)
				{
					target.y++;
					target.getThirsty() - 2;
					target.getHungry() - 4;
				}
				else if (target.y > posy)
				{
					target.y--;
					target.getThirsty() - 2;
					target.getHungry() - 4;
				}

				if (
					check(target.x - 1, target.y - 1, target) ||

					check(target.x - 1, target.y, target) ||
					check(target.x - 1, target.y + 1, target) ||
					check(target.x, target.y + 1, target) ||
					check(target.x, target.y - 1, target) ||
					check(target.x + 1, target.y - 1, target) ||
					check(target.x + 1, target.y, target) ||
					check(target.x + 1, target.y + 1, target))
				{
					target.getThirsty() + 50;
					return;
				}
			}
		}
	}


	//=======================HERBIVORE=============================
	if (target.getAliment() == 2)
	{
		void hungryanimal(Animal & target); {

			if (target.getHungry() < 50)
			{
				valeur = 2;
				research(valeur, target);
			}
			if (target.x < posx)
			{
				target.x++;
				target.getThirsty() - 2;
				target.getHungry() - 4;
			}
			else if (target.x > posx)
			{
				target.x--;
				target.getThirsty() - 2;
				target.getHungry() - 4;
			}

			if (target.y < posy)
			{
				target.y++;
				target.getThirsty() - 2;
				target.getHungry() - 4;
			}
			else if (target.y > posy)
			{
				target.y--;
				target.getThirsty() - 2;
				target.getHungry() - 4;
			}

			if (
				check(target.x - 1, target.y - 1, target) ||
				check(target.x - 1, target.y, target) ||
				check(target.x - 1, target.y + 1, target) ||
				check(target.x, target.y + 1, target) ||
				check(target.x, target.y - 1, target) ||
				check(target.x + 1, target.y - 1, target) ||
				check(target.x + 1, target.y, target) ||
				check(target.x + 1, target.y + 1, target))
			{
				target.getHungry() + 50;
				return;
			}


		}

	}
	else
	{
		void thirstyanimal(Animal & target); {

			if (target.getThirsty() < 50)
			{
				valeur = 2;
				research(valeur, target);
			}
			if (target.x < posx)
			{
				target.x++;
				target.getThirsty() - 2;
				target.getHungry() - 4;
			}
			else if (target.x > posx)
			{
				target.x--;
				target.getThirsty() - 2;
				target.getHungry() - 4;
			}

			if (target.y < posy)
			{
				target.y++;
				target.getThirsty() - 2;
				target.getHungry() - 4;
			}
			else if (target.y > posy)
			{
				target.y--;
				target.getThirsty() - 2;
				target.getHungry() - 4;
			}

			if (
				check(target.x - 1, target.y - 1, target) ||
				check(target.x - 1, target.y, target) ||
				check(target.x - 1, target.y + 1, target) ||
				check(target.x, target.y + 1, target) ||
				check(target.x, target.y - 1, target) ||
				check(target.x + 1, target.y - 1, target) ||
				check(target.x + 1, target.y, target) ||
				check(target.x + 1, target.y + 1, target))
			{
				target.getHungry() + 50;
				return;
			}
		}
	}
}


// déplacement aléatoire
// vérifier s'il peut se reproduire
// chasser déplacement plus rapide
// ne rien faire fait consommer faim et soif

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