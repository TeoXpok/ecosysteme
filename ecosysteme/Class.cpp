#include<vector>
#include"ecosysteme.cpp"
#include<iostream>
using namespace std;

const int Size = 30;
// const char tab[Size][Size];
vector<Animal*> animaux;

class Animal
{
protected:
	// nom, sexe, age, statut, faim, soif, race : attributs
	string race;
	string statut;
	bool sexe;// true = homme/false = femme
	int age;
	int speed;
	int thirsty;
	int hungry;
	int categorie;
	bool alive = true;
	

public:

	Animal( string Race, bool sexe, int e, int a, int c, int h, int x, int y) : race(Race), sexe(sexe), x(x), y(y), speed(e), age(a), categorie(c), thirsty(h), hungry(h) {}

	// reproduction, manger, boire, chasser, deplacer : methodes
	int x, y;
	

	virtual void eat() = 0;
	virtual void drink() = 0;
	virtual void reproduction(Animal& target) = 0;
	virtual void hunt(Animal& target) = 0;
	virtual void talk(Animal& other) = 0;
	// virtual void die() = 0;

	
	string getRace() const { return race; }
	string getPos() const { return statut; }
	bool getSexe() const { return sexe; }
	int getAge() const { return age; }
	int getSpeed() const { return speed; }
	int getThirsty() const { return thirsty; }
	int getHungry() const { return hungry; }
	int getCategorie() const { return categorie; }
};

class Capybara : public Animal
{
public:

	// bool sex { }
	// bool sexe, int x, int y, int age : pas besoin dans constructeur

	Capybara() : Animal("Capybara", sexe, 1,age, 1,100,x,y) {}

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
			if (age <= 10 && target.getAge() <= 10)
			{
				new Capybara();

				if (age == 10 && target.getAge() <= 10) 
				{
					animaux.push_back(new Capybara());

					cout << " Un Capybara est né." << endl;
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

	Hippopotamus() : Animal("Hippopotamus", sexe, 1, age, 2, 100, x, y) {}

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


	void reproduction(Animal & target) override
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

class Dragon : public Animal
{
public:

	Dragon() : Animal("Dragon", sexe, 1, age, 3, 100, x, y) {}

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

	void reproduction(Animal & target) override
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


int nbAnimaux; // besoin de ca si qq1 bouge le programme de fichier ca initialise la variables pour la suite du code

void intNbAnimaux()
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

// quand nb animaux sur map < au nombre dans la variable : creer un nouvel animal
class Jeu 
{
public:

	~Jeu() 
	{
		for (auto animal : animaux)
			delete animal;
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
/*void spawn()
{
	 pas besoin vecteur mis a l'exterieur normlement c'est bon
}*/