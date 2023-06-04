//
// Created by Utilisateur on 24/04/2023.
//

#ifndef LO21_SCHOTTEN_TOTTEN_BORNE_H
#define LO21_SCHOTTEN_TOTTEN_BORNE_H
#include "Combinaison.h"

class Borne{
    int m_num;
    int m_revendique;
    Combinaison *m_cartesj1;
    Combinaison *m_cartesj2;
    int m_dernier_pose;

public :
    friend class Plateau;

    explicit Borne(int num, bool collin=false, bool boue=false):
            m_num(num), m_revendique(0), m_dernier_pose(0){
        //printf("Borne %d cree\n", m_num);
        m_cartesj1 = new Combinaison();
        m_cartesj2 = new Combinaison();
    }
    int getNum() const {
        return m_num;
    }
    
    Combinaison* getCartesJ1() const{
        return m_cartesj1;
    }
    Combinaison* getCartesJ2() const{
        return m_cartesj2;
    }

    int getRevendique() const{
        return m_revendique;
    }
    int getDernierPose() const{
        return m_dernier_pose;
    }
    void setNum(int num){
        m_num = num;
    }
    void setCollin(bool collin){
        m_cartesj1[0].setCollin(collin);
        m_cartesj2[0].setCollin(collin);
    }
    void setBoue(bool boue){
        m_cartesj1[0].setBoue(boue);
        m_cartesj2[0].setBoue(boue);
    }
    void setRevendique(int revendique) {
        m_revendique = revendique;
    }
    void setDernierPose(int dernier_pose) {
        m_dernier_pose = dernier_pose;
    }

    /*Todo faire ces methodes ?
    set_cartesj1(in add : bool, in carte : CarteClan, in cote : int) : void
    set_cartesj2(in add : bool, in carte : CarteClan, in cote : int) : void
    check_exception(???) : ???
     */
    void ajouter_carte(CarteClan* carte){
        Controleur& c = Controleur::getControleur(true);
        if (c.getPlateau()->getJoueurActif() == 1) {
			m_cartesj1->ajouterCarte(carte);
            if (m_cartesj1->getBoue() == true)
                if (m_cartesj1->getCartes().size() == 4) {
                    m_cartesj1->setPremierComplet(1);
                    m_cartesj2->setPremierComplet(1);
                }
            else {
                    if (m_cartesj1->getCartes().size() == 3) {
                        m_cartesj1->setPremierComplet(1);
                        m_cartesj2->setPremierComplet(1);
                    }
                }
		}
        else {
			m_cartesj2->ajouterCarte(carte);
            if (m_cartesj1->getBoue())
                if (m_cartesj1->getPremierComplet() == 0)
                    if (m_cartesj1->getCartes().size() == 4) {
                        m_cartesj1->setPremierComplet(2);
                        m_cartesj2->setPremierComplet(2);
                    }
                else {
                        if (m_cartesj1->getPremierComplet() == 0)
                            if (m_cartesj1->getCartes().size() == 3) {
                                m_cartesj1->setPremierComplet(2);
                                m_cartesj2->setPremierComplet(2);
                            }
                }
		}
        
    }
};





#endif //LO21_SCHOTTEN_TOTTEN_BORNE_H
