``` cpp

class Capybara : public Animal
{
public:
	Capybara(string name) : Animal(name, "capybara", 'f', "bebe", /* x(rand() % 20), y(rand() % 20) */ 1, 0, 30) {}

	void eat() override
	{
		hungry += 10;
	}

	void drink() override
	{
		thirsty += 10;
	}

	void reproduction(Animal& target) override
	{
		// trouver un animal du sexe opposé et ken
		// création d'un nouveau bebe

		cout << " un nouveau " << target.getRace() << " est né ! " << endl;
	}

	void hunt(Animal& target) override
	{
		// se deplace en fonction de la position de target
		// si sur la meme case ou case adjacente target mouru

		cout << name << " chasse " << target.getName() << " ! " << endl;

		cout << target.getName() << " est mort, mangé par : " << name << " ! " << endl;
	}

	void talk() override
	{
		// regarder si qq1 autour
		// si oui

		cout << " wii wii" << endl;
	}

};
```
