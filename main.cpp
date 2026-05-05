#include <iostream>
#include <ctime>
#include "header/constants.h"
#include  "functions/array.cpp"
#include  "functions/queue.cpp"
#include "functions/stack.cpp"
#include "functions/CardStack.cpp"
#include "functions/stringQueue.cpp"
#include "functions/List.cpp"
#include "functions/CircularList.cpp"
#include <fstream>
#include <filesystem>

using namespace std;

void hatizsak() {
    int n = 3;             // Tárgyak száma
    int W = 5;             // Hátizsák kapacitása

    int weights[] = {2, 3, 4}; // Tárgyak súlyai
    int values[] = {3, 4, 5};  // Tárgyak értékei

    int dp[4][6];

    // 3. A táblázat feltöltése (inicializálás nullákkal)
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0; // Ha nincs tárgy vagy nincs hely, az érték 0
            }
            else if (weights[i - 1] <= j) {
                // Ha a tárgy befér: megnézzük, jobb-e ha berakjuk
                int ertek_ha_berakjuk = values[i - 1] + dp[i - 1][j - weights[i - 1]];
                int ertek_ha_kihagyjuk = dp[i - 1][j];

                if (ertek_ha_berakjuk > ertek_ha_kihagyjuk) {
                    dp[i][j] = ertek_ha_berakjuk;
                } else {
                    dp[i][j] = ertek_ha_kihagyjuk;
                }
            }
            else {
                // Ha a tárgy túl nehéz, marad az előzőleg elért max érték
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // 4. Eredmény kiírása
    cout << "A maximalis ertek, amit elvihetunk: " << dp[n][W] << endl;
    cout << "A renddezesi matrix: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

}

void leghosszabbSorozat() {
    int x[10]={5, 2, 3, 10, 6, 1, 10, 0};
    // keressuk az elso nem 0 inddexet
    int i=9;
    while (x[i]==0) i--;
    cout << i << endl;
    int n=i;

    // trackerben szamoljuk, hogy a szam utan mekkora a legnagyobb felepitheto novekvo sorrend
    int tracker[10]={0};
    tracker[i+1] = 1;
    while (i!=-1) {
        for (int j=i+1; j<=n; j++) {
            if (x[i]<x[j] && tracker[i]<=tracker[j]) {
            tracker[i] = tracker[j]+1;
            }
        }
        if (tracker[i]==0) tracker[i] = 1;
        i--;
    }

    for (int i=0; i<=n; i++) {
        cout << tracker[i]<<" ";
    }

    // 3. A leghosszabb sorozat hosszának megkeresése
    int maxHossz = 0;
    for (int k = 0; k <= n; k++) {
        if (tracker[k] > maxHossz) maxHossz = tracker[k];
    }
    cout << endl;
    cout << "Leghosszabb sorozat hossza: " << maxHossz << endl;

    // 4. A konkrét elemek kiíratása
    cout << "A sorozat elemei: ";
    int aktualisHossz = maxHossz;
    int utolsoErtek = -2147483648; // Nagyon kicsi szám (INT_MIN)

    for (int k = 0; k <= n; k++) {
        // Ha az elem illeszkedik a sorrendbe és a várt hosszúságot adja
        if (tracker[k] == aktualisHossz && x[k] > utolsoErtek) {
            cout << x[k] << " ";
            utolsoErtek = x[k];
            aktualisHossz--; // A következő elemet keressük, ami eggyel rövidebb sorozatot indít
        }
    }
    cout << endl;
}

int main() {
    /*ifstream input("Names.txt");
    if (!input) {
        cout<<"File not found"<<endl;
        cout << "The program is looking in: "<< std::filesystem::current_path() << endl;
    }

    Nodee* head = NULL;
    Child tempChild;

    while (input>>tempChild.firstName>>tempChild.lastName) {
        insertAtEnd(&head, tempChild);
    }
    input.close();

    // Lista kiírása ellenőrzésképpen
    printf("\nA lista eredeti tartalma:\n");
    if (!isEmpty(head)) {
        printList(head);
    }

    int n;
    cout << "Minden hanyadikat toroljem? ";
    cin >> n;
    cout << endl;

    Nodee* current = head;

    while (size(head) > 1) {
        for (int j = 1; j < n; j++) {
            current = current->next;
        }

        Child toDelete = current->data;

        Nodee* nextTarget = current->next;

        cout<<"Fireed: "<<toDelete.firstName<<" "<< toDelete.lastName<<endl;
        deleteNode(&head, toDelete);

        current = nextTarget;

        cout<<"Remaining:"<< size(head)<<endl;
        printList(head);
        cout<<"-------------------------------------------------------------------------"<<endl;
    }

    printf("\nAz utolso maradt szemely: %s %s\n", head->data.lastName, head->data.firstName);
    */
    //hatizsak();
    leghosszabbSorozat();
    return 0;
}



