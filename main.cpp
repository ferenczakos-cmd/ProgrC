#include <iostream>

using namespace std;

//
int n, limit_sum;
int x[100];              // Az 1. feladathoz
int szo_indexek[10];     // A 2. feladathoz
char mgh[] = "aeiou";    // A 2. feladathoz
int szamjegyek[20];      // A 3. feladathoz

// 1 --------------------------------------------------
void kiir_1(int k) {
    for (int i = 1; i <= k; i++) cout << x[i];
    cout << " ";
}

bool igeretes_1(int k) {
    if (k > 1 && x[k] <= x[k - 1]) return false;
    if (x[1]==0) return false;
    return true;
}

void back_1(int k) {
    for (int i = 0; i <= 9; i++) {
        x[k] = i;
        if (igeretes_1(k)) {
            if (k == n) kiir_1(k); // megoldas
            else back_1(k + 1);
        }
        
    }
}

// 2 --------------------------------------------------
void kiir_2() {
    for (int i = 1; i <= 5; i++) cout << mgh[szo_indexek[i]];
    cout << " ";
}

void back_2(int k) {
    for (int i = 0; i < 5; i++) {
        szo_indexek[k] = i;
        if (k == 5) kiir_2();
        else back_2(k + 1);
    }
}

// 3 --------------------------------------------------
void kiir_3(int k) {
    for (int i = 1; i <= k; i++) cout << szamjegyek[i];
    cout << " ";
}

bool igeretes_3(int k) {
    if (k == 1 && szamjegyek[k] == 0) return false;
    int osszeg = 0;
    for (int i = 1; i <= k; i++) osszeg += szamjegyek[i];
    return osszeg < limit_sum;
}

void back_3(int k, int max_h) {
    for (int i = 0; i <= 9; i++) {
        szamjegyek[k] = i;
        if (igeretes_3(k)) {
            kiir_3(k);
            if (k < max_h) back_3(k + 1, max_h);
        }
    }
}


// 4 --------------------------------------------------
int z[4];
const char* szinek[] = {"", "feher", "fekete", "piros", "kek", "zold", "sarga"};

void kiir_zaszlo() {
    for (int i = 1; i <= 3; i++) cout << szinek[z[i]] << " ";
    cout << endl;
}

bool igeretes_zaszlo(int k) {
    for (int i = 1; i < k; i++) if (z[i] == z[k]) return false;
    if (k == 2 && z[k] != 1 && z[k] != 2) return false;
    return true;
}

bool megoldas_zaszlo(int k){
    return k==3;
}

void back_zaszlo(int k) {
    for (int i = 1; i <= 6; i++) {
        z[k] = i;
        if (igeretes_zaszlo(k)) {
            if (megoldas_zaszlo(k)) kiir_zaszlo();
            else back_zaszlo(k + 1);
        }
    }
}

// 5 --------------------------------------------------
int n_ertek, p_darab;
int t[100];

void kiir_osszeg() {
    for (int i = 1; i <= p_darab; i++) cout << t[i] << (i == p_darab ? "" : "+");
    cout << endl;
}

bool igeretes_osszeg(int k) {
    int s = 0;
    for (int i = 1; i <= k; i++) s += t[i];
    if (s > n_ertek) return false;

    if (k == p_darab && s != n_ertek) return false;
    return true;
}

bool megoldas_osszeg(int k){
    return k == p_darab;
}

void back_osszeg(int k) {
    for (int i = 1; i <= n_ertek; i++) {
        t[k] = i;
        if (igeretes_osszeg(k)) {
            if (megoldas_osszeg(k)) kiir_osszeg();
            else back_osszeg(k + 1);
        }
    }
}

// 6 --------------------------------------------------
int n_osszes, p_nok, k_tag, q_no_kell;
int d[100];

void kiir_delegacio() {
    for (int i = 1; i <= k_tag; i++) cout << d[i] << " ";
    cout << endl;
}

bool igeretes_delegacio(int k) {
    int db_no = 0;
    for (int i = 1; i <= k; i++) {
        if (d[i] <= p_nok) db_no++;
    }
    return db_no <= q_no_kell;
}

void back_delegacio(int k) {
    for (int i = 1; i <= n_osszes; i++) {
        d[k] = i;
        if (igeretes_delegacio(k)) {
            if (k == k_tag) kiir_delegacio();
            else back_delegacio(k + 1);
        }
    }
}

// 7 --------------------------------------------------
int v[4]; // v[1]=x, v[2]=y, v[3]=z

void kiir_egyenlet() {
    cout << "x=" << v[1] << ", y=" << v[2] << ", z=" << v[3] << endl;
}

bool igeretes_egyenlet(int k) {
    if (k == 3) return (3 * v[1] + v[2] + 4 * v[1] * v[3] == 100);
    if (3 * v[1] > 100) return false;
    return true;
}

void back_egyenlet(int k) {
    for (int i = 0; i <= 100; i++) {
        v[k] = i;
        if (igeretes_egyenlet(k)) {
            if (k == 3) kiir_egyenlet();
            else back_egyenlet(k + 1);
        }
        if (k == 1 && 3 * i > 100) break;
    }
}

int main() {
    int valasztas;
    while(true){
        cout << "Valassz feladatot!\n 1 - novekvo sorozatok\n 2 - mgh.szavak\n 3 - szamjegyosszeg \n 4 - zaszloszinek\n 5 - osszegre bontas\n 6 - delegacio \n 7 - fugveny megoldas\n 0 - kilepes\n A muvelet kodja: ";
        cin >> valasztas;

        if(valasztas == 0 ) return 0;

        if (valasztas == 1) {
            cout << "Milyen hosszu novekvo sorozatokat szeretnel (n)? ";
            cin >> n;
            back_1(1);
        } 
        else if (valasztas == 2) {
            cout << "Az osszes 5 betus maganhangzos szo:\n";
            back_2(1);
        } 
        else if (valasztas == 3) {
            cout << "Add meg a maximalis osszeget (sum): ";
            cin >> limit_sum;
            cout << "Add meg a szamjegyek maximalis szamat: ";
            int m; cin >> m;
            back_3(1, m);
        }
        else if(valasztas == 4){
            cout << "A lehetseges zaszlok:\n";
            back_zaszlo(1);
        }
        else if(valasztas == 5){
            cout << "Addd meg, melyik szamot bontsam fel:";
            cin >> n_ertek;
            cout << "Add meg, hany szamra bontsam fel:";
            cin >> p_darab;
            back_osszeg(1);
        }
         else if(valasztas == 6){
            cout << "Add meg, hany tag van a delegacioban:";
            cin >> n_osszes;
            cout << "Add meg, ebbol az elso hany no:";
            cin >> p_nok;
            cout << "Add meg, mekkora delegaciot alitsunk ossze:";
            cin>>k_tag;
            cout << "Add meg, hany no legyen a delegacioban:";
            cin >> q_no_kell;
            back_delegacio(1);

        } 
        else if(valasztas == 7){
            back_egyenlet(1);
        }
        else {
            cout << "Ervenytelen valasztas!";
        }
        cout << endl;
    }
    return 0;
}