#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;



class Joueur
{
private:
    string : nom;
    vector<Carte>PaquetJoueur;
public:
    Joueur(string n, vector<Carte>pj){
    nom = n;
    PaquetJoueur = pj;
    }
};


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

    //Créer methode : prendrecarte

    //Créer methode : mettre carte
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

    PaquetDeCarte pdcj1;
    PaquetDeCarte pdcj2;
    PaquetDeCarte pdcj3;
    PaquetDeCarte pdcj4;

    //Distribution des cartes

        for(int dist=0; dist<13;dist++){
            pdcj1[dist]=distribution[dist];
        }


    //Je crée mes joueurs
    Joueur Joueur1("Dimitri", pdcj1);
    Joueur Joueur2("Kévin", pdcj2);
    Joueur Joueur3("Ursule", pdcj3);
    Joueur Joueur4("Abdelramouf" pdcj4);


    cout << pdcj1 << endl;




}
