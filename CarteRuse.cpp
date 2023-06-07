//
// Created by Utilisateur on 19/04/2023.
//

#include "CarteRuse.h"
#include "Controleur.h"
#include "Main_Joueur.h"
#include <random>

int generateRandomNumber2() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distribution(1, 100);
    return distribution(rng);
}

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

    if ( carte  = dynamic_cast<CarteTactique *>(carte)) {
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
    }}
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

void Supp_PushCarteClanTactiqueIA(){
    int carte1 = generateRandomNumber2()%(Controleur::getControleur(true).getPlateau()->getJoueur2()->getMain()->getCartes().size())+1;
    int carte1s = carte1;


    vector<Carte*> cartesMain = Controleur::getControleur(true).getPlateau()->getJoueur2()->getMain()->getCartes();
    while(carte1>cartesMain.size() || carte1<0){
        carte1 = generateRandomNumber2()%(Controleur::getControleur(true).getPlateau()->getJoueur2()->getMain()->getCartes().size())+1;
    }
    int  nb_tac=0,nb_clan=0,nb_total=0;
    Carte* carte = cartesMain[carte1];

    if ( carte  = dynamic_cast<CarteTactique *>(carte)) {
        for (auto carte: cartesMain) {
            nb_tac++;
            nb_total++;
        }
        if (nb_tac==0){
            cout << "Vous n'avez plus de cartes tactiques !" << endl;
        }
        Carte* carte1 = Controleur::getControleur(true).getPlateau()->getJoueur2()->getMain()->getCarte(carte1s);
        CarteTactique* carteClanChoisie = dynamic_cast<CarteTactique*>(carte1);
        if(carteClanChoisie!=nullptr) {
            cout << "Vous avez choisi la carte : Nom :" << carteClanChoisie->getNom() << endl;
            Controleur::getControleur(true).getPiocheTactique()->push_back(carte1);
            Controleur::getControleur(true).getPlateau()->getJoueur2()->getMain()->supprimerCarte(carte1s);
        }}
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
            Carte* carte1t = Controleur::getControleur(true).getPlateau()->getJoueur2()->getMain()->getCarte(carte1s);
            CarteClan* carteClanChoisie = dynamic_cast<CarteClan*>(carte1t);
            if(carteClanChoisie!=nullptr) {
                cout << "L'ia a choisi  la carte : Puissance :" << carteClanChoisie->getPuissance()<< " Couleur : " << carteClanChoisie->getCouleur() << endl;
                Controleur::getControleur(true).getPiocheClan()->push_back(carte1t);
                Controleur::getControleur(true).getPlateau()->getJoueur2()->getMain()->supprimerCarte(carte1s);
            }
        }
    }
}

