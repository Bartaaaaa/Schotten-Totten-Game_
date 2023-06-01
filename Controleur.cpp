//
// Created by Utilisateur on 26/04/2023.
//

#include "Controleur.h"
#include "CarteTroupeElite.h"
#include "CarteRuse.h"
#include <ctime>

Controleur::Controleur(bool tactique): m_tactique(tactique), m_gagnant(0), m_jeu_clan(JeuClan::getJeuClan()), m_jeu_tactique(JeuTactique::getJeuTactique()), m_carte_non_pose(m_jeu_clan.getNbCartes())
{
    m_pioche_clan = new Pioche(m_jeu_clan);
    if(tactique){
        m_pioche_tactique = new Pioche(m_jeu_tactique);
        printf("tactique\n");
        m_plateau = new Plateau(7, false, false);
    }
    else{
        m_plateau = new Plateau(6, false, false);
        printf("classique\n");
    }

    size_t i=0;
    JeuClan::Iterator it=m_jeu_clan.getIterator();
    while (!it.isDone()){
        m_carte_non_pose[i]= new CarteClan(static_cast<const CarteClan&>(it.currentItem()));
        it.next();
        i++;
    }
}

Controleur::~Controleur()
{
    delete m_pioche_clan;
    delete m_pioche_tactique;
    delete m_plateau;
    for(int i=0; i<m_carte_non_pose.size(); i++){
        delete m_carte_non_pose[i];
    }
}

Controleur& Controleur::getControleur(bool tactique)
{
    if (handler.controleur == nullptr)
        handler.controleur = new Controleur(tactique);
    return *handler.controleur;
}

void Controleur::libererControleur()
{
    delete handler.controleur;
    handler.controleur =nullptr;
}

Controleur::Handler Controleur::handler = Handler();


void clean(void)
{
    int c= 0;
    while ( (getchar()) != '\n' && c != EOF);
}

void Controleur::Afficher_Borne1(){
    for(auto i =1; i<9;i++){
        cout << "|B" << i<<":";
        affichage_vecteur_carteclan(m_plateau->getBornes(i)->getCartesJ1()->getCartes());
        cout <<"|"<< endl;
    }
    cout << endl;

}
void Controleur::Afficher_Borne2(){
    for(auto i =1; i<9;i++){
        cout << "|B" << i <<":";
        affichage_vecteur_carteclan(m_plateau->getBornes(i)->getCartesJ2()->getCartes());
        cout <<"|"<< endl;
    }
    cout << endl;
}

