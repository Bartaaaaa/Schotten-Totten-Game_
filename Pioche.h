//
// Created by Utilisateur on 23/04/2023.
//

#ifndef LO21_SCHOTTEN_TOTTEN_PIOCHE_H
#define LO21_SCHOTTEN_TOTTEN_PIOCHE_H

#include "JeuClan.h"
#include "JeuTactique.h"
#include <cstddef>

class Pioche
{
    const Carte** cartes;
    size_t m_nb;

public:
    Pioche(const JeuClan& jeuClan);
    Pioche(const JeuTactique& jeuTactique);

    bool estVide() const { return m_nb==0; }
    size_t getNbCartes() const { return m_nb; }
    const Carte& piocher();
    ~Pioche();

    Pioche(const Pioche&) = delete;
    Pioche& operator=(const Pioche&) = delete;
};


#endif //LO21_SCHOTTEN_TOTTEN_PIOCHE_H
