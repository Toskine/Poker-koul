
//////////////////////// Initialisation du code ////////////////////////////////////////////////

#include <string>
#include <iostream>
#include "algorithm"
#include <random>
using namespace std;

///initialisation des variables globales
int paire = 0, brelan = 0, carre = 0, royal=0,chaine = 0, suite=0,SIZE=5, cou=0,dpaire=0,ful=0;
int a=0;

/// Changement de mot en valeur pour faciliter la saisie des cartes
enum color { COEUR=1, CARREAU=2, PIQUE=3, TREFLE=4 } ;
enum values { UN=1, DEUX=2, TROIS=3, QUATRE=4, CINQ=5, SIX=6, SEPT=7, HUIT=8, NEUF=9, DIX=10, VALET=11, DAME=12, ROI=13, AS=14 } ;

///initialisation des paramètres pour utiliser  notre fonctions random
random_device rd;   // non-deterministic generator
mt19937 gen(rd());  // to seed mersenne twister.
uniform_int_distribution<> dist(2,14); // distribute results between 1 and 6 inclusive.
random_device dy;   // non-deterministic generator
mt19937 ge(dy());  // to seed mersenne twister.
uniform_int_distribution<> dis(1,4); // distribute results between 1 and 6 inclusive.

//////////////////////// Création des couleur et valeur (donc une carte) ////////////////////////////////////////////////

/// Main de poker avec une paire
/*
std::pair <char, int> carte1 {COEUR,DEUX};
std::pair <char, int> carte2 {CARREAU,ROI};
std::pair <char, int> carte3 {PIQUE,SEPT};
std::pair <char, int> carte4 {COEUR,TROIS};
std::pair <char, int> carte5 {TREFLE,AS};
*/

/// Main de poker triche
/*
std::pair <char, int> carte1 {1,11}; //création des paires valeur, couleur (donc une carte)
std::pair <char, int> carte2 {1,11};
std::pair <char, int> carte3 {1,13};
std::pair <char, int> carte4 {1,12};
std::pair <char, int> carte5 {1,14};
*/

/// Main de poker avec Quinte flush royal
/*
std::pair <char, int> carte1 {1,10}; //création des paires valeur, couleur (donc une carte)
std::pair <char, int> carte2 {1,11};
std::pair <char, int> carte3 {1,13};
std::pair <char, int> carte4 {1,12};
std::pair <char, int> carte5 {1,14};
 */

/// Main de poker avec Carré

/*
std::pair <char, int> carte1 {2,11};
std::pair <char, int> carte2 {1,11};
std::pair <char, int> carte3 {3,11};
std::pair <char, int> carte4 {1,12};
std::pair <char, int> carte5 {4,11};
*/

/// Main de poker avec flush
/*
std::pair <char, int> carte1 {1,14}; //création des paires valeur, couleur (donc une carte)
std::pair <char, int> carte2 {1,1};
std::pair <char, int> carte3 {1,5};
std::pair <char, int> carte4 {1,7};
std::pair <char, int> carte5 {1,2};
 */

///Main de poker avec quinte flush
/*
std::pair <char, int> carte1 {1,6}; //création des paires valeur, couleur (donc une carte)
std::pair <char, int> carte2 {1,8};
std::pair <char, int> carte3 {1,5};
std::pair <char, int> carte4 {1,7};
std::pair <char, int> carte5 {1,4};
*/

///Main de poker avec quinte
/*
std::pair <char, int> carte1 {1,6}; //création des paires valeur, couleur (donc une carte)
std::pair <char, int> carte2 {2,8};
std::pair <char, int> carte3 {3,5};
std::pair <char, int> carte4 {3,7};
std::pair <char, int> carte5 {1,4};
*/


/// Main de poker avec Brelan
/*
std::pair <char, int> carte1 {COEUR,DEUX};
std::pair <char, int> carte2 {CARREAU,DEUX};
std::pair <char, int> carte3 {PIQUE,DEUX};
std::pair <char, int> carte4 {COEUR,TROIS};
std::pair <char, int> carte5 {TREFLE,AS};
*/


