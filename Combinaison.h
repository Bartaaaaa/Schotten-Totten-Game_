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
    bool m_boue, m_collin;

public :
    Combinaison(vector<CarteClan*> cartes, int force_combi, int total_puissance):
            m_cartes(cartes), m_force_combi(force_combi), m_total_puissance(total_puissance), m_collin(false), m_boue(false){}
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
/*
    void setForceCombi(int force_combi) {
		m_force_combi = force_combi;
	}
*/
    void setTotalPuissance(int total_puissance){
        m_total_puissance = total_puissance;

    }

    bool getBoue() const {
		return m_boue;
	}

    void setBoue(bool boue) {
		m_boue = boue;
	}

    bool getCollin(){
        return m_collin;
    }

    void setCollin(bool collin) {
        m_collin = collin;
    }

    int calculerForceCombi(bool affichage = false);

    void ajouterCarte( CarteClan* carte) {
        if (m_boue) {
            if (m_cartes.size() == 4)
                throw std::invalid_argument("Vous ne pouvez pas ajouter plus de 4 cartes dans une combinaison");
            else
            {
                m_cartes.push_back(carte);
                setTotalPuissance(getTotalPuissance() + static_cast<int>(carte->getPuissance()));
            }
        }
        else
        {
            if (m_cartes.size() == 3)
                throw std::invalid_argument("Vous ne pouvez pas ajouter plus de 3 cartes dans une combinaison sans combat de boue");
            else
            {
                m_cartes.push_back(carte);
                setTotalPuissance(getTotalPuissance() + static_cast<int>(carte->getPuissance()));
            }
        }
        if (m_collin)
            m_force_combi = 0;
        else
            m_force_combi = calculerForceCombi();
    }


};

#endif //LO21_SCHOTTEN_TOTTEN_COMBINAISON_H
