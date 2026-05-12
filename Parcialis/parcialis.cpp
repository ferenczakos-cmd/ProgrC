#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iostream>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../header/queue.h"

using namespace std;

struct szoba {
    int szomszedszam;
    Queue SzomszedSzobak;
    bool latogatott=false;
};

int main() {


    ifstream f;
    f.open("kastely.txt");
    if (!f) {
        cout<<"Fajl olvasasi hiba...";
        return 1;
    }
    int a,b;
    f>>a>>b;
    cout<<a<<" "<<b<<endl;
    szoba Szobak[a];

    for (int i=0;i<a;i++) {
        Szobak[i].szomszedszam=0;
        createQueue(5,&Szobak[i].SzomszedSzobak);
    }
    for (int i=0;i<b;i++) {
        int x,y;

    }
    return 0;
}