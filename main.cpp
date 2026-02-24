#include <iostream>
#include "header/functions.h"

using namespace std;



///Maximum keresest, ami visszateriti az indexet
int maxindex(int a[],int i,int j){
    if(i==j) return i;
    int m1=maxindex(a,i,(i+j)/2);
    int m2=maxindex(a,(i+j)/2+1,j);
    if(a[m1]>a[m2]){
        return m1;
    }
    return m2;
}

///Minimum kereses, ami visszateriti az erteket
int minindex(int a[],int i,int j);
int minertek(int a[],int i,int j){
    return a[minindex(a,i,j)];
}

 int minindex(int a[],int i,int j){
    if(i==j) return i;
    int m1=minindex(a,i,(i+j)/2);
    int m2=minindex(a,(i+j)/2+1,j);
    if(a[m1]<a[m2]){
        return m1;
    }
    return m2;
}
///Osszegszamitas egy tombben
int tombosszeg(int a[],int i,int j){
    if(i==j) return a[i];
    int m1=tombosszeg(a,i,(i+j)/2);
    int m2=tombosszeg(a,(i+j)/2+1,j);
    return m1+m2;
}

///Szamold meg, hogy hany paratlan szam van
bool paratlan(int n){
    return (n%2==0);
}

int paratlanSzamolas(int a[],int i,int j){
    if(i==j) return (int)paratlan(a[i]);
    int m1=paratlanSzamolas(a,i,(i+j)/2);
    int m2=paratlanSzamolas(a,(i+j)/2+1,j);
    return m1+m2;
}

///Hanoi tornyai
int hanoi(int k, char d,char s,char h){
    if(k==1){
        cout<<"("<<s<<","<<d<<")"<<endl;
    }
    else{
        hanoi(k-1,s,h,d);
        cout<<"("<<s<<","<<d<<")"<<endl;
        hanoi(k-1,h,d,s);
    }
}

///MergeSort
void oszefesul(int x[], int i, int k, int j);
void mergesort(int x[],int i,int j){
    if(i,j){
        int k=(i+j)/2;
        mergesort(x,i,k);
        mergesort(x,k+1,j);
        oszefesul(x,i,k,j);
    }
}

void oszefesul(int x[], int i, int k, int j) {
    int temp[j - i + 1]; // Segédtömb a rendezett elemeknek
    int bal = i;         // Mutató a bal oldali részlet elejére
    int jobb = k + 1;    // Mutató a jobb oldali részlet elejére
    int m = 0;           // A segédtömb indexe

    // Amíg mindkét térfélen van még elem
    while (bal <= k && jobb <= j) {
        if (x[bal] <= x[jobb]) {
            temp[m++] = x[bal++];
        } else {
            temp[m++] = x[jobb++];
        }
    }

    // Ha a bal oldali rész marad ki (mert a jobb oldal elfogyott)
    while (bal <= k) {
        temp[m++] = x[bal++];
    }

    // Ha a jobb oldali rész marad ki (mert a bal oldal elfogyott)
    while (jobb <= j) {
        temp[m++] = x[jobb++];
    }

    // Visszamásoljuk az eredeti tömbbe a rendezett elemeket
    for (int n = 0; n < m; n++) {
        x[i + n] = temp[n];
    }
}
///BinarisKereses
int binarisKereses(int x[], int n, int keresett) {
    int bal = 0;
    int jobb = n - 1;

    while (bal <= jobb) {
        int kozep = bal + (jobb - bal) / 2; // Túlcsordulás elleni védelem

        // Megtaláltuk az elemet?
        if (x[kozep] == keresett) {
            return kozep;
        }

        // Ha az elem kisebb, a bal oldali részben keresünk tovább
        if (x[kozep] > keresett) {
            jobb = kozep - 1;
        }
        // Ha az elem nagyobb, a jobb oldali részben keresünk tovább
        else {
            bal = kozep + 1;
        }
    }

    // Ha kifutottunk a ciklusból, az elem nincs a tömbben
    return -1;
}
int main() {
    int a[5]={5,7,3,2,1};
    cout <<"Hanoi = " << hanoi(3,'a','b','c') << endl;
    //sayHello();
    return 0;
}
