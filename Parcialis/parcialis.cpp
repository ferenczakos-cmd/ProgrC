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

bool Szobaellenorzo(szoba Szobak[],int szobak_szama, int aktualis_szoba, Queue tesztsor) {
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
        cout<<"IGEN: ";
        display(tesztsor);
        return true;

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
    return false;
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
    bool megvanamegoldas=false;
    for (int i=0;i<a;i++) {
        if (Szobak[i].szomszedszam==0) {
            //cout<<i<<".szobabol nem lehet elindulni sem ";
        }else {
            if (!megvanamegoldas) {
                Queue tesztelosor;
                createQueue( 5,&tesztelosor);
                megvanamegoldas= Szobaellenorzo(Szobak,a,i,tesztelosor);
            }
        }
    }
    if (!megvanamegoldas)cout<<"NEM"<<endl;
    f.close();
}


void II() {
    ifstream f;
    f.open("festival.txt");
    if (!f) {
        cout<<"Festival olvasasi hiba...";
    }
    int N,K,Q;
    f>>N>>K>>Q;
    cout<<N<<" "<<K<<" "<<Q<<endl;
    int A[N][3];
    for (int i=0;i<N;i++) {
        f>>A[i][0]>>A[i][1]>>A[i][2];
        cout<<A[i][0]<<" "<<A[i][1]<<" "<<A[i][2]<<endl;
    }
    int B[Q][2];
    for (int i=0;i<Q;i++) {
        f>>B[i][0]>>B[i][1];
        cout<<B[i][0]<<" "<<B[i][1]<<endl;
    }

}

int main() {
    I();
    II();
    return 0;
}