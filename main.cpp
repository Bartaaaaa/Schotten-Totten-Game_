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

    Controleur& c = Controleur::getControleur(false);
    /*
    c.afficherCartesNonPose();

    cout<< "Il y a " << c.getCarteNonPose().size() << " cartes non posees" << endl;
    auto test = c.getPiocheClan()->piocherCarteClan();
    cout << "carte piochee: " << test.getCouleur() << " "<< test.getPuissance() << endl;
    // TODO ne marche pas car la creation des cartes dans m_cartesposé crée des nouvelles adresses
    c.supprimer_carte_pose_v1(&test);
    cout<< "\nV1 Il y a " << c.getCarteNonPose().size() << " cartes non posees" << endl;
    c.supprimer_carte_pose_v2(&test);
    cout<< "\nV2 Il y a " << c.getCarteNonPose().size() << " cartes non posees" << endl;
    c.afficherCartesNonPose();
    */
    system ("CLS");
    cout << "Il y a plus rien" << endl;
    c.debut_de_partie_classique();
    system ("CLS");
    c.JouerTour1();
    //c.JouerTourClassique1();
    //c.JouerTourClassique1();
    //c.JouerTourClassique1();
    //c.revendiquer_borne(1);

    return 0;
}