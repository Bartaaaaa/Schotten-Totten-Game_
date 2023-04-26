//
// Created by Utilisateur on 26/04/2023.
//

#ifndef LO21_SCHOTTEN_TOTTEN_MAIN_JOUEUR_H
#define LO21_SCHOTTEN_TOTTEN_MAIN_JOUEUR_H
#include "Carte.h"
#include<iostream>
#include<string>
#include <vector>


class Main {
    int m_taille;
    vector<Carte> m_cartes;
    bool m_joker;
    int m_nbr_carte_tactique_joue;
public:
    friend class Joueur;

    explicit Main(int taille) : m_taille(taille), m_joker(false), m_nbr_carte_tactique_joue(0) {};

    int getTaille() const {
        return m_taille;
    }

    vector<Carte> getCartes() const {
        return m_cartes;
    }

    bool getJoker() const {
        return m_joker;
    }

    int getNbrCarteTactiqueJoue() const {
        return m_nbr_carte_tactique_joue;
    }


};

#endif //LO21_SCHOTTEN_TOTTEN_MAIN_JOUEUR_H
