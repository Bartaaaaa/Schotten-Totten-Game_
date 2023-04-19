//
// Created by Utilisateur on 19/04/2023.
//

#ifndef LO21_SCHOTTEN_TOTTEN_CARTEEXCEPTION_H
#define LO21_SCHOTTEN_TOTTEN_CARTEEXCEPTION_H
#include <iostream>
#include <string>
#include <initializer_list>
#include <array>
#include <cstdlib>
using namespace std;

class CarteException {
private:
    string info;
public:
    CarteException(const string& i) : info(i) {}
    string getInfo() const { return info; }
};

enum class Couleur { jaune, vert, violet, rouge, bleu, marron};
enum class Puissance { un = 1, deux = 2, trois = 3, quatre = 4, cinq = 5, six = 6, sept = 7, huit = 8, neuf = 9};

string toString(Couleur c);
string toString(Puissance p);

ostream& operator<<(ostream& f, Couleur c);
ostream& operator<<(ostream& f, Puissance p);

extern std::initializer_list<Couleur> Couleurs;
extern std::initializer_list<Puissance> Puissances;

#endif //LO21_SCHOTTEN_TOTTEN_CARTEEXCEPTION_H