void CarteRuse::Jouer_ChasseurdeTeteIA(){
    cout << "L'IA a joué la carte Chasseur de tête :" << endl;
    int nbCarteClan = generateRandomNumber2()%3+1;
    while (nbCarteClan>3 || nbCarteClan<0){
        nbCarteClan = generateRandomNumber2()%3+1;
    }
    cout  << "L'ia a choisi de piocher " <<nbCarteClan << "cartes clan." << endl;
    switch(nbCarteClan){
        case 0 : {
            CarteTactique* ct01 = new CarteTactique(Controleur::getControleur(true).getPiocheTactique()->piocherCarteTactique());
            cout <<"Carte piochee : "<< ct01->getNom() << endl;
            CarteTactique* ct02 = new CarteTactique(Controleur::getControleur(true).getPiocheTactique()->piocherCarteTactique());
            cout <<"Carte piochee : "<< ct02->getNom() << endl;
            CarteTactique* ct03 = new CarteTactique(Controleur::getControleur(true).getPiocheTactique()->piocherCarteTactique());
            cout <<"Carte piochee : "<< ct03->getNom() << endl;
            Controleur::getControleur(true).getPlateau()->getJoueur2()->getMain()->ajouterCarte(ct01);
            Controleur::getControleur(true).getPlateau()->getJoueur2()->getMain()->ajouterCarte(ct02);
            Controleur::getControleur(true).getPlateau()->getJoueur2()->getMain()->ajouterCarte(ct03);


            break;}
        case 1:{
            CarteClan* c11 = new CarteClan(Controleur::getControleur(false).getPiocheClan()->piocherCarteClan());
            cout <<"Carte piochee : "<< c11->getPuissance() <<" "<< c11->getCouleur() << endl;
            CarteTactique* ct11 = new CarteTactique(Controleur::getControleur(true).getPiocheTactique()->piocherCarteTactique());
            cout <<"Carte piochee : "<< ct11->getNom() << endl;
            CarteTactique* ct12 = new CarteTactique(Controleur::getControleur(true).getPiocheTactique()->piocherCarteTactique());
            cout <<"Carte piochee : "<< ct12->getNom() << endl;
            Controleur::getControleur(false).getPlateau()->getJoueur2()->getMain()->ajouterCarte(c11);
            Controleur::getControleur(true).getPlateau()->getJoueur2()->getMain()->ajouterCarte(ct11);
            Controleur::getControleur(true).getPlateau()->getJoueur2()->getMain()->ajouterCarte(ct12);

            break;}
        case 2: {
            CarteClan *c21 = new CarteClan(Controleur::getControleur(false).getPiocheClan()->piocherCarteClan());
            Controleur::getControleur(false).getPlateau()->getJoueur1()->getMain()->ajouterCarte(c21);
            cout << "Carte piochee : " << c21->getPuissance() << " " << c21->getCouleur() << endl;
            CarteClan *c22 = new CarteClan(Controleur::getControleur(false).getPiocheClan()->piocherCarteClan());
            Controleur::getControleur(false).getPlateau()->getJoueur1()->getMain()->ajouterCarte(c22);
            cout << "Carte piochee : " << c22->getPuissance() << " " << c22->getCouleur() << endl;
            CarteTactique *ct21 = new CarteTactique(Controleur::getControleur(true).getPiocheTactique()->piocherCarteTactique());
            cout << "Carte piochee : " << ct21->getNom() << endl;
            Controleur::getControleur(false).getPlateau()->getJoueur2()->getMain()->ajouterCarte(c21);
            Controleur::getControleur(false).getPlateau()->getJoueur2()->getMain()->ajouterCarte(c22);
            Controleur::getControleur(true).getPlateau()->getJoueur2()->getMain()->ajouterCarte(ct21);

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
            Controleur::getControleur(false).getPlateau()->getJoueur2()->getMain()->ajouterCarte(c31);
            Controleur::getControleur(false).getPlateau()->getJoueur2()->getMain()->ajouterCarte(c32);
            Controleur::getControleur(false).getPlateau()->getJoueur2()->getMain()->ajouterCarte(c33);

        }

    }
    cout << "Vous allez maintenant devoir choisir deux cartes que vous allez supprimer de votre main" << endl;
    cout << "Voici votre main actuelle :" << endl;
    Controleur::getControleur(true).getPlateau()->afficherMainJoueur(1);
    Supp_PushCarteClanTactiqueIA();
    cout << "Voici votre main actuelle :" << endl;
    Controleur::getControleur(true).getPlateau()->afficherMainJoueur(1);
    Supp_PushCarteClanTactiqueIA();
}
 void CarteRuse::Jouer_StrategeIA() {

     cout << "L'ia a joué la carte Stratege" << endl;
     cout << "Voici toutes vos bornes : " << endl;
     Controleur::getControleur(true).Afficher_Borne1();
     cout << "Veuillez choisir une borne non revendiquee appartenant a vous " << endl;
     int choix_borne, choix_carte;
     choix_borne = generateRandomNumber2()%8+1;
     while (Controleur::getControleur(true).getPlateau()->getBornes(
             choix_borne)->getCartesJ1()->getCartes().empty() && Controleur::getControleur(true).getPlateau()->getBornes(
             choix_borne)->getRevendique() ==0) {
         choix_borne = generateRandomNumber2()%8+1;
     }
     auto cartesBornes = Controleur::getControleur(true).getPlateau()->getBornes(
             choix_borne)->getCartesJ1()->getCartes();
     for (int i = 0; i < cartesBornes.size(); i++) {
         cout << "id :" << i << " " << cartesBornes[i]->getCouleur() << " " << cartesBornes[i]->getPuissance()
              << endl;
     }
     cout << "Quelle carte souhaitee vous retirer de la borne "<< choix_borne << "?" << endl;
     Combinaison *combi_j1 = Controleur::getControleur(true).getPlateau()->getBornes(choix_borne)->getCartesJ1();
     Combinaison *combi_j2 = Controleur::getControleur(true).getPlateau()->getBornes(choix_borne)->getCartesJ2();
     vector<CarteClan *> cartes_pose_j1 = combi_j1->getCartes();
     vector<CarteClan *> cartes_pose_j2 = combi_j2->getCartes();
     //TODO : essayer plutot de récupérer la taille de la borne et faire rand%taille+1
     int taille_borne = Controleur::getControleur(true).getPlateau()->getBornes(choix_borne)->getCartesJ1()->getCartes().size();
     choix_carte = generateRandomNumber2()%taille_borne+1;

     while (choix_carte > cartesBornes.size() - 1 || choix_carte < 0) {
         choix_carte = generateRandomNumber2()%taille_borne+1;
     }
     auto carte_choisie = Controleur::getControleur(true).getPlateau()->getBornes(
             choix_borne)->getCartesJ1()->getCartes()[choix_carte];
     cout << "L'IA a choisi la carte : " << carte_choisie->getCouleur() << " " << carte_choisie->getPuissance()<< endl;
     Controleur::getControleur(true).getPlateau()->getBornes(choix_borne)->getCartesJ1()->supprimerCarte_Borne(
             choix_carte);
     cout << "L'ia a décidé de défausser la carte : "<< carte_choisie->getCouleur() << " " << carte_choisie->getPuissance()<< endl;
     delete carte_choisie;

}
 void CarteRuse::Jouer_BansheeIA() {
     cout << "L'IA a joué la carte Banshee" << endl;
     cout << "Voici les bornes de l'adversaire bornes : " << endl;
     Controleur::getControleur(false).Afficher_Borne2();
     cout << "Veuillez choisir une borne non revendiquee appartenant a l'adversaire " << endl;
     int choix_borne, choix_carte;
     choix_borne = generateRandomNumber2() % 8 + 1;
     while (Controleur::getControleur(true).getPlateau()->getBornes(
             choix_borne)->getCartesJ2()->getCartes().empty() &&
            Controleur::getControleur(true).getPlateau()->getBornes(
                    choix_borne)->getRevendique() == 0) {
         cout << "L'adversaire  n'a pas de cartes sur cette borne, veuillez en choisir une autre : " << endl;
         choix_borne = generateRandomNumber2() % 8 + 1;
     }
     auto cartesBornes = Controleur::getControleur(true).getPlateau()->getBornes(
             choix_borne)->getCartesJ2()->getCartes();
     for (int i = 0; i < cartesBornes.size(); i++) {
         cout << "id :" << i << " " << cartesBornes[i]->getCouleur() << " " << cartesBornes[i]->getPuissance()
              << endl;
     }
     cout << "Quelle carte souhaitee vous retirer de la borne " << choix_borne << "?" << endl;
     int taille_borne = Controleur::getControleur(true).getPlateau()->getBornes(
             choix_borne)->getCartesJ1()->getCartes().size();
     choix_carte = generateRandomNumber2() % taille_borne + 1;


     while (choix_carte > cartesBornes.size() - 1 || choix_carte < 0) {
         choix_carte = generateRandomNumber2() % taille_borne + 1;
     }
     auto carte_choisie = Controleur::getControleur(true).getPlateau()->getBornes(
             choix_borne)->getCartesJ2()->getCartes()[choix_carte];
     cout << "L'ia a choisi la carte : " << carte_choisie->getCouleur() << " " << carte_choisie->getPuissance() << endl;
     Controleur::getControleur(true).getPlateau()->getBornes(choix_borne)->getCartesJ2()->supprimerCarte_Borne(
             choix_carte);
 }
 void CarteRuseJouer_TraitreIA() {
     cout << "L'ia a joueé la carte Traitre" << endl;
     cout << "Voici les bornes de l'adversaire bornes : " << endl;
     Controleur::getControleur(false).Afficher_Borne2();
     cout << "Veuillez choisir une borne non revendiquee appartenant a l'adversaire " << endl;
     int choix_borne, choix_carte;
     choix_borne = generateRandomNumber2() % 8 + 1;
     while (Controleur::getControleur(true).getPlateau()->getBornes(choix_borne)->getCartesJ2()->getCartes().empty() && Controleur::getControleur(true).getPlateau()->getBornes(
                    choix_borne)->getRevendique() == 0) {
         cout << "L'adversaire  n'a pas de cartes sur cette borne, veuillez en choisir une autre : " << endl;
         choix_borne = generateRandomNumber2() % 8 + 1;
     }
     auto cartesBornes = Controleur::getControleur(true).getPlateau()->getBornes(
             choix_borne)->getCartesJ2()->getCartes();
     for (int i = 0; i < cartesBornes.size(); i++) {
         cout << "id :" << i << " " << cartesBornes[i]->getCouleur() << " " << cartesBornes[i]->getPuissance()
              << endl;
     }
     cout << "Quelle carte souhaitee vous retirer de la borne " << choix_borne << "?" << endl;
     int taille_borne = Controleur::getControleur(true).getPlateau()->getBornes(
             choix_borne)->getCartesJ1()->getCartes().size();
     choix_carte = generateRandomNumber2() % taille_borne + 1;

     while (choix_carte > cartesBornes.size() - 1 || choix_carte < 0) {
         cout << "Vous ne pouvez pas selectionner cette carte, veuillez en choisir une autre : " << endl;
         choix_carte = generateRandomNumber2() % taille_borne + 1;
     }
     auto carte_choisie = Controleur::getControleur(true).getPlateau()->getBornes(
             choix_borne)->getCartesJ2()->getCartes()[choix_carte];
     cout << "L'ia a choisi la carte : " << carte_choisie->getCouleur() << " " << carte_choisie->getPuissance()
          << endl;
     Controleur::getControleur(true).getPlateau()->getBornes(choix_borne)->getCartesJ2()->supprimerCarte_Borne(
             choix_carte);
     cout << "Sur quelle borne non revendiquee voulez vous placer votre carte ? " << endl;
     choix_borne = generateRandomNumber2() % 8 + 1;
     while (Controleur::getControleur(true).getPlateau()->getBornes(choix_borne)->getCartesJ2()->getCartes().empty() && Controleur::getControleur(true).getPlateau()->getBornes(
             choix_borne)->getRevendique() == 0) {
         cout << "Vous ne pouvez pas poser votre carte sur cette borne, veuillez en choisir une autre : " << endl;
         choix_borne = generateRandomNumber2() % 8 + 1;
     }
     Controleur::getControleur(true).getPlateau()->getBornes(choix_borne)->getCartesJ1()->ajouterCarte(carte_choisie);
     cout << "Voici vos bornes apres avoir joué la carte Traitre : " << endl;
     Controleur::getControleur(true).Afficher_Borne1();
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
            CarteTactique* ct01 = new CarteTactique(Controleur::getControleur(true).getPiocheTactique()->piocherCarteTactique());
            cout <<"Carte piochee : "<< ct01->getNom() << endl;
            CarteTactique* ct02 = new CarteTactique(Controleur::getControleur(true).getPiocheTactique()->piocherCarteTactique());
            cout <<"Carte piochee : "<< ct02->getNom() << endl;
            CarteTactique* ct03 = new CarteTactique(Controleur::getControleur(true).getPiocheTactique()->piocherCarteTactique());
            cout <<"Carte piochee : "<< ct03->getNom() << endl;
            Controleur::getControleur(true).getPlateau()->getJoueur1()->getMain()->ajouterCarte(ct01);
            Controleur::getControleur(true).getPlateau()->getJoueur1()->getMain()->ajouterCarte(ct02);
            Controleur::getControleur(true).getPlateau()->getJoueur1()->getMain()->ajouterCarte(ct03);


            break;}
        case 1:{
            CarteClan* c11 = new CarteClan(Controleur::getControleur(false).getPiocheClan()->piocherCarteClan());
            cout <<"Carte piochee : "<< c11->getPuissance() <<" "<< c11->getCouleur() << endl;
            CarteTactique* ct11 = new CarteTactique(Controleur::getControleur(true).getPiocheTactique()->piocherCarteTactique());
            cout <<"Carte piochee : "<< ct11->getNom() << endl;
            CarteTactique* ct12 = new CarteTactique(Controleur::getControleur(true).getPiocheTactique()->piocherCarteTactique());
            cout <<"Carte piochee : "<< ct12->getNom() << endl;
            Controleur::getControleur(false).getPlateau()->getJoueur1()->getMain()->ajouterCarte(c11);
            Controleur::getControleur(true).getPlateau()->getJoueur1()->getMain()->ajouterCarte(ct11);
            Controleur::getControleur(true).getPlateau()->getJoueur1()->getMain()->ajouterCarte(ct12);

            break;}
        case 2: {
            CarteClan *c21 = new CarteClan(Controleur::getControleur(false).getPiocheClan()->piocherCarteClan());
            Controleur::getControleur(false).getPlateau()->getJoueur1()->getMain()->ajouterCarte(c21);
            cout << "Carte piochee : " << c21->getPuissance() << " " << c21->getCouleur() << endl;
            CarteClan *c22 = new CarteClan(Controleur::getControleur(false).getPiocheClan()->piocherCarteClan());
            Controleur::getControleur(false).getPlateau()->getJoueur1()->getMain()->ajouterCarte(c22);
            cout << "Carte piochee : " << c22->getPuissance() << " " << c22->getCouleur() << endl;
            CarteTactique *ct21 = new CarteTactique(Controleur::getControleur(true).getPiocheTactique()->piocherCarteTactique());
            cout << "Carte piochee : " << ct21->getNom() << endl;
            Controleur::getControleur(false).getPlateau()->getJoueur1()->getMain()->ajouterCarte(c21);
            Controleur::getControleur(false).getPlateau()->getJoueur1()->getMain()->ajouterCarte(c22);
            Controleur::getControleur(true).getPlateau()->getJoueur1()->getMain()->ajouterCarte(ct21);

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

void CarteRuse::Jouer_Stratege() {
    cout << "Vous avez joue la carte Stratege" << endl;
    cout << "Voici toutes vos bornes : " << endl;
    Controleur::getControleur(false).Afficher_Borne1();
    cout << "Veuillez choisir une borne non revendiquee appartenant a vous " << endl;
    int choix_borne, choix_carte;
    cin >> choix_borne;
    while (Controleur::getControleur(true).getPlateau()->getBornes(
            choix_borne)->getCartesJ1()->getCartes().empty()) {
        cout << "Vous n'avez pas de cartes sur cette borne, veuillez en choisir une autre : " << endl;
        cin >> choix_borne;
    }
    auto cartesBornes = Controleur::getControleur(true).getPlateau()->getBornes(
            choix_borne)->getCartesJ1()->getCartes();
    for (int i = 0; i < cartesBornes.size(); i++) {
        cout << "id :" << i << " " << cartesBornes[i]->getCouleur() << " " << cartesBornes[i]->getPuissance()
             << endl;
    }
    cout << "Quelle carte souhaitee vous retirer de la borne "<< choix_borne << "?" << endl;
    cin >> choix_carte;
    while (choix_carte > cartesBornes.size() - 1 || choix_carte < 0) {
        cout << "Vous n'avez pas de cartes sur cette borne, veuillez en choisir une autre : " << endl;
        cin >> choix_carte;
    }
    auto carte_choisie = Controleur::getControleur(true).getPlateau()->getBornes(
            choix_borne)->getCartesJ1()->getCartes()[choix_carte];
    cout << "Vous avez choisi la carte : " << carte_choisie->getCouleur() << " " << carte_choisie->getPuissance()
         << endl;
    Controleur::getControleur(true).getPlateau()->getBornes(choix_borne)->getCartesJ1()->supprimerCarte_Borne(
            choix_carte);
    cout << "Voulez vous vous defausser de la carte ou bien la poser sur une autre borne ? " << endl;
    cout << "1 : Defausser la carte" << endl;
    cout << "2 : Poser la carte sur une autre borne" << endl;
    int choix;
    cin >> choix;
    if (choix == 2) {
    cout << "Sur quelle borne non revendiquee voulez vous placer votre carte ? " << endl;
    cin >> choix_borne;
    while(Controleur::getControleur(true).getPlateau()->getBornes(choix_borne)->getRevendique()!=0){
        cout << "Vous ne pouvez pas poser de carte sur cette borne, veuillez en choisir une autre : " << endl;
        cin >> choix_borne;
    }
    Controleur::getControleur(true).getPlateau()->getBornes(choix_borne)->getCartesJ1()->ajouterCarte(carte_choisie);
}
    else{
        cout << "Vous avez defausse la carte "<< carte_choisie->getCouleur() << " " << carte_choisie->getPuissance()<< endl;
        delete carte_choisie;
    }
    cout << "Voici vos bornes apres avoir joué la carte Stratege : " << endl;
    Controleur::getControleur(true).Afficher_Borne1();
}


void CarteRuse::Jouer_Traitre() {
    cout << "Vous avez joue la carte Traitre" << endl;
    cout << "Voici les bornes de l'adversaire bornes : " << endl;
    Controleur::getControleur(false).Afficher_Borne2();
    cout << "Veuillez choisir une borne non revendiquee appartenant a l'adversaire " << endl;
    int choix_borne, choix_carte;
    cin >> choix_borne;
    while (Controleur::getControleur(true).getPlateau()->getBornes(
            choix_borne)->getCartesJ2()->getCartes().empty()) {
        cout << "L'adversaire  n'a pas de cartes sur cette borne, veuillez en choisir une autre : " << endl;
        cin >> choix_borne;
    }
    auto cartesBornes = Controleur::getControleur(true).getPlateau()->getBornes(
            choix_borne)->getCartesJ2()->getCartes();
    for (int i = 0; i < cartesBornes.size(); i++) {
        cout << "id :" << i << " " << cartesBornes[i]->getCouleur() << " " << cartesBornes[i]->getPuissance()
             << endl;
    }
    cout << "Quelle carte souhaitee vous retirer de la borne "<< choix_borne << "?" << endl;
    cin >> choix_carte;
    while (choix_carte > cartesBornes.size() - 1 || choix_carte < 0) {
        cout << "Vous ne pouvez pas selectionner cette carte, veuillez en choisir une autre : " << endl;
        cin >> choix_carte;
    }
    auto carte_choisie = Controleur::getControleur(true).getPlateau()->getBornes(
            choix_borne)->getCartesJ2()->getCartes()[choix_carte];
    cout << "Vous avez choisi la carte : " << carte_choisie->getCouleur() << " " << carte_choisie->getPuissance()
         << endl;
    Controleur::getControleur(true).getPlateau()->getBornes(choix_borne)->getCartesJ2()->supprimerCarte_Borne(
            choix_carte);
    cout << "Sur quelle borne non revendiquee voulez vous placer votre carte ? " << endl;
    cin >> choix_borne;
    while(Controleur::getControleur(true).getPlateau()->getBornes(choix_borne)->getRevendique()!=0){
        cout << "Vous ne pouvez pas poser de carte sur cette borne, veuillez en choisir une autre : " << endl;
        cin >> choix_borne;
    }
    Controleur::getControleur(true).getPlateau()->getBornes(choix_borne)->getCartesJ1()->ajouterCarte(carte_choisie);
    cout << "Voici vos bornes apres avoir joué la carte Traitre : " << endl;
    Controleur::getControleur(true).Afficher_Borne1();
}

void CarteRuse::Jouer_Banshee() {
    cout << "Vous avez joue la carte Banshee" << endl;
    cout << "Voici les bornes de l'adversaire bornes : " << endl;
    Controleur::getControleur(false).Afficher_Borne2();
    cout << "Veuillez choisir une borne non revendiquee appartenant a l'adversaire " << endl;
    int choix_borne, choix_carte;
    cin >> choix_borne;
    while (Controleur::getControleur(true).getPlateau()->getBornes(
            choix_borne)->getCartesJ2()->getCartes().empty()) {
        cout << "L'adversaire  n'a pas de cartes sur cette borne, veuillez en choisir une autre : " << endl;
        cin >> choix_borne;
    }
    auto cartesBornes = Controleur::getControleur(true).getPlateau()->getBornes(
            choix_borne)->getCartesJ2()->getCartes();
    for (int i = 0; i < cartesBornes.size(); i++) {
        cout << "id :" << i << " " << cartesBornes[i]->getCouleur() << " " << cartesBornes[i]->getPuissance()
             << endl;
    }
    cout << "Quelle carte souhaitee vous retirer de la borne "<< choix_borne << "?" << endl;
    cin >> choix_carte;
    while (choix_carte > cartesBornes.size() - 1 || choix_carte < 0) {
        cout << "Vous ne pouvez pas selectionner cette carte, veuillez en choisir une autre : " << endl;
        cin >> choix_carte;
    }
    auto carte_choisie = Controleur::getControleur(true).getPlateau()->getBornes(
            choix_borne)->getCartesJ2()->getCartes()[choix_carte];
    cout << "Vous avez choisi la carte : " << carte_choisie->getCouleur() << " " << carte_choisie->getPuissance()
         << endl;
    Controleur::getControleur(true).getPlateau()->getBornes(choix_borne)->getCartesJ2()->supprimerCarte_Borne(
            choix_carte);
    cout << "Voici les bornes de l'adversaire  apres avoir joué la carte Banshee : " << endl;
    Controleur::getControleur(true).Afficher_Borne2();
}
