#ifndef INTARRAY_H
#define INTARRAY_H

#include <iostream>
#include <limits>

struct IntArray {
    int capacity;
    int size;
    int *elements;

    // Konstruktor
    IntArray(int initialCapacity = 10);
    
    // Destruktor
    ~IntArray();

    void printArray() const;
    bool isFull() const;
    bool isEmpty() const;
    int getItemAt(int position) const;
    void insertFirst(int item);
    void insertLast(int item);
    void insertAt(int position, int item);
    void deleteItemAt(int position);
    int search(int item) const;
    bool update(int position, int newItem);
    
    // Belső segédfüggvény a dinamikus bővítéshez
    void resize();
};
#endif