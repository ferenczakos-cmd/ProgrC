#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../functions/hash_table.cpp"

using namespace std;

typedef struct diak {
    int Id;
    string nev,osztaly;
    int jegy;
};

void I() {

    HashTable table;
    createHashArray(&table);


    diak diakTomb[110];
    int counter =1;


    // Diakok beolvasasa
    ifstream f;
    f.open("kmooc.txt");
    string sor;
    while(f>>sor) {
        string sor2;
        f>>sor2;
        sor=sor+" "+sor2;
        //cout<<sor<<endl;

        //sorok lebontasa
        int ID =0;
        ID-=(48-sor[0])*1000+(48-sor[1])*100+(48-sor[2])*10+(48-sor[3]);


        string nev="";
        int i=5;
        while (sor[i]!=',') {
            nev=nev+sor[i];

            i++;
        }

        i++;
        string osztaly="";
        while (i<sor.length()) {
            osztaly=osztaly+sor[i];

            i++;
        }

        diak newDiak;
        newDiak.Id=ID;
        newDiak.nev=nev;
        newDiak.osztaly=osztaly;

        diakTomb[counter]=newDiak;
        counter++;

        Diak actualDiak;
        actualDiak.Id=ID;
        for (int i=0;i<50;i++) {
            actualDiak.nev[i]=nev[i];
        }
        for (int i=0;i<10;i++) {
            actualDiak.osztaly[i]=osztaly[i];
        }

        int szamjegyosszeg=48-sor[0]+48-sor[1]+48-sor[2]+48-sor[3];
        szamjegyosszeg=-szamjegyosszeg;

        insertHashTable(&table,szamjegyosszeg,actualDiak);
    }
    f.close();
    displayHashTable(table);
    // diakok kiirasas



    // Eredmenyek beolvasasa
    cout<<"Eredmenyek:"<<endl;
    ifstream g;
    g.open("results.txt");
    string U_sor;
    while (g>>U_sor) {
        int ID =0;
        ID-=(48-sor[0])*1000+(48-sor[1])*100+(48-sor[2])*10+(48-sor[3]);
        int Jegy=0;
        Jegy-=(48-sor[5])*10+(48-sor[6])*1;

        cout<<U_sor<<" "<<ID<<" "<<Jegy<<endl;


    }


    g.close();

}
int main() {
    I();
    return 0;
}