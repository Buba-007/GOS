/*              Ср      Худш
* Расход памяти	O(n)	O(n)
* Поиск	        O(1)	O(n)
* Вставка	    O(1)	O(n)
* Удаление	    O(1)	O(n)
*/

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_TABLE_SIZE 3
#define PRIME 7
#define LOAD_FACTOR 0.7

struct HashElem {
    int key;
    int value;
} ;

struct HashTable {
    HashElem** array;
    int size;
    int count;
};

unsigned int hash1(int key, int size) {
    return key % size;
}

unsigned int hash2(int key) {
    return PRIME - (key % PRIME);
}

unsigned int hash(unsigned int h1, unsigned int h2, int i, int size) {
    return (h1 + i * h2) % size;
}

void rehash(HashTable* ht);

void insert(HashTable* ht, int key, int value) {
    if ((double)ht->count / ht->size >= LOAD_FACTOR) {
        rehash(ht);
    }

    int index = hash1(key, ht->size);
    int i = 1;
    while (ht->array[index] != NULL) {
        index = hash(index, hash2(key), i, ht->size);
        i++;
    }

    HashElem* new_elem = (HashElem*)malloc(sizeof(HashElem));
    new_elem->key = key;
    new_elem->value = value;

    ht->array[index] = new_elem;
    ht->count++;
}

void rehash(HashTable* ht) {
    int old_size = ht->size;
    HashElem** old_array = ht->array;

    ht->size = 2 * old_size;
    ht->array = (HashElem**)calloc(ht->size, sizeof(HashElem*));

    for (int i = 0; i < old_size; i++) {
        if (old_array[i] != NULL) {
            insert(ht, old_array[i]->key, old_array[i]->value);
            free(old_array[i]);
        }
    }

    free(old_array);
}

void initHashTable(HashTable* ht) {
    ht->array = (HashElem**)calloc(INITIAL_TABLE_SIZE, sizeof(HashElem*));
    ht->size = INITIAL_TABLE_SIZE;
    ht->count = 0;
}

void freeHashTable(HashTable* ht) {
    for (int i = 0; i < ht->size; i++) {
        if (ht->array[i] != NULL) {
            free(ht->array[i]);
        }
    }
    free(ht->array);
}

void printHash(HashTable* ht) {
    for (int i = 0; i < ht->size; i++) {
        if (ht->array[i] != NULL) {
            printf("(%d) ", ht->array[i]->value);
        }
        else {
            printf("( ) ");
        }
    }
    printf("\n");
}

int main() {
    HashTable ht;
    initHashTable(&ht);

    printHash(&ht);

    insert(&ht, 1, 100);
    insert(&ht, 11, 110);
    insert(&ht, 21, 120);

    printHash(&ht);

    freeHashTable(&ht);

    return 0;
}