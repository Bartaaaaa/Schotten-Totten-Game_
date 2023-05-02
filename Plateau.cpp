//
// Created by Utilisateur on 26/04/2023.
//

#include "Plateau.h"

void Plateau::poser(Borne borne, CarteClan* carte){
    if(m_joueur_actif == 1){
        
        borne.m_cartesj1->ajouterCarte(carte);
        // TO DO : ajouter une fonction retirer carte avec cette cate dans la main du joueur
    }
    else{
        borne.m_cartesj2->ajouterCarte(carte);
        // TO DO : ajouter une fonction retirer carte avec cette cate dans la main du joueur
    }
}