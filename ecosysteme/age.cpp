#include <iostream>
#include<vector>
#include <ecosysteme.cpp>
#include <capybara.cpp>
using namespace std;


/*
âge :
    naissance (création)
    bébé
    adulte
    vieux
    mort (destruction) : vieillesse ou tué
*/


class Age {
private:
    int age;

public:
    Age(int a) : age(a) {
        if (age == 0) {
        cout << " Naissance de " << Animal.race << "." << endl;
        }
    }

};