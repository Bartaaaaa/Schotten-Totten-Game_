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


    CarteClan cc1(Puissance::cinq, Couleur::rouge), cc2(Puissance::six, Couleur::rouge),  cc3(Puissance::sept, Couleur::rouge);
    Combinaison c1;
    c1.ajouterCarte(&cc2);
    c1.ajouterCarte(&cc1);
    c1.ajouterCarte(&cc3);

    affichage_vecteur_carteclan(c1.getCartes());
    cout << "Combinaison 1 : " << c1.calculerForceCombi(true) << endl;
    cout << "Combinaison 1 : " << c1.getForceCombi() << endl;

    CarteClan cc4(Puissance::cinq, Couleur::rouge), cc5(Puissance::six, Couleur::rouge),  cc6(Puissance::sept, Couleur::vert);
    Combinaison c2;
    c2.ajouterCarte(&cc4);
    c2.ajouterCarte(&cc5);
    c2.ajouterCarte(&cc6);

    affichage_vecteur_carteclan(c2.getCartes());
    cout << "Combinaison 2 : " << c2.calculerForceCombi(true) << endl;
    cout << "Combinaison 2 : " << c2.getForceCombi() << endl;


    cout << "Main joueur" << endl;
    Main mainj1(3);
    mainj1.ajouterCarte(&cc1);
    mainj1.ajouterCarte(&cc2);
    affichage_vecteur_carte(mainj1.getCartes());


    /* TODO ne marche pas
    cout << "Plateau :" << endl;
    Plateau p(3, false,false);
    cout <<"P: joueur actif:"<<p.getJoueurActif() << endl;

    p.getJoueur1().getMain().ajouterCarte(&cc1);
    p.getJoueur1().getMain().ajouterCarte(&cc2);
    affichage_vecteur_carte(p.getJoueur1().getMain().getCartes());
    *




    return 0;
}
