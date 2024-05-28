/*              Ср      Худш
* Расход памяти	O(n)	O(n)
* Поиск	        O(1)	O(n)
* Вставка	    O(1)	O(n)
* Удаление	    O(1)	O(n)
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 3


unsigned int hash(char* str) {
    unsigned int hash = 0;
    for (int i = 0; i < strlen(str); i++) {
        hash += str[i];
    }
    return hash % TABLE_SIZE;
}


struct HashNode {
    char* key;
    int value;
    struct HashNode* next;
};

struct HashTable {
    struct HashNode* hash_table[TABLE_SIZE];
};

struct HashTable* initHash() {
    struct HashTable* hash = (struct HashTable*)malloc(sizeof(struct HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash->hash_table[i] = NULL;
    }
    return hash;
}

void insert(HashTable* ht, char* key, int value) {
    struct HashNode* hashNode = (struct HashNode*)malloc(sizeof(struct HashNode));
    hashNode->key = key;
    hashNode->value = value;
    hashNode->next = NULL;

    int h = hash(key);
    if (ht->hash_table[h] == NULL) {
        ht->hash_table[h] = hashNode;
    }
    else {
        hashNode->next = ht->hash_table[h];
        ht->hash_table[h] = hashNode;
    }
}

void printHash(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->hash_table[i] == NULL) {
            printf("[ ] ");
        }
        else {
            printf("[%d] ", ht->hash_table[i]->value);
            struct HashNode* tmp = ht->hash_table[i];
            while (tmp->next != NULL)
            {
                printf("<-(%d) ", tmp->next->value);
                tmp = tmp->next;
            }
        }
    }
    printf("\n");
}

int main()
{
    HashTable* ht;
    ht = initHash();
    char str[] = "first";
    char str1[] = "first1";
    char str2[] = "first2";
    char str3[] = "first3";
    char str4[] = "first4";
    char str5[] = "first5";
    char str6[] = "first6";
    insert(ht, str, 11);
    insert(ht, str1, 1);
    insert(ht, str2, 3);
    insert(ht, str3, 7);
    insert(ht, str4, 9);
    insert(ht, str5, 12);
    insert(ht, str6, 16);

    printHash(ht);

}
