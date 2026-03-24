#include <iostream>
#include <cstdlib>
#include <fstream>
//#include  "functions/functions.cpp"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

 int intCMP(const void*a,const void*b ) {
    int arg1 = *(int*)a;
    int arg2 = *(int*)b;
    return arg1-arg2;
}

using namespace std;
// cukorkak -> moho modszert fogok alkalmazni
void I() {
    cout<<"A beolvasott adatok:"<<endl;

    // elosszor beolvassuk az adatokat
    ifstream f;
    f.open("cukorka.txt");
    int n,m;
    f>>n;
    cout<<n<<endl;
    // feltetelezek max 100 gyereket
    int x[100]={0};
    for(int i=0;i<n;i++) {
        f>>x[i];
        cout<<x[i]<<" ";
    }
    f>>m;
    cout<<endl<<m<<endl;
    // feltetelezek max 100 cukorkat
    int y[100]={0};
    for(int i=0;i<m;i++) {
        f>>y[i];
        cout<<y[i]<<" ";
    }
    f.close();

    // rendezni kell a tomboket
    qsort(x,n,sizeof(int),intCMP);
    qsort(y,m,sizeof(int),intCMP);

    //Teszteles miatt kiiratom a tomboket ujbol
    cout<<endl<<"A rendezett tombok:"<<endl;
    cout<<n<<endl;
    for(int i=0;i<n;i++) {
        cout<<x[i]<<" ";
    }
    cout<<endl<<m<<endl;
    for(int i=0;i<m;i++) {
        cout<<y[i]<<" ";
    }

    // moho megoldas alkalmazasa
    int cukorkaindex=0;
    int boldogGyerek=0;
    //vegigmegyunk a gyerekek listajan
    for(int i=0;i<n;i++) {
        //keressuk a megfelelo cukorkat, ha meg van nagyobb cukorka
        if (cukorkaindex<m) {
            for(int j=cukorkaindex;j<m;j++) {
                if (x[i]<=y[j]) {
                    // ez utan csak a nagyobb cukorkakat nezzuk
                    cukorkaindex=j+1;
                    boldogGyerek++;
                    // haladjuk tovabb a kovetkezo gyerekre
                    break;
                }
            }
        }

    }
    cout<<endl<<"A boldog gyerekek szama: "<<boldogGyerek<<endl;
}
// penz -> backtracking kell
int penz[100][2];int penzdarab=0;

int tomb[100]={0};
void backtrack(int index, int target) {
    for (int i=0;i<=penzdarab;i++) {
        tomb[index]=penz[i][0];
        // ellenorizzuk, hogy ne hasznalunk-e tul sokat az adott penzermebol
        if (igeretes()) {
            if (megoldas()){kiir()}
            backtrack(index+1,target);
        }else {
            // elhagyuk az agat, nincs tobb meghivas
        }

    }
}


void II() {
    cout<<"A beolvasott adatok:"<<endl;
    ifstream f;
    f.open("penzek.txt");
    int a,b;
    while (f>>a>>b){
        penz[penzdarab][0]=a;penz[penzdarab][1]=b;
        penzdarab++;
    }
    f.close();
    int target = 786;
    cout<<"Adja meg, mekkora osszeget kell kifizetni: ";cin>>target;
    backtrack(0,target);
}

int main() {
    I();
    return 0;
}