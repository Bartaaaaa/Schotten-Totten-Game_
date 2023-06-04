//
// Created by Utilisateur on 19/04/2023.
//

#ifndef LO21_SCHOTTEN_TOTTEN_CARTEMODECOMBAT_H
#define LO21_SCHOTTEN_TOTTEN_CARTEMODECOMBAT_H
#include "CarteTactique.h"
#include "Borne.h"

class CarteModeCombat : public CarteTactique {
public:
    CarteModeCombat(const string& nom) : CarteTactique(nom)  {};
    

    void jouer_ColinMaillard(Borne b) const {
        b.setCollin(true);
	}
    void jouer_CombatdeBoue(Borne b) const {
        b.setBoue(true);
    }

    void afficherCarte()const override{
        if(getNom()=="Colin Maillard"){
            cout<< "| Col Mail |";
        }
        else if(getNom()=="Combat de Boue"){
            cout<< "| Cbt Boue |";
        }
    }

    void afficherDosCarte()const override {
        cout << "| Tactique |";
    }
		
};
#endif //LO21_SCHOTTEN_TOTTEN_CARTEMODECOMBAT_H
