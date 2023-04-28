//
// Created by Utilisateur on 02/04/2023.
//
#include <iostream>
#include "CarteRuse.h"
#include "CarteModeCombat.h"
#include "CarteTroupeElite.h"
#include "Borne.h"
#include "Combinaison.h"
#include "CarteException.h"

#include <typeinfo>

using namespace std;

int main() {
    cout << "Test Vecteur de carte" << endl;
    // Sans etoile ne marche pas car on aura pas les infos des classes filles
    vector<Carte*> cartes1;

    // On cree les cartes
    CarteClan* cclan = new CarteClan(Puissance::cinq, Couleur::rouge);
    CarteTactique* ctactique = new CarteTactique("Test");
    cartes1.push_back(cclan);
    cartes1.push_back(ctactique);

    //on va afficher les cartes du vecteur carte en verfiant quel methode on peut faire:
    affichage_vecteur_carte(cartes1);


    cout << "\nTest Combinaison" << endl;
    Combinaison C( cartes1, 0, 4);
    cout << "  C Force : " << C.getForceCombi() << endl;
    cout << "  C Puissance : " << C.getTotalPuissance() << endl;
    cout << "  C Cartes : " << C.getCartes().size() << endl;


    cout << "\nTest Borne" << endl;
    Borne b1(1);
    cout << "  Borne 1 : " << b1.getNum() << endl;
    cout << "  B1 Colline : " << b1.getCollin() << endl;
    cout << "  B1 Boue : " << b1.getBoue() << endl;
    cout << "  B1 Revendique : " << b1.getRevendique() << endl;
    cout << "  B1 Dernier Pose : " << b1.getDernierPose() << endl;
    cout << "  B1 Cartes J1 : " << b1.getCartesJ1().getCartes().size() << endl;
    b1.getCartesJ1().ajouterCarte(cclan);
    cout << "  B1 Cartes J1 apres ajout : " << b1.getCartesJ1().getCartes().size() << endl;
    b1.ajout_carte_j1(ctactique);
    cout << "  B1 Cartes J1 apres ajout : " << b1.getCartesJ1().getCartes().size() << endl;
    affichage_vecteur_carte(b1.getCartesJ1().getCartes());



    return 0;
}
