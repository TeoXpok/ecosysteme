// lier les fichiers cpp
#include <iostream>
#include "ecosysteme"

//Catégorie herbi ou carni
//Suite de chaîne alimentaire

int x, y,researchx, researchy, nbCase;
// ajouter position animal pour suivre déplacement
// animal (int posX, int posY) : x(posX), y(posY){}
void deplacer(int deltax, int deltay){}
int besoin;
int nbCasex, nbCasey, posx,posy;





// rajouter une consommation // se déplacer (*2) ou ne rien faire consomme de l'énergie et de la faim
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
        // relier les bébés avec la mère
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
    {   // déplacement
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

// bébé se déplace en groupe avec mère, si mère chasse alors groupe éloigner
// une fois chasser les bébés doivent se nourrir avec mère

// chasser ou se nourrir augmente
// chasser déplacement plus rapide

// dormir (a voir)

int main()
{


}