//
// Created by Utilisateur on 19/04/2023.
//

#include "CarteRuse.h"
#include "Controleur.h"

void Supp_PushCarteClanTactique(){
    int carte1;
    cin >> carte1;
    int carte1s = carte1;

    vector<Carte*> cartesMain = Controleur::getControleur(false).getPlateau()->getJoueur1()->getMain()->getCartes();
    while(carte1>cartesMain.size() || carte1<0){
        cout<<"Vous n'avez pas cette carte, resaisissez une que vous avez :"<<endl;
        cin>>carte1;
    }
    int  nb_tac=0,nb_clan=0,nb_total=0;
    Carte* carte = cartesMain[carte1];

    /*if ( carte  = dynamic_cast<CarteTactique *>(carte)) {
        for (auto carte: cartesMain) {
            nb_tac++;
            nb_total++;
        }
        if (nb_tac==0){
            cout << "Vous n'avez plus de cartes tactiques !" << endl;
        }
        Carte* carte1 = Controleur::getControleur(true).getPlateau()->getJoueur1()->getMain()->getCarte(carte1s);
        CarteTactique* carteClanChoisie = dynamic_cast<CarteTactique*>(carte1);
        if(carteClanChoisie!=nullptr) {
            cout << "Vous avez choisi la carte : Nom :" << carteClanChoisie->getNom() << endl;
            Controleur::getControleur(true).getPiocheTactique()->push_back(carte1);
            Controleur::getControleur(true).getPlateau()->getJoueur1()->getMain()->supprimerCarte(carte1s);
    }}*/
    int a=0;
    if (a==1) cout<<"lacaca";
   else {
        if (carte = dynamic_cast<CarteClan *>(carte)) {
            for (auto carte: cartesMain) {

                nb_clan++;
                nb_total++;
            }
            if (nb_clan==0){
                cout << "Vous n'avez plus de cartes clans !" << endl;
            }
            if (nb_total ==0 ){
                cout << "Vous n'avez plus de cartes !" << endl;
                return; exit(0);
            }
            Carte* carte1t = Controleur::getControleur(false).getPlateau()->getJoueur1()->getMain()->getCarte(carte1s);
            CarteClan* carteClanChoisie = dynamic_cast<CarteClan*>(carte1t);
            if(carteClanChoisie!=nullptr) {
                cout << "Vous avez choisi la carte : Puissance :" << carteClanChoisie->getPuissance()<< " Couleur : " << carteClanChoisie->getCouleur() << endl;
                Controleur::getControleur(false).getPiocheClan()->push_back(carte1t);
                Controleur::getControleur(false).getPlateau()->getJoueur1()->getMain()->supprimerCarte(carte1s);
            }
        }
    }
}




void CarteRuse::Jouer_ChasseurdeTete() {
    cout << "Vous avez joué la carte Chasseur de Tête" << endl;
    cout  << "Veuillez choisir le nombre de carte Clan que vous voulez piocher :" << endl;
    int nbCarteClan;
    cin >> nbCarteClan;
    while (nbCarteClan>3 || nbCarteClan<0){
        cout << "Vous ne pouvez pas piocher plus ou moins de 3 cartes" << endl;
        cout  << "Veuillez d'abord choisir le nombre de carte Clan que vous voulez piocher :" << endl;
        cin >> nbCarteClan;
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

    }
    cout << "Vous allez maintenant devoir choisir deux cartes que vous allez supprimer de votre main" << endl;
    cout << "Voici votre main actuelle :" << endl;
    Controleur::getControleur(false).getPlateau()->afficherMainJoueur(1);
    Supp_PushCarteClanTactique();
    cout << "Voici votre main actuelle :" << endl;
    Controleur::getControleur(false).getPlateau()->afficherMainJoueur(1);
    Supp_PushCarteClanTactique();
}



void CarteRuse::jouer_Traitre(){
        cout << "Vous avez joué la carte Traître" << endl;
        cout << "Veuillez choisir une borne non revendiquée de l'adversaire qui comporte au moins une carte :" << endl;
        int choix_borne;
        cin >> choix_borne;
        auto cartesBornes = Controleur::getControleur(false).getPlateau()->getBornes(choix_borne)->getCartesJ1()->getCartes();
        for (int i=0; i<cartesBornes.size();i++){
            cout <<"id :" <<i<<" " << cartesBornes[i]->getCouleur() << " " << cartesBornes[i]->getPuissance() << endl;
        }
        cout<< "Quelle carte souhaitée vous retirer de la borne << choix_borne << ?" << endl;
        //TODO : stocker les infos sur la carte avant de la supprimer
        int choix_carte;
        cin >> choix_carte;
        //TODO : faire appel à la méthode qui supprime la carte de la borne adversaire
        cout << "Sur quelle borne souhaitez vous jouer votre carte ?" << endl;
        int choix_borne2;
        cin >> choix_borne2;
        Controleur::getControleur(false).getPlateau()->getBornes(choix_borne2)->getCartesJ1()->getCartes();

}
