#pragma once
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
            switch (valeur)// bouf = 1 , water = 2 , bouf arbre =3
            {
                case 1:
                    if (board[researchy][researchx].animal.species > target.getCategorie())
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
                    if (board[researchy][researchx].istree == true)
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
                default:
                    break;
            }
        }  
    }
}

void suppr(int x, int y) {// supprimer l'élément

    board[10][10].fruits--;
}

bool check(int x, int y, Animal& target) {
    if (x >= 0 || x < 30 || y >= 0 || y < 90) { return false; }
    if (board[y][x].animal.species > target.getCategorie())
    {
        suppr(x, y);
        return true;
    }
}

void choix(Animal& target) {
    if (target.getHungry() < target.getThirsty())
    {
        //======================CARNIVORE=======================
        if (target.getAliment() == 1)
        {
            void hungryanimal(Animal & target); {
                if (target.getHungry() < 50)
                {
                    valeur = 1;
                    research(valeur, target);
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

                if (check(target.x - 1, target.y - 1, target) ||
                    check(target.x - 1, target.y, target) ||
                    check(target.x - 1, target.y + 1, target) ||
                    check(target.x, target.y + 1, target) ||
                    check(target.x, target.y - 1, target) ||
                    check(target.x + 1, target.y - 1, target) ||
                    check(target.x + 1, target.y, target) ||
                    check(target.x + 1, target.y + 1, target))
                {
                    target.getHungry() + 50;
                    return;
                }
            }
            //=======================HERBIVORE=============================
            if (target.getAliment() == 2)
            {
                void hungryanimal(Animal & target); {

                    if (target.getHungry() < 50)
                    {
                        valeur = 2;
                        research(valeur, target);
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

                    if (
                        check(target.x - 1, target.y - 1, target) ||
                        check(target.x - 1, target.y, target) ||
                        check(target.x - 1, target.y + 1, target) ||
                        check(target.x, target.y + 1, target) ||
                        check(target.x, target.y - 1, target) ||
                        check(target.x + 1, target.y - 1, target) ||
                        check(target.x + 1, target.y, target) ||
                        check(target.x + 1, target.y + 1, target))
                    {
                        target.getHungry() + 50;
                        return;
                    }


                }

            }
            else
            {
                void thirstyanimal(Animal & target); {

                    if (target.getThirsty() < 50)
                    {
                        valeur = 2;
                        research(valeur, target);
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

                    if (
                        check(target.x - 1, target.y - 1, target) ||
                        check(target.x - 1, target.y, target) ||
                        check(target.x - 1, target.y + 1, target) ||
                        check(target.x, target.y + 1, target) ||
                        check(target.x, target.y - 1, target) ||
                        check(target.x + 1, target.y - 1, target) ||
                        check(target.x + 1, target.y, target) ||
                        check(target.x + 1, target.y + 1, target))
                    {
                        target.getHungry() + 50;
                        return;
                    }
                }
            }
        }
    }


//=================SOIF=======================
void thirstyanimal(const Animal& target) {// rajouter choix de vide
    if (target.getHungry() < 50)
    {
        valeur = 1;
        research(valeur, target);
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

    if (
        check(target.x - 1, target.y - 1, target) ||
        check(target.x - 1, target.y, target) ||
        check(target.x - 1, target.y + 1, target) ||
        check(target.x, target.y + 1, target) ||
        check(target.x, target.y - 1, target) ||
        check(target.x + 1, target.y - 1, target) ||
        check(target.x + 1, target.y, target) ||
        check(target.x + 1, target.y + 1, target))
    {
        target.getHungry() + 50;
        return;
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