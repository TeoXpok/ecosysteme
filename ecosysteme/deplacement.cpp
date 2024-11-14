// lier les fichiers cpp
#include <iostream>
#include "ecosysteme.cpp"
#include "class.cpp"

//Catégorie herbi ou carni
//Suite de chaîne alimentaire

// 0 = pas d'animal / 1 = Capybara / 2 = Hippopotame / 3 = Dragon
// ajouter position animal pour suivre déplacement
// animal (int posX, int posY) : x(posX), y(posY){}


int researchx, researchy, nbCase;

int besoin;
int posx,posy;
int nbCasex;
int nbCasey;
int nbCase;
int valeur;


// rajouter une consommation // se déplacer (*2) ou ne rien faire consomme de l'énergie et de la faim
void research(int valeur, const Animal& target) {
    int min = 30 * 90;



    for (int researchy = 0; researchy < 30; researchy++)
    {
        for (int researchx = 0; researchx < 90; researchx++)
        {
            switch (valeur)// bouf = 1 , water = 2 , bouf =3
            {
                case 1:
                    if (board[researchy][researchx].iswater == true)
                    {
                        if (researchx - target.x > 0)
                        {
                            nbCasex = researchx - target.x;
                        }
                        else
                        {
                            nbCasex = target.x - researchx;
                        }

                        if (researchy - target.y>0)
                        {
                            researchx - target.x;
                        }
                        else
                        {
                            researchx - target.x;
                        }
                        nbCase = nbCasex + nbCasey;
                        
                        if (nbCase<min)
                        {
                            min = nbCase;
                            posx = researchx;
                            posy = researchy;
                        }
                    }
                    break;
                case 2:
                    if (board[researchy][researchx].iswater == true)
                    {
                        if (researchx - target.x > 0)
                        {
                            nbCasex = researchx - target.x;
                        }
                        else
                        {
                            nbCasex = target.x - researchx;
                        }

                        if (researchy - target.y > 0)
                        {
                            researchx - target.x;
                        }
                        else
                        {
                            researchx - target.x;
                        }
                        nbCase = nbCasex + nbCasey;

                        if (nbCase < min)
                        {
                            min = nbCase;
                            posx = researchx;
                            posy = researchy;
                        }
                    }
                    break;
                case 3:

                    break;
                default:
                    break;
            }
           
        }  
    }
}








//BOUF < SOIF

//=================BOUF=======================
void hungryanimal(Animal& target) {// rajouter choix de vide en fonction chaine alimentaire
    if (target.getHungry() < 50)
    {
        valeur = 1;
        research(valeur);
    }
    if (target.x < posx)
    {
        target.x++;
        target.getThirsty() - 2;
        target.getHungry() - 4;
    }
    else if (target.x > posx)
    {
        target.x--;
        target.getThirsty() - 2;
        target.getHungry() - 4;
    }

    if (target.y < posy)
    {
        target.y++;
        target.getThirsty() - 2;
        target.getHungry() - 4;
    }
    else if (target.y > posy)
    {
        target.y--;
        target.getThirsty() - 2;
        target.getHungry() - 4;
    }
    
    if ((wx - 1, wy - 1) ||
    hungry(wx - 1, wy) ||
    hungry(wx - 1, wy + 1) ||
    hungry(wx, wy + 1) ||
    hungry(wx, wy - 1) ||
    hungry(wx + 1, wy - 1) ||
    hungry(wx + 1, wy) ||
    hungry(wx + 1, wy + 1) == true)

            wx >= 0 && wx < 30 && wy >= 0 && wy < 90
    {
        target.getHungry() + 50;
        return;
    }
}

//=================SOIF=======================
void thirstyanimal(const Animal& ) {// rajouter choix de vide
    if (animal.thirsty < 50)
    {
        valeur = 2;
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
            return;
        }
    }
}




//void suivreAnimal(const Animal& target, int x, int y) {
//    if (age < 3)
//    {
//        // relier les bébés avec la mère
//        if (x < animal.x)x++;
//        else if (x > animal.x)x--;
//
//        if (y < animal.y) y++;
//        else if (y > animal.y)y--;
//    }
//};



// bébé se déplace en groupe avec mère, si mère chasse alors groupe éloigner
// une fois chasser les bébés doivent se nourrir avec mère

// chasser ou se nourrir augmente
// chasser déplacement plus rapide

// dormir (a voir)

int main()
{


}