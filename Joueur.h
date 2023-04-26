//
// Created by Utilisateur on 26/04/2023.
//

#ifndef LO21_SCHOTTEN_TOTTEN_JOUEUR_H
#define LO21_SCHOTTEN_TOTTEN_JOUEUR_H
#include "Main_Joueur.h"

class Joueur {
    Main *m_main;
    bool m_ia;
public:
    explicit Joueur(int taille, bool ia) :m_main(nullptr), m_ia(ia) {
        m_main = new Main(taille);
    };

    Main getMain() const {
        return *m_main;
    }

    bool getIa() const {
        return m_ia;
    }

    Joueur(const Joueur&) = default;
    Joueur& operator=(const Joueur&) = delete;
};
#endif //LO21_SCHOTTEN_TOTTEN_JOUEUR_H
