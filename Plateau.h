//
// Created by Utilisateur on 26/04/2023.
//

#ifndef LO21_SCHOTTEN_TOTTEN_PLATEAU_H
#define LO21_SCHOTTEN_TOTTEN_PLATEAU_H

#include "Joueur.h"
#include "Carte.h"
#include "Borne.h"

class Plateau {
    Joueur *m_joueur1; // Ou de type Joueur ?
    Joueur *m_joueur2;
    int m_joueur_actif;
    vector<Carte> m_defausse;
    Borne m_bornes[9] = {Borne(1), Borne(2), Borne(3), Borne(4), Borne(5), Borne(6), Borne(7), Borne(8), Borne(9)};
public:
    Plateau(int taille, bool ia1, bool ia2) : m_joueur1(nullptr), m_joueur2(nullptr), m_joueur_actif(1){
        m_joueur1 = new Joueur(taille, ia1);
        m_joueur2 = new Joueur(taille, ia2);
    };

    Joueur getJoueur1() const {
        return *m_joueur1;
    }

    Joueur getJoueur2() const {
        return *m_joueur2;
    }

    int getJoueurActif() const {
        return m_joueur_actif;
    }

    vector<Carte> getDefausse() const {
        return m_defausse;
    }

    const Borne* getBornes() const {
        return m_bornes;
    }

    void setJoueurActif(int joueurActif) {
        m_joueur_actif = joueurActif;
    }

    void poser(int borne, int carte);

    Plateau(const Plateau&) = delete;
    Plateau& operator=(const Plateau&) = delete;
};

#endif //LO21_SCHOTTEN_TOTTEN_PLATEAU_H
