#include <iostream>
#include <ctime>
#include "header/constants.h"
#include  "functions/array.cpp"
#include  "functions/queue.cpp"
//#include "functions/stack.cpp"
#include "functions/CardStack.cpp".
#include "functions/stringQueue.cpp"
#include "functions/List.cpp"
#include <fstream>



using namespace std;

void printStackDestructive(Stack *stack) {
    if (isEmpty(*stack)) {
        printf("A verem ures.\n");
        return;
    }

    Stack tempStack;
    createStack(stack->capacity, &tempStack);

    printf("--- Verem tartalma ---\n");

    // 1. & 2. Kipakolunk az eredetiből és kiírunk
    while (!isEmpty(*stack)) {
        Card_t *current = pop(stack);

        // Kiírás
        printf("Szin: %s, Ertek: %d\n", current->szin, current->ertek);

        // 3. Átmentjük a segédverembe
        push(&tempStack, current);
    }

    // 4. Visszapakolunk mindent, hogy a verem állapota ne változzon
    while (!isEmpty(tempStack)) {
        push(stack, pop(&tempStack));
    }

    // A segédverem adminisztrációját töröljük (a kártyákat NE, mert azok kellenek!)
    destroyStack(&tempStack);
}


int main() {
    ifstream input("cards.txt");
    if (!input.is_open()) {
        cout << "Hiba: Az cards.txt nem talalhato!" << endl;
        return 1;
    }

    int n;
    input >> n;

    Stack myStack;
    createStack(35, &myStack);

    for (int i = 0; i < n; i++) {
        Card_t* temp = new Card_t;
        int ertek_seged;

        if (input >> ertek_seged >> temp->szin) {
            temp->ertek = (Szam_t)ertek_seged;

            if (isEmpty(myStack)) {
                push(&myStack, temp);
            } else {
                bool pushed = false;
                while (!isEmpty(myStack) && !pushed) {
                    Card_t* secondTemp = pop(&myStack);

                    // C++ string összehasonlítás a char[] tömbökhöz
                    if (secondTemp->ertek == temp->ertek || std::string(secondTemp->szin) == std::string(temp->szin)) {
                        push(&myStack, secondTemp); // Ezt megtartjuk
                        push(&myStack, temp);       // Erre rátesszük az újat
                        pushed = true;              // Megvagyunk, kilépünk a while-ból
                    } else {
                        // Ha nem talál, ezt a lapot végleg töröljük a memóriából
                        delete secondTemp;
                    }
                }

                // Ha végigfutott a verem és nem találtunk egyezést sehol
                if (!pushed) {
                    push(&myStack, temp);
                }
            }
            printStackDestructive(&myStack);
        } else {
            delete temp;
        }
    }
    input.close();

    cout << "A verem tartalma :" << endl;

    // 4. Kiírás és takarítás
    while (!isEmpty(myStack)) {
        Card_t* garbage = pop(&myStack);

        // Kiírjuk az adatokat
        cout << garbage->szin << " " << garbage->ertek << endl;

        // MOST kell törölni, mert már kivettük a veremből és nincs rá szükség
        delete garbage;
    }

    destroyStack(&myStack);

    return 0;
}