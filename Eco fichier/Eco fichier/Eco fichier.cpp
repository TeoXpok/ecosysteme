#include<vector>
#include<iostream>
#include<ctime>
using namespace std;

int nbMax;
int researchx, researchy, nbCase;
int besoin;
int posx, posy;
int nbCasex;
int nbCasey;
int valeur;
int depCase = rand() % 5 + 1;

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

class Animal
{
protected:
	// nom, sexe, age, faim, soif, race : attributs
	string race;
	int age;
	int speed;
	int thirsty;
	int hungry;
	int categorie;
	bool sexe = rand() % 2;// true = homme / false = femme
	int aliment;// 1 = carnivore, 2 = herbivore
	

public:

	Animal(string Race,  int e, int a, int c, int h, int x, int y, int l) : race(Race), x(x), y(y), speed(e), age(a), categorie(c), thirsty(h), hungry(h), aliment(l) {}

	// reproduction, manger, boire, chasser, deplacer : methodes
	int x, y;
	bool alive = true;
	// reproduction, manger, boire, chasser, deplacer : methodes

	virtual void eat(int nb) = 0;
	virtual void drink(int nb) = 0;
	virtual void reproduction(Animal& target) = 0;
	virtual void talk(Animal& other) = 0;

	void agee()
	{
		if (alive)
		{
			age++;
			if (age >= nbMax)
			{
				alive = false;
				cout << getRace() << "  est mort de vieillesse. " << endl;
			}
		}
	}
	void research(int valeur) {
		int min = 30 * 90;


		for (int researchy = 0; researchy < 30; researchy++)
		{
			for (int researchx = 0; researchx < 90; researchx++)
			{
				switch (valeur)// recherche proie = 1 , recherche arbre = 2 , recherche eau =3
				{
				case 1:
					if (board[researchy][researchx].animal.species > categorie)
					{
						if (researchx - x > 0)
						{
							nbCasex = researchx -x;
						}
						else
						{
							nbCasex = x - researchx;
						}

						if (researchy - y > 0)
						{
							researchx - x;
						}
						else
						{
							researchx - x;
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
						if (researchx - x > 0)
						{
							nbCasex = researchx - x;
						}
						else
						{
							nbCasex = x - researchx;
						}

						if (researchy - y > 0)
						{
							researchx - x;
						}
						else
						{
							researchx - x;
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
						if (researchx - x > 0)
						{
							nbCasex = researchx - x;
						}
						else
						{
							nbCasex = x - researchx;
						}

						if (researchy - y > 0)
						{
							researchx - x;
						}
						else
						{
							researchx - x;
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

	void suppr(int x, int y) {//a revoir, supprimer l'élément
		if (hungry < thirsty)
		{
			if (aliment == 1)
			{
				alive = false;
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

	bool check(int x, int y) {
		if (x >= 0 || x < 30 || y >= 0 || y < 90) { return false; }
		if (board[y][x].animal.species > categorie)// voir pour categorie 3 pour arbre
		{
			suppr(x, y);
			return true;
		}
	}

	void deplacement(int posx, int posy)
	{
		if (x < posx)
		{
			x++;
			drink(-2);
			eat(-4);
		}
		else if (x > posx)
		{
			x--;
			drink(-2);
			eat(-4);
		}

		if (y < posy)
		{
			y++;
			drink(-2);
			eat(-4);
		}
		else if (y > posy)
		{
			y--;
			drink(-2);
			eat(-4);
		}
	}

	void choix()
	{
		agee();

		if (hungry < thirsty && hungry < 50)
		{
			//======================CARNIVORE==========================
			if (aliment == 1)
			{
				valeur = 1;
				research(valeur);
				deplacement( posx, posy);

				if (check(x - 1, y - 1) ||
					check(x - 1, y) ||
					check(x - 1, y + 1) ||
					check(x, y + 1) ||
					check(x, y - 1) ||
					check(x + 1, y - 1) ||
					check(x + 1, y) ||
					check(x + 1, y + 1))
				{
					eat(50);
					return;
				}
			}
			//=======================HERBIVORE=========================
			else if (aliment == 2)
			{
				valeur = 2;
				research(valeur);
				deplacement(posx, posy);

				if (check(x - 1, y - 1) ||
					check(x - 1, y) ||
					check(x - 1, y + 1) ||
					check(x, y + 1) ||
					check(x, y - 1) ||
					check(x + 1, y - 1) ||
					check(x + 1, y) ||
					check(x + 1, y + 1))
				{
					eat(30);
					return;
				}
			}
		}
		//========================SOIF=============================
		else if (aliment == 3)
		{
			valeur = 3;
			research(valeur);
			deplacement(posx, posy);

			if (check(x - 1, y - 1) ||
				check(x - 1, y) ||
				check(x - 1, y + 1) ||
				check(x, y + 1) ||
				check(x, y - 1) ||
				check(x + 1, y - 1) ||
				check(x + 1, y) ||
				check(x + 1, y + 1))
			{
				drink(50);
				return;
			}
		}
		//=================DEPLACEMENT ALEATOIRE===================
		else if (true)
		{
			reproduction();
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

	Capybara(int x, int y, int age) : Animal("Capybara", 1, age, 1, 100, x, y, 1) {}


	void eat(int nb) override
	{
		hungry += nb;
	}

	void drink(int nb) override
	{
		thirsty += nb;
	}

	void reproduction() override// A revoir
	{
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if (i == 0 && j == 0) continue; // Ne pas compter la case elle-même
				if (i >= 0 && i < 30 && j >= 0 && j < 90)
				{
					if (board[i][j].animal.species == categorie)
					{
						if (board[i][j].animal.sexe != sexe)
						{
							if (age > 10 && board[i][j].animal.isadulte)
							{
								animaux.push_back(new Capybara(i,j,0));
								cout << " Un Capybara est né." << endl;
							}
						}
					}
				}
			}
		}
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

	Hippopotamus(int x, int y, int age) : Animal("Hippopotamus", 1, age, 2, 100, x, y, 1) {}

	void eat(int nb) override
	{
		hungry += nb;
	}

	void drink(int nb) override
	{
		thirsty += nb;
	}


	void reproduction() override// A revoir
	{
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if (i == 0 && j == 0) continue; // Ne pas compter la case elle-même
				if (i >= 0 && i < 30 && j >= 0 && j < 90)
				{
					if (board[i][j].animal.species == categorie)
					{
						if (board[i][j].animal.sexe != sexe)
						{
							if (age > 10 && board[i][j].animal.isadulte)
							{
								animaux.push_back(new Hippopotamus(i, j, 0));
								cout << " Un Hippopotamus est né." << endl;
							}
						}
					}
				}
			}
		}
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

	Dragon(int x, int y, int age) : Animal("Dragon", 1, age, 3, 100, x, y, 2) {}

	void eat(int nb) override
	{
		hungry += nb;
	}

	void drink(int nb) override
	{
		thirsty += nb;
	}

	void reproduction() override// A revoir
	{
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if (i == 0 && j == 0) continue; // Ne pas compter la case elle-même
				if (i >= 0 && i < 30 && j >= 0 && j < 90)
				{
					if (board[i][j].animal.species == categorie)
					{
						if (board[i][j].animal.sexe != sexe)
						{
							if (age > 10 && board[i][j].animal.isadulte)
							{
								animaux.push_back(new Dragon(i, j, 0));
								cout << " Un Dragon est né." << endl;
							}
						}
					}
				}
			}
		}
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

void add() {

	for (auto& animal : animaux) {
		int x = animal->x;
		int y = animal->y;
		board[y][x].animal.sexe = animal->getSexe();
		board[y][x].animal.species = animal->getCategorie();
		if (animal->getAge() > 10) board[y][x].animal.isadulte = true;
		else board[y][x].animal.isadulte = false;
	}
}

void display() {
	cout << endl;
	string sexe = "";
	int bg = 0;
	clear();
	add();
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
				if (board[i][j].animal.sexe) sexe = "34";
				else sexe = "31";

				switch (board[i][j].animal.species)
				{
				case 1:
					if (board[i][j].animal.isadulte) cout << "\033[2;" + sexe + ";" << bg << "mC\033[0m";
					else cout << "\033[2;" << sexe << ";" << bg << "mc\033[0m";
					break;
				case 2:
					if (board[i][j].animal.isadulte) cout << "\033[2;" << sexe << ";" << bg << "mH\033[0m";
					else cout << "\033[2;" << sexe << ";" << bg << "mh\033[0m";
					break;
				case 3:
					if (board[i][j].animal.isadulte) cout << "\033[2;" << sexe << ";" << bg << "mD\033[0m";
					else cout << "\033[2;" << sexe << ";" << bg << "md\033[0m";
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

	for (size_t i = 0; i < 4; i++)
	{
		x = rand() % 89;
		y = rand() % 29;
		if (board[y][x].iswater) i--;
		else water(x, y, 100);
	}
	for (size_t i = 0; i < 10; i++)
	{
		x = rand() % 89;
		y = rand() % 29;
		if (board[y][x].iswater || board[y][x].istree) i--;
		else tree(x, y, 100);
	}
}




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

	int NbAnimaux()
	{
		cout << " voulez choisir un nb d'animaux ? " << endl << " oui : 1, non : 0 " << endl; // demander au joueur si il veut donner un nb d'animaux precis ou un nb predefinit 
		int choix;
		cin >> choix;
		switch (choix)
		{
		case 0:
			nbAnimaux = 44;
			return  nbAnimaux;
			break;
		case 1:
			cout << " Choissisez le nb d'animaux : " << endl;
			int nb;
			cin >> nb;
			return nb;
		}
	}

	void init(int nombreAniamux)
	{
		int x;
		int y;
		for (int i = 0; i < nombreAniamux; ++i)
		{
			int classe = rand() % 3;
			x = rand() % 89;
			y = rand() % 29;
			switch (classe)
			{
			case 0: animaux.push_back(new Capybara(x, y, 11)); break;
			case 1: animaux.push_back(new Hippopotamus(x, y, 11)); break;
			case 2: animaux.push_back(new Dragon(x, y, 11)); break;
			}
		}

		int debut = 0;

			cout << " Choisissez l'age maximum des animaux : " << endl;
			cin >> nbMax;
	}
};




void update() {
	
	for (auto& animal : animaux) {
		animal->choix();
	}
}
// vérifier s'il peut se reproduire


int main()
{
	srand(time(0));
	int x;
	generate();
	Jeu jeu;
	int nb = jeu.NbAnimaux();
	jeu.init(nb);
	while (true)
	{
		system("cls");
		display();
		cin >> x;
		if (x == 0)break;
		cin.ignore(1000, '\n');
		update();

	}
}