/// Main de poker avec Full
/*
std::pair <char, int> carte1 {COEUR,DEUX}; //création des paires couleur et valeur (donc une carte)
std::pair <char, int> carte2 {CARREAU,DEUX};
std::pair <char, int> carte3 {PIQUE,DEUX};
std::pair <char, int> carte4 {COEUR, AS};
std::pair <char, int> carte5 {TREFLE,AS};
*/

///Main de poker aléatoire

std::pair <char, int> carte1 {dis(ge),dist(gen)};
std::pair <char, int> carte2 {dis(ge),dist(gen)};
std::pair <char, int> carte3 {dis(ge),dist(gen)};
std::pair <char, int> carte4 {dis(ge),dist(gen)};
std::pair <char, int> carte5 {dis(ge),dist(gen)};


/// Main de poker avec double paire
/*
std::pair <char, int> carte1 {COEUR,DEUX};
std::pair <char, int> carte2 {CARREAU, AS};
std::pair <char, int> carte3 {PIQUE,DEUX};
std::pair <char, int> carte4 {COEUR,TROIS};
std::pair <char, int> carte5 {TREFLE,AS};
*/

/// Main de poker avec une paire
/*
std::pair <char, int> carte1 {COEUR,DEUX};
std::pair <char, int> carte2 {CARREAU,ROI};
std::pair <char, int> carte3 {PIQUE,DEUX};
std::pair <char, int> carte4 {COEUR,TROIS};
std::pair <char, int> carte5 {TREFLE,AS};
*/

///Remplissage des tableaux avec les valeurs et couleurs des cartes
std::pair <char, int> hand[5]={carte1, carte2, carte3, carte4, carte5}; //tableau de cartes (main)
int couleur[5] = {carte1.first, carte2.first, carte3.first, carte4.first, carte5.first}; //tableau de couleur
int valeur[5] = {carte1.second, carte2.second, carte3.second, carte4.second, carte5.second};//tableau de valeur


//////////////////////// Creation de nos fonctions  ////////////////////////////////////////////////


/// Fonction qui tri notre tableau de valeur
int tri() {
    int i, tmp, tmpc;
    int j;
    int g;
    for (i=0 ; i < SIZE-1; i++){
        for (j=0 ; j < SIZE-i-1; j++){
            if (valeur[j] < valeur[j+1]){
                tmp = valeur[j];
                valeur[j] = valeur[j+1];
                valeur[j+1] = tmp;

                tmpc = couleur[j];
                couleur[j] = couleur[j+1];
                couleur[j+1] = tmpc;
            }
        }
    }
    for (g= 0; g < 5; ++g){
        printf("valeur : %4d ", valeur[g]);
        printf("couleur : %4d \n", couleur[g]);
    }
}

/// Fonction qui verifie le Full dans notre main
bool Full(int valeur[]){
    if(valeur[0] == valeur[1] && valeur[2] == valeur[3] && valeur[3] == valeur[4]){
        //printf("Full \n" );
        brelan = 0;
        carre = 0;
        dpaire=0;
        ful=1;
    }
    else{
        if (valeur[3] == valeur[4] && valeur[0] == valeur[1] && valeur[1] == valeur[2]){
           // printf("Full 2 \n" );
            brelan = 0;
            carre = 0;
            dpaire=0;
            ful=1;
        }
        else {
        }
    }
}

/// Fonction qui verifie la double pair dans notre main
bool Dpaire(int valeur[]){
    if (ful==0){
        if(valeur[0] == valeur[1] && valeur[2] == valeur[3] && valeur[0] != valeur[2] && valeur[2] != valeur[4]){
            //printf("dpaire1 \n" );
            brelan = 0;
            dpaire=1;
        }
        else{
            if (valeur[1] == valeur[2] && valeur[3] == valeur[4] && valeur[1] != valeur[3] && valeur [3] != valeur[0]){
              //  printf("dpaire2 \n" );
                brelan = 0;
                dpaire=1;
            }
            else {
                if (valeur[0] == valeur[1] && valeur[3] == valeur[4] && valeur[0] != valeur[3] && valeur[3] != valeur[2]){
                  //  printf("dpaire3 \n" );
                    brelan = 0;
                    dpaire=1;
                }
            }
        }
    }
    return 0;
}


