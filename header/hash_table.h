#ifndef HASH_STATIC_HASH_TABLE_H
#define HASH_STATIC_HASH_TABLE_H
#define CAPACITY 31

/**
* Egy hasító tábla elemet reprezentáló struktúra.
* @param key - az elem kulcsa
* @param data - az elem adata
*/
typedef struct {
    int key;
    char *data;
} HashItem;
/**
* Egy hasító tábla struktúra.
* @param items - pointer a hash tábla elemeire
* @param size - a hasító tábla aktuális elemeinek száma
*/
typedef struct {
    HashItem *items;
    int size;
} HashTable;

/**
* Dummy adat az üres elemek megjelölésére.
*/
static HashItem dummyData = {-1, NULL};
/**
* Memóriát foglal egy hasító táblához a megadott mérettel.
* @param pHashTable - pointer a hasító tábla struktúrájához
*/
void createHashArray(HashTable *pHashTable);
// Ez csak a .c fájlban érhető el.
// int hashCode(int key);
/**
* Új adatot szúr be a hasító táblába.
* @param hashTable - a hasító tábla struktúrája
* @param key - az új adat kulcsa
* @param data - az új adat értéke
*/
void insertHashTable(HashTable *hashTable, int key, int data);
/**
* Töröl egy elemet a hasító táblából a megadott kulcs alapján.
* @param hashTable - a hasító tábla struktúrája
* @param key - a törlendő adat kulcsa
*/
void deleteHashTable(HashTable *hashTable, int key);
/**
* Megkeresi egy adott kulcshoz tartozó adatot a hasító táblában.
* @param hashTable - a hasító tábla struktúrája
* @param key - a keresett adat kulcsa
* @return az elem pozíciója, ha megtalálja, -1 ha nem található
*/
int searchHashTable(HashTable hashTable, int key);
/**
* Kiírja a hasító tábla tartalmát a standard kimenetre.
* @param hashTable - a hasító tábla struktúrája
*/
void displayHashTable(HashTable hashTable);
/**
* Visszaadja a hasító táblában található elemek számát.
* @param hashTable - a hasító tábla struktúrája
* @return az elemek száma
*/
int sizeHashTable(HashTable hashTable);
/**
* Felszabadítja a hasító tábla memóriáját.
* @param pHashTable - pointer a hasító tábla struktúrájához
*/
void destroyHashArray(HashTable *pHashTable);
#endif