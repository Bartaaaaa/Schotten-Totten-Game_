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
#include <stdlib.h>
#include <unistd.h>


using namespace std;

int main() {
    /*
    cout << "Bienvenue dans Schotten-Totten haha ! bienvenue bienvnue dans ce superbe jeu, je suis bob lennon et voici le jeu" << endl;
    cout << "Plusieurs options s'offrent à vous , veillez en choisir une haha ! " << endl;
    cout << "1- Jouer une partie contre un autre joueur haha !" << endl;
    cout << "2- Jouer une partie contre une IA haha !" << endl;
    cout << "3- Quitter le jeu haha !" << endl;
    int choix;
    cin >> choix;
    switch(choix) {
        case 1:
            cout << "Vous avez choisi de jouer contre un autre joueur haha !" << endl;
            //JoeurTour1();
            break;
        case 2:
            cout << "Vous avez choisi de jouer contre une IA haha !" << endl;
            break;
        case 3:
            cout << "Vous avez choisi de quitter le jeu haha !" << endl;
            break;
        default:
            cout << "Vous n'avez pas choisi une option valide, veuillez recommencer haha !" << endl;
            break;
    }*/

    Controleur& c = Controleur::getControleur(true);
    c.getPlateau()->getBornes(1);

    c.getPlateau()->getBornes(1)->setBoue(true);
    c.getPlateau()->getBornes(1)->getCartesJ1()->ajouterCarte(new CarteClan(Puissance::un, Couleur::bleu));
    c.getPlateau()->getBornes(1)->getCartesJ1()->ajouterCarte(new CarteTroupeElite("Joker", Puissance::zero, Couleur::neutre));
    c.getPlateau()->getBornes(1)->getCartesJ1()->ajouterCarte(new CarteClan(Puissance::trois, Couleur::bleu));


    /*c.getPlateau()->getBornes(1)->getCartesJ2()->ajouterCarte(new CarteClan(Puissance::deux, Couleur::rouge));
    c.getPlateau()->getBornes(1)->getCartesJ2()->ajouterCarte(new CarteClan( Puissance::quatre, Couleur::rouge));
    */

    c.revendiquer_borne(1);
    sleep(5);

    auto k = new CarteTroupeElite("Joker", Puissance::zero, Couleur::neutre);
    cout << k->getNom() << " "<< k->getPuissance() << " " << k->getCouleur() << endl;
    k->jouer_Joker();
    cout << k->getNom() << " "<< k->getPuissance() << " " << k->getCouleur() << endl;




    return 0;
}