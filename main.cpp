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

int main() {
    Node *head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 3);

    printf("Original list:\n");
    printList(head);

    reverseList(&head);

    printf("Reversed list:\n");
    printList(head);

    removeDuplicates(head);
    printf("Cleared list:\n");
    printList(head);

    freeList(&head);

    return 0;
}