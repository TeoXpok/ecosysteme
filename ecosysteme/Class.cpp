#include<vector>
#include<iostream>
using namespace std;

const int Size = 30;
const char tab[Size][Size];

class Animal
{
protected:
	// nom, sexe, age, statut, faim, soif, race : attributs
	string name; // a voir si gardé ou non
	string race;
	string sexe;
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
	string getSexe() const { return sexe; }
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
		// trouver un animal du sexe opposé et ken
		
		// création d'un nouveau bebe : avoir avec manager

		cout << " un nouveau " << target.getRace() << " est né ! " << endl;
	}

	void hunt(Animal& target) override
	{
		// se deplace en fonction de la position de target : appeler deplacement()
		
		// si sur la meme case mouru
		if (x == target.getX() && y == target.getY())
		{
			// appel du destructeur a voir avec le manager
		}
		cout << name << " chasse " << target.getName() << " ! " << endl;

		cout << target.getName() << " est mort, mangé par : " << name << " ! " << endl;
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

/*class managerAnimal
{
private:
	vector<Animal*> animaux;

public:

	~managerAnimal()
	{
		for (auto animal : animaux)
		{
			delete animal;
		}
		animaux.clear();
	}

	Animal* creerAnimal(string name, string race, string sexe, string pos, int e, int a, int h)
	{
		Animal* a = new Animal( name, race, sexe, pos, e, a, h)
	}
};*/