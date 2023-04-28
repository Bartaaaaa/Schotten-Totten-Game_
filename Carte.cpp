//
// Created by Utilisateur on 19/04/2023.
//

#include "Carte.h"
#include "CarteClan.h"
#include "CarteTactique.h"
#include "vector"

void affichage_vecteur_carte(vector<Carte*> v) {
    for (auto carte: v) {
        if (CarteClan * carte_clan = dynamic_cast<CarteClan *>(carte)) {
            cout << "  CarteClan : " << endl;
            cout << *carte_clan << endl;

        } else if (CarteTactique * carte_tactique = dynamic_cast<CarteTactique *>(carte)) {
            cout << "  CarteTactique : " << endl;
            cout << carte_tactique->getNom() << endl;
        }
    }
}