void Controleur::afficherCartesNonPose() const
{
    std::cout << "Cartes non posées : " << std::endl;
    for (int i = 0; i < m_carte_non_pose.size(); ++i)
    {
        std::cout << "Carte " << i + 1 << ": ";
        if (m_carte_non_pose[i] != nullptr)
            std::cout << m_carte_non_pose[i]->getCouleur() << " "<< m_carte_non_pose[i]->getPuissance()<< std::endl;
        else
            std::cout << "Aucune carte" << std::endl;
    }
}
void Controleur::JouerTour1(){


    /*if ( carte  = dynamic_cast<CarteTactique *>(carte)) {
        for (auto carte: cartes) {
                nb_tac++;
                nb_total++;
            }
            if (nb_tac==0){
                cout << "Vous n'avez plus de cartes tactiques !" << endl;
                return;
            }
        }
    else {
        if (carte = dynamic_cast<CarteClan *>(carte)) {
            for (auto carte: cartes) {

                    nb_clan++;
                    nb_total++;
                }
            if (nb_clan==0){
                cout << "Vous n'avez plus de cartes clans !" << endl;
                return;
            }
            if (nb_total ==0 ){
                cout << "Vous n'avez plus de cartes !" << endl;
                return; exit(0);
            }
        }
    }*/


    cout << "Voici votre main :" << endl;
    m_plateau->afficherMainJoueur(1);
    vector<Carte*> cartesMain = m_plateau->m_joueur1->getMain()->getCartes();

    cout<<"Veuillez choisir la carte que vous voulez jouer (son id) :"<<endl;
    int choix_carte, nb_tac=0,nb_clan=0,nb_total=0;
    cin>>choix_carte; clean();
    while(choix_carte>cartesMain.size() || choix_carte<0){
        cout<<"Vous n'avez pas cette carte, resaisissez une que vous avez :"<<endl;
        cin>>choix_carte;
    }
    vector<Carte*> cartes = m_plateau->m_joueur1->getMain()->getCartes();
    Carte* carte = cartes[choix_carte];
    if (carte = dynamic_cast<CarteClan *>(carte)) {
            Carte* carteChoisie = m_plateau->getJoueur1()->getMain()->getCarte(choix_carte);
            CarteClan* carteClanChoisie = dynamic_cast<CarteClan*>(carteChoisie);
            if(carteClanChoisie!=nullptr)
                cout << "Vous avez choisi la carte : Puissance :" << carteClanChoisie->getPuissance() << " Couleur : " << carteClanChoisie->getCouleur() << endl;
            else
                cout << "Vous avez choisi la mauvaise carte" << endl;
        //affichage borne
        Afficher_Borne1();
        //Choix de la borne
        cout << "Veuillez choisir une borne :" << endl;
        int choix_borne;
        cin >> choix_borne;
        affichage_vecteur_carteclan(m_plateau->getBornes(choix_borne)->getCartesJ1()->getCartes());cout <<endl;
        cout << "On pose la carte piochee sur la borne "<< choix_borne << " :"<<endl;
        m_plateau->poser(*m_plateau->getBornes(choix_borne),carteClanChoisie );
        cout << "Borne " << choix_borne << " :" << endl;
        affichage_vecteur_carteclan(m_plateau->getBornes(choix_borne)->getCartesJ1()->getCartes());cout <<endl;
        m_plateau->getJoueur1()->getMain()->supprimerCarte(choix_carte);
    }
    else {

    }
    CarteRuse::Jouer_Stratege();
    cout << "Voulez vous revendiquer une borne ? 1 pour oui, 0 pour non :" << endl;
    int choix_revendication;
    cin >> choix_revendication;

    if(choix_revendication==1){
        cout << "Veuillez choisir la borne que vous voulez revendiquer :" << endl;
        int choix_borne;
        cin >> choix_borne;
        while (m_plateau->m_bornes[choix_borne]->getRevendique()==2 || m_plateau->m_bornes[choix_borne]->getRevendique()==1) {
            cout << "La borne a déjà été revendiquée, veuillez choisir une autre borne :" << endl;
            cin>> choix_borne;
            return;
        }
        auto cartesBornes = m_plateau->getBornes(choix_borne)->getCartesJ1()->getCartes();
        int i =0;
        while(cartesBornes[i]!=NULL){
            if (dynamic_cast<CarteTroupeElite*>(cartesBornes[i]) != nullptr) {
                CarteTroupeElite* carteTroupeElite = dynamic_cast<CarteTroupeElite*>(cartesBornes[i]);
                if (carteTroupeElite->getNom()== "Joker"){
                    Couleur couleur;
                    Puissance puissance;  // Initialiser la puissance avec une valeur valide
                    cout << "Veuillez choisir une couleur :" << endl;
                    for (int i = 0; i < 6; i++) {  // Boucle pour afficher les choix de couleur possibles
                        cout << i+1 << ": " << static_cast<Couleur>(i) << endl;
                    }
                    int choix_couleur;
                    cin >> choix_couleur;
                    couleur = Couleur::neutre;
                    while (puissance < Puissance::un || puissance > Puissance::neuf) {
                        cout << "Veuillez choisir une puissance entre 1 et 9 :" << endl;
                        int choix_puissance;
                        cin >> choix_puissance;
                    puissance = static_cast<Puissance>(0);
                    cartesBornes[i]= new CarteClan(puissance, couleur);
                    }
                    }
                else if (carteTroupeElite->getNom()== "PorteBouclier"){
                    Couleur couleur;
                    Puissance puissance = Puissance::quatre;  // Initialiser la puissance avec une valeur valide
                    cout << "Veuillez choisir une couleur :" << endl;
                    for (int i = 0; i < 6; i++) {  // Boucle pour afficher les choix de couleur possibles
                        cout << i+1 << ": " << static_cast<Couleur>(i) << endl;
                    }
                    int choix_couleur;
                    cin >> choix_couleur;
                    couleur = Couleur::neutre;
                    while (puissance < Puissance::un || puissance > Puissance::trois) {
                    cout << "Veuillez choisir une puissance entre 1 et 3 :" << endl;
                    int choix_puissance;
                    cin >> choix_puissance;
                    puissance = static_cast<Puissance>(0);
                    cartesBornes[i]= new CarteClan(puissance, couleur);
                    }
                }
                else if (carteTroupeElite->getNom()== "Espion"){
                    Couleur couleur;
                    Puissance puissance = Puissance::sept;
                    cout << "Veuillez choisir une couleur :" << endl;
                    for (int i = 0; i < 6; i++) {  // Boucle pour afficher les choix de couleur possibles
                        cout << i+1 << ": " << static_cast<Couleur>(i) << endl;
                    }
                    int choix_couleur;
                    cin >> choix_couleur;
                    couleur = Couleur::neutre;
                    cartesBornes[i]= new CarteClan(puissance, couleur);
                }
            }
            }i++;
        check_fin_partie();
    }
    cout << "Veuillez choisir si vous voulez choisir une carte tactique ou normale :, 1 pour normale et n'importe qu'elle autre chiffre pour tactique" << endl;
    int choix_style;
    cin >> choix_style;
    cout <<"taille pioche clan : "<<getPiocheClan()->getNbCartes()<<"\n";
    if( int(choix_style)==1 ){
        CarteClan* ci = new CarteClan(getPiocheClan()->piocherCarteClan());
        m_plateau->getJoueur1()->getMain()->ajouterCarte(ci);
        cout <<"Carte piochee : "<< ci->getPuissance() <<" "<< ci->getCouleur() << endl;
        m_plateau->afficherMainJoueur(1);

    }
    //jouer carte espion
    CarteRuse::Jouer_ChasseurdeTete() ;

    //Affichage de la main du joueur 1
    cout << "Votre main est maintenant composee de : " << endl;
    m_plateau->afficherMainJoueur(1);
    cout <<"taille pioche clan : "<<getPiocheClan()->getNbCartes()<<"\n";
    //cout <<"taille pioche tactique : "<<getPiocheTactique()->getNbCartes()<<"\n";
    Afficher_Borne1();
    cout << "\nFIN DU TOUR" << endl;
}

