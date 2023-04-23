//
// Created by Utilisateur on 19/04/2023.
//

#ifndef LO21_SCHOTTEN_TOTTEN_CARTECLAN_H
#define LO21_SCHOTTEN_TOTTEN_CARTECLAN_H
#include"Carte.h"





class CarteClan : public Carte {
    Puissance puissance;
    Couleur couleur;
public:
    CarteClan(Puissance puissance, Couleur couleur): puissance(puissance), couleur(couleur) {};
    Puissance getPuissance() const { return puissance; }
    Couleur getCouleur() const { return couleur; }
};



#endif //LO21_SCHOTTEN_TOTTEN_CARTECLAN_H
