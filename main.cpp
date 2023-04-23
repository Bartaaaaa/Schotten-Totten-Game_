//
// Created by Utilisateur on 02/04/2023.
//
#include <iostream>
#include "CarteRuse.h"
#include "CarteModeCombat.h"
#include "CarteTroupeElite.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    CarteClan cc=CarteClan(Puissance(1), Couleur(1));
    cout << cc.getPuissance() << endl;
    cout << cc.getCouleur() << endl;

    CarteTroupeElite cte=CarteTroupeElite("Joker", Puissance(1), Couleur(1));
    cout << cte.getNom() << endl;
    cout << cte.getPuissance() << endl;
    cout << cte.getCouleur() << endl;

    return 0;
}
