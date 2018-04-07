#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

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

    int getValeur() { return valeur; }

    void afficher() {
        cout << valeur << " " << couleur << endl;
    }
};

class PaquetDeCarte
{
    vector<Carte*> distribution;

public:

    //J'AJOUTE UNE CARTE DANS MON PAQUET DE CARTE

    void ajouterUneCarte(Carte* carte)
    {
        distribution.push_back(carte);
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

    void afficherPdc (){
        int oui;
    for(oui = 0; oui < distribution.size(); oui++){
        distribution[oui]->afficher();
        //cout << distribution[oui].getValeur() << endl;
        }
    }

    vector<Carte*> tampon;

    void prendre(){
        int ok;
        for(ok = 0;ok < 26;ok++){
          tampon.push_back(distribution[ok]);
          cout << tampon[ok] << endl;
        }
            distribution.erase( distribution.begin() + 0, distribution.begin() + 26 );
    }

    void mettre(){
        int ko;
        for(ko = 0;ko < tampon.size();ko++){
        distribution.push_back(tampon[ko]);
        }
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

    pdc.prendre();

    PaquetDeCarte PdcJ1;

    PdcJ1.mettre();
    PdcJ1.afficherPdc();
    cout << "ça marche pas excellent" << endl;

    return 0;
}
