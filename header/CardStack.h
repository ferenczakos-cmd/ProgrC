#ifndef STACK_CARDSTACK_H
#define STACK_CARDSTACK_H
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
} CardStack;

/**
* Inicializálja a verem kapacitását és tetejét.
*/
void createCardStack(int capacity, CardStack * stack);

/**
* Felszabadítja a veremhez lefoglalt memóriát.
*/
void destroyCardStack(CardStack* stack);

bool isCardStackFull(Stack stack);
bool isCardStackEmpty(Stack stack);

/**
* Új kártya pointert helyez a verembe.
*/
void CardStackPush(CardStack* stack, Card_t* item);

/**
* Eltávolítja a verem tetején lévő kártya pointert.
*/
Card_t* CardStackPop(CardStack* stack);

/**
* Visszaadja a verem tetején lévő kártya pointert.
*/
Card_t* CardStackPeek(CardStack stack);

int size(CardStack stack);

#endif