void Controleur::JouerTour2(){
    cout << "Voici votre main :" << endl;
    m_plateau->afficherMainJoueur(1);
    vector<Carte*> cartesMain = m_plateau->m_joueur2->getMain()->getCartes();
    cout<<"Veuillez choisir la carte que vous voulez jouer (son id) :"<<endl;
    int choix_carte, nb_tac=0,nb_clan=0,nb_total=0;
    cin>>choix_carte; clean();
    while(choix_carte>cartesMain.size() || choix_carte<0){
        cout<<"Vous n'avez pas cette carte, resaisissez une que vous avez :"<<endl;
        cin>>choix_carte;
    }
    vector<Carte*> cartes = m_plateau->m_joueur2->getMain()->getCartes();
    Carte* carte = cartes[choix_carte];
    if ( carte  = dynamic_cast<CarteTactique *>(carte)) {
        for (auto carte: cartes) {
            nb_tac++;
            nb_total++;
        }
        if (nb_tac==0){
            cout << "Vous n'avez plus de cartes tactiques !" << endl;
            return;
        }
    }
    else {
        if (carte = dynamic_cast<CarteClan *>(carte)) {
            for (auto carte: cartes) {

                nb_clan++;
                nb_total++;
            }
            if (nb_clan==0){
                cout << "Vous n'avez plus de cartes clans !" << endl;
                return;
            }
            if (nb_total ==0 ){
                cout << "Vous n'avez plus de cartes !" << endl;
                return; exit(0);
            }
        }
    }



    cout << "Voulez vous jouer une carte tactique ou clan ? 1 pour tactique, 0 pour clan :" << endl;
    int choix_type;
    cin >> choix_type;
    if (choix_type==0){
        Carte* carteChoisie = m_plateau->getJoueur2()->getMain()->getCarte(choix_carte);
        CarteClan* carteClanChoisie = dynamic_cast<CarteClan*>(carteChoisie);
        if(carteClanChoisie!=nullptr)
            cout << "Vous avez choisi la carte : Puissance :" << carteClanChoisie->getPuissance() << " Couleur : " << carteClanChoisie->getCouleur() << endl;
        else
            cout << "Vous avez choisi la mauvaise carte" << endl;
        //affichage borne
        Afficher_Borne2();
        //Choix de la borne
        cout << "Veuillez choisir une borne :" << endl;
        int choix_borne;
        cin >> choix_borne;
        affichage_vecteur_carteclan(m_plateau->getBornes(choix_borne)->getCartesJ2()->getCartes());cout <<endl;
        cout << "On pose la carte piochee sur la borne "<< choix_borne << " :"<<endl;
        m_plateau->poser(*m_plateau->getBornes(choix_borne),carteClanChoisie );
        cout << "Borne " << choix_borne << " :" << endl;
        affichage_vecteur_carteclan(m_plateau->getBornes(choix_borne)->getCartesJ2()->getCartes());cout <<endl;
        m_plateau->getJoueur2()->getMain()->supprimerCarte(choix_carte);
    }










    cout << "Voulez vous revendiquer une borne ? 1 pour oui, 0 pour non :" << endl;
    int choix_revendication;
    cin >> choix_revendication;

    if(choix_revendication==1){
        cout << "Veuillez choisir la borne que vous voulez revendiquer :" << endl;
        int choix_borne;
        cin >> choix_borne;
        while (m_plateau->m_bornes[choix_borne]->getRevendique()==2 || m_plateau->m_bornes[choix_borne]->getRevendique()==1) {
            cout << "La borne a déjà été revendiquée, veuillez choisir une autre borne :" << endl;
            cin>> choix_borne;
            return;
        }
        auto cartesBornes = m_plateau->getBornes(choix_borne)->getCartesJ2()->getCartes();
        int i =0;
        while(cartesBornes[i]!=NULL){
            if (dynamic_cast<CarteTroupeElite*>(cartesBornes[i]) != nullptr) {
                CarteTroupeElite* carteTroupeElite = dynamic_cast<CarteTroupeElite*>(cartesBornes[i]);
                if (carteTroupeElite->getNom()== "Joker"){
                    Couleur couleur;
                    Puissance puissance;  // Initialiser la puissance avec une valeur valide
                    cout << "Veuillez choisir une couleur :" << endl;
                    for (int i = 0; i < 6; i++) {  // Boucle pour afficher les choix de couleur possibles
                        cout << i+1 << ": " << static_cast<Couleur>(i) << endl;
                    }
                    int choix_couleur;
                    cin >> choix_couleur;
                    couleur = Couleur::neutre;
                    while (puissance < Puissance::un || puissance > Puissance::neuf) {
                        cout << "Veuillez choisir une puissance entre 1 et 9 :" << endl;
                        int choix_puissance;
                        cin >> choix_puissance;
                        puissance = static_cast<Puissance>(0);
                        cartesBornes[i]= new CarteClan(puissance, couleur);
                    }
                }
                else if (carteTroupeElite->getNom()== "PorteBouclier"){
                    Couleur couleur;
                    Puissance puissance = Puissance::quatre;  // Initialiser la puissance avec une valeur valide
                    cout << "Veuillez choisir une couleur :" << endl;
                    for (int i = 0; i < 6; i++) {  // Boucle pour afficher les choix de couleur possibles
                        cout << i+1 << ": " << static_cast<Couleur>(i) << endl;
                    }
                    int choix_couleur;
                    cin >> choix_couleur;
                    couleur = Couleur::neutre;
                    while (puissance < Puissance::un || puissance > Puissance::trois) {
                        cout << "Veuillez choisir une puissance entre 1 et 3 :" << endl;
                        int choix_puissance;
                        cin >> choix_puissance;
                        puissance = static_cast<Puissance>(0);
                        cartesBornes[i]= new CarteClan(puissance, couleur);
                    }
                }
                else if (carteTroupeElite->getNom()== "Espion"){
                    Couleur couleur;
                    Puissance puissance = Puissance::sept;
                    cout << "Veuillez choisir une couleur :" << endl;
                    for (int i = 0; i < 6; i++) {  // Boucle pour afficher les choix de couleur possibles
                        cout << i+1 << ": " << static_cast<Couleur>(i) << endl;
                    }
                    int choix_couleur;
                    cin >> choix_couleur;
                    couleur = Couleur::neutre;
                    cartesBornes[i]= new CarteClan(puissance, couleur);
                }
            }
        }i++;
        check_fin_partie();
    }
    cout << "Veuillez choisir si vous voulez choisir une carte tactique ou normale :, 1 pour normale et n'importe qu'elle autre chiffre pour tactique" << endl;
    int choix_style;
    cin >> choix_style;
    cout <<"taille pioche clan : "<<getPiocheClan()->getNbCartes()<<"\n";

    if( int(choix_style)==1 ){
        CarteClan* ci = new CarteClan(getPiocheClan()->piocherCarteClan());
        m_plateau->getJoueur2()->getMain()->ajouterCarte(ci);
        cout <<"Carte piochee : "<< ci->getPuissance() <<" "<< ci->getCouleur() << endl;
        m_plateau->afficherMainJoueur(2);

    cout << "Votre main est maintenant composee de : " << endl;
    m_plateau->afficherMainJoueur(2);
    cout <<"taille pioche clan : "<<getPiocheClan()->getNbCartes()<<"\n";

    Afficher_Borne2();
    }
}

