#ifndef STACK_STACK_H
#define STACK_STACK_H
#include <stdbool.h>

/**
* Kártya értékek típusa.
*/
typedef enum {
    KETTO, HAROM, NEGY, OT, HAT, HET, NYOLC,
    KILENC, TIZ, BUBI, DAMA, KIRALY, ASZ
} Szam_t;

/**
* Egy kártyát reprezentáló struktúra.
*/
typedef struct {
    char szin[10]; // Megnövelve 10-re, hogy a "Kör/Pikk/Treff" kényelmesen elférjen
    Szam_t ertek;
} Card_t;

/**
* Egy struktúra, amely Card_t pointereket tartalmazó veremet reprezentál.
*/
typedef struct {
    int capacity;
    int top;
    Card_t **elements;
} Stack;

/**
* Inicializálja a verem kapacitását és tetejét.
*/
void createStack(int capacity, Stack * stack);

/**
* Felszabadítja a veremhez lefoglalt memóriát.
*/
void destroyStack(Stack* stack);

bool isFull(Stack stack);
bool isEmpty(Stack stack);

/**
* Új kártya pointert helyez a verembe.
*/
void push(Stack* stack, Card_t* item);

/**
* Eltávolítja a verem tetején lévő kártya pointert.
*/
Card_t* pop(Stack* stack);

/**
* Visszaadja a verem tetején lévő kártya pointert.
*/
Card_t* peek(Stack stack);

int size(Stack stack);

#endif