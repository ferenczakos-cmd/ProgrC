#include <iostream>
#include "header/constants.h"
#include  "functions/array.cpp"
#include  "functions/queue.cpp"
#include "functions/stack.cpp"
#include "functions/stringQueue.cpp"
#include <fstream>

using namespace std;

/*
 * <string.h>
 * strlen(s)  Visszaadja a string hosszát (a lezáró \0 nélkül).
 * strcmp(s1, s2)   Összehasonlít két stringet. 0-t ad, ha teljesen egyeznek.
 * strcpy(dest, src)   Átmásolja a src tartalmát a dest helyre (lehet veszélyes!).
 * strncpy(dest, src, n)   Biztonságosabb másolás: maximum n karaktert másol át.
 * strcat(dest, src)   Hozzáfűzi a src-t a dest végéhez (konkatenáció).
 * strchr(s, c)   Megkeresi a c karakter első előfordulását a stringben.
 * strstr(s1, s2)   Megkeresi az alstringet (s2) a főstringben (s1).
 * strtok(s, delim)   Szétbontja a stringet "tokenekre" (szavakra) határolójelek mentén.
 */

void RunStack () {
    // ----------------- Stack -------------------
    Stack myStack;
    int capacity = 5;

    // 1. Initialize the stack
    createStack(capacity, &myStack);
    printf("Stack created with capacity: %d\n", capacity);

    // 2. Add some elements (Push)
    printf("Pushing elements: 10, 20, 30\n");
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    // 3. Check the top element (Peek)
    if (!isEmpty(myStack)) {
        printf("Current top element (peek): %d\n", peek(myStack));
    }

    // 4. Check current size
    printf("Current stack size: %d\n", size(myStack));

    // 5. Remove and print elements (Pop)
    printf("Popping elements until empty:\n");
    while (!isEmpty(myStack)) {
        printf("Popped: %d\n", pop(&myStack));
    }

    // 6. Final check
    if (isEmpty(myStack)) {
        printf("The stack is now empty.\n");
    }

    // 7. Clean up memory!
    destroyStack(&myStack);
    printf("Stack memory freed.\n");
}


void RunQueue () {
    // ---------------- Queue ------------------
    Queue myQueue;
    int capacity = 5;

    // 1. Sor inicializálása
    createQueue(capacity, &myQueue);
    printf("Sor letrehozva %d elemnyi kapacitassal.\n", capacity);

    // 2. Elemek hozzáadása (Enqueue)
    printf("Elemek hozzaadasa: 10, 20, 30, 40\n");
    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);
    enqueue(&myQueue, 40);

    // 3. A sor tartalmának megjelenítése
    printf("A sor jelenlegi tartalma: ");
    display(myQueue);

    // 4. Elem kivétele (Dequeue)
    if (!isEmpty(myQueue)) {
        int removed = dequeue(&myQueue);
        printf("Kivett elem: %d\n", removed);
    }

    // 5. Megnézzük, mi maradt benne
    printf("Tartalom a dequeue utan: ");
    display(myQueue);

    // 6. "Körbeérés" tesztelése
    // Ha a sor majdnem tele van, és adunk hozzá újat,
    // a belső logika (modulo operátor) visszaviszi az indexet az elejére.
    printf("Tovabbi elemek hozzaadasa...\n");
    enqueue(&myQueue, 50);
    enqueue(&myQueue, 60);
    enqueue(&myQueue, 70);

    display(myQueue);

    if (isFull(myQueue)) {
        printf("A sor megtelt!\n");
    }

    // 7. Memória felszabadítása
    destroyQueue(&myQueue);
    printf("Memoria felszabaditva.\n");
}


