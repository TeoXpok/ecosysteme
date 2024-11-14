#include <iostream>
#include<vector>
#include "ecosysteme.cpp"
#include "class.cpp"
using namespace std;


/*
�ge :
    naissance (cr�ation)
    b�b�
    adulte
    vieux
    mort (destruction) : vieillesse ou tu�
*/


/*class Age {
private:
    int age;

public:
    Age(int a) : age(a) {
        if (age == 0) {
        cout << " Naissance de " << Animal.race << "." << endl;
        }
    }

};*/

/**/

/*public:
    Age(int a) : age(a) {
        // Print the current life stage based on the initial age
        if (age == 0) {
            cout << "Naissance de "<< Animal.race << endl;
        }
        else if (age > 0 && age <= 2) {
            cout << "B�b�" << endl;
        }
        else if (age > 2 && age < 65) {
            cout << "Adulte" << endl;
        }
        else if (age >= 65) {
            cout << "Vieux" << endl;
        }
    }

    
    // Method to simulate death
    void mourir() {
        cout << "Mort (Destruction) : ";
        if (age >= 65) {
            cout << "Mort de vieillesse." << endl;
        }
        else {
            cout << "Mort pr�matur�e." << endl;
        }
    }

    ~Age() {
        mourir();
    }
};
It looks like you�re starting to set up an Age class and trying to print something in the constructor. Here's a basic outline that can help illustrate the different stages of life and handle the various cases you mentioned. I'll fill in the constructor and add an example of how the class might handle stages based on age.

Here's an expanded version of the code:

#include <iostream>
#include <memory>
using namespace std;

class Age {
private:
    int age;

public:
    Age(int a) : age(a) {
        // Print the current life stage based on the initial age
        if (age == 0) {
            cout << "Naissance (Cr�ation) - Nouveau-n�" << endl;
        } else if (age > 0 && age <= 2) {
            cout << "B�b�" << endl;
        } else if (age > 2 && age < 65) {
            cout << "Adulte" << endl;
        } else if (age >= 65) {
            cout << "Vieux" << endl;
        }
    }

    // Method to increment age each year
    void vieillir() {
        age++;
        if (age < 65) {
            cout << "Nouvelle ann�e : �ge " << age << " - Toujours adulte." << endl;
        } else if (age == 65) {
            cout << "Vous �tes maintenant vieux." << endl;
        } else {
            cout << "Nouvelle ann�e : �ge " << age << " - Vieux." << endl;
        }
    }

    // Method to simulate death
    void mourir() {
        cout << "Mort (Destruction) : ";
        if (age >= 65) {
            cout << "Mort de vieillesse." << endl;
        } else {
            cout << "Mort pr�matur�e." << endl;
        }
    }

    ~Age() {
        mourir();
    }
};

int main() {
    // Example: create an instance and simulate aging
    unique_ptr<Age> person = make_unique<Age>(0);  // naissance (age 0)
    person->vieillir();  // increment age to simulate aging
    person->vieillir();  // increment again

    return 0;
}
int main() {
    // Example: create an instance and simulate aging
    unique_ptr<Age> person = make_unique<Age>(0);  // naissance (age 0)
    person->vieillir();  // increment age to simulate aging
    person->vieillir();  // increment again

    return 0;
}*/