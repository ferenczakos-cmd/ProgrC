#include <iostream>
#include <cstdlib>
#include <fstream>
//#include  "functions/functions.cpp"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

const int intCMP(const void*a,const void*b ) {
    int arg1 = *(int*)a;
    int arg2 = *(int*)b;
    return arg1-arg2;
}

using namespace std;
// cukorkak -> moho modszert fogok alkalmazni
void I() {
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
    qsort(x,m,sizeof(int),intCMP());
    // moho megoldas alkalmazasa
}
// penz -> backtracking kell
void II() {

}

int main() {
    I();
    return 0;
}