#include <iostream>
#include <ctime>
#include "header/constants.h"
#include  "functions/array.cpp"
#include  "functions/queue.cpp"
#include "functions/stack.cpp"
#include "functions/CardStack.cpp"
#include "functions/stringQueue.cpp"
#include "functions/List.cpp"
#include "functions/CircularList.cpp"
#include <fstream>
#include <filesystem>
using namespace std;

int main() {
    ifstream input("Names.txt");
    if (!input) {
        cout<<"File not found"<<endl;
        cout << "The program is looking in: "<< std::filesystem::current_path() << endl;
    }

    Nodee* head = NULL;
    Child tempChild;

    while (input>>tempChild.firstName>>tempChild.lastName) {
        insertAtEnd(&head, tempChild);
    }
    input.close();

    // Lista kiírása ellenőrzésképpen
    printf("\nA lista eredeti tartalma:\n");
    if (!isEmpty(head)) {
        printList(head);
    }

    int n;
    cout << "Minden hanyadikat toroljem? ";
    cin >> n;
    cout << endl;

    Nodee* current = head;

    while (size(head) > 1) {
        for (int j = 1; j < n; j++) {
            current = current->next;
        }

        Child toDelete = current->data;

        Nodee* nextTarget = current->next;

        cout<<"Fireed: "<<toDelete.firstName<<" "<< toDelete.lastName<<endl;
        deleteNode(&head, toDelete);

        current = nextTarget;

        cout<<"Remaining:"<< size(head)<<endl;
        printList(head);
        cout<<"-------------------------------------------------------------------------"<<endl;
    }

    printf("\nAz utolso maradt szemely: %s %s\n", head->data.lastName, head->data.firstName);

    return 0;
}