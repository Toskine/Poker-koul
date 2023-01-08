
//////////////////////// Initialisation du code ////////////////////////////////////////////////

#include <string>
#include <iostream>
#include "algorithm"
#include "defpoker.h"
#include <random>
using namespace std;


/// Heritage des fonctions valeur et couleur
Hands::Hands(int val, int col) {
    this->valeur=val;
    this->couleur=col;
}

///initialisation des variables globales
int paire = 0, brelan = 0, carre = 0, royal=0,chaine = 0, suite=0,SIZE=5, cou=0,dpaire=0,ful=0;
int a=0;

/// Changement de mot en valeur pour faciliter la saisie des cartes
enum color { COEUR=1, CARREAU=2, PIQUE=3, TREFLE=4 };
enum values { UN=1, DEUX=2, TROIS=3, QUATRE=4, CINQ=5, SIX=6, SEPT=7, HUIT=8, NEUF=9, DIX=10, VALET=11, DAME=12, ROI=13, AS=14 };

///initialisation des paramètres pour utiliser  notre fonctions random
random_device rd;   // non-deterministic generator
mt19937 gen(rd());  // to seed mersenne twister.
uniform_int_distribution<> dist(2,14); // distribute results between 1 and 6 inclusive.
random_device dy;   // non-deterministic generator
mt19937 ge(dy());  // to seed mersenne twister.
uniform_int_distribution<> dis(1,4); // distribute results between 1 and 6 inclusive.


//////////////////////// Création des couleur et valeur (donc une carte) ////////////////////////////////////////////////


/// Main de poker avec rien de particulier
/*
Hands carte1 = Hands (COEUR, DEUX);
Hands carte2 = Hands (PIQUE , QUATRE);
Hands carte3 = Hands (CARREAU, ROI);
Hands carte4 = Hands (COEUR, AS);
Hands carte5 = Hands (TREFLE, DAME);
*/

/// Main de poker triche
/*
Hands carte1 = Hands (COEUR, DEUX);
Hands carte2 = Hands (PIQUE , QUATRE);
Hands carte3 = Hands (CARREAU, ROI);
Hands carte4 = Hands (COEUR, DEUX);
Hands carte5 = Hands (TREFLE, DAME);
*/

/// Main de poker avec Quinte flush royal
/*
Hands carte1 = Hands (COEUR, AS);
Hands carte2 = Hands (COEUR , ROI);
Hands carte3 = Hands (COEUR , DAME);
Hands carte4 = Hands (COEUR ,VALET);
Hands carte5 = Hands (COEUR, DIX);
 */

///Main de poker avec flush
/*
Hands carte1 = Hands (COEUR, DIX);
Hands carte2 = Hands (COEUR , DEUX);
Hands carte3 = Hands (COEUR , SEPT);
Hands carte4 = Hands (COEUR ,VALET);
Hands carte5 = Hands (COEUR, ROI);
*/

/// Main de poker avec Carré
/*
Hands carte1 = Hands (COEUR, DAME);
Hands carte2 = Hands (PIQUE , DAME);
Hands carte3 = Hands (CARREAU, DAME);
Hands carte4 = Hands (COEUR, AS);
Hands carte5 = Hands (TREFLE, DAME);
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
std::pair <char, int> carte1 {COEUR,DEUX};
std::pair <char, int> carte2 {CARREAU,DEUX};
std::pair <char, int> carte3 {PIQUE,DEUX};
std::pair <char, int> carte4 {COEUR,TROIS};
std::pair <char, int> carte5 {TREFLE,TROIS};
*/


///Main de poker aléatoire

Hands carte1 = Hands (dis(ge), dist(gen));
Hands carte2 = Hands (dis(ge), dist(gen));
Hands carte3 = Hands (dis(ge), dist(gen));
Hands carte4 = Hands (dis(ge), dist(gen));
Hands carte5 = Hands (dis(ge), dist(gen));


///Remplissage des tableaux avec les valeurs et couleurs des cartes
Hands hand[5] = {carte1, carte2, carte3, carte4, carte5}; //tableau de cartes (main)
Hands couleur[5] = {carte1.couleur, carte2.couleur, carte3.couleur, carte4.couleur, carte5.couleur}; //tableau de couleur
Hands valeur[5] = {carte1.valeur, carte2.valeur, carte3.valeur, carte4.valeur, carte5.valeur};//tableau de valeur


