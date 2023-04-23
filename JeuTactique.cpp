//
// Created by Utilisateur on 23/04/2023.
//

#include "JeuTactique.h"



JeuTactique::JeuTactique()
{
    size_t i = 0;
    /*
    cartes[i++]= new CarteTroupeElite("Joker", 1, 1);
    cartes[i++]= new CarteTroupeElite("Joker", 1, 1);
    cartes[i++]= new CarteTroupeElite("Espion", 7, 1);
    cartes[i++]= new CarteTroupeElite("Porte_Bouclier", 1, 1);
    */
    cartes[i++]= new CarteModeCombat("Colin Maillard");
    cartes[i++]= new CarteModeCombat("Combat de Boue");

    cartes[i++]= new CarteRuse("Chasseur de Tete");
    cartes[i++]= new CarteRuse("Stratege");
    cartes[i++]= new CarteRuse("Banshee");
    cartes[i++]= new CarteRuse("Traitre");

}


JeuTactique::~JeuTactique()
{
    for (size_t i = 0; i < getNbCartes(); i++)
        delete cartes[i];
}

JeuTactique & JeuTactique::getJeuTactique()
{
    if (handler.jeu == nullptr)
        handler.jeu = new JeuTactique;
    return *handler.jeu;
}

void JeuTactique::libererJeuTactique()
{
    delete handler.jeu;
    handler.jeu =nullptr;
}

JeuTactique::Handler JeuTactique::handler = Handler();