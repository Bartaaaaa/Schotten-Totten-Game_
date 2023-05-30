//
// Created by Utilisateur on 19/04/2023.
//

#ifndef LO21_SCHOTTEN_TOTTEN_CARTERUSE_H
#define LO21_SCHOTTEN_TOTTEN_CARTERUSE_H
#include"CarteTactique.h"

class CarteRuse : public CarteTactique {
public:
    CarteRuse(const string& nom) : CarteTactique(nom)  {};

    static void Jouer_ChasseurdeTete() ;

    static void Jouer_Stratege() ;
    static void Jouer_Banshee() ;
    static void Jouer_Traitre() ;

};

#endif //LO21_SCHOTTEN_TOTTEN_CARTERUSE_H
