#include<vector>
#include<iostream>
using namespace std;

const int Size = 30;
const char tab[Size][Size];

class Animal
{
protected:
	// nom, sexe, age, statut, faim, soif, race : attributs
	string name; // a voir si gard� ou non
	string race;
	bool sexe;
	string pos;
	int age;
	int x, y;
	int speed;
	int thirsty;
	int hungry;

public:

	Animal(string name, string race, string sexe, string pos, int e, int a, int h) : name(name), race(race), sexe(sexe), pos(pos), x(rand() % 20), y(rand() % 20), speed(e), age(a), thirsty(h), hungry(h) {}

	// reproduction, manger, boire, chasser, deplacer : methodes

	virtual void eat() = 0;
	virtual void drink() = 0;
	virtual void reproduction(Animal& target) = 0;
	virtual void hunt(Animal& target) = 0;
	virtual void talk(Animal& other) = 0;
	// virtual void die() = 0;

	// bool alive(){}

	string getName() const { return name; }
	string getRace() const { return race; }
	bool getSexe() const { return sexe; }
	string getPos() const { return pos; }
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
	Capybara(string name) : Animal(name, "capybara", 'f', "bebe", x, y, 1, 0, 100) {}

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
		if (race == target.getRace()) {
			if (age <= 10 &&  target.getAge() <= 10) {
			Capybara: (name, "Capybara", "f", "B�b�", x, y, 1, 0, 100) {}

			}
		}
		
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
		cout << name << " chasse " << target.getName() << " ! " << endl;

		cout << target.getName() << " est mort, mang� par : " << name << " ! " << endl;
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
				if (nx >= 0 && nx < Size && ny >= 0 && ny < Size)
				{
					if (tab[nx][ny] == ...  && other.getRace() == race) // ... = parcours de vecteurs et regarder si position correspond
					{
						cout << " le " << race << " discute avec " << other.getRace() << endl;
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
