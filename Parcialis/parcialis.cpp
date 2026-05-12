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

// valamiert nem irja ki a talalt megoldast, pedig a tesztfajlra megkapja a lehetseges megoldast, azt megsem
void Szobaellenorzo(szoba Szobak[],int szobak_szama, int aktualis_szoba, Queue tesztsor) {
    Szobak[aktualis_szoba].latogatott=true;
    enqueue(&tesztsor,aktualis_szoba);
    //nezzuk meg, hogy megoldast kaptunk-e
    bool megoldva = true;
    for (int i = 0; i < szobak_szama; i++) {
        // ha barmelyik szoba nem latogatott, akkor nem jo a megoldas
        if (!Szobak[i].latogatott) {
            megoldva = false;
            break;
        }
    }
    //testing
    //display(tesztsor);
    if (megoldva) {
        cout<<"megoldva: ";
        display(tesztsor);

    } else {
        Queue masolat;
        createQueue(Szobak[aktualis_szoba].szomszedszam + 1, &masolat);

        if (Szobak[aktualis_szoba].szomszedszam!=0) {
            for (int i = 0; i < Szobak[aktualis_szoba].szomszedszam; i++) {
                int szomszed = dequeue(&Szobak[aktualis_szoba].SzomszedSzobak);

                if (!Szobak[szomszed].latogatott) {
                    Szobaellenorzo(Szobak, szobak_szama, szomszed, tesztsor);
                }
                enqueue(&Szobak[aktualis_szoba].SzomszedSzobak, szomszed);
            }
        }

    }
    Szobak[aktualis_szoba].latogatott = false;
}

void I() {

    ifstream f;
    f.open("kastely.txt");
    if (!f) {
        cout<<"Fajl olvasasi hiba...";

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
    //for (int i=0;i<a;i++) {
    //    cout<<i<<": Szomszedszobak: ";  display(Szobak[i].SzomszedSzobak ); cout<< "  szobak szama: "<<Szobak[i].szomszedszam<<endl;
    //}
    //induljunk el minden szobabol, hogy lassuk be lehet - e jarni a kastelyt
    for (int i=0;i<a;i++) {
        if (Szobak[i].szomszedszam==0) {
            //cout<<i<<".szobabol nem lehet elindulni sem ";
        }else {
            Queue tesztelosor;
            createQueue( 5,&tesztelosor);
            Szobaellenorzo(Szobak,a,i,tesztelosor);
        }
    }
    f.close();
}


void II() {
    ifstream f;
    f.open("festival.txt");
    if (!f) {
        cout<<"Festival olvasasi hiba...";
    }

}

int main() {
    //I();
    II();
    return 0;
}