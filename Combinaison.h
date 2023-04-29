//
// Created by Grzadziel Bartlomiej on 24/04/2023.
//

#ifndef LO21_SCHOTTEN_TOTTEN_COMBINAISON_H
#define LO21_SCHOTTEN_TOTTEN_COMBINAISON_H
#include "CarteClan.h"
#include<iostream>
#include<string>
#include <vector>

class Combinaison{
    vector<CarteClan*> m_cartes;
    int m_force_combi;
    int m_total_puissance;
public :
    Combinaison(vector<CarteClan*> cartes, int force_combi, int total_puissance):
            m_cartes(cartes), m_force_combi(force_combi), m_total_puissance(total_puissance){}
    Combinaison() = default; //on a besoin d'un constructeur sans arguments sinon on peut pas créer mcartes_j1 dans borne, à moins qu'on les créer autrepart.

    vector<CarteClan*> getCartes(){
        return m_cartes;
    }
    int getForceCombi() const{
        return m_force_combi;
    }
    int getTotalPuissance() const{
        return m_total_puissance;
    }

    void setForceCombi(int force_combi) {
		m_force_combi = force_combi;
	}

    void setTotalPuissance(int total_puissance){
        m_total_puissance = total_puissance;
    }

    int calculerForceCombi();// TO DO; Pb : si'il y a une Troupe d'élite, est-ce que cette fonction fige sa valeur et sa couleur sachant qu'il y a un risque de combat de Boue qui change la donne ? (en vrai ca sera rarement(ou jamais) le cas pour la Couleur mais pour la puissance c'est vraiment possible)

    void ajouterCarte(CarteClan* carte) {
        m_cartes.push_back(carte);
        setTotalPuissance(getTotalPuissance() + (int)carte->getPuissance());
        // TO DO : ajouter une appel a calculerForceCombi qi il y a 3 cartes ou plus dans la combinaison 
    }


};

#endif //LO21_SCHOTTEN_TOTTEN_COMBINAISON_H
