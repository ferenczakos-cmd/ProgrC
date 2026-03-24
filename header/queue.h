#ifndef CIRCULARQUEUE_QUEUE_H
#define CIRCULARQUEUE_QUEUE_H
#include <stdbool.h>
/**
* Egy struktúra, amely egy körkörös sort reprezentál.
* @param capacity - a sor kapacitása
* @param front - a sor elejének indexe
* @param rear - a sor végének indexe
* @param elements - pointer a sor elemeire (egész számok)
*/
typedef struct {
    int capacity;
    int front;
    int rear;
    int *elements;
} Queue;
/**
* Létrehozza a körkörös sort, memóriát foglal az elemek számára.
* @param capacity - a sor kapacitása
* @param queue - pointer a sor struktúrájához
*/
void createQueue(int capacity, Queue *queue);
/**
* Felszabadítja az elemek tömbjéhez lefoglalt memóriát.

2
* @param queue - pointer a sor struktúrájához
*/
void destroyQueue(Queue* queue);
/**
* Ellenőrzi, hogy a körkörös sor tele van-e.
* @param queue - a sor struktúrája
* @return igaz, ha tele van, hamis egyébként
*/
bool isFull(Queue queue);
/**
* Ellenőrzi, hogy a körkörös sor üres-e.
* @param queue - a sor struktúrája
* @return igaz, ha üres, hamis egyébként
*/
bool isEmpty(Queue queue);
/**
* Új elemet ad a körkörös sor végéhez.
* @param queue - pointer a sor struktúrájához
* @param item - a hozzáadandó elem (egész szám)
*/
void enqueue(Queue* queue, int item);
/**
* Eltávolítja a körkörös sor elején lévő elemet.
* @param queue - pointer a sor struktúrájához
* @return a levett elem (egész szám)
*/
int dequeue(Queue* queue);
/**
* Kiírja a körkörös sor összes elemét.
* @param queue - a sor struktúrája
*/
void display(Queue queue);
#endif