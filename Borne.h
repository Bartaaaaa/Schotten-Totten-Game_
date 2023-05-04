//
// Created by Utilisateur on 24/04/2023.
//

#ifndef LO21_SCHOTTEN_TOTTEN_BORNE_H
#define LO21_SCHOTTEN_TOTTEN_BORNE_H
#include "Combinaison.h"

class Borne{
    int m_num;
    bool m_collin;
    bool m_boue;
    int m_revendique;
    Combinaison *m_cartesj1;
    Combinaison *m_cartesj2;
    int m_dernier_pose;

public :
    friend class Plateau;

    explicit Borne(int num, bool collin=false, bool boue=false):
            m_num(num), m_collin(collin), m_boue(boue), m_revendique(0), m_dernier_pose(0){
        //printf("Borne %d cree\n", m_num);
        m_cartesj1 = new Combinaison();
        m_cartesj2 = new Combinaison();
    }
    int getNum() const {
        return m_num;
    }
    bool getCollin() const{
        return m_collin;
    }
    bool getBoue() const{
        return m_boue;
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
        m_collin = collin;
    }
    void setBoue(bool boue){
        m_boue = boue;
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
    void ajout_carte_j1(CarteClan* carte){
        m_cartesj1->ajouterCarte(carte);
    }
};





#endif //LO21_SCHOTTEN_TOTTEN_BORNE_H
