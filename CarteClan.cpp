//
// Created by Utilisateur on 19/04/2023.
//

#include "CarteClan.h"

ostream& operator<<(ostream& os, const CarteClan& carteClan) {
    os << "CarteClan :\n\tPuissance : " << carteClan.getPuissance() << "\n\tCouleur : " << carteClan.getCouleur();
    return os;
}