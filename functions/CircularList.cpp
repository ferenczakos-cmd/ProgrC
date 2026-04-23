#include "../header/CircularList.h"
#include <stdlib.h>
#include <stdio.h>
#include "../header/constants.h"
#include <string.h>

Nodee *newNode(Child new_data) {
    Nodee* new_node = (Nodee*)malloc(sizeof(Nodee));
    if(!new_node) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    // adat beszúrása
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}
void insertAtEnd(Nodee** head_ref, Child new_data) {
    Nodee* new_node = newNode(new_data);
    Nodee* last = *head_ref; /* used in step 5*/
    if (isEmpty(*head_ref)) {
        *head_ref = new_node;
        new_node->next = *head_ref;
        return;
    }
    while (last->next != *head_ref) last = last->next;
    last->next = new_node;
    new_node->next = *head_ref;
}
void deleteNode(Nodee** head_ref, Child key) {
    Nodee *temp = *head_ref, *prev;
    if (temp != NULL && compare(temp->data, key) == 0) {
        Nodee *last = (*head_ref)->next;
        if(last == *head_ref)
        {
            *head_ref = NULL;
            free(*head_ref);
            return;
        }
        while(last->next != (*head_ref)) last = last->next;
        *head_ref = temp->next;
        last->next = *head_ref;
        free(temp);
        return;
    }
    // kulcs megkeresése
    while (temp != NULL && compare(temp->data, key) != 0) {
        prev = temp;
        temp = temp->next;
    }
    // ha a kulcs nincs jelen
    if (temp == NULL) return;
    // csomópont törlése
    prev->next = temp->next;
    free(temp);
}

void printList(Nodee* node) {
    Nodee *first = node;
    while (node->next != first) {
        printf("%s %s\n", node->data.firstName, node->data.lastName);
        node = node->next;
    }
    printf("%s %s\n", node->data.firstName, node->data.lastName);
}
int size(Nodee* node) {
    int nr = 0;
    Nodee *first = node;
    while (node->next != first) {
        nr++;
        node = node->next;
    }
    return nr + 1;
}
bool isEmpty(Nodee *head) {
    return head == NULL;
}
int compare(Child child1, Child child2) {
    int result = strcmp(child1.lastName, child2.lastName);
    if(result == 0) {
        return strcmp(child1.firstName, child2.firstName);
    }
    return result;
}