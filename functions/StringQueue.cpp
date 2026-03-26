#include "../header/constants.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../header//StringQueue.h"

void createQueue_String(int capacity, StringQueue *queue) {
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->elements = (char**)calloc(capacity, sizeof
    (char*));
    if(!queue->elements) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
        }
    for (int i = 0; i < queue->capacity; ++i) {
        queue->elements[i] = (char*)calloc(CAR_PLATE_NUMBER_LIMIT, sizeof
        (char));
        if(!queue->elements[i]) {
            printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
            exit(MEMORY_ALLOCATION_ERROR_CODE);
        }
    }
}

void destroyQueue_String(StringQueue *queue) {
    for (int i = 0; i < queue->capacity; ++i) {
        free(queue->elements[i]);
    }
    free(queue->elements);
    queue->capacity = 0;
    queue->front = queue->rear = -1;
    queue = NULL;
}

bool isFull_String(StringQueue queue) {
    return queue.rear == queue.capacity - 1;
}

bool isEmpty_String(StringQueue queue) {
    return queue.front == -1 && queue.rear == -1;
}

void enqueue_String(StringQueue *queue, char *item) {
    if(isFull_String(*queue))
    {
        printf(FULL_MESSAGE);
        return;
    }
    //ha az elso elem
    if(queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    strcpy(queue->elements[queue->rear], item);
}

char *dequeue_String(StringQueue *queue) {
    if(isEmpty_String(*queue))
    {
        printf(EMPTY_MESSAGE);
        return NULL;
    }
    //ha csak egy elem van
    if(queue->front == queue->rear) {
        int poz = queue->front;
        queue->front = queue->rear = -1;
        return queue->elements[poz];
    }
    return queue->elements[queue->front++];
}

void display_String(StringQueue queue) {
    if(isEmpty_String(queue))
    {
        printf(EMPTY_MESSAGE);
        return;
    }
    printf("The elements of the queue:\n");
    for (int i = queue.front; i <= queue.rear; ++i) {
        printf("\t- %s\n", queue.elements[i]);
    }
    printf("\n");
}