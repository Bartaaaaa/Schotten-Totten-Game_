//
// Created by Utilisateur on 19/04/2023.
//

#include "CarteRuse.h"
#include "Controleur.h"

void CarteRuse::Jouer_ChasseurdeTete() {
    cout << "Vous avez joué la carte Chasseur de Tête" << endl;
    cout  << "Veuillez choisir le nombre de carte Clan que vous voulez piocher :" << endl;
    int nbCarteClan;
    cin >> nbCarteClan;
    while (nbCarteClan>3 || nbCarteClan<0){
        cout << "Vous ne pouvez pas piocher plus ou moins de 3 cartes" << endl;
        cout  << "Veuillez d'abord choisir le nombre de carte Clan que vous voulez piocher :" << endl;
        int nbCarteClan;
        cin >> nbCarteClan;
        cout << "Veuillez choisir le nombre de carte Tactique que vous voulez piocher :" << endl;
        int nbCarteTactique;
        cin >> nbCarteTactique;
    }
    switch(nbCarteClan){
        case 0 : {
            CarteTactique* ct01 = new CarteTactique(Controleur::getControleur(false).getPiocheTactique()->piocherCarteTactique());
            cout <<"Carte piochee : "<< ct01->getNom() << endl;
            CarteTactique* ct02 = new CarteTactique(Controleur::getControleur(false).getPiocheTactique()->piocherCarteTactique());
            cout <<"Carte piochee : "<< ct02->getNom() << endl;
            CarteTactique* ct03 = new CarteTactique(Controleur::getControleur(false).getPiocheTactique()->piocherCarteTactique());
            cout <<"Carte piochee : "<< ct03->getNom() << endl;
            Controleur::getControleur(false).getPlateau()->getJoueur1()->getMain()->ajouterCarte(ct01);
            Controleur::getControleur(false).getPlateau()->getJoueur1()->getMain()->ajouterCarte(ct02);
            Controleur::getControleur(false).getPlateau()->getJoueur1()->getMain()->ajouterCarte(ct03);
            break;}
        case 1:{
            CarteClan* c11 = new CarteClan(Controleur::getControleur(false).getPiocheClan()->piocherCarteClan());
            cout <<"Carte piochee : "<< c11->getPuissance() <<" "<< c11->getCouleur() << endl;
            CarteTactique* ct11 = new CarteTactique(Controleur::getControleur(false).getPiocheTactique()->piocherCarteTactique());
            cout <<"Carte piochee : "<< ct11->getNom() << endl;
            CarteTactique* ct12 = new CarteTactique(Controleur::getControleur(false).getPiocheTactique()->piocherCarteTactique());
            cout <<"Carte piochee : "<< ct12->getNom() << endl;
            Controleur::getControleur(false).getPlateau()->getJoueur1()->getMain()->ajouterCarte(c11);
            Controleur::getControleur(false).getPlateau()->getJoueur1()->getMain()->ajouterCarte(ct11);
            Controleur::getControleur(false).getPlateau()->getJoueur1()->getMain()->ajouterCarte(ct12);
            break;}
        case 2: {
            CarteClan *c21 = new CarteClan(Controleur::getControleur(false).getPiocheClan()->piocherCarteClan());
            Controleur::getControleur(false).getPlateau()->getJoueur1()->getMain()->ajouterCarte(c21);
            cout << "Carte piochee : " << c21->getPuissance() << " " << c21->getCouleur() << endl;
            CarteClan *c22 = new CarteClan(Controleur::getControleur(false).getPiocheClan()->piocherCarteClan());
            Controleur::getControleur(false).getPlateau()->getJoueur1()->getMain()->ajouterCarte(c22);
            cout << "Carte piochee : " << c22->getPuissance() << " " << c22->getCouleur() << endl;
            CarteTactique *ct21 = new CarteTactique(
                    Controleur::getControleur(false).getPiocheTactique()->piocherCarteTactique());
            cout << "Carte piochee : " << ct21->getNom() << endl;
            Controleur::getControleur(false).getPlateau()->getJoueur1()->getMain()->ajouterCarte(c21);
            Controleur::getControleur(false).getPlateau()->getJoueur1()->getMain()->ajouterCarte(c22);
            Controleur::getControleur(false).getPlateau()->getJoueur1()->getMain()->ajouterCarte(ct21);
        }
        case 3: {
            CarteClan* c31 = new CarteClan(Controleur::getControleur(false).getPiocheClan()->piocherCarteClan());
            Controleur::getControleur(false).getPlateau()->getJoueur1()->getMain()->ajouterCarte(c31);
            cout <<"Carte piochee : "<< c31->getPuissance() <<" "<< c31->getCouleur() << endl;
            CarteClan* c32 = new CarteClan(Controleur::getControleur(false).getPiocheClan()->piocherCarteClan());
            Controleur::getControleur(false).getPlateau()->getJoueur1()->getMain()->ajouterCarte(c32);
            cout <<"Carte piochee : "<< c32->getPuissance() <<" "<< c32->getCouleur() << endl;
            CarteClan* c33 = new CarteClan(Controleur::getControleur(false).getPiocheClan()->piocherCarteClan());
            Controleur::getControleur(false).getPlateau()->getJoueur1()->getMain()->ajouterCarte(c33);
            cout <<"Carte piochee : "<< c33->getPuissance() <<" "<< c33->getCouleur() << endl;
            Controleur::getControleur(false).getPlateau()->getJoueur1()->getMain()->ajouterCarte(c31);
            Controleur::getControleur(false).getPlateau()->getJoueur1()->getMain()->ajouterCarte(c32);
            Controleur::getControleur(false).getPlateau()->getJoueur1()->getMain()->ajouterCarte(c33);
        }
            cout << "Voici votre main après avoir joué la carte Chasseur de tête :" << endl;
            Controleur::getControleur(false).getPlateau()->afficherMainJoueur(1);
            cout << "Veuillez choisir deux cartes à défausser :" << endl;
            int choix_defausse1,choix_defausse2;
            cin >> choix_defausse1;
            cin >> choix_defausse2;

            //TODO : faire appel à la méthode qui met les cartes de la main dans la pioche


    }


}