void RunStringQueue() {
    // USE stringQueue here
    StringQueue carQueue;
    int maxCars = 5;

    // 1. Sor inicializálása
    createQueue_String(maxCars, &carQueue);
    printf("Autosor letrehozva (%d hely).\n", maxCars);

    // 2. Rendszámok hozzáadása (Enqueue)
    printf("Autok erkeznek a mosoba...\n");
    enqueue_String(&carQueue, "ABC-123");
    enqueue_String(&carQueue, "XYZ-789");
    enqueue_String(&carQueue, "HUN-001");
    enqueue_String(&carQueue, "HUN-002");

    // 3. Sor állapotának ellenőrzése
    if (isFull_String(carQueue)) {
        printf("A sor megtelt, nem fer be tobb auto.\n");
    }

    // 4. Jelenlegi sor kiírása
    printf("Varakozasi sor: ");
    display_String(carQueue);

    // 5. Elemek eltávolítása (Dequeue)
    printf("\nMosashoz behajt: %s\n", dequeue_String(&carQueue));
    printf("Mosashoz behajt: %s\n", dequeue_String(&carQueue));

    // 6. Új autó érkezik a felszabadult helyre
    printf("Uj auto erkezik: QWE-456\n");
    enqueue_String(&carQueue, "QWE-456");

    printf("Aktualis sor: ");
    display_String(carQueue);

    // 7. Takarítás
    // Megjegyzés: Ha a dequeue során nem szabadítottuk fel a stringeket
    // (esetleges dinamikus foglalas eseten), itt kell figyelni.
    destroyQueue_String(&carQueue);
    printf("\nProgram vege, memoria felszabaditva.\n");

}
void RunStringQueueLines() {
    StringQueue carQueue;
    int maxCars = 10;
    createQueue_String(maxCars, &carQueue);

    // 1. Fájl megnyitása olvasásra (ifstream)
    ifstream inputFile("rendszamok.txt");

    // Ellenőrizzük, sikerült-e megnyitni
    if (!inputFile.is_open()) {
        cout << "Hiba: A rendszamok.txt nem talalhato!" << endl;
        destroyQueue_String(&carQueue);
        return;
    }

    cout << "Rendszamok beolvasasa (ifstream)..." << endl;

    string line;
    // 2. Soronkénti beolvasás
    while (getline(inputFile, line)) {
        // Ellenőrizzük, hogy nem üres-e a sor
        if (!line.empty()) {
            if (!isFull_String(carQueue)) {
                // Mivel a sorunk char*-ot var, konvertálnunk kell: line.c_str()
                enqueue_String(&carQueue, (char*)line.c_str());
                cout << "Beolvasva: " << line << endl;
            } else {
                cout << "A sor megtelt, a tobbi auto varakozik." << endl;
                break;
            }
        }
    }

    // 3. Fájl bezárása (bár az ifstream destruktora magától is megtenné)
    inputFile.close();

    // 4. Eredmény megjelenítése
    display_String(carQueue);

    // 5. Takarítás
    destroyQueue_String(&carQueue);
}

void RunStringQueueWords() {
    StringQueue carQueue;
    int maxCars = 15;
    createQueue_String(maxCars, &carQueue);

    ifstream inputFile("rendszamok.txt");

    if (!inputFile.is_open()) {
        cout << "Hiba: A fajlt nem sikerult megnyitni!" << endl;
        destroyQueue_String(&carQueue);
        return;
    }

    cout << "Rendszamok beolvasasa szavankent..." << endl;

    string word;
    // Az '>>' operátor szóközig, tabig vagy sorvégéig olvas egy szót
    while (inputFile >> word) {
        if (!isFull_String(carQueue)) {
            // Konvertálás string -> char* a C-stílusú függvényhez
            enqueue_String(&carQueue, (char*)word.c_str());
            cout << "Hozzaadva: " << word << endl;
        } else {
            cout << "A sor megtelt!" << endl;
            break;
        }
    }

    inputFile.close();

    cout << "\nA sor vegleges tartalma:" << endl;
    display_String(carQueue);

    destroyQueue_String(&carQueue);
}

int RunArray() {
    // 1. Creation (Constructor handles memory allocation)
    IntArray myList(5);
    std::cout << "Dynamic array created with capacity 5." << std::endl;

    // 2. Inserting elements
    myList.insertLast(10);
    myList.insertLast(30);
    myList.insertFirst(5);      // Array is now: [5, 10, 30]
    myList.insertAt(2, 20);     // Array is now: [5, 10, 20, 30]

    // 3. Displaying content
    std::cout << "Current array: ";
    myList.printArray();

    // 4. Searching and Updating
    int pos = myList.search(20);
    if (pos != -1) {
        std::cout << "Found 20 at index: " << pos << std::endl;
        myList.update(pos, 25); // Change 20 to 25
    }

    // 5. Deleting an item
    std::cout << "Deleting item at index 1..." << std::endl;
    myList.deleteItemAt(1);     // Removes 10, shifts others left

    // 6. Final state
    myList.printArray();

    // No need to call a destroy function!
    // The Destructor (~IntArray) runs automatically when main ends.
    return 0;
}

int main() {

    return 0;
}