#include <iostream>
#include<vector>
#include <ecosysteme.cpp>
#include <capybara.cpp>
using namespace std;


/*
�ge :
    naissance (cr�ation)
    b�b�
    adulte
    vieux
    mort (destruction) : vieillesse ou tu�
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