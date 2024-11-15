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
            switch (valeur)// recherche proie = 1 , recherche arbre = 2 , recherche eau =3
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

void suppr(int x, int y, Animal& target) {// supprimer l'élément
    if (target.getHungry() < target.getThirsty())
    {
        if (target.getAliment() == 1)
        {
            target.getAlive = false;//atomisation de la cible
        }
        else
        {
            board[10][10].fruits--;
        }
    }
    else
    {
        //boire mais ne se passera rien
    }
    
}

bool check(int x, int y, Animal& target) {
    if (x >= 0 || x < 30 || y >= 0 || y < 90) { return false; }
    if (board[y][x].animal.species > target.getCategorie())// voir pour categorie 3 pour arbre
    {
        suppr(x, y, target);
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
<<<<<<< HEAD
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
        }
        //========================SOIF=============================
        else
        {
            void thirstyanimal(Animal & target);
            {
                if (target.getThirsty() < 50)
                {
                    valeur = 3;
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
=======
>>>>>>> df7655e0e5bb6e6a35b9b9505ab14b7267786474
                    check(target.x - 1, target.y, target) ||
                    check(target.x - 1, target.y + 1, target) ||
                    check(target.x, target.y + 1, target) ||
                    check(target.x, target.y - 1, target) ||
                    check(target.x + 1, target.y - 1, target) ||
                    check(target.x + 1, target.y, target) ||
                    check(target.x + 1, target.y + 1, target))
                {
                    target.getThirsty() + 50;
                    return;
                }
<<<<<<< HEAD
            }
        }
    }
}

=======
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
>>>>>>> df7655e0e5bb6e6a35b9b9505ab14b7267786474

// déplacement aléatoire
// vérifier s'il peut se reproduire
// chasser déplacement plus rapide
// ne rien faire fait consommer faim et soif