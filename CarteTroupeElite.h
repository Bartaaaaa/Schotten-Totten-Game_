//
// Created by Utilisateur on 19/04/2023.
//

#ifndef LO21_SCHOTTEN_TOTTEN_CARTETROUPEELITE_H
#define LO21_SCHOTTEN_TOTTEN_CARTETROUPEELITE_H
#include "CarteTactique.h"
#include "CarteClan.h"

class CarteTroupeElite : public CarteClan {
    string nom;

public:

    CarteTroupeElite(const string& nom, Puissance puissance, Couleur couleur) : nom(nom), CarteClan( puissance, couleur)  {};
    CarteTroupeElite jouer_Joker() {
        Couleur couleur;
        Puissance puissance;  // Initialiser la puissance avec une valeur valide
        //cout << "Veuillez choisir une couleur :" << endl;
        //for (int i = 0; i < 6; i++) {  // Boucle pour afficher les choix de couleur possibles
        //    cout << i+1 << ": " << static_cast<Couleur>(i) << endl;
        //}
        //int choix_couleur;
        //cin >> choix_couleur;
        couleur = Couleur::neutre;
        //while (puissance < Puissance::un || puissance > Puissance::neuf) {
        //    cout << "Veuillez choisir une puissance entre 1 et 9 :" << endl;
        //    int choix_puissance;
        //    cin >> choix_puissance;
        puissance = static_cast<Puissance>(0);
        //}
        return CarteTroupeElite("Joker", puissance, couleur);
    }
    string getNom() const {
        return nom;
    }


    CarteTroupeElite jouer_PorteBouclier()  {
        Couleur couleur;
        Puissance puissance = Puissance::quatre;  // Initialiser la puissance avec une valeur valide
        //cout << "Veuillez choisir une couleur :" << endl;
        //for (int i = 0; i < 6; i++) {  // Boucle pour afficher les choix de couleur possibles
        //    cout << i+1 << ": " << static_cast<Couleur>(i) << endl;
        //}
        //int choix_couleur;
        //cin >> choix_couleur;
        couleur = Couleur::neutre;
            /*while (puissance < Puissance::un || puissance > Puissance::trois) {
            cout << "Veuillez choisir une puissance entre 1 et 3 :" << endl;
            int choix_puissance;
            cin >> choix_puissance;*/
            puissance = static_cast<Puissance>(0);
        //}
        return CarteTroupeElite("PorteBouclier", puissance, couleur);  // Retourner l'instance de CarteTroupeElite créée
    }
    CarteTroupeElite jouer_Espion() {
        Couleur couleur;
        Puissance puissance = Puissance::sept;
        //cout << "Veuillez choisir une couleur :" << endl;
        //for (int i = 0; i < 6; i++) {  // Boucle pour afficher les choix de couleur possibles
        //    cout << i+1 << ": " << static_cast<Couleur>(i) << endl;
        //}
        //int choix_couleur;
        //cin >> choix_couleur;
        couleur = Couleur::neutre;
        return CarteTroupeElite("Espion", puissance, couleur);
    }

};

#endif //LO21_SCHOTTEN_TOTTEN_CARTETROUPEELITE_H
