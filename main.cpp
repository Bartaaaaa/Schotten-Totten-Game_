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
            c.JouerTourClassique1();
            if (c.check_fin_partie()) {
                break;
            }
            c.getPlateau()->setJoueurActif(2);
            c.JouerTourClassique2();
            c.getPlateau()->setJoueurActif(1);
        }
        cout << "Fin de partie" << endl;
        cout << "Le joueur " << c.getGagnant()<< " a gagné" << endl;
        c.fin_de_partie();
    }

}

void launchTacticalGame(bool againstAI) {
    std::cout << "test TacticalGame "<< againstAI<<endl;
    Controleur& c = Controleur::getControleur(true);
    c.debut_de_partie_tactique();
    if (againstAI) {
        while (! c.check_fin_partie()) {

            c.JouerTour1();

            if (c.check_fin_partie()) {
                break;
            }
            c.getPlateau()->setJoueurActif(2);
            c.JouerTourIA();
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



int main1() {
    system ("CLS");
    std::cout << "Bienvenue dans le jeu  !" << std::endl;
    // affichage du logo:
    std::cout << "     ___            _                _       _                               _____            _       _                     " << std::endl;
    std::cout << "    / __|    __    | |_      ___    | |_    | |_     ___    _ _       o O O |_   _|   ___    | |_    | |_     ___    _ _    " << std::endl;
    std::cout << "    \\__ \\   / _|   | ' \\    / _ \\   |  _|   |  _|   / -_)  | ' \\     o        | |    / _ \\   |  _|   |  _|   / -_)  | ' \\   " << std::endl;
    std::cout << "    |___/   \\__|_  |_||_|   \\___/   _\\__|   _\\__|   \\___|  |_||_|   TS__[O]  _|_|_   \\___/   _\\__|   _\\__|   \\___|  |_||_|  " << std::endl;
    std::cout << "  _|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"| {======|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"| " << std::endl;
    std::cout << "  \"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'./o--000'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-' " << std::endl;
    sleep(1);


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

int main()
{
    main1();
    Controleur& c = Controleur::getControleur(true);
    cout << "Il y a " << c.getPiocheTactique()->getNbCartes() << " cartes dans le paquet" << endl;
    Carte carte;
    // on pioche
    switch (c.getPiocheTactique()->quandjepiochejefaisattention()) {
        case 1: {
            cout << "Vous avez pioche la carte tactique :" << endl;
            CarteTactique * a = new CarteTactique(c.getPiocheTactique()->piocherCarteTactique());
            c.getPlateau()->getJoueur1()->getMain()->ajouterCarte(a);
            cout << a->getNom() << endl;
            carte = *a;
            break;
        }
        case 2: {
            cout << "Vous avez pioche la carte troupe Elite :" << endl;
            CarteTroupeElite * b = new CarteTroupeElite( c.getPiocheTactique()->piocherCarteTroupeElite());
            c.getPlateau()->getJoueur1()->getMain()->ajouterCarte(b);
            cout << b->getNom() << endl;
            carte = *b;
            break;
        }
    }
    cout << "\n\nIl y a " << c.getPiocheTactique()->getNbCartes() << " cartes dans le paquet" << endl;
    auto a =c.getPiocheTactique()->getCartes();
    c.getPiocheTactique()->setM_nb(c.getPiocheTactique()->getNbCartes() + 1);
    cout << "Il y a " << c.getPiocheTactique()->getNbCartes() << " cartes dans le paquet" << endl;
    // on la refout dans le paquet
    a[c.getPiocheTactique()->getNbCartes()]= &carte;


    // on repioche
    switch (c.getPiocheTactique()->quandjepiochejefaisattention()) {
        case 1: {
            cout << "Vous avez pioche la carte tactique :" << endl;
            CarteTactique * a = new CarteTactique(c.getPiocheTactique()->piocherCarteTactique());
            c.getPlateau()->getJoueur1()->getMain()->ajouterCarte(a);
            cout << a->getNom() << endl;
            carte = *a;
            break;
        }
        case 2: {
            cout << "Vous avez pioche la carte troupe Elite :" << endl;
            CarteTroupeElite * b = new CarteTroupeElite( c.getPiocheTactique()->piocherCarteTroupeElite());
            c.getPlateau()->getJoueur1()->getMain()->ajouterCarte(b);
            cout << b->getNom() << endl;
            carte = *b;
            break;
        }
    }
    cout << "\n\nIl y a " << c.getPiocheTactique()->getNbCartes() << " cartes dans le paquet" << endl;
    return 0;
}





