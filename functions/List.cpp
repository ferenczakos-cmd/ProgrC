#include "../header/list.h"
#include <stdlib.h>
#include <stdio.h>
#include "../header/constants.h"

Node *newNode(int new_data) {
    Node *newItem = (Node*) malloc(sizeof (Node));
    if(!newItem)
    {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    newItem->data = new_data;
    newItem->next = NULL;
    return newItem;
}
bool isEmpty(Node *head) {
    return head == NULL;
}
void insertAtEnd(Node **head_ref, int new_data) {
    if(isEmpty(*head_ref))
    {
        *head_ref = newNode(new_data);
    return;
    }
    Node *temp = *head_ref;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode(new_data);
}
void printList(Node *node) {
    Node* temp = node;
    while(temp != NULL)
    {
        printf("%i -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void deleteFromBeginning(Node **head_ref) {
    if(isEmpty(*head_ref))
    {
        printf(NULL_POINTER_EXCEPTION_ERROR_MESSAGE);
        return;
    }
    Node *temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}
void insertAfter(Node *prev_ref, int new_data) {
    if(prev_ref == NULL)
    {
        printf(NULL_POINTER_EXCEPTION_ERROR_MESSAGE);
        return;
    }
    Node *newItem = newNode(new_data);
    newItem->next = prev_ref->next;
    prev_ref->next = newItem;
}
void insertAtBeginning(Node **head_ref, int new_data) {
    Node* temp = newNode(new_data);
    if(isEmpty(*head_ref))
    {
        *head_ref = temp;
        return;
    }
    temp->next = *head_ref;
    *head_ref = temp;
}
bool searchNode(Node *head_ref, int key) {
    Node *temp = head_ref;
    while(temp != NULL)
    {
        if(temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}
void deleteNode(Node **head_ref, int key) {
    if(isEmpty(*head_ref))
    {
        printf(NULL_POINTER_EXCEPTION_ERROR_MESSAGE);
        return;
    }
    if((*head_ref)->data == key)
    {
        deleteFromBeginning(head_ref);
        return;
    }
    Node *temp = (*head_ref)->next;
    Node *prev = (*head_ref);
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp != NULL)
    {
        prev->next = temp->next;
        free(temp);
    }
}
void deleteFromEnd(Node **head_ref) {
    if(isEmpty(*head_ref))
    {
        printf(NULL_POINTER_EXCEPTION_ERROR_MESSAGE);
        return;
    }
    if((*head_ref)->next == NULL)
    {
        free(*head_ref);
        *head_ref = NULL;
        return;
    }
    Node *temp = *head_ref;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
void sortLinkedList(Node *head_ref) {
    if(isEmpty(head_ref))
    {
        printf(NULL_POINTER_EXCEPTION_ERROR_MESSAGE);
        return;
    }
    Node *first = head_ref;
    while (first != NULL)
    {
        Node *current = first->next;
        while (current != NULL)
        {
            if(first->data > current->data)
            {
                int aux = first->data;
                first->data = current->data;
                current->data = aux;
            }
            current = current->next;
        }
        first = first->next;
    }
}
void freeList(Node **head) {
    while(*head != NULL)
    {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    *head = NULL;
}

void reverseList(Node **head_ref) {
    Node *prev = NULL;
    Node *current = *head_ref;
    Node *next = NULL;

    while (current != NULL) {
        next = current->next;   // store next node
        current->next = prev;   // reverse link
        prev = current;         // move prev forward
        current = next;         // move current forward
    }

    *head_ref = prev; // new head
}

void removeDuplicates(Node *head) {
    if (head == NULL) return;

    Node *current = head;

    while (current->next != NULL) {
        if (current->data == current->next->data) {
            Node *temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}