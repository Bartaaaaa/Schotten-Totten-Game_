//
// Created by Utilisateur on 26/04/2023.
//

#ifndef LO21_SCHOTTEN_TOTTEN_CONTROLEUR_H
#define LO21_SCHOTTEN_TOTTEN_CONTROLEUR_H
#include "Plateau.h"
#include "Pioche.h"

class Controleur {
    int m_gagnant;
    bool m_tactique; // ou const bool ?
    Pioche* m_pioche_clan;
    Pioche* m_pioche_tactique;
    Plateau* m_plateau; // ou Plateau
    JeuClan m_jeu_clan;
    JeuTactique m_jeu_tactique;

    //vector<CarteClan *> m_carte_non_pose;

    Controleur(bool m_tactique);
    ~Controleur();

    struct Handler
    {
        Controleur* controleur;
        Handler() : controleur(nullptr) {}
        ~Handler() { delete controleur; }
    };

    static Handler handler;

public:
    Controleur(const Controleur& j) = delete;
    Controleur& operator=(const Controleur& j) = delete;

    static Controleur& getControleur(bool tactique);
    static void libererControleur();

    int getGagnant() const { return m_gagnant; }
    bool getTactique() const { return m_tactique; }
    void fin_de_partie();
    /*TODO verifier si on a besoin de ces getters
    const Pioche& getPiocheClan() const { return *m_pioche_clan; }
    const Pioche& getPiocheTactique() const { return *m_pioche_tactique; }

    JeuClan getJeuClan() const { return m_jeu_clan; }
    JeuTactique getJeuTactique() const { return m_jeu_tactique; }
     */

    Plateau* getPlateau() const { return m_plateau; }
    void setGagnant(int gagnant) { m_gagnant = gagnant; }
    void setTactique(bool tactique) { m_tactique = tactique; }
    void JouerTour();
    void JouerTourClassique();
    Pioche* getPiocheClan() const { return m_pioche_clan; }
    Pioche* getPiocheTactique() const { return m_pioche_tactique; }
    void renvendiquer_borne(int num_borne);
    void renvendiquer_borne_pleine_non_tactique(int num_borne);

    /* Todo faire ces methodes:
    jouer_tour() : void
    revendiquer_exception(???) : ???
     */
    void test();

    bool check_fin_partie();
};
#endif //LO21_SCHOTTEN_TOTTEN_CONTROLEUR_H
