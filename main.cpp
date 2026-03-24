#include <iostream>
#include <cstdlib>
#include <fstream>
#include  "functions/functions.cpp"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

typedef struct {
int capacity;
int front;
int rear;
int *elements;
} Queue;

#define CAR_PLATE_NUMBER_LIMIT 20
#define MEMORY_ALLOCATION_ERROR_CODE 1
#define MEMORY_ALLOCATION_ERROR_MESSAGE "Memory allocation failed!\n"
#define FULL_MESSAGE "Queue is full!\n"
#define EMPTY_MESSAGE "Queue is empty!\n"



void createQueue(int capacity, Queue *queue) {
queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;

    queue->elements = (int*)calloc(capacity, sizeof(int));

    if (!queue->elements) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}
void destroyQueue(Queue *queue) {
    if (queue->elements != NULL) {
        free(queue->elements); 
        queue->elements = NULL;
    }
    queue->capacity = 0;
    queue->front = -1;
    queue->rear = -1;
}
bool isFull(Queue queue) {
    return queue.rear == queue.capacity - 1;
}
bool isEmpty(Queue queue) {
    return queue.front == -1 && queue.rear == -1;
}
void enqueue(Queue *queue,int item) {
    if(isFull(*queue))
    {
        printf(FULL_MESSAGE);
        return;
    }
    //ha az elso elem
    if(queue->front == -1) {
    queue->front = 0;
    }
    queue->rear++;
    queue->elements[queue->rear] = item;
}

int dequeue(Queue *queue) {
    
    if (isEmpty(*queue)) {
        printf("%s", EMPTY_MESSAGE);
        return -1;
    }
    int value = queue->elements[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    return value;
}

void display(Queue queue) {
    if (isEmpty(queue)) {
        printf("%s", EMPTY_MESSAGE);
        return;
    }
    printf("The elements of the queue:\n");
    for (int i = queue.front; i <= queue.rear; ++i) {
        // Changed %s to %d for integers
        printf("\t- %d\n", queue.elements[i]);
    }
    printf("\n");
}

void I(){
    Queue myQueue;
    createQueue(10,&myQueue);
    enqueue(&myQueue,1);
    enqueue(&myQueue,2);
    enqueue(&myQueue,3);
    enqueue(&myQueue,4);
    enqueue(&myQueue,5);
    display(myQueue);
    ///Next is 10
    int nextElement = 10;
    if(nextElement-myQueue.elements[myQueue.front]<=10){
        myQueue.front ++;
        enqueue(&myQueue,nextElement);
    }else{
        printf("Az elem nem hozzaadhato...\n");
    }
    display(myQueue);
    nextElement = 20;
    if(nextElement-myQueue.elements[myQueue.front]<=10){
        myQueue.front ++;
        enqueue(&myQueue,nextElement);
    }else{
        printf("Az elem nem hozzaadhato...\n");
    }
    display(myQueue);
    destroyQueue(&myQueue);
}
void II(){
    Queue myQueue;
    createQueue(10,&myQueue);
    enqueue(&myQueue,1);
    enqueue(&myQueue,3);
    enqueue(&myQueue,-1);
    enqueue(&myQueue,-3);
    enqueue(&myQueue,5);
    enqueue(&myQueue,3);
    enqueue(&myQueue,6);
    enqueue(&myQueue,7);
    int myMax[10]={0};
    int window=3;
    for(int start=myQueue.front;start<=myQueue.rear;start++){
        for(int current = start; current <= start + window; current++){
            if(current<myQueue.rear){
                if(myMax[myQueue.front-start]<myQueue.elements[current]) myMax[myQueue.front-start]=myQueue.elements[current];
            }else{
                if(myMax[myQueue.front-start]<myQueue.elements[current%(myQueue.rear)+myQueue.front])myMax[myQueue.front-start]=myQueue.elements[current%(myQueue.rear)+myQueue.front];
            }
        }
    }
    for(int i=0;i<10;i++){
        printf("%i ",myMax[i]);
    }
}
int main() {
    sayHello();
    return 0;
}