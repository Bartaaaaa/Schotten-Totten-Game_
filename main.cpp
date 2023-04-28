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
#include "Controleur.h"
#include "CarteClan.h"
#include "Plateau.h"
#include "Pioche.h"
#include "Joueur.h"
#include "Main_Joueur.h"

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

    cout << "\nTest Main" << endl;
    Main main_joueur1(6);
    cout << "  Main J1 : " << main_joueur1.getTaille() << endl;
    cout << "  Main J1 : " << main_joueur1.getCartes().size() << endl;
    cout << "  Main J1 : " << main_joueur1.getJoker() << endl;
    cout << "  Main J1 : " << main_joueur1.getNbrCarteTactiqueJoue() << endl;

    cout << "\nTest Joueur" << endl;
    Joueur j1 ( 6, false);
    Joueur j2 ( 6, false);
    main_joueur1= j1.getMain();
    cout << "  Joueur :main J1 : " << j1.getMain().getTaille() << endl;
    cout << "  Joueur  J1 IA: " << j1.getIa() << endl;

    //cout << "\nTest Plateau" << endl;
    Plateau plat1(6, false, false);
    cout << "  Plateau j1 ia ? : " << plat1.getJoueur1().getIa() << endl;
    cout << "  Plateau, main de j1 . taille() : " << plat1.getJoueur1().getMain().getTaille() << endl;
    cout << "  Plateau joueur actif : " << plat1.getJoueurActif() << endl;
    plat1.setJoueurActif(2);
    cout << "  Plateau joueur actif : " << plat1.getJoueurActif() << endl;
    cout << "  Plateau borne 1 : " << plat1.getBornes(1).getNum() << endl;
    // TODO modifier pour que getBornes(1) renvoie la borne intitulee 1 et choisir si on fait demarrer nos bornes a 0 ou 1

    /* TODO ne marche pas on ne peut pas ajouter une carte a la main d'un joueur du plateau (il faut passer par le controleur ?)
    CarteClan* cclan2 = new CarteClan(Puissance::cinq, Couleur::rouge);
    plat1.getJoueur1().getMain().getCartes().push_back(cclan2);
    Carte* c = plat1.getJoueur1().getMain().getCartes().at(0);
    affichage_vecteur_carte(plat1.getJoueur1().getMain().getCartes());

    plat1.poser(2, 0);
    affichage_vecteur_carte(plat1.getBornes(2).getCartesJ1().getCartes());
    */


    return 0;
}
