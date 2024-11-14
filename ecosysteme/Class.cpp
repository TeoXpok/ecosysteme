#pragma once
#include<vector>
#include"ecosysteme.cpp"
#include<iostream>
using namespace std;

vector<Animal*> animaux;

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
<<<<<<< Updated upstream
	bool alive;
	bool sexe;// true = homme/false = femme
=======
	bool alive = true;
	int aliment;// 1 = carnivore, 2 = herbivore
>>>>>>> Stashed changes
	

public:

<<<<<<< Updated upstream
	Animal( string race, bool s, int e, int a, int c, int h, int x, int y) : race(race), sexe(s), x(x), y(y), speed(e), age(a), categorie(c), thirsty(h), hungry(h) {}

	// reproduction, manger, boire, chasser, deplacer : methodes
	int x, y;
	
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

=======
	Animal( string Race, bool sexe, int e, int a, int c, int h, int x, int y, int l) : race(Race), sexe(sexe), x(x), y(y), speed(e), age(a), categorie(c), thirsty(h), hungry(h), aliment(l) {}
	
	int x, y;
	
	// reproduction, manger, boire, chasser, deplacer : methodes
	
>>>>>>> Stashed changes
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
	bool getAlive() const { return alive; }
	int getAge() const { return age; }
	int getSpeed() const { return speed; }
	int getThirsty() const { return thirsty; }
	int getHungry() const { return hungry; }
	int getCategorie() const { return categorie; }
<<<<<<< Updated upstream

=======
	int getAliment() const { return aliment; }
>>>>>>> Stashed changes
};

class Capybara : public Animal
{
public:

	bool sex()
	{
		int alea = rand() % 1;
		if ( alea == 0 )
		{
			sexe = true;
		}

		else
		{
			sexe = false;
		}
	}
	// bool sexe, int x, int y, int age : pas besoin dans constructeur

<<<<<<< Updated upstream
	Capybara() : Animal("Capybara", sex(), 1, age, 1, 100, x, y) {}
=======
	Capybara() : Animal("Capybara", sexe, 1,age, 1,100,x,y,1) {}
>>>>>>> Stashed changes

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
			if (sexe == target.getSexe())
			{
				if (age == 10 && target.getAge() <= 10)
				{
					animaux.push_back(new Capybara());

					cout << " Un Capybara est n�." << endl;

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

		cout << target.getRace() << " est mort, mang� par : " << race << " ! " << endl;
	}

	void talk(Animal& other) override
	{
		// V�rification des cases adjacentes
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if (i == 0 && j == 0) continue; // Ne pas compter la case elle-m�me
				int nx = x + i;
				int ny = y + j;

				// V�rification des limites
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

<<<<<<< Updated upstream
	Hippopotamus() : Animal("Hippopotamus", sex(), 1, age, 2, 100, x, y) {}
=======
	Hippopotamus() : Animal("Hippopotamus", sexe, 1, age, 2, 100, x, y,1) {}
>>>>>>> Stashed changes

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

				cout << " Un hippopotame est n�." << endl;
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

		cout << target.getRace() << " est mort, mang� par : " << race << " ! " << endl;
	}

	void talk(Animal& other) override
	{
		// V�rification des cases adjacentes
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if (i == 0 && j == 0) continue; // Ne pas compter la case elle-m�me
				int nx = x + i;
				int ny = y + j;

				// V�rification des limites
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

	Dragon() : Animal("Dragon", sexe, 1, age, 3, 100, x, y,2) {}

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

				cout << " Un dragon est n�." << endl;
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

		cout << target.getRace() << " est mort, mang� par : " << race << " ! " << endl;
	}

	void talk(Animal& other) override
	{
		// V�rification des cases adjacentes
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if (i == 0 && j == 0) continue; // Ne pas compter la case elle-m�me
				int nx = x + i;
				int ny = y + j;

				// V�rification des limites
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