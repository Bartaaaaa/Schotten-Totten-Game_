//
// Created by Utilisateur on 26/04/2023.
//

#include "Controleur.h"

Controleur::Controleur()
{
    m_pioche_clan = new Pioche();
    m_pioche_tactique = new Pioche();
    m_plateau = new Plateau(6, false, false);
}

Controleur::~Controleur()
{
    delete m_pioche_clan;
    delete m_pioche_tactique;
    delete m_plateau;
}
