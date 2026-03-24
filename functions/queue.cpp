//
// Created by Crusher on 3/22/2026
#include "../header/queue.h"

#include <stdlib.h>
#include <stdio.h>
#include "../header/constants.h"
#include <limits.h>


void createQueue(int capacity, Queue *queue) {
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->elements = (int*) calloc(queue->capacity, sizeof (int));
    if(!queue->elements) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

void destroyQueue(Queue *queue) {
    free(queue->elements);
    queue->front = queue->rear = -1;
    queue->capacity = 0;
    queue = NULL;
}
//0 1 2 3 4 5
// 5 6 7 8
bool isFull(Queue queue) {
    return queue.front == 0 && queue.rear == queue.capacity-1 ||
    queue.rear == queue.front-1;
}
bool isEmpty(Queue queue) {
    return queue.front == -1;
}
void enqueue(Queue *queue, int item) {
    if(isFull(*queue)) {
        printf(FULL_MESSAGE);
        return;
    }
    if(isEmpty(*queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->elements[queue->rear] = item;
}
int dequeue(Queue *queue) {
    if(isEmpty(*queue)) {
        printf(EMPTY_MESSAGE);
        return INT_MIN;
    }
    int save = queue->elements[queue->front];
    if(queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    return save;
}
void display(Queue queue) {
    if (isEmpty(queue)) {
        printf("The queue is ");
        printf(EMPTY_MESSAGE);
        return;
    }
    printf("The items of the queue:");
    int i = queue.front;
    do
    {
        printf("%i ", queue.elements[i]);
        i = (i+1) % queue.capacity;
    }while(i != queue.rear);
    printf("%i ", queue.elements[i]);
    printf("\n");
}
