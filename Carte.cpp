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
            cout << "  CarteClan : "  << carte_clan->getPuissance()<< " "<< carte_clan->getCouleur() << endl;

        } else if (CarteTactique * carte_tactique = dynamic_cast<CarteTactique *>(carte)) {
            cout << "  CarteTactique : " << carte_tactique->getNom() << endl;
        }
    }
}

void affichage_vecteur_carte2(vector<CarteClan*> v) {   //temporaire juste pour l'affichage dans le main
    for (auto carte: v) {
        if (CarteClan *carte_clan = dynamic_cast<CarteClan *>(carte)) {
            cout << "  CarteClan : " << carte_clan->getPuissance() << " " << carte_clan->getCouleur() << endl;
        }
    }
}