void Controleur::JouerTourIAClassique(){
    m_plateau->afficherMainJoueur(1);
    vector<Carte*> cartesMain = m_plateau->m_joueur1->getMain()->getCartes();
    srand(time(0));
    cout<<"Veuillez choisir la carte que vous voulez jouer (son id) :"<<endl;
    int choix_carte, nb_tac=0,nb_clan=0,nb_total=0;
    choix_carte = rand()%cartesMain.size();
    while(choix_carte>cartesMain.size() || choix_carte<0){
        cout<<"Vous n'avez pas cette carte, resaisissez une que vous avez :"<<endl;
        choix_carte = rand()%cartesMain.size()+1;
    }
    vector<Carte*> cartes = m_plateau->m_joueur1->getMain()->getCartes();
    Carte* carte = cartes[choix_carte];
    if (carte = dynamic_cast<CarteClan *>(carte)) {
        Carte* carteChoisie = m_plateau->getJoueur1()->getMain()->getCarte(choix_carte);
        CarteClan* carteClanChoisie = dynamic_cast<CarteClan*>(carteChoisie);
        /*while(carteClanChoisie!=nullptr){
            cout << "Vous avez choisi la mauvaise carte" << endl;
            choix_carte = rand()%cartesMain.size()+1;
            Carte* carteChoisie = m_plateau->getJoueur1()->getMain()->getCarte(choix_carte);
            CarteClan* carteClanChoisie = dynamic_cast<CarteClan*>(carteChoisie);
        }*/
            cout << "L'IA a choisi la carte : Puissance :" << carteClanChoisie->getPuissance() << " Couleur : " << carteClanChoisie->getCouleur() << endl;
        //affichage borne
        Afficher_Borne1();
        //Choix de la borne
        cout << "L'IA va choisir une borne :" << endl;
        int choix_borne = rand()%7+1;
        if (choix_borne > 7 || choix_borne < 0) {
            cout << "Vous n'avez pas cette borne, resaisissez une que vous avez :" << endl;
            choix_borne = rand()%7+1;
        }

        while (m_plateau->getBornes(choix_borne)->getCartesJ1()->getCartes().size()==3){
            cout << "La borne est pleine, veuillez choisir une autre borne :" << endl;
            choix_borne = rand()%7+1;
        }
        cout << "L'IA a choisi la borne : " << choix_borne << endl;
        affichage_vecteur_carteclan(m_plateau->getBornes(choix_borne)->getCartesJ1()->getCartes());cout <<endl;
        cout << "On pose la carte piochee sur la borne "<< choix_borne << " :"<<endl;
        m_plateau->poser(*m_plateau->getBornes(choix_borne),carteClanChoisie );
        cout << "Borne " << choix_borne << " :" << endl;
        affichage_vecteur_carteclan(m_plateau->getBornes(choix_borne)->getCartesJ1()->getCartes());cout <<endl;
        m_plateau->getJoueur1()->getMain()->supprimerCarte(choix_carte);
    }
    int count_cartes = 0;

    for (int i=0 ;i <8;i++) {

        auto cartesBornes = m_plateau->getBornes(i)->getCartesJ1()->getCartes();
            if (cartesBornes.size() ==3) {
                count_cartes = 3;
        }

        if (count_cartes == 3) {
            cout << "Vous avez 3 cartes sur la borne " << i<< ", voulez vous la revendiquer ? 1 pour oui, 0 pour non :" << endl;

            int choix_revendication = rand() % 2;
            if (choix_revendication == 1) {
                if (m_plateau->m_bornes[i]->getRevendique() == 2 || m_plateau->m_bornes[i]->getRevendique() == 1) {
                    cout << "test3";
                    return;
                } else {
                    //m_plateau->m_bornes[i]->setRevendique(1);
                    cout << "Vous avez revendique la borne " << i << endl;
                }
            }
        }
    }


    cout <<"taille pioche clan : "<<getPiocheClan()->getNbCartes()<<"\n";
        CarteClan* ci = new CarteClan(getPiocheClan()->piocherCarteClan());
        m_plateau->getJoueur1()->getMain()->ajouterCarte(ci);
        cout <<"L'ia a piochee la carte  : "<< ci->getPuissance() <<" "<< ci->getCouleur() << endl;
        m_plateau->afficherMainJoueur(1);
    //jouer carte espion
    //Affichage de la main du joueur 1
    cout << "La main de l'IA est maintenant composé de :" << endl;
    m_plateau->afficherMainJoueur(1);
    cout <<"taille pioche clan : "<<getPiocheClan()->getNbCartes()<<"\n";
    //cout <<"taille pioche tactique : "<<getPiocheTactique()->getNbCartes()<<"\n";
    Afficher_Borne1();
    cout << "\nFIN DU TOUR" << endl;
}



