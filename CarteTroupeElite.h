//
// Created by Utilisateur on 19/04/2023.
//

#ifndef LO21_SCHOTTEN_TOTTEN_CARTETROUPEELITE_H
#define LO21_SCHOTTEN_TOTTEN_CARTETROUPEELITE_H
#include "CarteTactique.h"
#include "CarteClan.h"

class CarteTroupeElite : public CarteTactique, public CarteClan {
public:
    CarteTroupeElite(const string& nom, Puissance puissance, Couleur couleur) : CarteTactique(nom), CarteClan( puissance, couleur)  {};
    void jouer_Joker() const;
    void jouer_PorteBouclier() const;
    void jouer_Espion() const;
};

#endif //LO21_SCHOTTEN_TOTTEN_CARTETROUPEELITE_H
