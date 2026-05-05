#include <iostream>
#include <ctime>
#include "header/constants.h"
#include "functions/array.cpp"
#include "functions/queue.cpp"
#include "functions/stack.cpp"
#include "functions/CardStack.cpp"
#include "functions/stringQueue.cpp"
#include "functions/List.cpp"
#include "functions/CircularList.cpp"
#include <fstream>
#include <filesystem>

using namespace std;

struct SzomszedLista {
    int szamlalo=0;
    bool latogatott = false;
    IntArray szomszedok= new IntArray(5);
};

int main(){
    ifstream fin;
    fin.open("input.txt");
    if (!fin) {
        cout<<"File not found"<<endl;
        return 1;
    }
    int a, b;
    fin>>a>>b;
    SzomszedLista* listak = new SzomszedLista[a];
    for (int i=0; i<b; i++) {
        int x,y;
        fin>>x>>y;
        listak[x].szamlalo++;
        listak[x].szomszedok.insertLast(y);
        listak[y].szamlalo++;
        listak[y].szomszedok.insertLast(x);
    }
    fin.close();
    delete[] listak;
    return 0;
}