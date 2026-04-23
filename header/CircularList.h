#ifndef CIRCULARLINKEDLIST_CIRCULAR_LINKED_LIST_H
#define CIRCULARLINKEDLIST_CIRCULAR_LINKED_LIST_H
#include <stdbool.h>
/**
* Egy gyermeket reprezentáló struktúra.
* @param firstName - a gyermek keresztneve
* @param lastName - a gyermek vezetékneve
*/
typedef struct {
    char firstName[20];
    char lastName[20];
} Child;
/**
* Egy csomópontot reprezentáló struktúra a körkörös láncolt listában.
* @param data - a csomópont által tárolt gyermek adatai
* @param next - pointer a következő csomópontra
*/
typedef struct Nodee{
    Child data;
    struct Nodee* next;
} Nodee;
/**
* A lista elemeinek száma.
* @param node - a lista kezdőcsomópontja
* @return a gyermekek teljes száma
*/
int size(Nodee* node);
/**
* Összehasonlít két gyermeket név alapján.
* @param child1 - az első gyermek adatai
* @param child2 - a második gyermek adatai
* @return -1, ha az első kisebb, 1, ha nagyobb, 0, ha egyenlőek
*/
int compare(Child child1, Child child2);
/**
* Memóriát foglal egy új csomóponthoz.
* @param new_data - az új csomópont adatai
* @return pointer az újonnan lefoglalt csomópontra
*/
Nodee* newNode(Child new_data);
/**
* Ellenőrzi, hogy a lista üres-e (a head NULL pointer).
* @param head - a lista kezdőcsomópontja
* @return igaz, ha üres, hamis egyébként
*/
bool isEmpty(Nodee *head);
/**
* Új csomópontot szúr be a lista végére.
* @param head_ref - pointer a lista kezdőcsomópontjára mutató pointerre
* @param new_data - az új csomópont adatai
*/
void insertAtEnd(Nodee** head_ref, Child new_data);
/**
* Töröl egy adott csomópontot a gyermek adatai alapján.
* @param head_ref - pointer a lista kezdőcsomópontjára mutató pointerre
* @param key - a törlendő gyermek adatai
*/
void deleteNode(Nodee** head_ref, Child key);
/**
* Kiírja a lista összes elemét.
* @param node - a lista kezdőcsomópontja
*/
void printList(Nodee* node);
#endif