void Controleur::JouerTourIA(){
    m_plateau->afficherMainJoueur(1);
    vector<Carte*> cartesMain = m_plateau->m_joueur1->getMain()->getCartes();
    srand(time(0));
    cout<<"Veuillez choisir la carte que vous voulez jouer (son id) :"<<endl;
    int choix_carte, nb_tac=0,nb_clan=0,nb_total=0;
    choix_carte = rand()%cartesMain.size();
    while(choix_carte>cartesMain.size() || choix_carte<0){
        cout<<"Vous n'avez pas cette carte, resaisissez une que vous avez :"<<endl;
        choix_carte = rand()%cartesMain.size()+1;
    }
    vector<Carte*> cartes = m_plateau->m_joueur1->getMain()->getCartes();
    Carte* carte = cartes[choix_carte];
    if (carte = dynamic_cast<CarteClan *>(carte)) {
        Carte* carteChoisie = m_plateau->getJoueur1()->getMain()->getCarte(choix_carte);
        CarteClan* carteClanChoisie = dynamic_cast<CarteClan*>(carteChoisie);
        if(carteClanChoisie!=nullptr)
            cout << "L'IA a choisi la carte : Puissance :" << carteClanChoisie->getPuissance() << " Couleur : " << carteClanChoisie->getCouleur() << endl;
        else
            cout << "Vous avez choisi la mauvaise carte" << endl;
        //affichage borne
        Afficher_Borne1();
        //Choix de la borne
        cout << "L'IA va choisir une borne :" << endl;
        int choix_borne = rand()%7+1;
        if (choix_borne > 7 || choix_borne < 0) {
            cout << "Vous n'avez pas cette borne, resaisissez une que vous avez :" << endl;
            choix_borne = rand()%7+1;
        }

        while (m_plateau->getBornes(choix_borne)->getCartesJ1()->getCartes().size()==3){
            cout << "La borne est pleine, veuillez choisir une autre borne :" << endl;
            choix_borne = rand()%7+1;
        }
        cout << "L'IA a choisi la borne : " << choix_borne << endl;
        affichage_vecteur_carteclan(m_plateau->getBornes(choix_borne)->getCartesJ1()->getCartes());cout <<endl;
        cout << "On pose la carte piochee sur la borne "<< choix_borne << " :"<<endl;
        m_plateau->poser(*m_plateau->getBornes(choix_borne),carteClanChoisie );
        cout << "Borne " << choix_borne << " :" << endl;
        affichage_vecteur_carteclan(m_plateau->getBornes(choix_borne)->getCartesJ1()->getCartes());cout <<endl;
        m_plateau->getJoueur1()->getMain()->supprimerCarte(choix_carte);
    }
    int count_cartes = 0;

    for (int i=0 ;i <8;i++) {

        auto cartesBornes = m_plateau->getBornes(i)->getCartesJ1()->getCartes();
        if (cartesBornes.size() ==3) {
            count_cartes = 3;
        }

        if (count_cartes == 3) {
            cout << "Vous avez 3 cartes sur la borne " << i<< ", voulez vous la revendiquer ? 1 pour oui, 0 pour non :" << endl;

            int choix_revendication = rand() % 2;
            if (choix_revendication == 1) {
                if (m_plateau->m_bornes[i]->getRevendique() == 2 || m_plateau->m_bornes[i]->getRevendique() == 1) {
                    cout << "test3";
                    return;
                } else {
                    m_plateau->m_bornes[i]->setRevendique(1);
                    cout << "Vous avez revendique la borne " << i << endl;
                }
            }
        }


/*
        auto cartesBornes = m_plateau->getBornes(i)->getCartesJ1()->getCartes();
        int j = 0;
        while (cartesBornes[i] != NULL) {
            if (dynamic_cast<CarteTroupeElite *>(cartesBornes[i]) != nullptr) {
                CarteTroupeElite *carteTroupeElite = dynamic_cast<CarteTroupeElite *>(cartesBornes[i]);
                if (carteTroupeElite->getNom() == "Joker") {
                    Couleur couleur;
                    Puissance puissance;  // Initialiser la puissance avec une valeur valide
                    cout << "Veuillez choisir une couleur :" << endl;
                    for (int i = 0; i < 6; i++) {  // Boucle pour afficher les choix de couleur possibles
                        cout << i + 1 << ": " << static_cast<Couleur>(i) << endl;
                    }
                    int choix_couleur;
                    cin >> choix_couleur;
                    couleur = Couleur::neutre;
                    while (puissance < Puissance::un || puissance > Puissance::neuf) {
                        cout << "Veuillez choisir une puissance entre 1 et 9 :" << endl;
                        int choix_puissance;
                        cin >> choix_puissance;
                        puissance = static_cast<Puissance>(0);
                        cartesBornes[i] = new CarteClan(puissance, couleur);
                    }
                } else if (carteTroupeElite->getNom() == "PorteBouclier") {
                    Couleur couleur;
                    Puissance puissance = Puissance::quatre;  // Initialiser la puissance avec une valeur valide
                    cout << "Veuillez choisir une couleur :" << endl;
                    for (int i = 0; i < 6; i++) {  // Boucle pour afficher les choix de couleur possibles
                        cout << i + 1 << ": " << static_cast<Couleur>(i) << endl;
                    }
                    int choix_couleur;
                    cin >> choix_couleur;
                    couleur = Couleur::neutre;
                    while (puissance < Puissance::un || puissance > Puissance::trois) {
                        cout << "Veuillez choisir une puissance entre 1 et 3 :" << endl;
                        int choix_puissance;
                        cin >> choix_puissance;
                        puissance = static_cast<Puissance>(0);
                        cartesBornes[i] = new CarteClan(puissance, couleur);
                    }
                } else if (carteTroupeElite->getNom() == "Espion") {
                    Couleur couleur;
                    Puissance puissance = Puissance::sept;
                    cout << "Veuillez choisir une couleur :" << endl;
                    for (int i = 0; i < 6; i++) {  // Boucle pour afficher les choix de couleur possibles
                        cout << i + 1 << ": " << static_cast<Couleur>(i) << endl;
                    }
                    int choix_couleur;
                    cin >> choix_couleur;
                    couleur = Couleur::neutre;
                    cartesBornes[i] = new CarteClan(puissance, couleur);
                }
            }
        }
        i++;
        check_fin_partie();
    }
    */}

    cout << "Veuillez choisir si vous voulez piocher une carte tactique ou normale :, 1 pour normale et n'importe qu'elle autre chiffre pour tactique" << endl;
    int choix_style = rand()%2;
    cout <<"taille pioche clan : "<<getPiocheClan()->getNbCartes()<<"\n";
    if( int(choix_style)==1 ){
        CarteClan* ci = new CarteClan(getPiocheClan()->piocherCarteClan());
        m_plateau->getJoueur1()->getMain()->ajouterCarte(ci);
        cout <<"L'ia a piochee la carte  : "<< ci->getPuissance() <<" "<< ci->getCouleur() << endl;
        m_plateau->afficherMainJoueur(1);

    }
    else {
        CarteTactique* ti = new CarteTactique(getPiocheTactique()->piocherCarteTactique());
        m_plateau->getJoueur1()->getMain()->ajouterCarte(ti);
        cout <<"L'ia a piochee la carte tactique : "<< ti->getNom() << endl;
        m_plateau->afficherMainJoueur(1);
    }
    //jouer carte espion
    //Affichage de la main du joueur 1
    cout << "La main de l'IA est maintenant composé de :" << endl;
    m_plateau->afficherMainJoueur(1);
    cout <<"taille pioche clan : "<<getPiocheClan()->getNbCartes()<<"\n";
    //cout <<"taille pioche tactique : "<<getPiocheTactique()->getNbCartes()<<"\n";
    Afficher_Borne1();
    cout << "\nFIN DU TOUR" << endl;
}