//////////////////////// Creation de nos fonctions  ////////////////////////////////////////////////

/// Fonction qui verifie le Full dans notre main
bool Hands::full(int *valeur){
    if(valeur[0] == valeur[1] && valeur[2] == valeur[3] && valeur[3] == valeur[4]){
        printf("Full \n" );
        brelan = 0;
        carre = 0;
        dpaire=0;
        ful=1;
    }
    else{
        if (valeur[3] == valeur[4] && valeur[0] == valeur[1] && valeur[1] == valeur[2]){
            printf("Full 2 \n" );
            brelan = 0;
            carre = 0;
            dpaire=0;
            ful=1;
        }
        else {
        }
    }
}

/// Fonction qui tri notre tableau de valeur (et de couleur)
int Hands::tri(int *valeur,int *couleur){
    int j;
    int g;
    int i, tmp, tmpc;
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

/// Fonction qui verifie la double pair dans notre main
int Hands::dpairs(int *valeur){
    if (ful==0){
        if(valeur[0] == valeur[1] && valeur[2] == valeur[3] && valeur[0] != valeur[2] != valeur[4]){
            printf("dpaire1 \n" );
            brelan = 0;
            dpaire=1;
        }
        else{
            if (valeur[1] == valeur[2] && valeur[3] == valeur[4] && valeur[1] != valeur[3] != valeur[0]){
                brelan = 0;
                dpaire=1;
            }
            else {
                if (valeur[0] == valeur[1] && valeur[3] == valeur[4] && valeur[0] != valeur[3] != valeur[2]){
                    brelan = 0;
                    dpaire=1;
                }
            }
        }
    }
    return 0;
}


/// Fonction qui verifie la couleur dans notre main
int Hands::flush(int *couleur){
    if (couleur[0] == couleur[1] == couleur[3] == couleur[4] == couleur[5]) {
        printf("pas couleur \n" );
        cou = 0;
        return cou;
    }
    else{
        printf("couleur \n" );
        cou= 1;
        return cou;
    }

}

/// Fonction qui verifie la suite dans notre main
bool Hands::quinte(int *valeur){
    for (int k = 0; k < 5; k++) {
        if (valeur[k]== valeur[k+1]+1){
            suite++;
        }
    }
    if (suite==4){
        printf("suite \n" );

        /// Nous verifions si la suite est royal ou non
        if (valeur[0]== 14){
            royal = royal + 1;
            printf("royal \n" );
            return royal,suite;
        } else{
            printf("pas de royale \n");
            return royal,suite;
        }
    }
    else{
        printf("pas de suite \n" );
        return suite;
    }
}

/// Fonction qui verifie la paire, le brelan ou le carré dans notre main
int Hands::pairs(int *valeur){
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
                printf("chelou ce tricheur \n" );
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
int Hands::forte(int *valeur) {
    int fort = valeur[0];
    printf("valeur la plus forte:  " );
    std::cout<<valeur[0]<<std::endl;
    printf("\n" );
}

//////////////////////// Appel des fonctions et return du resultat  ////////////////////////////////////////////////

/// Fonction qui va appeler toutes nos fonctions et renvoyer la meilleur combinaison
int main(){
    Hands h;
    h.tri(valeur[5], couleur[5]);
    h.full();
    Hands::dpairs();
    Hands::flush();
    Hands::quinte();
    Hands::pairs();
    Hands::forte();

    /// Verification des cartes et renvoie la combinaison la plus forte si toutes les cartes sont différentes
    if (carte1 != carte2 && carte1 != carte3 && carte1 != carte4 && carte1 != carte5 && carte2 != carte3 && carte2 != carte4 && carte2 != carte5 && carte3 != carte4 && carte3 != carte5 && carte4 != carte5){ //vérification qu'il n'y a pas 2 cartes identiques
        //std::cout << "go jouer" <<std::endl;
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
        std::cout << "tricheur, redonne des cartes differentes stp !" <<std::endl; //si 2 cartes identiques insulter le joueur
        return 0;
    }


}


