#include <iostream>
#include <ctime>
#include "header/constants.h"
#include  "functions/array.cpp"
#include  "functions/queue.cpp"
#include "functions/stack.cpp"
#include "functions/CardStack.cpp"
#include "functions/stringQueue.cpp"
#include "functions/List.cpp"
#include <fstream>
#include <filesystem>
using namespace std;

int main() {
    ifstream input("viragok.txt");
    if (!input) {
        cout<<"File not found"<<endl;
        cout << "The program is looking in: "<< std::filesystem::current_path() << endl;
    }
    int n,m;
    input>>n>>m;
    cout<<"n:"<<n<<" m:"<<m<<endl;
    int e[n+1][m+1];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            input>>e[i][j];
            cout<<e[i][j]<<" ";
        }
        cout<<endl;
    }

    input.close();

    cout<<endl<<"MAX:"<<endl;
    int c[n+1][m+1];
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            c[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=i;j<i+n;j++) {
            c[i][j]=max(c[i-1][j-1]+e[i-1][j-1],c[i][j-1]);
        }
    }
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    int aktualis_vaza = m;
    for (int i = n; i > 0; i--) {
        // Addig megyünk balra, amíg az érték ugyanaz marad (tehát nem itt dőlt el a max)
        while (aktualis_vaza > i && c[i][aktualis_vaza] == c[i][aktualis_vaza - 1]) {
            aktualis_vaza--;
        }

        // Itt találtuk meg, melyik vázába került az i-edik virág
        cout << i << ". virag -> " << aktualis_vaza << ". vaza" << endl;

        // Mivel ezt a virágot leraktuk, a következő (előző) virágot már csak
        // az ettől balra lévő vázákba tehettük
        aktualis_vaza--;
    }

    cout<<endl<<"MIN:"<<endl;
    int d[n+1][m+1];
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            d[i][j]=99;
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=i;j<i+n;j++) {
            d[i][j]=min(c[i-1][j-1]+e[i-1][j-1],c[i][j-1]);
        }
    }
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    aktualis_vaza = m;
    for (int i = n; i > 0; i--) {
        // Addig megyünk balra, amíg az érték ugyanaz marad (tehát nem itt dőlt el a max)
        while (aktualis_vaza > i && d[i][aktualis_vaza] == d[i][aktualis_vaza - 1]) {
            aktualis_vaza--;
        }

        // Itt találtuk meg, melyik vázába került az i-edik virág
        cout << i << ". virag -> " << aktualis_vaza << ". vaza" << endl;

        // Mivel ezt a virágot leraktuk, a következő (előző) virágot már csak
        // az ettől balra lévő vázákba tehettük
        aktualis_vaza--;
    }

    return 0;
}