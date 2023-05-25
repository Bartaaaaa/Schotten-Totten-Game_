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
    /* Todo faire ces methodes
    void jouer_Stratege() const;
    void jouer_Banshee() const;
    void jouer_Traitre() const;
     */
};

#endif //LO21_SCHOTTEN_TOTTEN_CARTERUSE_H