/// Fonction qui verifie la couleur dans notre main
bool flush(int couleur[]){
    if (couleur[0] == couleur[1] == couleur[3] == couleur[4] == couleur[5]) {
        //printf("pas couleur \n" );
        cou = 0;
        return cou;
    }
    else{
        //printf("couleur \n" );
        cou= 1;
        return cou;
    }

}

/// Fonction qui verifie la suite dans notre main
bool quinte(int valeur[]){
    for (int k = 0; k < 5; k++) {
        if (valeur[k]== valeur[k+1]+1){
            suite++;
        }
    }
    if (suite==4){
        //printf("suite \n" );

        /// Nous verifions si la suite est royal ou non
        if (valeur[0]== 14){
            royal = royal + 1;
           // printf("royal \n" );
            return royal,suite;
        } else{
          //  printf("pas de royale \n");
            return royal,suite;
        }
    }
    else{
      //  printf("pas de suite \n" );
        return suite;
    }
};

/// Fonction qui verifie la pair, le brelan ou le carré dans notre main
int pairs(int valeur[]){
    if (ful==0){
        if(dpaire==0){
            for (int i = 0; i < 5; ++i) {
                if (valeur[i] == valeur[i+1]){
                    chaine++;
                }
            }
            if (chaine== 1){
                paire++;
            }
            if (chaine== 2){
                brelan++;
            }
            if (chaine== 3){
                carre++;
            }
            if (chaine== 4){
                printf("impossible \n" );
                return 0;
            }
            if (chaine == 0){
            }
            //printf("carre = " ), std::cout<<carre<<std::endl, printf("brelan = " ),std::cout<<brelan<<std::endl,printf("pair = " ),std::cout<<paire<<std::endl;
            return paire, brelan, carre;
        }
        else{
            return 0;
        }
    }
    return 0;
}

/// Fonction qui verifie la carte la plus forte dans notre main
int forte(int valeur[]) {
    int fort = valeur[0];
    //printf("valeur la plus forte:  " ), std::cout<<valeur[0]<<std::endl, printf("\n" );
}


//////////////////////// Appel des fonctions et return du resultat  ////////////////////////////////////////////////
/// Fonction qui va appeler toutes nos fonctions et renvoyer la meilleur combinaison
int main(){
    /// Appel des fonctions
    tri();
    Full(valeur);
    Dpaire(valeur);
    flush(couleur);
    quinte(valeur);
    pairs(valeur);
    forte(valeur);

    /// Verification des cartes et renvoie la combinaison la plus forte si toutes les cartes sont différentes
    if (carte1 != carte2 && carte1 != carte3 && carte1 != carte4 && carte1 != carte5 && carte2 != carte3
    && carte2 != carte4 && carte2 != carte5 && carte3 != carte4 && carte3 != carte5 && carte4 != carte5){ //vérification qu'il n'y a pas 2 cartes identiques
        //std::cout << "go jouer" <<std::endl;
        printf("\n" );
        printf("Meilleur combinaison : \n" );
        if (royal == 1 && suite == 4 && cou == 1){
            printf("Quinte flush royal" );
        }
        else{
            if (suite==4 && cou==1){
                printf("Quinte flush" );
            }
            else{
                if (carre==1){
                    printf("Carre" );
                }
                else {
                    if (ful==1){
                        printf("Full" );
                    }
                    else{
                        if (cou==1){
                            printf("Flush" );
                        }
                        else {
                            if (suite==4){
                                printf("Quinte" );
                            }
                            else {
                                if (brelan==1){
                                    printf("Brelan" );
                                }
                                else {
                                    if (dpaire==1){
                                        printf("Double pair" );
                                    }
                                    else {
                                        if (paire==1){
                                            printf("Paire" );
                                        }
                                        else {
                                            printf("Carte haute  " );
                                            std::cout<<valeur[0]<<std::endl;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
        /// Si deux cartes sont identiques alors ce n'est pas possible
    else{
        std::cout << "tricheur, donne moi des cartes differentes stp !" <<std::endl; //si 2 cartes identiques insulter le joueur
        return 0;
    }
    printf("\n" );
}



