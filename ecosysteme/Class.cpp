#include<vector>
#include"ecosysteme.cpp"
#include<iostream>
using namespace std;

;class Animal
{
protected:
	// nom, sexe, age, statut, faim, soif, race : attributs
	string race;
	bool sexe;
	int age;
	int speed;
	int thirsty;
	int hungry;
	int categorie;
	

public:

	Animal( string race, bool sexe, int e, int a, int c, int h) : race(race), sexe(sexe), x(rand() % 20), y(rand() % 20), speed(e), age(a),categorie(c), thirsty(h), hungry(h) {}

	// reproduction, manger, boire, chasser, deplacer : methodes
	int x, y;
	virtual void eat() = 0;
	virtual void drink() = 0;
	virtual void reproduction(Animal& target) = 0;
	virtual void hunt(Animal& target) = 0;
	virtual void talk(Animal& other) = 0;
	// virtual void die() = 0;

	// bool alive(){}

	string getRace() const { return race; }
	bool getSexe() const { return sexe; }
	int getX() const { return x; }
	int getY() const { return y; }
	int getAge() const { return age; }
	int getSpeed() const { return speed; }
	int getThirsty() const { return thirsty; }
	int getHungry() const { return hungry; }

};

class Capybara : public Animal
{
public:

	// bool sex { }
	Capybara() : Animal("Capybara", 'f', "bebe", x, y, 1, 0,1, 100) {}

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
		// trouver un animal du sexe oppos� et ken
		
		// cr�ation d'un nouveau bebe : avoir avec manager

		cout << " un nouveau " << target.getRace() << " est n� ! " << endl;
	}

	void hunt(Animal& target) override
	{
		// se deplace en fonction de la position de target : appeler deplacement()

		cout << "Position du personnage : (" << x << ", " << y << ")" << std::endl;

		// si sur la meme case mouru
		if (x == target.getX() && y == target.getY())
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

	Hippopotamus(string name) : Animal( "Hippopotame", 'f', "bebe", x, y, 1, 0,2, 100) {}


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
		// trouver un animal du sexe oppos� et ken : avoir si male / femmelle ou juste deux de la memee spece et on s'en fout dans les attributs de leur sexe
		// cr�ation d'un nouveau bebe

		cout << " un nouveau " << target.getRace() << " est n� ! " << endl;
	}

	void hunt(Animal& target) override
	{
		// se deplace en fonction de la position de target
		// si sur la meme case target mouru : a voir si enregistre oou non

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

	Dragon(string name) : Animal( "Dragon", 'f', "bebe", x, y, 1, 0, 3, 100) {}

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
		// trouver un animal du sexe oppos� et ken : avoir si male / femmelle ou juste deux de la memee spece et on s'en fout dans les attributs de leur sexe
		// cr�ation d'un nouveau bebe

		cout << " un nouveau " << target.getRace() << " est n� ! " << endl;
	}

	void hunt(Animal& target) override
	{
		// se deplace en fonction de la position de target
		// si sur la meme case target mouru : a voir si enregistre oou non

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

/* void init(int nombreAniamux)
{
	srand(time(0));
	for (int i = 0; i < nombreAnimaux; ++i)
	{
		int classe = rand() % 3;
		switch (classe)
		{
			case 0: animaux.push_back(new Capybara()); break;
			case 1: animaux.push_back(new Hippopotamus()); break;
			case 2: animaux.push_back(new Dragon()); break;
		}
	}
}*/

// demander au joueur si il veut donner un nb d'animaux precis ou un nb predefinit 

// cout << " voulez choisir un nb d'animaux ? " << endl << " oui : 1, non : 0 " << endl;
// int choix;
// cin >> choix;
// switch (choix)
// case 0 :
// break;
// nbAnimaux = 10;
// case 1 :
// cout << " Choissisez le nb d'animaux : " << endl;
// int nb;
// cin >> nb;
// nbAnimaux = nb;

// quand nb animaux sur map < au nombre dans la variable : creer un nouvel animal
