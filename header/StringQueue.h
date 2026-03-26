#include <stdbool.h>
#define CAR_PLATE_NUMBER_LIMIT 10
/**
* Egy struktúra, amely egy sor típusú adatstruktúrát reprezentál.
* @param capacity - a sor kapacitása
* @param front - a sor elejének indexe
* @param rear - a sor végének indexe
* @param elements - pointer a sor elemeire (karakterláncok)
*/
typedef struct {
    int capacity;
    int front;
    int rear;
    char **elements;
} StringQueue;

/**
* Létrehozza a sor adatstruktúrát, memóriát foglal az elemek számára.
* @param capacity - a sor kapacitása
* @param queue - pointer a sor struktúrájához
*/
void createQueueString(int capacity, StringQueue *queue);

/**
* Felszabadítja az elemek tömbjéhez lefoglalt memóriát.
* @param queue - pointer a sor struktúrájához
*/
void destroyQueueString(StringQueue* queue);
/**
* Ellenőrzi, hogy a sor tele van-e.
* @param queue - a sor struktúrája
* @return igaz, ha tele van, hamis egyébként
*/
bool isFullString(StringQueue queue);
/**
* Ellenőrzi, hogy a sor üres-e.
* @param queue - a sor struktúrája
* @return igaz, ha üres, hamis egyébként
*/
bool isEmptyString(StringQueue queue);
/**
* Új elemet ad a sor végéhez (FIFO).
* @param queue - pointer a sor struktúrájához
* @param item - a hozzáadandó elem (karakterlánc)
*/
void enqueueString(StringQueue* queue, char* item);
/**
* Eltávolítja a sor elején lévő elemet.
* @param queue - pointer a sor struktúrájához
* @return a levett elem (karakterlánc)
*/
char* dequeueString(StringQueue* queue);
/**
* Kiírja a sor összes elemét.
* @param queue - a sor struktúrája
*/
void display(StringQueue queue);