//
// Created by Grzadziel Bartlomiej on 24/04/2023.
//

#include "Combinaison.h"

int Combinaison::calculerForceCombi()// MARCHE PAS !!!!! Ne fonctioone qu'en version classique, j'attends que les fonctions pour les modes de combat soient là 
{
    int pmin, pmil, pmax;
    pmin = min({ static_cast<int>(m_cartes[0]->getPuissance()),static_cast<int>(m_cartes[1]->getPuissance()), static_cast<int>(m_cartes[0]->getPuissance()) });
    pmax = max({ static_cast<int>(m_cartes[0]->getPuissance()),static_cast<int>(m_cartes[1]->getPuissance()), static_cast<int>(m_cartes[0]->getPuissance()) });
    pmil = static_cast<int>(m_cartes[0]->getPuissance()) + static_cast<int>(m_cartes[1]->getPuissance()) + static_cast<int>(m_cartes[2]->getPuissance()) - pmin - pmax;
    Couleur c1(m_cartes[0]->getCouleur()), c2(m_cartes[1]->getCouleur()), c3(m_cartes[2]->getCouleur());
    if (c1 == c2 && c2 == c3 && pmin +1 == pmil && pmil + 1 == pmax)
        return 4;
    if (pmin == pmil && pmil == pmax)
        return 3;
    if (c1 == c2 && c2 == c3)
        return 2;
    if (pmin +1 == pmil && pmil + 1 == pmax)
        return 1;
    return 0;
}
