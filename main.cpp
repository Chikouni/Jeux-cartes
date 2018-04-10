#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;



    /******************************************

                    CLASSE CARTE

     ******************************************/

class Carte
{
    private:
        int valeur;
        int couleur;
        string couleurs;

    public:
        Carte(int v,int c) //Constructeur
        {
            valeur=v;
            couleur=c;
        }

        int getValeur() { return valeur; } //Accesseur

        void afficher()
        {
            if(couleur==1)
            {
                couleurs="Coeur";
            }
            if(couleur==2)
            {
                couleurs="Carreau";
            }
            if(couleur==3)
            {
                couleurs="Pique";
            }
            if(couleur==4)
            {
                couleurs="Trefle";
            }

            cout << valeur << " " << couleurs << endl;
        }
};

    /******************************************

            CLASSE PAQUET DE CARTE

     ******************************************/

class PaquetDeCarte
{
        vector<Carte*> distribution; //Constructeur

    public:


    Carte* retirerCarte()
    {
        Carte* t = distribution[0];
        distribution.erase(distribution.begin());
        return t;
    }

    //JE VEUX SELECTIONNER UNE CARTE DE MON PAQUET DE CARTES

    Carte* getCarte(int i)
    {
        return distribution[i];
    }

    //J'AJOUTE UNE CARTE DANS MON PAQUET DE CARTE

    void ajouterUneCarte(Carte* carte)
    {
        distribution.push_back(carte);
    }

    //JE VEUX SUPPRIMER UNE CARTE DE MON PAQUET DE CARTE

    void supprimerCarte()
    {
        distribution.erase(distribution.begin());
    }

    //JE VEUX SUPPRIMER LES 3 PREMIERES CARTES DE MON PAQUET

    void supprimer3Cartes()
    {
        distribution.erase(distribution.begin(), distribution.begin() + 3);
    }

    //JE VEUX SUPPRIMER LES 3 PREMIERES CARTES DE MON PAQUET

    void supprimer5Cartes()
    {
        distribution.erase(distribution.begin(), distribution.begin() + 5);
    }

    //JE VEUX SAVOIR LA TAILLE DE MON PAQUET DE CARTES

    int size()
    {
    return distribution.size();
    }

    //JE MELANGE MON PAQUET DE CARTE

    void melangerCarte()
    {
    int i;
    int a;
    int b;
    int c;
    int d;
    for (int i=0; i<100; i++){
        a=rand()%52;
        b=rand()%52;
        distribution[53]=distribution[a];
        distribution[54]=distribution[b];
        distribution[a]=distribution[54];
        distribution[b]=distribution[53];
        }
    }

    //J'AFFICHE MON PAQUET DE CARTE

    void afficherPdc ()
    {
        int oui;
        for(oui = 0; oui < distribution.size(); oui++)
        {
        distribution[oui]->afficher();
        }
    }

};


    /******************************************

                    CLASSE JOUEUR

     ******************************************/

class Joueur
{
    private:
        string nom;

    public:
        Joueur(string n)
        {
            nom = n;
        }

        string getNom()
        {
        return nom;
        }

};

    /******************************************

                    INT MAIN

     ******************************************/

