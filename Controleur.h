//
// Created by Utilisateur on 26/04/2023.
//

#ifndef LO21_SCHOTTEN_TOTTEN_CONTROLEUR_H
#define LO21_SCHOTTEN_TOTTEN_CONTROLEUR_H
#include "Plateau.h"
#include "Pioche.h"

class Controleur {
    int m_gagnant;
    bool m_tactique;
    Pioche* m_pioche_clan;
    Pioche* m_pioche_tactique;
    Plateau* m_plateau;
    JeuClan m_jeu_clan;
    JeuTactique m_jeu_tactique;

public:

    Controleur();

    ~Controleur();


    const Plateau& getPlateau() const { return *m_plateau; }
};
#endif //LO21_SCHOTTEN_TOTTEN_CONTROLEUR_H