void Controleur::JouerTourClassique(){
    cout << "Voici votre main :" << endl;
    m_plateau->afficherMainJoueur(1);

    //Choix de la carte
    cout << "Veuillez choisir une carte :" << endl;
    int choix_carte;
    cin >> choix_carte;

    //TODO : ici ne marche pas
    Carte* carteChoisie = m_plateau->getJoueur1()->getMain()->getCarte(choix_carte);

    CarteClan* carteClanChoisie = dynamic_cast<CarteClan*>(carteChoisie);
    if(carteClanChoisie!=nullptr)
        cout << "Vous avez choisi la carte : Puissance :" << carteClanChoisie->getPuissance() << " Couleur : " << carteClanChoisie->getCouleur() << endl;
    else
        cout << "Vous avez choisi la mauvaise carte" << endl;


    //affichage borne
    for(auto i =1; i<4;i++){
        cout << "Borne " << i << " :" << endl;
        affichage_vecteur_carteclan(m_plateau->getBornes(i)->getCartesJ1()->getCartes());
    }
    //Choix de la borne

    cout << "Veuillez choisir une borne :" << endl;
    int choix_borne;
    cin >> choix_borne;

    affichage_vecteur_carteclan(m_plateau->getBornes(choix_borne)->getCartesJ1()->getCartes());
    cout << "On pose la carte piochee sur la borne "<< choix_borne << " :"<<endl;
    m_plateau->poser(*m_plateau->getBornes(choix_borne),carteClanChoisie );
    cout << "Borne " << choix_borne << " :" << endl;
    affichage_vecteur_carteclan(m_plateau->getBornes(choix_borne)->getCartesJ1()->getCartes());

    auto ci= getPiocheClan()->piocherCarteClan();
    m_plateau->getJoueur1()->getMain()->ajouterCarte(&ci);
    cout <<"Carte piochee: "<< ci.getPuissance()<<" "<< ci.getCouleur() <<endl;
    cout << "Main J1: "<<endl;
    m_plateau->afficherMainJoueur(1);


    cout << "FIN DU TOUR" << endl;

}

bool Controleur::check_fin_partie() {
    int sum1=0;
    int serie1=0;
    int sum2=0;
    int serie2=0;
    for(auto i=0; i<9; i++){
        int j = m_plateau->m_bornes[i]->getRevendique();
        //printf("test");
        if(j==1){
            sum1++;
            serie1++;
            //printf("test1");
            if(serie1==3){
                m_gagnant=1;
                //printf("test3");
                return true;
            }
            serie2=0;
        }
        else if(j==2){
            sum2++;
            serie2++;
            //printf("test2");
            if(serie2==3){
                m_gagnant=2;
                return true;
            }
            serie1=0;
        }
    }
    return false;
}

