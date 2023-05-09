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