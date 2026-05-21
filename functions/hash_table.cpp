#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../header/constants.h"
#include "../header/hash_table.h"

int hashCode(int key) {
    return key % CAPACITY;
}

HashItem createHashItem(int key, char *data){

    HashItem item = {key, data};
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
void insertHashTable(HashTable *hashTable, int key, char *data) {
    if(hashTable->size >= CAPACITY) return;
    int index = hashCode(key);
    int i = 0;
    while (hashTable->items[(index + i)%CAPACITY].key != dummyData.key){
        i++;
    }
    int finalPos = (index + i) % CAPACITY;
    hashTable->items[finalPos].key = key;

    int length = strlen(data) + 1;
    char *newStorage = (char*)malloc(length * sizeof(char));

    if (newStorage != NULL) {
        strcpy(newStorage, data);
        hashTable->items[finalPos].data = newStorage;
    }
    hashTable->size++;
}
void displayHashTable(HashTable hashTable) {
    if(hashTable.size == 0) {
        printf("The table is empty\n");
        return;
    }
    printf("The hash table:\n\tpos\t:\tkey\tvalue\t->\tmod\n");
    for (int i = 0; i < CAPACITY; ++i) {
        if(hashTable.items[i].key != dummyData.key){
            printf("\t%i\t:\t%i\t%s\t->\t%i\n", i, hashTable.items[i].key,
            hashTable.items[i].data, hashCode(hashTable.items[i].key));
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

        if (hashTable->items[pos].data != NULL) {
            free(hashTable->items[pos].data);
        }

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
void destroyHashArray(HashTable *pHashTable) {
    for (int i = 0; i < CAPACITY; ++i) {
        if (pHashTable->items[i].key != dummyData.key && pHashTable->items[i].data != NULL) {
            free(pHashTable->items[i].data);
        }
    }
    free(pHashTable->items);
    pHashTable->items = NULL;
    pHashTable->size = 0;
}