void Controleur::revendiquer_borne(int num_borne) {
    if (getTactique()){

    }
    else {
        if ((m_plateau->getBornes(num_borne)->getCartesJ1()->getCartes().size()==3) && (m_plateau->getBornes(num_borne)->getCartesJ2()->getCartes().size()==3)){
            revendiquer_borne_pleine_non_tactique(num_borne);
        }
        else if (((m_plateau->getBornes(num_borne)->getCartesJ1()->getCartes().size()==3) && (m_plateau->getBornes(num_borne)->getCartesJ2()->getCartes().size()<3))
            || ((m_plateau->getBornes(num_borne)->getCartesJ1()->getCartes().size()<3) && (m_plateau->getBornes(num_borne)->getCartesJ2()->getCartes().size()==3))){
            revendiquer_borne_non_pleine_non_tactique(num_borne);
        }
    }
}
void Controleur::revendiquer_borne_pleine_non_tactique(int num_borne){
    Borne * borne = m_plateau->getBornes(num_borne);
    Combinaison* combi_j1 = borne->getCartesJ1();
    Combinaison* combi_j2 = borne->getCartesJ2();
    vector<CarteClan*> cartes_pose_j1 = combi_j1->getCartes();
    vector<CarteClan*> cartes_pose_j2 = combi_j2->getCartes();

    int joueur_qui_revendique = getPlateau()->getJoueurActif();

    // affichage des valeurs:
    std::cout << "Le joueur " << joueur_qui_revendique << " revendique la borne " << borne->getNum() << std::endl;
    std::cout << "cartes pose j1 : " << std::endl;
    affichage_vecteur_carteclan(cartes_pose_j1);
    std::cout << "Force combi j1: " << combi_j1->getForceCombi() << std::endl;


    std::cout << "cartes pose j2 : " << std::endl;
    affichage_vecteur_carteclan(cartes_pose_j2);
    std::cout << "Force combi j2: " << combi_j2->getForceCombi() << std::endl;

    // on verifie que le joeur actif a tt les cartes dans sa borne


    if (joueur_qui_revendique == 1){
        if (combi_j1->getForceCombi() >combi_j2->getForceCombi()){
            //cas ou J1 a une meilleur combinaison que J2
            std::cout << "J1 gagne la borne car il a une meuilleur combianison que J2" << std::endl;
            borne->setRevendique(1);
        }
        else if (combi_j1->getForceCombi() == combi_j2->getForceCombi()){
            // cas ou J1 et J2 ont la meme combinaison on verifie la somme des valeurs
                if (combi_j1->getTotalPuissance() > combi_j2->getTotalPuissance())
                {// J1 a bien une meuilleur main que J2
                    std::cout << "J1 gagne la borne car meme niveau de combi mais somme des valeurs plus eleve que J2" << std::endl;
                    borne->setRevendique(1);}
                else if(combi_j1->getTotalPuissance() == combi_j2->getTotalPuissance()){
                    //TODO verifier que J1 a bien été le premier a poser la 3eme carte
                    std::cout << "J1 gagne la borne car meme niveau de combi mais somme des valeurs plus eleve que J2" << std::endl;
                    borne->setRevendique(1);
                }
                else{
                    std::cout << "J1 perd et ne peut pas revendiquer la borne car meme niveau de combi mais somme des valeurs plus eleve pour J2 " << std::endl;
                }
        }
        else{
            std::cout << "J1 perd et ne peut pas revendiquer la borne car J2 a une meuilleur combianison que J1" << std::endl;
        }
    }
    // J2 revendique
    else{
        if (combi_j2->getForceCombi() > combi_j1->getForceCombi()){
            //cas ou J2 a une meilleur combinaison que J1
            std::cout << "J2 gagne la borne car il a une meuilleur combianison que J2" << std::endl;
            borne->setRevendique(2);
        }
        else if (combi_j1->getForceCombi() == combi_j2->getForceCombi()){
            // cas ou J1 et J2 ont la meme combinaison on verifie la somme des valeurs
            if (combi_j2->getTotalPuissance() > combi_j1->getTotalPuissance())
            {// J2 a bien une meuilleur main que J1
                std::cout << "J2 gagne la borne car meme niveau de combi mais somme des valeurs plus eleve que J1" << std::endl;
                borne->setRevendique(2);}
            else if(combi_j1->getTotalPuissance() == combi_j2->getTotalPuissance()){
                //TODO verifier que J1 a bien été le premier a poser la 3eme carte
                std::cout << "J2 gagne la borne car meme niveau de combi et somme des valeurs, mais carte pose avant " << std::endl;
                borne->setRevendique(2);
            }
            else{
                std::cout << "J2 perd et ne peut pas revendiquer la borne car meme niveau de combi mais somme des valeurs plus eleve pour J1 " << std::endl;
            }
        }
        else{
            std::cout << "J2 perd et ne peut pas revendiquer la borne car J1 a une meuilleur combianison que J1" << std::endl;
        }


    }
}
void Controleur::revendiquer_borne_non_pleine_non_tactique(int num_borne ) {

    Borne *borne = m_plateau->getBornes(num_borne);
    Combinaison *combi_j1 = borne->getCartesJ1();
    Combinaison *combi_j2 = borne->getCartesJ2();
    vector<CarteClan *> cartes_pose_j1 = combi_j1->getCartes();
    vector<CarteClan *> cartes_pose_j2 = combi_j2->getCartes();

    int joueur_qui_revendique = getPlateau()->getJoueurActif();

    // affichage des valeurs:
    std::cout << "Le joueur " << joueur_qui_revendique << " revendique la borne " << borne->getNum() << std::endl;
    std::cout << "cartes pose j1 : " << std::endl;
    affichage_vecteur_carteclan(cartes_pose_j1);
    std::cout << "\nForce combi j1: " << combi_j1->getForceCombi() << std::endl;

    std::cout << "cartes pose j2 : " << std::endl;
    affichage_vecteur_carteclan(cartes_pose_j2);
    std::cout << "\nForce combi j2: " << combi_j2->getForceCombi() << std::endl;

    if (joueur_qui_revendique == 1) {
        //J1 revendique
        if (cartes_pose_j1.size() != 3) {
            cout << "J1 ne peut pas revendiquer la borne car il n'a pas pose 3 cartes" << endl;
        } else {
            int nbr_carte_manquante_a_j2 = 3 - cartes_pose_j2.size();
            switch (nbr_carte_manquante_a_j2) {
                case (1): {
                    // J2 a pose 2 cartes
                    int max = 0;
                    for (auto a1: m_carte_non_pose) {
                        Combinaison *combi_temp = new Combinaison();
                        combi_temp->ajouterCarte(cartes_pose_j2[0]);
                        combi_temp->ajouterCarte(cartes_pose_j2[1]);
                        combi_temp->ajouterCarte(a1);
                        if (cartes_pose_j2[0] != cartes_pose_j2[1] && cartes_pose_j2[0] != a1 &&
                            cartes_pose_j2[1] != a1) {
                            if (combi_temp->getForceCombi() > max) {
                                max = combi_temp->getForceCombi();
                                combi_j2 = combi_temp;
                            }
                            if (max > combi_j1->getForceCombi()) {
                                cout
                                        << "J1 perd et ne peut pas revendiquer la borne car certaines carte non posé peuvent battre J1"
                                        << std::endl;
                                break;
                            } else if (max == combi_j1->getForceCombi()) {
                                if (combi_temp->getTotalPuissance() > combi_j1->getTotalPuissance()) {
                                    cout
                                            << "J1 perd et ne peut pas revendiquer la borne car certaines carte non posé peuvent battre J1"
                                            << std::endl;
                                    break;
                                } else if (combi_temp->getTotalPuissance() == combi_j1->getTotalPuissance()) {
                                    //TODO reverifier que J2 a bien pose la 3eme carte
                                    cout
                                            << "J1 perd et ne peut pas revendiquer la borne car certaines carte non posé peuvent battre J1"
                                            << std::endl;
                                    break;
                                }
                            }
                        }
                    }
                    cout << "J1 gagne la borne car J2 ne peut pas battre J1 avec les cartes restantes" << endl;
                    borne->setRevendique(1);
                    break;
                }

                case (2): {
                    // J2 a pose 1 carte
                    int max = 0;
                    for (auto a1: m_carte_non_pose) {
                        for (auto a2: m_carte_non_pose) {
                            Combinaison *combi_temp = new Combinaison();
                            combi_temp->ajouterCarte(cartes_pose_j2[0]);
                            combi_temp->ajouterCarte(a1);
                            combi_temp->ajouterCarte(a2);
                            if (cartes_pose_j2[0] != a1 && cartes_pose_j2[0] != a2 && a1 != a2) {
                                if (combi_temp->getForceCombi() > max) {
                                    max = combi_temp->getForceCombi();
                                    combi_j2 = combi_temp;
                                }
                                if (max > combi_j1->getForceCombi()) {
                                    cout
                                            << "J1 perd et ne peut pas revendiquer la borne car certaines carte non posé peuvent battre J1"
                                            << std::endl;
                                    break;
                                } else if (max == combi_j1->getForceCombi()) {
                                    if (combi_temp->getTotalPuissance() > combi_j1->getTotalPuissance()) {
                                        cout
                                                << "J1 perd et ne peut pas revendiquer la borne car certaines carte non posé peuvent battre J1"
                                                << std::endl;
                                        break;
                                    } else if (combi_temp->getTotalPuissance() == combi_j1->getTotalPuissance()) {
                                        //TODO reverifier que J2 a bien pose la 3eme carte
                                        cout
                                                << "J1 perd et ne peut pas revendiquer la borne car certaines carte non posé peuvent battre J1"
                                                << std::endl;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    cout << "J1 gagne la borne car J2 ne peut pas battre J1 avec les cartes restantes" << endl;
                    borne->setRevendique(1);
                    break;
                }
                case (3): {
                    // J2 a pose 0 carte
                    int max = 0;
                    for (auto a1: m_carte_non_pose) {
                        for (auto a2: m_carte_non_pose) {
                            for (auto a3: m_carte_non_pose) {
                                Combinaison *combi_temp = new Combinaison();
                                combi_temp->ajouterCarte(a1);
                                combi_temp->ajouterCarte(a2);
                                combi_temp->ajouterCarte(a3);

                                //TODO enlever ca
                                affichage_vecteur_carteclan(combi_temp->getCartes());
                                cout << endl;
                                if (a1 != a2 && a1 != a3 && a2 != a3) {
                                    if (combi_temp->getForceCombi() > max) {
                                        max = combi_temp->getForceCombi();
                                        combi_j2 = combi_temp;
                                    }
                                    if (max > combi_j1->getForceCombi()) {
                                        cout
                                                << "J1 perd et ne peut pas revendiquer la borne car certaines carte non posé peuvent battre J1"
                                                << std::endl;
                                        return;
                                    } else if (max == combi_j1->getForceCombi()) {
                                        if (combi_temp->getTotalPuissance() > combi_j1->getTotalPuissance()) {
                                            cout
                                                    << "J1 perd et ne peut pas revendiquer la borne car certaines carte non posé peuvent battre J1"
                                                    << std::endl;
                                            return;
                                        } else if (combi_temp->getTotalPuissance() == combi_j1->getTotalPuissance()) {
                                            //TODO reverifier que J2 a bien pose la 3eme carte
                                            cout
                                                    << "J1 perd et ne peut pas revendiquer la borne car certaines carte non posé peuvent battre J1"
                                                    << std::endl;
                                            return;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    cout << "J1 gagne la borne car J2 ne peut pas battre J1 avec les cartes restantes" << endl;
                    borne->setRevendique(1);
                    break;

                }

            }

        }
    }
    // TODO faire J2
}
void Controleur::fin_de_partie(){

    delete m_plateau->m_joueur1;
    delete m_plateau->m_joueur2;


    // Libérer la mémoire des objets membres des différentes classes
    delete[] m_plateau->m_joueur1->getMain();
    delete[] m_plateau->m_joueur2->getMain();

    // Vider et supprimer les conteneurs de pointeurs
    vector<Carte*> cartesMain1 = m_plateau->m_joueur1->getMain()->getCartes();
    for (int i = 0; i < cartesMain1.size(); i++) {
        delete cartesMain1[i];
    }
    cartesMain1.clear();

    vector<Carte*> cartesMain2 = m_plateau->m_joueur2->getMain()->getCartes();
    for (int i = 0; i < cartesMain2.size(); i++) {
        delete cartesMain2[i];
    }
    cartesMain2.clear();
    for (int i=0;i<9;i++){
        delete m_plateau->m_bornes[i];
    }
    delete m_plateau;
}

void Controleur::debut_de_partie_classique() {
    // Ajout des 6 cartes dans la main du joueur 1
    for (int i = 0; i < 6; i++) {
        CarteClan *ci = new CarteClan(getPiocheClan()->piocherCarteClan());
        m_plateau->m_joueur1->getMain()->ajouterCarte(ci);
    }

    // Ajout des 6 cartes dans la main du joueur 2
    for (int i = 0; i < 6; i++) {
        CarteClan *ci = new CarteClan(getPiocheClan()->piocherCarteClan());
        m_plateau->m_joueur2->getMain()->ajouterCarte(ci);
    }

    // Affichage des mains des joueurs
    m_plateau->afficherMainJoueur(1);
    m_plateau->afficherMainJoueur(2);
    cout << "Fin de la phase de pioche" << endl<<endl;
}

void Controleur::supprimer_carte_pose_v1(CarteClan *carte) {
    for (int i = 0; i < m_carte_non_pose.size(); i++) {
        if (m_carte_non_pose[i] == carte) {
            m_carte_non_pose.erase(m_carte_non_pose.begin() + i);
        }
    }
}
void Controleur::supprimer_carte_pose_v2(CarteClan *carte) {
    auto p = carte->getPuissance();
    auto c = carte->getCouleur();
    for (int i = 0; i < m_carte_non_pose.size(); i++) {
        if (m_carte_non_pose[i]->getPuissance() == p && m_carte_non_pose[i]->getCouleur() == c) {
            m_carte_non_pose.erase(m_carte_non_pose.begin() + i);
        }
    }
}

void Controleur::JouerTourClassique1(){
    system ("CLS");
    cout << "Voici votre main :" << endl;
    m_plateau->afficherMainJoueur(1);
    vector<Carte*> cartesMain = m_plateau->m_joueur1->getMain()->getCartes();

    cout<<"Veuillez choisir la carte que vous voulez jouer (son id) :"<<endl;
    int choix_carte, nb_tac=0,nb_clan=0,nb_total=0;
    cin>>choix_carte; clean();
    while(choix_carte>cartesMain.size() || choix_carte<0){
        cout<<"Vous n'avez pas cette carte, resaisissez une que vous avez :"<<endl;
        cin>>choix_carte;
    }
    vector<Carte*> cartes = m_plateau->m_joueur1->getMain()->getCartes();
    Carte* carte = cartes[choix_carte];
    if (auto carte_choisie = dynamic_cast<CarteClan *>(carte)) {
        for (auto carte: cartes) {
            nb_clan++;
            nb_total++;
        }
        if (nb_clan==0){
            cout << "Vous n'avez plus de cartes clans !" << endl;
            return;
        }
        if (nb_total ==0 ){
            cout << "Vous n'avez plus de cartes !" << endl;
            return; exit(0);
            }

        system ("CLS");
        cout << "Carte choisie : " << carte_choisie->getCouleur() << " " << carte_choisie->getPuissance() << endl;
        Afficher_Borne1();
        //Choix de la borne
        cout << "Veuillez choisir une borne :" << endl;
        int choix_borne;
        cin >> choix_borne;
        affichage_vecteur_carteclan(m_plateau->getBornes(choix_borne)->getCartesJ1()->getCartes());cout <<endl;
        cout << "On pose la carte piochee sur la borne "<< choix_borne << " :"<<endl;
        m_plateau->poser(*m_plateau->getBornes(choix_borne),carte_choisie);
        cout << "Borne " << choix_borne << " :" << endl;
        affichage_vecteur_carteclan(m_plateau->getBornes(choix_borne)->getCartesJ1()->getCartes());cout <<endl;
        m_plateau->getJoueur1()->getMain()->supprimerCarte(choix_carte);

    }
    system ("CLS");
    CarteClan* ci = new CarteClan(getPiocheClan()->piocherCarteClan());
    m_plateau->getJoueur1()->getMain()->ajouterCarte(ci);
    cout <<"Carte piochee : "<< ci->getPuissance() <<" "<< ci->getCouleur() << endl;
    m_plateau->afficherMainJoueur(1);
    Afficher_Borne1();
    cout << "\nFIN DU TOUR" << endl;

}


