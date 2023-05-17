//
// Created by Utilisateur on 26/04/2023.
//

#include "Plateau.h"

void Plateau::poser(Borne borne, CarteClan* carte){
    if(m_joueur_actif == 1){
        

        int fcombi = borne.m_cartesj1->getForceCombi();
        //std::cout << "Force combi : " << fcombi << std::endl;
        borne.m_cartesj1->setTotalPuissance(borne.m_cartesj1->getForceCombi() + static_cast<int>(carte->getPuissance()));
        borne.m_cartesj1->ajouterCarte(carte);
        // TODO : ajouter une fonction retirer carte avec cette cate dans la main du joueur
    }
    else{
        int fcombi = borne.m_cartesj2->getForceCombi();
        //std::cout << "Force combi : " << fcombi << std::endl;
        borne.m_cartesj2->setTotalPuissance(borne.m_cartesj1->getForceCombi() + static_cast<int>(carte->getPuissance()));
        borne.m_cartesj2->ajouterCarte(carte);
        // TODO : ajouter une fonction retirer carte avec cette cate dans la main du joueur
    }
}

void Plateau::afficherMainJoueur(int joueur) {
    Joueur* joueurcourant= (joueur==1) ? m_joueur1 : m_joueur2;
    vector<Carte*> main = joueurcourant->getMain()->getCartes();

    cout << "Main du joueur " << joueur << ":\n";
    int i=0;
    for (const auto& carte : main) {
        if (CarteClan* carteClan = dynamic_cast<CarteClan*>(carte)) {
            cout <<"Id : "<<i<<  "| " << carteClan->getPuissance() << " " << carteClan->getCouleur() << " |";
            i++;
        } else if (CarteTactique* carteTactique = dynamic_cast<CarteTactique*>(carte)) {
            cout <<"Id : "<< i<< "| " << carteTactique->getNom() << " |";
            i++;
        }
    }
    cout << endl;
}

void Plateau::afficherDosMain(int joueur) {
    Joueur* joueurcourant= (joueur==1) ? m_joueur1 : m_joueur2;
    vector<Carte*> main = joueurcourant->getMain()->getCartes();

    cout << "Main du joueur " << joueur << ":\n";
    for (const auto& carte : main) {
        if (CarteClan* carteClan = dynamic_cast<CarteClan*>(carte)) {
            cout << "| clan |";
        } else if (CarteTactique* carteTactique = dynamic_cast<CarteTactique*>(carte)) {
            cout << "| tactique |";
        }
    }
}