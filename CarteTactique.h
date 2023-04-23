//
// Created by Utilisateur on 19/04/2023.
//

#ifndef LO21_SCHOTTEN_TOTTEN_CARTETACTIQUE_H
#define LO21_SCHOTTEN_TOTTEN_CARTETACTIQUE_H
#include"Carte.h"


class CarteTactique : public Carte {
    const string nom;
public:
    CarteTactique(const string& nom): nom(nom) {};
    const string &getNom() const { return nom; }
};

#endif //LO21_SCHOTTEN_TOTTEN_CARTETACTIQUE_H
