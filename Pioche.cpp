//
// Created by Utilisateur on 23/04/2023.
//

#include "Pioche.h"
#include "CarteException.h"

    Pioche::Pioche(const JeuClan& jeuClan) : m_cartes(new const Carte*[jeuClan.getNbCartes()]), m_nb(jeuClan.getNbCartes())
    {
        size_t i=0;
        for(auto it = jeuClan.getIterator(); !it.isDone(); it.next())
            m_cartes[i++] = &it.currentItem();


        // shuffle (très naif)
        for(size_t it=0; it<2*m_nb ; ++it){
            size_t a = rand() % m_nb,  b = rand() % m_nb; // on tire deux positions entre 0 et nb
            const Carte * tmp = m_cartes[a];
            m_cartes[a]=m_cartes[b];
            m_cartes[b]=tmp;
        }
    }

    Pioche::Pioche(const JeuTactique& jeuTactique) : m_cartes(new const Carte*[jeuTactique.getNbCartes()]), m_nb(jeuTactique.getNbCartes())
    {
        size_t i = 0;
        for (auto it = jeuTactique.getIterator(); !it.isDone(); it.next()) {
            m_cartes[i++] = &it.currentItem();
        }

        // shuffle (très naif)
        for(size_t it=0; it<2*m_nb ; ++it){
            size_t a = rand() % m_nb,  b = rand() % m_nb; // on tire deux positions entre 0 et nb
            const Carte * tmp = m_cartes[a];
            m_cartes[a]=m_cartes[b];
            m_cartes[b]=tmp;
        }
    }

    const Carte& Pioche::piocher()
    {
        if(estVide()) throw CarteException("La pioche est vide");
        m_nb--;
        return *m_cartes[getNbCartes()];

    }

    Pioche::~Pioche()
    {
        delete [] m_cartes;
    }
