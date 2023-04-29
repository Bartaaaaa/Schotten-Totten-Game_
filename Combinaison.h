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
    vector<Carte*> m_cartes;
    int m_force_combi;
    int m_total_puissance;
public :
    Combinaison(vector<Carte*> cartes, int force_combi, int total_puissance):
            m_cartes(cartes), m_force_combi(force_combi), m_total_puissance(total_puissance){}
    Combinaison() = default; //on a besoin d'un constructeur sans arguments sinon on peut pas créer mcartes_j1 dans borne, à moins qu'on les créer autrepart.

    vector<Carte*> getCartes(){
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


    void ajouterCarte(CarteClan* carte){
        m_cartes.push_back(carte);
        setTotalPuissance(getTotalPuissance() + (int) carte->getPuissance());
    }


};

#endif //LO21_SCHOTTEN_TOTTEN_COMBINAISON_H
