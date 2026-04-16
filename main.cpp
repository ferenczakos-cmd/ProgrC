#include <iostream>
#include <ctime>
#include "header/constants.h"
#include  "functions/array.cpp"
#include  "functions/queue.cpp"
#include "functions/stack.cpp"
#include "functions/stringQueue.cpp"
#include "functions/List.cpp"
#include <fstream>


using namespace std;

// 1. FELADAT: Timestamp ellenőrzés
void checkTimestamps(int timestamps[], int n, int window, int limit) {
    Queue q;
    createQueue(n + 1, &q); // Elég nagy sor a kéréseknek

    printf("Rate Limiter vizsgalat:\n");
    for (int i = 0; i < n; i++) {
        int current = timestamps[i];

        // Megnézzük, mi volt a sorban az 5-tel ezelőtti elem (limit)
        // Ha a sorban már van legalább 'limit' darab elem
        int count = 0;
        if (!isEmpty(q)) {
            if (q.rear >= q.front) count = q.rear - q.front + 1;
            else count = (q.capacity - q.front) + (q.rear + 1);
        }

        if (count < limit) {
            // Ha még nincs tele a limit, simán hozzáadjuk
            enqueue(&q, current);
            printf("Timestamp %d: OK (Hozzaadva)\n", current);
        } else {
            // Ha már van bent legalább 'limit', megnézzük a legelsőt a sorban
            int oldestInLimit = q.elements[q.front];
            if (current - oldestInLimit >= window) {
                // Ha eltelt 'window' mp az 'limit'-tel ezelőtti óta, mehet be az új
                //dequeue(&q); // A régit kivesszük, hogy tartsuk a limitet
                enqueue(&q, current);
                printf("Timestamp %d: OK (Hozzaadva)\n", current);
            } else {
                // Ha túl sűrűn jöttek, nem adjuk hozzá a sorhoz
                printf("Timestamp %d: ELUTASITVA (Tul sok keres)\n", current);
            }
        }
        display(q);
    }
    destroyQueue(&q);
}

// 2. FELADAT: Maximum keresés az ablakban
void slidingWindowMaxCircular(int nums[], int n, int k) {
    // 1. Kezdjük egy nagyon kicsi számmal (vagy az első számított max-szal)
    int globalMax = -1000000;
    printf("Output: [ ");

    for (int i = 0; i < n; i++) {
        Queue q;
        createQueue(k + 1, &q);

        for (int j = 0; j < k; j++) {
            int circularIndex = (i + j) % n;
            enqueue(&q, nums[circularIndex]);
        }

        // Itt keressük meg az AKTUÁLIS ablak maximumát
        int currentWindowMax = q.elements[q.front];
        int idx = q.front;
        while (true) {
            if (q.elements[idx] > currentWindowMax) {
                currentWindowMax = q.elements[idx];
            }
            if (idx == q.rear) break;
            idx = (idx + 1) % q.capacity;
        }

        printf("%d ", currentWindowMax);

        // 2. Frissítjük a globális maximumot, ha a mostani ablaké nagyobb
        if (currentWindowMax > globalMax) {
            globalMax = currentWindowMax;
        }

        destroyQueue(&q);
    }
    // Itt a végén a legeslegnagyobb számot kapod meg
    printf("] -> Max: %d\n", globalMax);
}

int main() {
    // 1. Teszt
    int timestamps[] = {1, 2, 3, 4, 5, 6, 8, 12, 13};
    checkTimestamps(timestamps, 9, 5, 3);

    printf("\n---\n");

    // 2. Teszt
    int nums[] = {8, 3, -1, -3, 5, 3, 6, 7};
    slidingWindowMaxCircular(nums, 8, 3);

    return 0;
}