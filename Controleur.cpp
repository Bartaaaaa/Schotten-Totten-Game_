//
// Created by Utilisateur on 26/04/2023.
//

#include "Controleur.h"
#include "CarteTroupeElite.h"
Controleur::Controleur(bool tactique): m_tactique(tactique), m_gagnant(0), m_jeu_clan(JeuClan::getJeuClan()), m_jeu_tactique(JeuTactique::getJeuTactique())
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


void clean(void)
{
    int c= 0;
    while ( (getchar()) != '\n' && c != EOF);
}

void Controleur::JouerTour(){

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

    /*  cout<<"Veuillez choisir la borne sur laquelle vous voulez jouer :"<<endl;
        int choix_borne;
       cin>>choix_borne;
      Carte* carteChoisie = m_plateau->getJoueur1()->getMain()->getCarte(choix_carte);
       //On pose la carte
       if (CarteClan* carteChoisie = dynamic_cast<CarteClan*>(carteChoisie)) {
           m_plateau->poser(*m_plateau->getBornes(choix_borne), carteChoisie);
       } else if (CarteTroupeElite* carteChoisie = dynamic_cast<CarteTroupeElite*>(carte)) {
           m_plateau->poser(*m_plateau->getBornes(choix_borne), carteChoisie);
       }*/


    cout << "Voulez vous jouer une carte tactique ou clan ? 1 pour tactique, 0 pour clan :" << endl;
    int choix_type;
    cin >> choix_type;
    if (choix_type==0){
        Carte* carteChoisie = m_plateau->getJoueur1()->getMain()->getCarte(choix_carte);
        CarteClan* carteClanChoisie = dynamic_cast<CarteClan*>(carteChoisie);
        if(carteClanChoisie!=nullptr)
            cout << "Vous avez choisi la carte : Puissance :" << carteClanChoisie->getPuissance() << " Couleur : " << carteClanChoisie->getCouleur() << endl;
        else
            cout << "Vous avez choisi la mauvaise carte" << endl;
        //affichage borne
        for(auto i =1; i<9;i++){
            cout << "Borne " << i << " :" << endl;
            affichage_vecteur_carteclan(m_plateau->getBornes(i)->getCartesJ1()->getCartes());
        }
        //Choix de la borne
        cout << "Veuillez choisir une borne :" << endl;
        int choix_borne;
        cin >> choix_borne;
        affichage_vecteur_carteclan(m_plateau->getBornes(2)->getCartesJ1()->getCartes());
        cout << "On pose la carte piochee sur la borne "<< choix_borne << " :"<<endl;
        m_plateau->poser(*m_plateau->getBornes(choix_borne),carteClanChoisie );
        cout << "Borne " << choix_borne << " :" << endl;
        affichage_vecteur_carteclan(m_plateau->getBornes(choix_borne)->getCartesJ1()->getCartes());
        m_plateau->getJoueur1()->getMain()->supprimerCarte(choix_carte);
    }
    /*
    else {
        Carte* carteChoisie = m_plateau->getJoueur1()->getMain()->getCarte(choix_carte);
        CarteTactique* carteTactiquechoisie = dynamic_cast<CarteTactique*>(carteChoisie);
        if(carteTactiquechoisie!=nullptr)
            cout << "Vous avez choisi la carte :" << carteTactiquechoisie->getNom() << endl;
        else
            cout << "Vous avez choisi la mauvaise carte" << endl;
        //affichage borne
        for(auto i =1; i<9;i++){
            cout << "Borne " << i << " :" << endl;
            affichage_vecteur_carteclan(m_plateau->getBornes(i)->getCartesJ1()->getCartes());
        }
        //Choix de la borne
        cout << "Veuillez choisir une borne :" << endl;
        int choix_borne;
        cin >> choix_borne;
        //affichage_vecteur_carteTactique(m_plateau->getBornes(2)->getCartesJ1()->getCartes());
        cout << "On pose la carte piochee sur la borne "<< choix_borne << " :"<<endl;
        m_plateau->poser(*m_plateau->getBornes(choix_borne),*carteTactiquechoisie );
        cout << "Borne " << choix_borne << " :" << endl;
        affichage_vecteur_carteclan(m_plateau->getBornes(choix_borne)->getCartesJ1()->getCartes());
    }
*/












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
    //on récupére la carte clan ici qu'on piochera si le joueur le souhaite

    //auto ct = getPiocheTactique()->piocherCarteTactique();
   // cout <<"taille pioche tactique : "<<getPiocheTactique()->getNbCartes()<<"\n";
    if( int(choix_style)==1 ){
        CarteClan* ci = new CarteClan(getPiocheClan()->piocherCarteClan());
        m_plateau->getJoueur1()->getMain()->ajouterCarte(ci);
        cout <<"Carte piochee : "<< ci->getPuissance() <<" "<< ci->getCouleur() << endl;
        m_plateau->afficherMainJoueur(1);
        //auto c1= getPiocheClan()->piocherCarteClan();
       // m_plateau->getJoueur1()->getMain()->ajouterCarte(&c1);
       // const CarteClan& c1 = dynamic_cast<const CarteClan&>(getPiocheClan()->piocher());
        //CarteClan* nonConstC1 = const_cast<CarteClan*>(&c1);
        //getControleur(false).getPlateau()->getJoueur2()->getMain()->ajouterCarte(nonConstC1);
      //  cout << "Vous avez pioche la carte : Puissance :" << c1.getPuissance() << " Couleur : " << c1.getCouleur() << endl;
        // CarteClan* ci = new CarteClan(getPiocheClan()->piocherCarteClan());
        //m_plateau->getJoueur1()->getMain()->ajouterCarte(ci);
        //cout <<"Carte piochee : "<< ci->getPuissance() <<" "<< ci->getCouleur() << endl;
        //m_plateau->afficherMainJoueur(1);
    }
    //On pioche la carte tactique ici
    /*
    else if (0<getPiocheTactique()->getNbCartes() && choix_style!=1 ){
        m_plateau->getJoueur1()->getMain()->ajouterCarte(&ct);
        cout <<"Carte piochee : "<< ct.getNom()<< endl;
        m_plateau->afficherMainJoueur(1);;
    }
    */
    //Affichage de la main du joueur 1
    cout << "Votre main est maintenant composee de : " << endl;
    m_plateau->afficherMainJoueur(1);
    cout <<"taille pioche clan : "<<getPiocheClan()->getNbCartes()<<"\n";
    //cout <<"taille pioche tactique : "<<getPiocheTactique()->getNbCartes()<<"\n";

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

    affichage_vecteur_carteclan(m_plateau->getBornes(2)->getCartesJ1()->getCartes());
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

void Controleur::renvendiquer_borne(int num_borne) {
    if (getTactique()){

    }
    else {
        if ((m_plateau->getBornes(num_borne)->getCartesJ1()->getCartes().size()==3) && (m_plateau->getBornes(num_borne)->getCartesJ2()->getCartes().size()==3))
        { renvendiquer_borne_pleine_non_tactique(num_borne);
        }
    }
}
void Controleur::renvendiquer_borne_pleine_non_tactique(int num_borne){
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



