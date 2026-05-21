
#include <fstream>
#include <iostream>

#include "../header/queue.h"
#include "../header/constants.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

using namespace std;

void createQueue(int capacity, Queue *queue) {
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->elements = (float*) calloc(queue->capacity, sizeof (int));
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
void enqueue(Queue *queue, float item) {
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
        printf("Nicsenek meresi addatok...\n");
        printf(EMPTY_MESSAGE);
        return;
    }
    //printf("The items of the queue:");
    int i = queue.front;
    do
    {
        cout<<queue.elements[i]<<endl;
        i = (i+1) % queue.capacity;
    }while(i != queue.rear);
    cout<<queue.elements[i]<<endl;
    printf("\n");
}

void atlag(Queue queue) {
    if (isEmpty(queue)) {
        printf("Nicsenek meresi addatok...\n");
        printf(EMPTY_MESSAGE);
        return;
    }

    float sum = 0; int counter = 0;
    int i = queue.front;
    do
    {
        sum += queue.elements[i];
        counter++;
        i = (i+1) % queue.capacity;
    }while(i != queue.rear);
    sum += queue.elements[i];
    counter++;

    if (counter==0) {
        cout<<"Error(division by 0) returning... "<<endl;
        return;
    }
    float atlag = sum / counter;
    cout<<"Atlag: "<<atlag<<endl;

}

void kics_nagy(Queue queue) {
    if (isEmpty(queue)) {
        printf("Nicsenek meresi addatok...\n");
        printf(EMPTY_MESSAGE);
        return;
    }


    int i = queue.front;
    float kicsi= queue.elements[i];
    float nagy = queue.elements[i];
    do
    {
        if (queue.elements[i] < kicsi) {
            kicsi = queue.elements[i];
        }
        if (queue.elements[i] >nagy) {
            nagy = queue.elements[i];
        }

        i = (i+1) % queue.capacity;
    }while(i != queue.rear);

    if (queue.elements[i] < kicsi) {
        kicsi = queue.elements[i];
    }
    if (queue.elements[i] >nagy) {
        nagy = queue.elements[i];
    }

    cout<<"Kicsi: "<<kicsi<<endl;
    cout<<"Nagy: "<<nagy<<endl;
}

void novekvo(Queue queue) {
    if (isEmpty(queue)) {
        printf("Nicsenek meresi addatok...\n");
        printf(EMPTY_MESSAGE);
        return;
    }

    bool no = true;

    int i = queue.front;
    float prev_element= queue.elements[i];
    if (i+1!=queue.rear) {
        i++;
    }else {
        printf("Csak egy meresi adat van...\n");
        return;
    }

    do
    {
        if (queue.elements[i]<=prev_element) {
            no = false;
        }
        prev_element = queue.elements[i];

        i = (i+1) % queue.capacity;
    }while(i != queue.rear);

    if (queue.elements[i]<=prev_element) {
        no = false;
    }
    prev_element = queue.elements[i];

    if (no) {
        printf("A meresi adatok novekednek!");
    }else {
        printf("A meresi adatok nem novekednek!");
    }

}
