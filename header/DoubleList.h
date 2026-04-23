#ifndef LINKEDLIST_LINKED_LIST_H
#define LINKEDLIST_LINKED_LIST_H
#include <stdbool.h>
/**
* Egy csomópontot reprezentáló struktúra.
* @param data - a csomópont által tárolt adat (egész szám)
* @param next - pointer a következő csomópontra
*/
typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
/**
* Memóriát foglal egy új csomóponthoz.
* @param new_data - az új csomópont adata
* @return pointer az újonnan lefoglalt csomópontra
*/
Node* newNode(int new_data);
/**
* Ellenőrzi, hogy a lista üres-e (a head NULL pointer).
* @param head - a lista kezdőcsomópontja
* @return igaz, ha üres, hamis egyébként
*/
bool isEmpty(Node *head);
/**
* Új csomópontot szúr be a lista elejére.
* @param head_ref - pointer a lista kezdőcsomópontjára mutató pointerre
* @param new_data - az új csomópont adata
*/
void insertAtBeginning(Node** head_ref, int new_data);
/**
* Új csomópontot szúr be egy adott csomópont után.
* @param prev_ref - pointer az előző csomópontra
* @param new_data - az új csomópont adata
*/
void insertAfter(Node* prev_ref, int new_data);
/**
* Új csomópontot szúr be a lista végére.
* @param head_ref - pointer a lista kezdőcsomópontjára mutató pointerre
* @param new_data - az új csomópont adata
*/
void insertAtEnd(Node** head_ref, int new_data);
/**
* Törli a lista első csomópontját.
* @param head_ref - pointer a lista kezdőcsomópontjára mutató pointerre
*/
void deleteFromBeginning(Node** head_ref);
/**
* Törli a lista utolsó csomópontját.
* @param head_ref - pointer a lista kezdőcsomópontjára mutató pointerre
*/
void deleteFromEnd(Node** head_ref);
/**
* Töröl egy adott csomópontot a lista kulcs alapján.
* @param head_ref - pointer a lista kezdőcsomópontjára mutató pointerre
* @param key - a törlendő csomópont adata
*/
void deleteNode(Node** head_ref, int key);
/**
* Megkeres egy adott kulccsal rendelkező csomópontot.
* @param head_ref - a lista kezdőcsomópontja
* @param key - a keresett adat
* @return igaz, ha megtalálta, hamis egyébként
*/
bool searchNode(Node* head_ref, int key);
/**
* A lista elemeit növekvő sorrendbe rendezi.
* @param head_ref - a lista kezdőcsomópontja
*/
void sortLinkedList(Node* head_ref);
/**
* Kiírja a lista összes elemét.
* @param node - a lista kezdőcsomópontja
*/
void printList(Node* node);
/**

3

* Felszabadítja a lista elemeihez lefoglalt memóriát.
* @param head - pointer a lista kezdőcsomópontjára mutató pointerre
*/
void freeList(Node **head);
#endif