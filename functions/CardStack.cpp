#include <stdlib.h>
#include <stdio.h>
#include "../header/constants.h"
#include "../header/CardStack.h"

// Note: Your Stack.h must define 'elements' as Card_t**
void createStack(int capacity, Stack *stack) {
    stack->capacity = capacity;
    stack->top = -1;
    // We allocate memory for an array of POINTERS (Card_t*)
    stack->elements = (Card_t**)calloc(stack->capacity, sizeof(Card_t*));
    
    if(!stack->elements) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

void destroyStack(Stack *stack) {
    stack->capacity = 0;
    stack->top = -1;
    free(stack->elements);
    // stack = NULL; // Note: This line has no effect outside the function in C
}

bool isFull(Stack stack) {
    return stack.top == stack.capacity - 1;
}

bool isEmpty(Stack stack) {
    return stack.top == -1;
}

int size(Stack stack) {
    return stack.top + 1;
}

// Accepts a pointer to a Card
void push(Stack *stack, Card_t *item) {
    if(isFull(*stack)) {
        printf(FULL_MESSAGE);
        return;
    }
    stack->elements[++stack->top] = item;
}

// Returns a pointer to a Card, or NULL if empty
Card_t* pop(Stack *stack) {
    if (isEmpty(*stack)) {
        printf(EMPTY_MESSAGE);
        return NULL; 
    }
    Card_t *save = stack->elements[stack->top];
    stack->elements[stack->top--] = NULL;
    return save;
}

Card_t* peek(Stack stack) {
    if (isEmpty(stack)) {
        printf(EMPTY_MESSAGE);
        return NULL;
    }
    return stack.elements[stack.top];
}