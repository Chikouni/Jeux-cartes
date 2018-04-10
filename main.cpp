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
    string couleurs;
public:
    Carte(int v,int c) //Constructeur
    {
        valeur=v;
        couleur=c;
    }

    int getValeur() { return valeur; }

    void afficher() {
        if(couleur==1){
            couleurs="Coeur";
        }
        if(couleur==2){
            couleurs="Carreau";
        }
        if(couleur==3){
            couleurs="Pique";
        }
        if(couleur==4){
            couleurs="Trefle";
        }

        cout << valeur << " " << couleurs << endl;
    }
};

class PaquetDeCarte
{
    vector<Carte*> distribution;

public:
    Carte* retirerCarte(){
        Carte * t = distribution[0];
        distribution.erase(distribution.begin());
        return t;
    }

    //J'AJOUTE UNE CARTE DANS MON PAQUET DE CARTE

    void ajouterUneCarte(Carte* carte)
    {
        distribution.push_back(carte);

    }
    int size(){
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

    void afficherPdc (){
        int oui;
    for(oui = 0; oui < distribution.size(); oui++){
        distribution[oui]->afficher();
        //cout << distribution[oui].getValeur() << endl;
        }
    }

    vector<Carte*> tampon;






//    void prendre(){
//        int ok;
//        for(ok = 0;ok < 26;ok++){
//          tampon.push_back(distribution[ok]);
//          cout << tampon[ok] << endl;
//        }
//            distribution.erase( distribution.begin() + 0, distribution.begin() + 26 );
//    }
//
//    void mettre(){
//        int ko;
//        for(ko = 0;ko < tampon.size();ko++){
//        distribution.push_back(tampon[ko]);
//        }
//    }
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
     PaquetDeCarte PdcJ1;
     PaquetDeCarte PdcJ2;
    vector<Carte*> tampon;
    for (int d=0;d<52;d++){
    Carte* toto;
    toto=pdc.retirerCarte();

    if(d%2==1){

    PdcJ1.ajouterUneCarte(toto);

    } else {
    PdcJ2.ajouterUneCarte(toto);

    }
    }
 PdcJ1.afficherPdc();
cout <<endl<<endl;
 PdcJ2.afficherPdc();










    PaquetDeCarte Milieuj1;
    PaquetDeCarte Milieuj2;


    //Distribution des cartes

int tour=0;
int egalite;
int j1=0;
int j2=0;
while(PdcJ1.size()>0 && PdcJ2.size()>0){
tour++;


//while(pdcj1.size()>0 || pdcj2.size()>0){
//Retire une carte d'un paquet et le met dans celui du milieu.
Carte* toto = PdcJ1.retirerCarte();
Milieuj1.ajouterUneCarte(toto);
//pareil joueur 2
Carte* toto2 = PdcJ2.retirerCarte();
Milieuj2.ajouterUneCarte(toto2);

int valeur1=toto->getValeur();
int valeur2=toto2->getValeur();

//teste de la valeur
if(valeur1>valeur2){

    cout << valeur1 << "Joueur 1 " << valeur2 << " Joueur2 " <<"victoire joueur 1 mamene"<<endl;
    j1++;
    cout << "victoire joueur 1 " << endl << j1 << endl << " victoire joueur 2" << endl << j2 << endl;
    cout << " nombre de cartes joueur 1 : " << PdcJ1.size() << endl << " nombre de cartes joueur 2 : " << PdcJ2.size() << endl;
    toto=PdcJ1.retirerCarte();
     toto2=PdcJ2.retirerCarte();
     PdcJ1.ajouterUneCarte(toto);
    PdcJ1.ajouterUneCarte(toto2);

    for(int j=0; j<Milieuj1.size(); j++){
        Carte* toto3 = Milieuj1.retirerCarte();
        PdcJ1.ajouterUneCarte(toto3);
        Carte* toto4 = Milieuj2.retirerCarte();
        PdcJ1.ajouterUneCarte(toto4);
}


} else { if(valeur1<valeur2){
    cout << valeur1 << "Joueur 1 " << valeur2 << " Joueur2" <<" victoire joueur 2 mamene "<<endl;
j2++;
 cout << "victoire joueur 1 " << endl << j1 << endl << " victoire joueur 2" << endl << j2 << endl;
 cout << " nombre de cartes joueur 1 : " << PdcJ1.size() << endl << " nombre de cartes joueur 2 : " << PdcJ2.size() << endl;
    Carte* toto7=PdcJ1.retirerCarte();
    Carte* toto8=PdcJ2.retirerCarte();
     PdcJ2.ajouterUneCarte(toto7);
     PdcJ2.ajouterUneCarte(toto8);
     for(int j=0; j<Milieuj2.size(); j++){
        Carte* toto5 = Milieuj1.retirerCarte();
        PdcJ2.ajouterUneCarte(toto5);
        Carte* toto6 = Milieuj2.retirerCarte();
        PdcJ2.ajouterUneCarte(toto6);
    }

} else {
    if(valeur1==valeur2){
cout << "---------------------------------------------------------------------------"<<endl;
        toto=PdcJ1.retirerCarte();
        toto2=PdcJ2.retirerCarte();
        Milieuj1.ajouterUneCarte(toto);
        Milieuj2.ajouterUneCarte(toto2);


    }
}
}
}




}








