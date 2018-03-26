#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

//Je crée ma carte
class Carte
{
private:
    int valeur;
    int couleur;

public:
    Carte(int v,int c) //Constructeur
    {
        valeur=v;
        couleur=c;
    }
};

//Je crée mon Paquet de carte composé de cartes et je les distribues
class PaquetDeCarte
{
    vector<Carte>distribution;

public:
    void ajouterUneCarte(Carte carte)
    {
        distribution.push_back(carte);
    }

    void melangerCarte(Carte carte)
    {
    int i;
    int a;
    int b;
    int c;
    int d;
    for (int i=0; i<100; i++){
        a=rand()%52;
        b=rand()%52;
        c=distribution[a];
        d=distribution[b];
        distribution[a]=d;
        distribution[b]=c;
    }
    }

    void distribuer()
    {
        int yui;
        for (yui=0; yui<13; yui++){
        Joueur1[yui]=distribution[1];
        distribution.erase(distribution.begin());
    }
    }
};

//Ce sont les cartes qui sont mises par les joueurs sur la table
class PaquetTable
{
    int valeur;
    vector<Carte>surLaTable;

    void afficherTable()
    {
        cout << "Carte " << valeur << endl;
    }
};

class PaquetJoueur
{

    public:
    vector<Carte>PaquetDuJoueur;

    void afficherPaquetJoueur()
    {
        cout << "Carte " << valeur << endl;
    }
};



int main()
{
    srand (time(NULL));
    //Création d'un paquet de carte
    PaquetDeCarte pdc;
    int i;
    int a;

    for(i=1; i<14; i++)
    {
        for(a=1; i<5; a++)
        {
            Carte carte(i,a);
            pdc.ajouterUneCarte(carte);
        }
    }

    //Mélanger le paquet de carte

    pdc.melangerCarte();


    //Création des paquets des joueurs
    PaquetJoueur Joueur1;
    PaquetJoueur Joueur2;
    PaquetJoueur Joueur3;
    PaquetJoueur Joueur4;

    //Je distribue les cartes de mon paquet aux joueurs

    pdc.distribuer();





}
