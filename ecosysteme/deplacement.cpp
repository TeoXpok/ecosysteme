// lier les fichiers cpp
#include <iostream>
#include "ecosysteme"

//Cat�gorie herbi ou carni
//Suite de cha�ne alimentaire

int x, y,researchx, researchy, nbCase;
// ajouter position animal pour suivre d�placement
// animal (int posX, int posY) : x(posX), y(posY){}
void deplacer(int deltax, int deltay){}
int besoin;
int nbCasex, nbCasey, posx,posy;





// rajouter une consommation // se d�placer (*2) ou ne rien faire consomme de l'�nergie et de la faim
void research() {
    for (int researchy = 0; researchy < 30; researchy++)
    {
        for (int researchx = 0; researchx < 90; researchx++)
        {
            //switch
            if (tab[researchy][researchx].iswater == true)// changer la recherche
            {
                nbCasex = tab[researchx] - x;
                nbCasey = tab[researchy] - y;
                nbCase = nbCasex + nbCasey;
            }
            if ()
            {

            }
        }  
    }
}







void suivreAnimal(int x, int y) {
    if (age < 3)
    {
        // relier les b�b�s avec la m�re
        if (x < animal.x)x++;
        else if (x > animal.x)x--;

        if (y < animal.y) y++;
        else if (y > animal.y)y--;
    }
};
//BOUF < SOIF

//=================BOUF=======================
void hungryanimal(const Animal& ) {// rajouter choix de vide en fonction chaine alimentaire
    if (animal.hungry < 50)
    {
        research();
    }
    if(x < animal.x)
    {
        x++;
        animal.thirsty - 2;
        animal.hungry - 4;
    }
    else if (x > iswater.x)
    {
        x--;
        animal.thirsty - 2;
        animal.hungry - 4;
    }

    if (y < iswater.y)
    {
        y++;
        animal.thirsty - 2;
        animal.hungry - 4;
    }
    else if (y > iswater.y)
    {
        y--;
        animal.thirsty - 2;
        animal.hungry - 4;
    }

    if (hungry(wx - 1, wy - 1) ||
        hungry(wx - 1, wy) ||
        hungry(wx - 1, wy + 1) ||
        hungry(wx, wy + 1) ||
        hungry(wx, wy - 1) ||
        hungry(wx + 1, wy - 1) ||
        hungry(wx + 1, wy) ||
        hungry(wx + 1, wy + 1) == true)
    {
        animal.hungry + 50;
    }
    }
}

//=================SOIF=======================
void thirstyanimal(const Animal& ) {// rajouter choix de vide
    if (animal.thirsty < 50)
    {
        research();
    }
    while (animal.thirsty < 50)
    {   // d�placement
        if (x < iswater.x)
        {
            x++;
            animal.thirsty - 2;
            animal.hungry - 4;
        }
        else if (x > iswater.x)
        {
            x--;
            animal.thirsty - 2;
            animal.hungry - 4;
        }

        if (y < iswater.y) 
        {
            y++;
            animal.thirsty - 2;
            animal.hungry - 4;
        }

        else if (y > iswater.y)
        {
            y--;
            animal.thirsty - 2;
            animal.hungry - 4;
        }
        if (iswater(wx - 1, wy - 1) ||
            iswater(wx - 1, wy) ||
            iswater(wx - 1, wy + 1) ||
            iswater(wx, wy + 1) ||
            iswater(wx, wy - 1) ||
            iswater(wx + 1, wy - 1) ||
            iswater(wx + 1, wy) ||
            iswater(wx + 1, wy + 1) == true)
        {
            animal.thirsty + 50;
        }
    }
}

// b�b� se d�place en groupe avec m�re, si m�re chasse alors groupe �loigner
// une fois chasser les b�b�s doivent se nourrir avec m�re

// chasser ou se nourrir augmente
// chasser d�placement plus rapide

// dormir (a voir)

int main()
{


}