#include "../header/array.h"

using namespace std;

// Konstruktor: inicializálja a tagokat és memóriát foglal
IntArray::IntArray(int cap) : capacity(cap), size(0) {
    if (capacity <= 0) capacity = 1;
    elements = new int[capacity];
}

// Destruktor: automatikusan lefut, ha az objektum megszűnik
IntArray::~IntArray() {
    delete[] elements;
    elements = nullptr;
}

void IntArray::resize() {
    capacity *= 2;
    int* newElements = new int[capacity];
    for (int i = 0; i < size; ++i) {
        newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
}

bool IntArray::isFull() const {
    return size == capacity;
}

bool IntArray::isEmpty() const {
    return size == 0;
}

void IntArray::printArray() const {
    if (isEmpty()) {
        cout << "A tomb ures." << endl;
        return;
    }
    cout << "A tomb elemei: ";
    for (int i = 0; i < size; ++i) {
        cout << elements[i] << " ";
    }
    cout << endl;
}

int IntArray::getItemAt(int position) const {
    if (position < 0 || position >= size) {
        cout << "Hiba: Ervenytelen index!" << endl;
        return 0;
    }
    return elements[position];
}

void IntArray::insertLast(int item) {
    if (isFull()) resize();
    elements[size++] = item;
}

void IntArray::insertFirst(int item) {
    insertAt(0, item);
}

void IntArray::insertAt(int position, int item) {
    if (position < 0 || position > size) {
        cout << "Ervenytelen pozicio!" << std::endl;
        return;
    }
    if (isFull()) resize();

    // Elemek eltolása jobbra
    for (int i = size; i > position; --i) {
        elements[i] = elements[i - 1];
    }
    elements[position] = item;
    size++;
}

void IntArray::deleteItemAt(int position) {
    if (isEmpty() || position < 0 || position >= size) {
        cout << "Torles sikertelen: ervenytelen index vagy ures tomb." << std::endl;
        return;
    }

    // Elemek eltolása balra
    for (int i = position; i < size - 1; ++i) {
        elements[i] = elements[i + 1];
    }
    size--;
}

int IntArray::search(int item) const {
    for (int i = 0; i < size; ++i) {
        if (elements[i] == item) return i;
    }
    return -1;
}

bool IntArray::update(int position, int newItem) {
    if (position < 0 || position >= size) return false;
    elements[position] = newItem;
    return true;
}