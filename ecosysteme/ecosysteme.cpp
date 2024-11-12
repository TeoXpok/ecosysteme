// Groupe 7
// Projet : Ecosysteme
// AYITE Julia
// ALVES GAMA Miguel
// GRUMIAUX--KAPAHOU KENMOE Janelle
// GONCALVES Teo

#include <iostream>
using namespace std;

//===============================================================================================================//

int main()
{
	printf("\033[3;42;30mTexting\033[0m\b\t");
	printf("\033[3;43;30mTexting\033[0m\t\t");
	printf("\033[3;44;30mTexting\033[0m\t\t");
	printf("\033[3;104;30mTexting\033[0m\t\t");
	printf("\033[3;100;30mTexting\033[0m\n");


	for (size_t i = 0; i < 20; i++)
	{
		for (size_t j = 0; j < 30; j++)
		{
			cout << "\033[1;35;102m[ ]\033[0m";
		}
	}
}