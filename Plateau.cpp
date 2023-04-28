//
// Created by Utilisateur on 26/04/2023.
//

#include "Plateau.h"

void Plateau::poser(int borne, int carte){
    if(m_joueur_actif == 1){
        vector<Carte> v = m_joueur1->getMain().getCartes();
        Carte c = v.at(carte);
        m_bornes[borne+1].m_cartesj1->ajouterCarte(&c);
        v.erase(v.begin()+carte);
    }
    else{
        vector<Carte> v = m_joueur2->getMain().getCartes();
        Carte c = v.at(carte);
        m_bornes[borne+1].m_cartesj2->ajouterCarte(&c);
        v.erase(v.begin()+carte);
    }
}