int main()
{
    srand (time(NULL));

    string nomJ1;
    string nomJ2;


    cout << "[ BATAILLE ]" << endl;
    cout << "Veuillez préciser le nom du joueur 1 : ";
    cin >> nomJ1;

    cout << "Veuillez préciser le nom du joueur 2 : ";
    cin >> nomJ2;

    //Création du paquet de cartes
    PaquetDeCarte pdc;

    int i;
    int a;

    for(i=1; i<14; i++)
    {
        for(a=1; a<5; a++)
        {
            Carte* carte = new Carte(i,a);
            pdc.ajouterUneCarte(carte);
        }
    }


    pdc.melangerCarte();
    pdc.afficherPdc();

    cout << endl;
    cout << endl;

    PaquetDeCarte PdcJ1;
    PaquetDeCarte PdcJ2;

    for (int d=0;d<52;d++)
    {
        Carte* toto;
        toto=pdc.retirerCarte();

        if(d%2==1)
        {
            PdcJ1.ajouterUneCarte(toto);
        }else{
        PdcJ2.ajouterUneCarte(toto);
        }
    }

    Joueur Joueur1(nomJ1);
    Joueur Joueur2(nomJ2);

   // PdcJ1.afficherPdc();

    cout <<endl<<endl;

   // PdcJ2.afficherPdc();

    int o = 0;

    while (PdcJ1.size() > 0 && PdcJ2.size() > 0)
    {
        cout << "Cartes restantes dans le paquet de : " << Joueur1.getNom() << " " << PdcJ1.size() << endl;
        cout << "Cartes restantes dans le paquet de : " << Joueur2.getNom() << " " << PdcJ2.size() << endl;

        cout << "Tour [" <<  o << "] : " << PdcJ1.getCarte(0)->getValeur() << " contre " << PdcJ2.getCarte(0)->getValeur() << endl;
        o++;

        if ( PdcJ1.getCarte(0)->getValeur() > PdcJ2.getCarte(0)->getValeur() )
        {
            PdcJ1.ajouterUneCarte(PdcJ2.getCarte(0));
            PdcJ1.ajouterUneCarte(PdcJ1.getCarte(0));

            PdcJ1.supprimerCarte();
            PdcJ2.supprimerCarte();

            cout << Joueur1.getNom() << " a gagne ce tour" << endl;

        } else if( PdcJ1.getCarte(0)->getValeur() < PdcJ2.getCarte(0)->getValeur() ){
            PdcJ2.ajouterUneCarte(PdcJ1.getCarte(0));
            PdcJ2.ajouterUneCarte(PdcJ2.getCarte(0));

            PdcJ1.supprimerCarte();
            PdcJ2.supprimerCarte();

            cout << Joueur2.getNom() << " a gagne ce tour" << endl;
        }else{
        cout << "Egalite !" << endl;

        cout << PdcJ1.getCarte(2)->getValeur() << " contre " << PdcJ2.getCarte(2)->getValeur() << endl;

                if ( PdcJ1.getCarte(2)->getValeur() > PdcJ2.getCarte(2)->getValeur() )
                    {
                    PdcJ1.ajouterUneCarte(PdcJ2.getCarte(0));
                    PdcJ1.ajouterUneCarte(PdcJ1.getCarte(0));
                    PdcJ1.ajouterUneCarte(PdcJ2.getCarte(1));
                    PdcJ1.ajouterUneCarte(PdcJ1.getCarte(1));
                    PdcJ1.ajouterUneCarte(PdcJ2.getCarte(2));
                    PdcJ1.ajouterUneCarte(PdcJ1.getCarte(2));

                    PdcJ1.supprimer3Cartes();
                    PdcJ2.supprimer3Cartes();

            cout << Joueur1.getNom() << " a gagne ce tour" << endl;

                    } else if( PdcJ1.getCarte(2)->getValeur() < PdcJ2.getCarte(2)->getValeur() ){
                        PdcJ2.ajouterUneCarte(PdcJ1.getCarte(0));
                        PdcJ2.ajouterUneCarte(PdcJ2.getCarte(0));
                        PdcJ2.ajouterUneCarte(PdcJ1.getCarte(1));
                        PdcJ2.ajouterUneCarte(PdcJ2.getCarte(1));
                        PdcJ2.ajouterUneCarte(PdcJ1.getCarte(2));
                        PdcJ2.ajouterUneCarte(PdcJ2.getCarte(2));

                        PdcJ1.supprimer3Cartes();
                        PdcJ2.supprimer3Cartes();

            cout << Joueur2.getNom() << " a gagne ce tour" << endl;
                    }else{
                        cout << "Encore egalite !" << endl;
                        cout << PdcJ1.getCarte(4)->getValeur() << " contre " << PdcJ2.getCarte(4)->getValeur() << endl;

                         if ( PdcJ1.getCarte(4)->getValeur() > PdcJ2.getCarte(4)->getValeur() )
                         {
                            PdcJ1.ajouterUneCarte(PdcJ2.getCarte(0));
                            PdcJ1.ajouterUneCarte(PdcJ1.getCarte(0));
                            PdcJ1.ajouterUneCarte(PdcJ2.getCarte(1));
                            PdcJ1.ajouterUneCarte(PdcJ1.getCarte(1));
                            PdcJ1.ajouterUneCarte(PdcJ2.getCarte(2));
                            PdcJ1.ajouterUneCarte(PdcJ1.getCarte(2));
                            PdcJ1.ajouterUneCarte(PdcJ2.getCarte(3));
                            PdcJ1.ajouterUneCarte(PdcJ1.getCarte(3));
                            PdcJ1.ajouterUneCarte(PdcJ2.getCarte(4));
                            PdcJ1.ajouterUneCarte(PdcJ1.getCarte(4));

                            PdcJ1.supprimer5Cartes();
                            PdcJ2.supprimer5Cartes();

            cout << Joueur1.getNom() << " a gagne ce tour" << endl;

                        } else if( PdcJ1.getCarte(4)->getValeur() < PdcJ2.getCarte(4)->getValeur() ){
                            PdcJ2.ajouterUneCarte(PdcJ1.getCarte(0));
                            PdcJ2.ajouterUneCarte(PdcJ2.getCarte(0));
                            PdcJ2.ajouterUneCarte(PdcJ1.getCarte(1));
                            PdcJ2.ajouterUneCarte(PdcJ2.getCarte(1));
                            PdcJ2.ajouterUneCarte(PdcJ1.getCarte(2));
                            PdcJ2.ajouterUneCarte(PdcJ2.getCarte(2));
                            PdcJ2.ajouterUneCarte(PdcJ1.getCarte(3));
                            PdcJ2.ajouterUneCarte(PdcJ2.getCarte(3));
                            PdcJ2.ajouterUneCarte(PdcJ1.getCarte(4));
                            PdcJ2.ajouterUneCarte(PdcJ2.getCarte(4));

                            PdcJ1.supprimer5Cartes();
                            PdcJ2.supprimer5Cartes();

            cout << Joueur2.getNom() << " a gagne ce tour" << endl;
                        }
                    }
        }

    //DU COUPS, S'IL Y A TROIS FOIS DE SUITE UNE EGALITE YA UN PROBLEME, ON AURAIT PU REFAIRE UN AUTRE ELSE POUR PARER CETTE SITUATION

    }
        if (PdcJ1.size() <= 0)
        {
        cout << Joueur2.getNom() << " GAGNE" << endl;
        }
        if (PdcJ2.size() <= 0)
        {
        cout << Joueur1.getNom() << " GAGNE" << endl;
        }
}



