#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Кольцевой список для АиСД на С
typedef struct RingNode {
    char data;
    struct RingNode* next;
} RingNode;

typedef struct RingLinkedListC {
    RingNode* head = NULL;
} RingLinkedListC;

void InsertBefore(RingLinkedListC* list, int index, char data) {
    RingNode* newNode = (RingNode*)malloc(sizeof(RingNode));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        newNode->next = newNode;
        list->head = newNode;
        return;
    }

    RingNode* indexNode = NULL;

    if (index == 0) {
        RingNode* ptr = list->head;
        while (ptr->next != list->head) {
            ptr = ptr->next;
        }
        indexNode = ptr;
    } 
    else {
        indexNode = list->head;
        for (int i = 1; i < index; i++) {
            if (indexNode->next->next != list->head) {
                indexNode = indexNode->next;
            }
        }
    }

    newNode->next = indexNode->next;
    if (indexNode->next == list->head) {
        list->head = newNode;
    }
    indexNode->next = newNode;
}

void InsertAfter(RingLinkedListC* list, int index, char data) {
    RingNode* newNode = (RingNode*)malloc(sizeof(RingNode));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        newNode->next = newNode;
        list->head = newNode;
        return;
    }

    RingNode* indexNode = list->head;
    for (int i = 0; i < index; i++) {
        if (indexNode->next != list->head) {
            indexNode = indexNode->next;
        }
    }

    newNode->next = indexNode->next;
    indexNode->next = newNode;
}

void RemoveAt(RingLinkedListC* list, int index) {
    if (list->head == NULL) {
        return;
    }
    if (list->head->next == list->head) {
        list->head = NULL;
        return;
    }

    RingNode* indexNode = NULL;

    if (index == 0) {
        RingNode* ptr = list->head;
        while (ptr->next != list->head) {
            ptr = ptr->next;
        }
        indexNode = ptr;
    }
    else {
        indexNode = list->head;
        for (int i = 0; i < index; i++) {
            if (indexNode->next->next != list->head) {
                indexNode = indexNode->next;
            }   
        }
    }
    if (indexNode->next == list->head) {
        list->head = indexNode->next->next;
    }
    indexNode->next = indexNode->next->next;
}

int Lenght(RingLinkedListC* list) {
    int count = 1;
    RingNode* indexNode = list->head;
    if (list->head == NULL) {
        return 0;
    }
    while (indexNode->next != list->head)
    {
        indexNode = indexNode->next;
        count++;
    }
    return count;
}

void InsertBeginning(RingLinkedListC* list, char data) {
    RingNode* newNode = (RingNode*)malloc(sizeof(RingNode));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        newNode->next = newNode;
        list->head = newNode;
        return;
    }
    else {
        InsertBefore(list, 0, data);
    }
}

void InsertEnd(RingLinkedListC* list, char data) {
    RingNode* newNode = (RingNode*)malloc(sizeof(RingNode));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        InsertBeginning(list, data);
    }
    else {
        InsertAfter(list, Lenght(list) - 1, data);
    }
}

void PrintListFromHead(RingLinkedListC* list) {
    struct RingNode* ptr = list->head;
    do {
        printf("(%c)->", ptr->data);
        ptr = ptr->next;
    } while (ptr != list->head);
    printf("(head...)\n");
}

int main()
{
    /* --- C --- */

    RingLinkedListC myList = { NULL };

    InsertBeginning(&myList, '5');
    PrintListFromHead(&myList);
    InsertEnd(&myList, '4');
    PrintListFromHead(&myList);
    InsertBefore(&myList, 723, '3');
    PrintListFromHead(&myList);
    InsertBefore(&myList, 0, '1');
    PrintListFromHead(&myList);
    InsertBefore(&myList, 1, '7');
    PrintListFromHead(&myList);
    InsertAfter(&myList, 0, '9');
    PrintListFromHead(&myList);
    InsertAfter(&myList, 3, '9');
    PrintListFromHead(&myList);
    InsertAfter(&myList, 7, '9');
    PrintListFromHead(&myList);
    RemoveAt(&myList, 6);
    PrintListFromHead(&myList);
    RemoveAt(&myList, 76);

    printf("List from head: ");
    PrintListFromHead(&myList);

    return 0;
}
