//
// Created by Utilisateur on 26/04/2023.
//

#include "Controleur.h"

Controleur::Controleur(bool tactique): m_tactique(tactique), m_gagnant(0)
{
    m_pioche_clan = new Pioche(m_jeu_clan);
    if(tactique){
        m_pioche_tactique = new Pioche(m_jeu_tactique);
        printf("tactique\n");
        m_plateau = new Plateau(7, false, false);
    }
    else{
        m_plateau = new Plateau(6, false, false);
        printf("classique\n");
    }
}

Controleur::~Controleur()
{
    delete m_pioche_clan;
    delete m_pioche_tactique;
    delete m_plateau;
}

Controleur& Controleur::getControleur(bool tactique)
{
    if (handler.controleur == nullptr)
        handler.controleur = new Controleur(tactique);
    return *handler.controleur;
}

void Controleur::libererControleur()
{
    delete handler.controleur;
    handler.controleur =nullptr;
}

Controleur::Handler Controleur::handler = Handler();
/*
void Controleur::JouerTour(){

    cout << "Voici votre main :" << endl;
    //m_plateau->m_joueur1->getMain()->afficher();
    cout<<"Veuillez choisir la carte que vous voulez jouer"<<endl;
    int choix_carte, nb_tac=0,nb_clan=0,nb_total=0;
    cin>>choix_carte;
    vector<Carte*> cartes = m_plateau->m_joueur1->getMain()->getCartes();
    Carte* carte = cartes[choix_carte];
    if ( carte  = dynamic_cast<CarteTactique *>(carte)) {
        for (auto carte: cartes) {
            if (carte = dynamic_cast<CarteTactique *>(carte)) {
                nb_tac++;
                nb_total++;
            }}
            if (nb_tac==0){
                cout << "Vous n'avez plus de cartes tactiques !" << endl;
                return;
            }
        }
    else {
        if (carte = dynamic_cast<CarteClan *>(carte)) {
            for (auto carte: cartes) {
                if (carte = dynamic_cast<CarteClan *>(carte)) {
                    nb_clan++;
                    nb_total++;
                }}
            if (nb_clan==0){
                cout << "Vous n'avez plus de cartes clans !" << endl;
                return;
            }
            if (nb_total ==0 ){
                cout << "Vous n'avez plus de cartes !" << endl;
                return; exit(0);
            }
        }
    }

    cout<<"Veuillez choisir la borne sur laquelle vous voulez jouer"<<endl;
    int choix_borne;
    cin>>choix_borne;


    if (CarteClan* carte_clan = dynamic_cast<CarteClan*>(carte)) {
        m_plateau->poser(*(m_plateau->getBornes(choix_borne)), carte_clan);
    } else if (CarteTactique* carte_tactique = dynamic_cast<CarteTactique*>(carte)) {
        m_plateau->poser(*(m_plateau->getBornes(choix_borne)), carte_tactique);
    }

    //m_plateau->m_joueur1->getMain().retirerCarte(choix_carte);
    cout << "Voulez vous revendiquer la borne ? 1 pour oui, 0 pour non" << endl;
    int choix_revendication;
    cin >> choix_revendication;

    if(choix_revendication==1){
        cout << "Veuillez choisir la borne que vous voulez revendiquer" << endl;
        int choix_borne;
        cin >> choix_borne;
        while (m_plateau->m_bornes[choix_borne]->getRevendique()==2 || m_plateau->m_bornes[choix_borne]->getRevendique()==1) {
            cout << "La borne a déjà été revendiquée, veuillez choisir une autre borne" << endl;
            cin>> choix_borne;
            return;
        }
    }
    cout << "Veuillez choisir si vous voulez choisir une carte tactique ou normale :, 1 pour normale et n'importe qu'elle autre touche pour tactique" << endl;
    int choix_style;
    cin >> choix_style;
    if(choix_style==1){
        if (!m_plateau->Pioche->estVide())
        m_plateau->m_joueur1->piocher(m_pioche_clan);
    }
    else{
        if (!Pioche::estVide())
        m_plateau->m_joueur1->piocher(m_pioche_tactique);
    }
    m_plateau->m_joueur1->setMain();

} */

bool Controleur::check_fin_partie() {
    int sum1=0;
    int serie1=0;
    int sum2=0;
    int serie2=0;
    for(auto i=0; i<9; i++){
        int j = m_plateau->m_bornes[i]->getRevendique();
        //printf("test");
        if(j==1){
            sum1++;
            serie1++;
            //printf("test1");
            if(serie1==3){
                m_gagnant=1;
                //printf("test3");
                return true;
            }
            serie2=0;
        }
        else if(j==2){
            sum2++;
            serie2++;
            //printf("test2");
            if(serie2==3){
                m_gagnant=2;
                return true;
            }
            serie1=0;
        }
    }
    return false;
}

