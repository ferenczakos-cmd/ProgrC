#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include "../functions/Stack.cpp"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


using namespace std;

typedef struct {
    int ID,birthYear,brutto;
    string gender;
    float netto;
} Alkalmazott;

void netto(Alkalmazott *alkalmazott,int i) {
    float szorzo=70;
    if (alkalmazott->gender=="NO") {
        szorzo+=5;
    }
    if (alkalmazott->birthYear>2000) {
        szorzo+=10;
    }
    szorzo/=100;
    alkalmazott->netto=alkalmazott->brutto*szorzo;
}

void I() {
    ifstream inputFile;
    inputFile.open("ceg.txt");
    if (!inputFile.is_open()) {
        cout << "Hiba: A fajlt nem sikerult megnyitni!" << endl;
        return;
    }
    string CegNev="\0";
    int alkalmazottakSzama;
    inputFile>>CegNev>>alkalmazottakSzama;
    Alkalmazott alkalmazott[alkalmazottakSzama];
    for (int i=0;i<alkalmazottakSzama;i++) {
        int a,b,c;
        string gen;
        inputFile>>a>>b>>gen>>c;
        alkalmazott[i].ID=a;
        alkalmazott[i].birthYear=b;
        alkalmazott[i].brutto=c;
        alkalmazott[i].gender=gen;
        netto(&alkalmazott[i],i);
    }
    cout<<"Az Alkalmazottak:"<<endl;
    for (int i=0;i<alkalmazottakSzama;i++) {
        cout<<alkalmazott[i].ID<<" "<<alkalmazott[i].birthYear<<" "<<alkalmazott[i].gender<<" "<<alkalmazott[i].brutto<<" "<<alkalmazott[i].netto<<endl;
    }
}

void Remove(string szo) {
    if (szo.empty()) {
        cout << "Vegleges Szo: " << endl;
        return;
    }

    Stack myStack;
    int length = szo.length();
    // Use a safe capacity
    createStack(length + 1, &myStack);

    bool deleted = false;

    push(&myStack, (int )szo[0]);
    for (int i = 1; i < length; i++) {

        if (!isEmpty(myStack) && (peek(myStack) == szo[i] + 32 || peek(myStack) == szo[i] - 32)) {
            char popped = (char)pop(&myStack);
            //cout<<"Popped: "<<popped<<endl;
            deleted = true;
        } else {
            push(&myStack, (int)szo[i]);
        }
    }

    string ujSzo = "";
    while (!isEmpty(myStack)) {

        char c = (char)pop(&myStack);
        ujSzo = c + ujSzo;
    }

    if (deleted) {
        destroyStack(&myStack);
        Remove(ujSzo);
    } else {
        cout << "Vegleges Szo: " << ujSzo << endl;
        destroyStack(&myStack);
    }
}

int main() {
    Remove("leEeetcode");
    return 0;
}