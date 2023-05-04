//
// Created by Utilisateur on 26/04/2023.
//

#include "Controleur.h"

Controleur::Controleur(bool tactique): m_tactique(tactique), m_gagnant(0)
{
    m_pioche_clan = new Pioche(m_jeu_clan);
    m_pioche_tactique = new Pioche(m_jeu_tactique);
    printf("test");
    m_plateau = new Plateau(6, false, false);
    printf("test2");
}

Controleur::~Controleur()
{
    delete m_pioche_clan;
    delete m_pioche_tactique;
    delete m_plateau;
}
/*
void Controleur::JouerTour(){
    cout << "Voulez vous revendiquer la borne ? 1 pour oui, 0 pour non" << endl;
    int choix_revendication;
    cin >> choix_revendication;

    if(choix_revendication==1){
        cout << "Veuillez choisir la borne que vous voulez revendiquer" << endl;
        int choix_borne;
        cin >> choix_borne;
        // TODO : Vérifie si la borne a déjà été revendiquée ou pas
       // m_plateau->revendiquer(choix_borne);
    }
    cout<<"Veuillez choisir la carte que vous voulez jouer"<<endl;
    int choix_carte;
    cin>>choix_carte;
    Carte * carte = choix_carte;
    if (m_plateau.m_joueur_actif->getMain().getCarte(choix_carte)->estTactique()) {
        if (!m_plateau.m_joueur_actif->getMain().possedeCarteTactique()) {
            cout << "Vous n'avez plus de cartes tactiques !" << endl;
            return;
        }
    } else {
        if (!m_plateau.m_joueur_actif->getMain().possedeCarte()) {
            cout << "Vous n'avez plus de cartes normales !" << endl;
            return;
        }
    }
    // TODO : je veux que le if verifie si la carte est tactique ou pas
    if (choix_carte) {
    CarteClan* carte = m_plateau->m_joueur_actif->getMain().getCarte(choix_carte);}
    else {
        CarteTactique * carte = m_plateau->m_joueur_actif->getMain().getCarte(choix_carte);
    }
    cout<<"Veuillez choisir la borne sur laquelle vous voulez jouer"<<endl;
    int choix_borne;
    cin>>choix_borne;
    // TODO : Vérifie si la borne a été revendiquée ou pas
    Borne borne = m_plateau->m_bornes[choix_borne];
        m_plateau->poser(borne, carte);
    m_plateau->m_joueur_actif->getMain().retirerCarte(choix_carte);
    cout << "Veuillez choisir si vous voulez choisir une carte tactique ou normale :, 1 pour normale et n'importe qu'elle autre touche pour tactique" << endl;
    int choix_style;
    cin >> choix_style;
    if(choix_style==1){
        if (!Pioche::estVide())
        m_plateau->m_joueur_actif->piocher(m_pioche_clan);
    }
    else{
        if (!Pioche::estVide())
        m_plateau->m_joueur_actif->piocher(m_pioche_tactique);
    }
    m_plateau->m_joueur_actif->setMain();

}
*/
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
