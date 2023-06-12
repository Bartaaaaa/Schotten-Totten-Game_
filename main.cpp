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


void launchClassicGame(bool againstAI) {
    std::cout << "test ClassicGame "<< againstAI<<endl;
    Controleur& c = Controleur::getControleur(false);
    c.debut_de_partie_classique();
    if (againstAI) {
        while (! c.check_fin_partie()) {
            c.JouerTourClassique1();
            if (c.check_fin_partie()) {
                break;
            }
            c.getPlateau()->setJoueurActif(2);
            c.JouerTourIAClassique();
            c.getPlateau()->setJoueurActif(1);
        }
        cout << "Fin de partie" << endl;
        cout << "Le joueur " << c.getGagnant()<< " a gagné" << endl;
        c.fin_de_partie();
    }
    else{
        while (! c.check_fin_partie()) {
            c.JouerTour1();
            if (c.check_fin_partie()) {
                break;
            }
            c.getPlateau()->setJoueurActif(2);
            c.JouerTour2();
            c.getPlateau()->setJoueurActif(1);
        }
        cout << "Fin de partie" << endl;
        cout << "Le joueur " << c.getGagnant()<< " a gagné" << endl;
        c.fin_de_partie();
    }

}

void launchTacticalGame(bool againstAI) {
    std::cout << "test TacticalGame "<< againstAI<<endl;
}



int main() {
    system ("CLS");
    std::cout << "Bienvenue dans le jeu  !" << std::endl;
    // affichage du logo:
    std::cout << "     ___            _                _       _                               _____            _       _                     " << std::endl;
    std::cout << "    / __|    __    | |_      ___    | |_    | |_     ___    _ _       o O O |_   _|   ___    | |_    | |_     ___    _ _    " << std::endl;
    std::cout << "    \\__ \\   / _|   | ' \\    / _ \\   |  _|   |  _|   / -_)  | ' \\     o        | |    / _ \\   |  _|   |  _|   / -_)  | ' \\   " << std::endl;
    std::cout << "    |___/   \\__|_  |_||_|   \\___/   _\\__|   _\\__|   \\___|  |_||_|   TS__[O]  _|_|_   \\___/   _\\__|   _\\__|   \\___|  |_||_|  " << std::endl;
    std::cout << "  _|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"| {======|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"| " << std::endl;
    std::cout << "  \"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'./o--000'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-' " << std::endl;
    sleep(5);


//     ___            _                _       _                               _____            _       _
//    / __|    __    | |_      ___    | |_    | |_     ___    _ _       o O O |_   _|   ___    | |_    | |_     ___    _ _
//    \__ \   / _|   | ' \    / _ \   |  _|   |  _|   / -_)  | ' \     o        | |    / _ \   |  _|   |  _|   / -_)  | ' \
//    |___/   \__|_  |_||_|   \___/   _\__|   _\__|   \___|  |_||_|   TS__[O]  _|_|_   \___/   _\__|   _\__|   \___|  |_||_|
//  _|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""| {======|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|
//  "`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'./o--000'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'

    while (true) {
        system ("CLS");
        std::cout << "=== Menu ===" << std::endl;
        std::cout << "1. Partie classique contre un humain" << std::endl;
        std::cout << "2. Partie classique contre l'IA" << std::endl;
        std::cout << "3. Partie tactique contre un humain" << std::endl;
        std::cout << "4. Partie tactique contre l'IA" << std::endl;
        std::cout << "5. Quitter" << std::endl;

        int choice;
        std::cout << "Entrez votre choix : ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                launchClassicGame(false);
                break;
            case 2:
                launchClassicGame(true);
                break;
            case 3:
                launchTacticalGame(false);
                break;
            case 4:
                launchTacticalGame(true);
                break;
            case 5:
                std::cout << "Au revoir !" << std::endl;
                std::exit(0);
            default:
                std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
        }
    }
return 0;
}








   //Controleur& c = Controleur::getControleur(true);
    //Controleur& c = Controleur::getControleur(true);
/*
    c.getPlateau()->getBornes(1);

    c.getPlateau()->getBornes(1)->setBoue(true);
*/

   // c.revendiquer_borne(1);
    //cout << "revendiquer 1:" << c.getPlateau()->getBornes(1)->getRevendique() << endl;
