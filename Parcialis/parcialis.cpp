#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iostream>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../functions/queue.cpp"

using namespace std;

struct szoba {
    int szomszedszam;
    Queue SzomszedSzobak;
    bool latogatott=false;
};

void Szobaellenorzo(szoba Szobak[],int szobak_szama, int aktualis_szoba) {
    Szobak[aktualis_szoba].latogatott=true;
    //nezzuk meg, hogy megoldast kaptunk-e
    bool megoldva = true;
    for (int i=0;i<szobak_szama;i++) {
        if (!Szobak[i].latogatott) {
            megoldva=false;
        }
    }
    if (megoldva) {
        //kiirjuk a megoldast

    }
    else {
        if (Szobak[aktualis_szoba].szomszedszam==0) {
            //leallunk, innene nem lehet tovabbmenni;
        }else {
            for (int i=0;i<Szobak[aktualis_szoba].szomszedszam;i++) {}
        }
    }
}

int main() {

    ifstream f;
    f.open("kastely.txt");
    if (!f) {
        cout<<"Fajl olvasasi hiba...";
        return 1;
    }
    int a,b;
    f>>a>>b;
    //inicializalas
    szoba Szobak[a];
    for (int i=0;i<a;i++) {
        Szobak[i].szomszedszam=0;
        createQueue(2,&Szobak[i].SzomszedSzobak);
    }
    //beolvasas
    for (int i=0;i<b;i++) {
        int x,y;
        f>>x>>y;
        Szobak[x].szomszedszam++;
        enqueue(&Szobak[x].SzomszedSzobak,y);

        // egyiranyu folyosok vannak
        //Szobak[y].szomszedszam++;
        //enqueue(&Szobak[y].SzomszedSzobak,x);
    }
    //kiiratas teszteleshez
    for (int i=0;i<a;i++) {
        cout<<i<<": Szomszedszobak: ";  display(Szobak[i].SzomszedSzobak ); cout<< "  szobak szama: "<<Szobak[i].szomszedszam<<endl;
    }
    //induljunk el minden szobabol, hogy lassuk be lehet - e jarni a kastelyt
    for (int i=0;i<a;i++) {
        if (Szobak[i].szomszedszam==0) {
            cout<<i<<".szobabol nem lehet elindulni sem ";
        }else {
            Queue tesztelosor;
            //createQueue( &tesztelosor,5);
            Szobaellenorzo(Szobak,a,i);
        }
    }
    return 0;
}