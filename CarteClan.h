//
// Created by Utilisateur on 19/04/2023.
//

#ifndef LO21_SCHOTTEN_TOTTEN_CARTECLAN_H
#define LO21_SCHOTTEN_TOTTEN_CARTECLAN_H
#include"Carte.h"





class CarteClan : public Carte {
    Puissance m_puissance;
    Couleur m_couleur;
public:
    CarteClan(Puissance puissance, Couleur couleur): m_puissance(puissance), m_couleur(couleur) {};
    Puissance getPuissance() const { return m_puissance; }
    Couleur getCouleur() const { return m_couleur; }
};

ostream &operator<<(ostream &os, const CarteClan &carteClan);



#endif //LO21_SCHOTTEN_TOTTEN_CARTECLAN_H
