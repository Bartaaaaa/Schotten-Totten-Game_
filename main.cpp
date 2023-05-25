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
    }
    */
/*
    CarteClan cc1(Puissance::cinq, Couleur::rouge), cc2(Puissance::six, Couleur::rouge),  cc3(Puissance::sept, Couleur::rouge);
    CarteClan cc4(Puissance::cinq, Couleur::rouge), cc5(Puissance::six, Couleur::rouge),  cc6(Puissance::sept, Couleur::vert);

    Controleur& c = Controleur::getControleur(false);
    cout <<"P: joueur actif:"<<c.getPlateau()->getJoueurActif() << endl;

    c.getPlateau()->getJoueur1()->getMain()->ajouterCarte(&cc1);
    c.getPlateau()->getJoueur1()->getMain()->ajouterCarte(&cc2);
    c.getPlateau()->getJoueur1()->getMain()->ajouterCarte(&cc3);

    c.getPlateau()->getJoueur2()->getMain()->ajouterCarte(&cc4);
    c.getPlateau()->getJoueur2()->getMain()->ajouterCarte(&cc5);
    c.getPlateau()->getJoueur2()->getMain()->ajouterCarte(&cc6);

    c.JouerTour1();
    c.getPlateau()->poser(*c.getPlateau()->getBornes(0), &cc1);
    c.getPlateau()->poser(*c.getPlateau()->getBornes(0), &cc2);
    c.getPlateau()->poser(*c.getPlateau()->getBornes(0), &cc3);
    // J1 a donc une suite couleur 5,6,7 rouge (foce de combi = 4)
    c.getPlateau()->setJoueurActif(2);

    c.getPlateau()->poser(*c.getPlateau()->getBornes(0), &cc4);
    c.getPlateau()->poser(*c.getPlateau()->getBornes(0), &cc5);
    c.getPlateau()->poser(*c.getPlateau()->getBornes(0), &cc6);
    // J2 a donc une suite 5 Rouge 6 Rouge 7 Vert (force de combi = 1)
    affichage_vecteur_carteclan(c.getPlateau()->getBornes(0)->getCartesJ1()->getCartes());
    cout<<"force combi j1 borne 0: "<<c.getPlateau()->getBornes(0)->getCartesJ1()->getForceCombi()<<endl;
    affichage_vecteur_carteclan(c.getPlateau()->getBornes(0)->getCartesJ1()->getCartes());
    cout<<"force combi j2 borne 0: "<<c.getPlateau()->getBornes(0)->getCartesJ2()->getForceCombi()<<endl;
    c.getPlateau()->setJoueurActif(1);

    //TODO getForceCombi ne marche pas  depuis le controleur


    // 0 : somme, 1: suite, 2: couleur, 3: brelan, 4: suite couleur

    //c.renvendiquer_borne(0);


    /*
    //test pioche
    int i = 0;
    while (c.getPiocheClan()->estVide() == false){
        auto ci= c.getPiocheClan()->piocherCarteClan();
        cout << "carte numero"<< i <<" : " << ci.getPuissance()  << endl;
        i++;
    }
    cout << "nb cartes piochee: " << i << endl;
*/
    Controleur& c = Controleur::getControleur(false);
    c.debut_de_partie_classique();

    return 0;
}
