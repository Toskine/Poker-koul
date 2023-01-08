#ifndef UNTITLED4_DEFPOKER_H
#define UNTITLED4_DEFPOKER_H
#endif //UNTITLED4_DEFPOKER_H

#include <random>
#include <iostream>

class Hands {
public:
    //méthodes
    //ctor
    Hands(int val=0, int col=0);  //création d'une main (association couleur/valeur)
    //dtor
    ~Hands();

    //working méthodes
    int tri(int *valeur,int  *couleur);
    int flush(int *valeur);
    int pairs(int *valeur);
    bool quinte(int *valeur);
    int forte(int *valeur);
    bool full(int *valeur);
    int dpairs(int *valeur);

    //attributs
    int valeur;
    int couleur;

};