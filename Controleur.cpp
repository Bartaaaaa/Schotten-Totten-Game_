//
// Created by Utilisateur on 26/04/2023.
//

#include "Controleur.h"
#include "CarteTroupeElite.h"
Controleur::Controleur(bool tactique): m_tactique(tactique), m_gagnant(0)
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
}

Controleur::~Controleur()
{
    delete m_pioche_clan;
    delete m_pioche_tactique;
    delete m_plateau;
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


void Controleur::JouerTour(){

    cout << "Voici votre main :" << endl;
    vector<Carte*> cartesMain = m_plateau->m_joueur1->getMain()->getCartes();
    for (int i = 0; i < cartesMain.size(); i++) {
        CarteClan* carteClan = dynamic_cast<CarteClan*>(cartesMain[i]);
        if (carteClan != nullptr) {
            cout << i << " : Puissance = " << carteClan->getPuissance() << " et Couleur : "<< carteClan->getCouleur()<< endl;
        }else {
            CarteTactique* carteTactique = dynamic_cast<CarteTactique*>(cartesMain[i]);
            if (carteTactique != nullptr) {
                cout << i << " : CarteTactique - Nom = " << carteTactique->getNom() << endl;
            }
        }

    }
    cout<<"Veuillez choisir la carte que vous voulez jouer"<<endl;
    int choix_carte, nb_tac=0,nb_clan=0,nb_total=0;
    cin>>choix_carte;
    while(choix_carte>cartesMain.size() || choix_carte<0){
        cout<<"Vous n'avez pas cette carte, resaisissez une que vous avez :"<<endl;
        cin>>choix_carte;
    }
    vector<Carte*> cartes = m_plateau->m_joueur1->getMain()->getCartes();
    Carte* carte = cartes[choix_carte];
    if ( carte  = dynamic_cast<CarteTactique *>(carte)) {
        for (auto carte: cartes) {
            if (carte = dynamic_cast<CarteTactique *>(carte)) {
                nb_tac++;
                nb_total++;
            }}
            if (nb_tac==0){
                cout << "Vous n'avez plus de cartes tactiques !" << endl;
                return;
            }
        }
    else {
        if (carte = dynamic_cast<CarteClan *>(carte)) {
            for (auto carte: cartes) {
                if (carte = dynamic_cast<CarteClan *>(carte)) {
                    nb_clan++;
                    nb_total++;
                }}
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

    cout<<"Veuillez choisir la borne sur laquelle vous voulez jouer"<<endl;
    int choix_borne;
    cin>>choix_borne;

    //On pose la carte
    if (CarteClan* carte_clan = dynamic_cast<CarteClan*>(carte)) {
        m_plateau->poser(*(m_plateau->getBornes(choix_borne)), carte_clan);
    } else if (CarteTroupeElite* carte_elite = dynamic_cast<CarteTroupeElite*>(carte)) {
        m_plateau->poser(*(m_plateau->getBornes(choix_borne)), carte_elite);
    }

    //m_plateau->m_joueur1->getMain().retirerCarte(choix_carte);
    cout << "Voulez vous revendiquer une borne ? 1 pour oui, 0 pour non" << endl;
    int choix_revendication;
    cin >> choix_revendication;

    if(choix_revendication==1){
        cout << "Veuillez choisir la borne que vous voulez revendiquer" << endl;
        int choix_borne;
        cin >> choix_borne;
        while (m_plateau->m_bornes[choix_borne]->getRevendique()==2 || m_plateau->m_bornes[choix_borne]->getRevendique()==1) {
            cout << "La borne a déjà été revendiquée, veuillez choisir une autre borne" << endl;
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
    /*
    cout << "Veuillez choisir si vous voulez choisir une carte tactique ou normale :, 1 pour normale et n'importe qu'elle autre touche pour tactique" << endl;
    int choix_style;
    cin >> choix_style;
    if(choix_style==1){
        if (!m_plateau->Pioche->estVide())
        CarteClan * c1 = m_plateau->m_joueur1->piocher();
    }
    else{
        if (!Pioche::estVide())
        m_plateau->m_joueur1->piocher(m_pioche_tactique);
    }
    m_plateau->getJoueur1()->getMain()->ajouterCarte(&c1);
*/
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

void Controleur::renvendiquer_borne(int num_borne){
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
        if (cartes_pose_j1.size() == 3){
            // si le joeur qui revendique a bien posé c'est trois cartes alors on verifie si il peut revendiquer
            if (cartes_pose_j2.size() ==3){
                // cas simple les 2 joueurs on posé leur 3 cartes
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
        }


    }
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



