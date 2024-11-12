```cpp

#include<vector>
#include<iostream>
using namespace std;

// const int Size = 30;
// const char tab[Size][Size];

class Animal
{
protected:
	// nom, sexe, age, statut, faim, soif, race : attributs
	string name;
	string race;
	string sexe;
	string pos;
	int age;
	// int x, y;
	int speed;
	int thirsty;
	int hungry;

public:

	Animal(string name, string race, string sexe, string pos, int e, int a, int h) : name(name), race(race), sexe(sexe), pos(pos), /* x(rand() % 20), y(rand() % 20) */ speed(e), age(a), thirsty(h), hungry(h) {}

	// reproduction, manger, boire, chasser, deplacer : methodes

	virtual void eat() = 0;
	virtual void drink() = 0;
	virtual void reproduction(Animal& target) = 0;
	virtual void hunt(Animal& target) = 0;
	virtual void talk() = 0;
	// virtual void die() = 0;

	// bool alive(){}

	string getName() const { return name; }
	string getRace() const { return race; }
	string getSexe() const { return sexe; }
	string getPos() const { return pos; }
	int getAge() const { return age; }
	int getSpeed() const { return speed; }
	int getThirsty() const { return thirsty; }
	int getHungry() const { return hungry; }

};
```
