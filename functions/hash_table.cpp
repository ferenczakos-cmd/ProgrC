#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../header/constants.h"
#include "../header/hash_table.h"

using namespace std;

int hashCode(int key) {
    return key % CAPACITY;
}

HashItem createHashItem(int key, Diak diak){
    HashItem item = {key, diak};
    return item;
}
void createHashArray(HashTable *pHashTable) {
    pHashTable->items = (HashItem*)calloc(CAPACITY, sizeof(HashItem));
    if(!pHashTable->items)
    {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    for (int i = 0; i < CAPACITY; ++i) {
        pHashTable->items[i] = dummyData;
    }
    pHashTable->size = 0;
}
void insertHashTable(HashTable *hashTable, int key, Diak diak) {
    if(hashTable->size >= CAPACITY) return;
    int index = hashCode(key);
    int i = 0;
    while (hashTable->items[(index + i)%CAPACITY].key != dummyData.key){
        i++;
    }
    int finalPos = (index + i) % CAPACITY;
    hashTable->items[finalPos].key = key;
    hashTable->items[finalPos].diak = diak;
    hashTable->size++;
}
void displayHashTable(HashTable hashTable) {
    if(hashTable.size == 0) {
        printf("The table is empty\n");
        return;
    }
    for (int i = 0; i < CAPACITY; ++i) {
        if(hashTable.items[i].key != dummyData.key){
            cout<<hashTable.items[i].key<<": "<<hashTable.items[i].diak.Id<<" "<<hashTable.items[i].diak.nev<<" "<<hashTable.items[i].diak.osztaly<<endl;
        }
    }
}
int sizeHashTable(HashTable hashTable) {
    return hashTable.size;
}
void deleteHashTable(HashTable *hashTable, int key) {
    int index = hashCode(key);
    int i = 0;

    while(hashTable->items[(index+i)%CAPACITY].key != key && i < CAPACITY){
        i++;
    }

    int pos = (index + i) % CAPACITY;
    if(i < CAPACITY && hashTable->items[pos].key != dummyData.key) {
        hashTable->items[pos] = dummyData;
        hashTable->size--;
        printf("\n Key (%d) has been removed \n", key);
    } else {
        printf("\n This key does not exist \n");
    }
}
int searchHashTable(HashTable hashTable, int key) {
    int index = hashCode(key);
    if (hashTable.items[index].key == dummyData.key){
        return -1;
    }
    int i = 0;
    while(hashTable.items[(index+i)%CAPACITY].key != key && i < CAPACITY){
        i++;
    }
    if(i == CAPACITY) return -1;
    return index;
}
bool updateNoteAt(HashTable hashTable, int key,int Jegy) {
    int index=searchHashTable(hashTable,key);
    if (index==-1) return false;
    hashTable.items[index].diak.jegy=Jegy;
    return true;
}
void destroyHashArray(HashTable *pHashTable) {

    free(pHashTable->items);
    pHashTable->items = NULL;
    pHashTable->size = 0;
}
