#include <iostream>

#include <ctime>
#include "header/constants.h"
#include  "functions/array.cpp"
#include  "functions/queue.cpp"
#include "functions/stack.cpp"
#include "functions/stringQueue.cpp"
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Statikus méretkorlátok
const int MAX_N = 1001;
const int MAX_K = 1001;

// Globális tömbök
int suly[MAX_N];
int ertek[MAX_N];
int dp[MAX_N][MAX_K];
int kivalasztott_indexek[MAX_N];

// Mohó módszerhez szükséges segédtömbök
int eredeti_index[MAX_N];
double egyseg_ertek[MAX_N];


void GenerateInput() {
    ofstream fki("bemenet.txt");

    int N = 1000;  // Maximális tárgyszám
    int K = 500;   // Hátizsák kapacitása

    fki << N << " " << K << endl;

    srand(time(0));

    for (int i = 0; i < N; i++) {
        int s = rand() % 50 + 1;  // Súly: 1 és 50 között
        int e = rand() % 100 + 1; // Érték: 1 és 100 között
        fki << s << " " << e << endl;
    }

    fki.close();
    cout << "A bemenet.txt elkeszult "<<N<<" tárggyal!" << endl;
}

int maximalis(int a, int b) {
    return (a > b) ? a : b;
}

void backtrack() {
    ifstream f("bemenet.txt");
    if (!f.is_open()) {
        cout << "Hiba: A bemenet.txt nem talalhato!" << endl;
        return;
    }

    int N, K;
    if (!(f >> N >> K)) return;

    for (int i = 1; i <= N; i++) {
        f >> suly[i] >> ertek[i];
    }
    f.close();

    // DP tábla nullázása
    for(int i = 0; i <= N; i++) for(int j = 0; j <= K; j++) dp[i][j] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            if (suly[i] <= j) {
                dp[i][j] = maximalis(dp[i - 1][j], dp[i - 1][j - suly[i]] + ertek[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << "\n=== BackTrack  ===" << endl;
    cout << "Osszertek: " << dp[N][K] << endl;
    //cout << "Kivalasztott targyak:" << endl;

    int maradek_kapa = K;
    for (int i = N; i > 0; i--) {
        if (dp[i][maradek_kapa] != dp[i - 1][maradek_kapa]) {
            //cout << " - " << i << ". targy (Suly: " << suly[i] << ", Ertek: " << ertek[i] << ")" << endl;
            maradek_kapa -= suly[i];
        }
    }
}

void greedy() {
    ifstream fbe("bemenet.txt");
    if (!fbe.is_open()) return;

    int N, K;
    if (!(fbe >> N >> K)) return;

    for (int i = 1; i <= N; i++) {
        fbe >> suly[i] >> ertek[i];
        eredeti_index[i] = i;
        egyseg_ertek[i] = (double)ertek[i] / suly[i];
    }
    fbe.close();

    // Buborékrendezés (egységnyi érték szerint csökkenő)
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= N - i; j++) {
            if (egyseg_ertek[j] < egyseg_ertek[j + 1]) {
                swap(egyseg_ertek[j], egyseg_ertek[j+1]);
                swap(suly[j], suly[j+1]);
                swap(ertek[j], ertek[j+1]);
                swap(eredeti_index[j], eredeti_index[j+1]);
            }
        }
    }

    int akt_suly = 0;
    int ossz_e = 0;

    cout << "\n=== Moho modszer  ===" << endl;
    //cout << "Kivalasztott targyak:" << endl;
    for (int i = 1; i <= N; i++) {
        if (akt_suly + suly[i] <= K) {
            akt_suly += suly[i];
            ossz_e += ertek[i];
            //cout << " - " << eredeti_index[i] << ". targy (Suly: " << suly[i] << ", Ertek: " << ertek[i] << ")" << endl;
        }
    }
    cout << "Osszertek: " << ossz_e << " (Osszsuly: " << akt_suly << "/" << K << ")" << endl;
}

int main() {
    GenerateInput();
    auto start = high_resolution_clock::now();
    backtrack();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "\nEltelt ido: " << duration.count() << " ms" << endl;

    start = high_resolution_clock::now();
    greedy();
    end = high_resolution_clock::now();
     duration = duration_cast<microseconds>(end - start);
    cout << "\nEltelt ido: " << duration.count() << " ms" << endl;

    return 0;
}