/*

    c.getPlateau()->getJoueur1()->getMain()->ajouterCarte(new CarteClan(Puissance::neuf, Couleur::violet));
    c.getPlateau()->getJoueur1()->getMain()->ajouterCarte(new CarteClan(Puissance::huit, Couleur::rouge));
    c.getPlateau()->getJoueur1()->getMain()->ajouterCarte(new CarteClan(Puissance::sept, Couleur::rouge));
    c.getPlateau()->getJoueur1()->getMain()->ajouterCarte(new CarteClan(Puissance::six, Couleur::rouge));
    c.getPlateau()->getJoueur1()->getMain()->ajouterCarte(new CarteClan(Puissance::cinq, Couleur::rouge));
    c.getPlateau()->getJoueur1()->getMain()->ajouterCarte(new CarteClan(Puissance::quatre, Couleur::rouge));
    c.getPlateau()->getJoueur1()->getMain()->ajouterCarte(new CarteClan(Puissance::trois, Couleur::rouge));
    c.getPlateau()->getJoueur1()->getMain()->ajouterCarte(new CarteClan(Puissance::deux, Couleur::rouge));
    c.getPlateau()->getJoueur1()->getMain()->ajouterCarte(new CarteClan(Puissance::un, Couleur::rouge));
    c.getPlateau()->getBornes(1)->getCartesJ1()->ajouterCarte(new CarteClan(Puissance::neuf, Couleur::violet));
    c.getPlateau()->getBornes(2)->getCartesJ1()->ajouterCarte(new CarteClan(Puissance::huit, Couleur::rouge));

    c.getPlateau()->getJoueur2()->getMain()->ajouterCarte(new CarteClan(Puissance::un, Couleur::rouge));
    c.getPlateau()->getJoueur2()->getMain()->ajouterCarte(new CarteClan(Puissance::deux, Couleur::rouge));
    c.getPlateau()->getJoueur2()->getMain()->ajouterCarte(new CarteClan(Puissance::trois, Couleur::rouge));
    c.getPlateau()->getJoueur2()->getMain()->ajouterCarte(new CarteClan(Puissance::quatre, Couleur::rouge));
    auto k = new CarteTroupeElite("Joker", Puissance::zero, Couleur::neutre);
    c.getPlateau()->getBornes(5)->getCartesJ2()->ajouterCarte(k);

    c.getPlateau()->getBornes(5)->getCartesJ2()->ajouterCarte(new CarteClan(Puissance::trois, Couleur::vert));
    c.getPlateau()->getBornes(6)->getCartesJ2()->ajouterCarte(new CarteClan(Puissance::huit, Couleur::rouge));
    //c.JouerTour1();
    for (int i = 0 ; i<3;i++){
        c.JouerTour1();
        sleep(10);
    }
*/

    /*
    *//*c.getPlateau()->getBornes(1)->getCartesJ2()->ajouterCarte(new CarteClan(Puissance::deux, Couleur::rouge));
    c.getPlateau()->getBornes(1)->getCartesJ2()->ajouterCarte(new CarteClan( Puissance::quatre, Couleur::rouge));
   *//**//*

    for (int i = 0; i < 5; i++) {

        c.JouerTourIAClassique();
    }

*//**//*
   // c.revendiquer_borne(1);
    //sleep(5);
*//**//*
    auto k = new CarteTroupeElite("Joker", Puissance::zero, Couleur::neutre);
    cout << k->getNom() << " "<< k->getPuissance() << " " << k->getCouleur() << endl;
    //k->jouer_Joker();
    cout << k->getNom() << " "<< k->getPuissance() << " " << k->getCouleur() << endl;*//**//*


*//**//*    Controleur& c = Controleur::getControleur(true);
    cout << "il ya "<<c.getPiocheTactique()->getNbCartes()<< endl;
    for (auto i =0; i<4; i++) {
        auto a = c.getPiocheTactique()->piocherCarteTroupeElite();
        cout<< a.getNom() << endl;

    }
    while ( ! c.getPiocheTactique()->estVide()) {
        auto a = c.getPiocheTactique()->piocherCarteTactique();
        cout << a.getNom()<<endl;
    }*//**//*

    c.JouerTour1(); c.JouerTour1(); c.JouerTour1();
    c.JouerTour1(); c.JouerTour1(); c.JouerTour1();
    c.JouerTour1(); c.JouerTour1(); c.JouerTour1();
    //TODO sucer Nathan

    cout << "il ya "<<c.getPiocheTactique()->getNbCartes()<< endl;
    cout << "attention : " << c.getPiocheTactique()->quandjepiochejefaisattention()<< endl;
    switch (c.getPiocheTactique()->quandjepiochejefaisattention()) {
        case 1: {
            cout << "pioche tactique" << endl;
            auto a = c.getPiocheTactique()->piocherCarteTactique();
            cout << a.getNom() << endl;
            break;
        }

        case 2: {
            cout << "pioche troupe elite" << endl;
            auto b = c.getPiocheTactique()->piocherCarteTroupeElite();
            cout << b.getNom() << endl;
            break;
        }
    }

*//*

*/

/*
 * PAS drole :( Si c'est drole
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