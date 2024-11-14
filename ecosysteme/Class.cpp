#include<vector>
#include"ecosysteme.cpp"
#include<iostream>
using namespace std;

<<<<<<< HEAD
const int Size = 30;
// const char tab[Size][Size];

=======
>>>>>>> fadf2623e52c9aff066417887817bb5395783be3
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

<<<<<<< HEAD
	Animal( string race, string sexe, string pos, int e, int a, int h) : race(race), sexe(sexe), pos(pos), x(rand() % 20), y(rand() % 20), speed(e), age(a), thirsty(h), hungry(h) {}
=======
	Animal( string Race, bool sexe, int e, int a, int c, int h, int x, int y) : race(Race), sexe(sexe), x(x), y(y), speed(e), age(a), categorie(c), thirsty(h), hungry(h) {}
>>>>>>> fadf2623e52c9aff066417887817bb5395783be3

	// reproduction, manger, boire, chasser, deplacer : methodes
	int x, y;
	

	virtual void eat() = 0;
	virtual void drink() = 0;
	virtual void reproduction(Animal& target) = 0;
	virtual void hunt(Animal& target) = 0;
	virtual void talk(Animal& other) = 0;
	// virtual void die() = 0;

	

	string getRace() const { return race; }
	bool getSexe() const { return sexe; }
	string getPos() const { return statut; }
	int getX() const { return x; }
	int getY() const { return y; }
	int getAge() const { return age; }
	int getSpeed() const { return speed; }
	int getThirsty() const { return thirsty; }
	int getHungry() const { return hungry; }
	int getCategorie() const { return categorie; }
};

class Capybara : public Animal
{
public:
<<<<<<< HEAD
	Capybara() : Animal("capybara", 'f', "bebe", x, y, 1, 0, 100) {} // a voir male femelle
=======

	// bool sex { }
	Capybara(bool sexe, int x, int y, int age) : Animal("Capybara", sexe, 1,age, 1,100,x,y) {}

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

	
	void reproduction(Animal & target) override {
		if (race == target.getRace()) {
			if (age <= 10 && target.getAge() <= 10) {
			Capybara: ("Capybara", "f", "Bebe", x, y, 1, 0, 100); {}
				if (age == 10 && target.getAge() <= 10) {
				Capybara: ("Capybara", "f", "Bebe", x, y, 1, 0, 100); {}
					cout << " Un Capybara est né." << endl;
				}
			}
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

	Hippopotamus(bool sexe, int x, int y, int age) : Animal("Hippopotamus", sexe, 1, age, 2, 100, x, y) {}

>>>>>>> fadf2623e52c9aff066417887817bb5395783be3

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
<<<<<<< HEAD
		// trouver un animal du sexe opposé et ken
		


=======
		// trouver un animal du sexe opposé et ken : avoir si male / femmelle ou juste deux de la memee spece et on s'en fout dans les attributs de leur sexe
>>>>>>> fadf2623e52c9aff066417887817bb5395783be3
		// création d'un nouveau bebe
		


		// race de l'animal en question() : Animal(target.getRace(), 'f', "bebe", x(rand() % 20), y(rand() % 20), 1, 0, 100) {}

		cout << " un nouveau " << target.getRace() << " est né ! " << endl;
	}

	void hunt(Animal& target) override
	{
<<<<<<< HEAD
		// se deplace en fonction de la position de target : deplacer()
		// si sur la meme case target mouru
		if (x == target.getX() && target.getY())
		{
			// detruire dans le vecteur
		}
=======
		// se deplace en fonction de la position de target
		// si sur la meme case target mouru : a voir si enregistre oou non
>>>>>>> fadf2623e52c9aff066417887817bb5395783be3

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
<<<<<<< HEAD
					if ( ...  && other.getRace() == race) // ... = parcours de vecteur  et regarder si position correspond
=======
					if (board[nx][ny].animal.species == 1)
>>>>>>> fadf2623e52c9aff066417887817bb5395783be3
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

	Dragon(bool sexe, int x, int y, int age) : Animal("Dragon", sexe, 1, age, 3, 100, x, y) {}

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
		// trouver un animal du sexe opposé et ken : avoir si male / femmelle ou juste deux de la memee spece et on s'en fout dans les attributs de leur sexe
		// création d'un nouveau bebe

		cout << " un nouveau " << target.getRace() << " est né ! " << endl;
	}

	void hunt(Animal& target) override
	{
		// se deplace en fonction de la position de target
		// si sur la meme case target mouru : a voir si enregistre oou non

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
