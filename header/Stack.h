#ifndef STACK_STACK_H
#define STACK_STACK_H
#include <stdbool.h>
/**
* Egy struktúra, amely egy egész számokat tartalmazó veremet reprezentál.
* @param capacity - a verem kapacitása
* @param top - a verem tetejének indexe
* @param elements - pointer a verem elemeire
*/
typedef struct {
    int capacity;
    int top;
    int *elements;
} Stack;
/**
* Inicializálja a verem kapacitását és tetejét,
* memóriát foglal az @elements tömbhöz.
* @param capacity - a verem kapacitása
* @param stack - pointer a verem struktúrájához
*/
void createStack(int capacity, Stack * stack);
/**
* Felszabadítja a veremhez lefoglalt memóriát.
* @param stack - pointer a verem struktúrájához
*/
void destroyStack(Stack* stack);
/**
* Ellenőrzi, hogy a verem tele van-e.
* @param stack - a verem struktúrája
* @return igaz, ha tele van, hamis egyébként
*/
bool isFull(Stack stack);
/**
* Ellenőrzi, hogy a verem üres-e.
* @param stack - a verem struktúrája
* @return igaz, ha üres, hamis egyébként
*/
bool isEmpty(Stack stack);
/**
* Új elemet helyez a verembe, ha nincs tele.
* @param stack - pointer a verem struktúrájához
* @param item - a beszúrandó elem
*/
void push(Stack* stack, int item);
/**
* Eltávolítja a verem tetején lévő elemet, ha nem üres.
* @param stack - pointer a verem struktúrájához
* @return a levett elem értéke
*/
int pop(Stack* stack);
/**
* Visszaadja a verem tetején lévő elemet, ha nem üres.
* @param stack - a verem struktúrája
* @return a tetején lévő elem értéke
*/
int peek(Stack stack);
/**
* Visszaadja a verem méretét.
* @param stack - a verem struktúrája
* @return a verem elemeinek száma
*/
int size(Stack stack);
#endif