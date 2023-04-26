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
    Borne(int num, bool collin=false, bool boue=false, int revendique=0, int dernier_pose=0):
            m_num(num), m_collin(collin), m_boue(boue), m_revendique(revendique), m_dernier_pose(dernier_pose){
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
    void setRevendique(int revendique){
        m_revendique = revendique;
    }
    void setDernierPose(int dernier_pose){
        m_dernier_pose = dernier_pose;
    }
};





#endif //LO21_SCHOTTEN_TOTTEN_BORNE_H
