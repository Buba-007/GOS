#include <iostream>

// Двусвязный список для АиСД на С++ (если можно на нём)
template <typename T>
class DoublyLinkedListCPP {
private:
    struct DoublyNode {
        T data;
        struct DoublyNode* next;
        struct DoublyNode* previous;
    };

    DoublyNode* head = nullptr;
    DoublyNode* tail = nullptr;

public:
    void InsertBeginning(T data) {
        DoublyNode* newNode = new DoublyNode();
        newNode->data = data;
        
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }
        else {
            InsertBefore(0, data);
        }
    }

    void InsertEnd(T data) {
        DoublyNode* newNode = new DoublyNode();
        newNode->data = data;

        if (head == nullptr) {
            InsertBeginning(data);
        }
        else {
            InsertAfter(Lenght() - 1, data);
        }
    }

    void InsertBefore(int index, T data) {
        DoublyNode* newNode = new DoublyNode();
        newNode->data = data;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }

        DoublyNode* indexNode = head;

        for (int i = 0; i < index; i++) {
            if (indexNode->next != nullptr) {
                indexNode = indexNode->next;
            }
        }

        newNode->next = indexNode;
        if (indexNode->previous == nullptr) {
            newNode->previous = nullptr;
            indexNode->previous = newNode;
            head = newNode;
        }
        else {
            newNode->previous = indexNode->previous;
            indexNode->previous->next = newNode;
            indexNode->previous = newNode;
        }
    }

    void InsertAfter(int index, T data) {
        DoublyNode* newNode = new DoublyNode();
        newNode->data = data;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }

        DoublyNode* indexNode = head;

        for (int i = 0; i < index; i++) {
            if (indexNode->next != nullptr) {
                indexNode = indexNode->next;
            }
        }

        if (indexNode->next == nullptr) {
            newNode->next = nullptr;
            newNode->previous = indexNode;
            indexNode->next = newNode;
            tail = newNode;
        }
        else {
            newNode->next = indexNode->next;
            newNode->previous = indexNode;
            indexNode->next->previous = newNode;
            indexNode->next = newNode;
        }
    }

    void RemoveAt(int index) {
        if (head == nullptr) {
            return;
        }
        if (head->next == nullptr) {
            head = nullptr;
            tail = nullptr;
        }

        DoublyNode* indexNode = head;

        for (int i = 0; i < index; i++) {
            if (indexNode->next != nullptr) {
                indexNode = indexNode->next;
            }
        }

        if (indexNode->next == nullptr) {
            indexNode->previous->next = nullptr;
            tail = indexNode->previous;
        }
        else {
            if (indexNode->previous == nullptr) {
                indexNode->next->previous = nullptr;
                head = indexNode->next;
            }
            else {
                indexNode->previous->next = indexNode->next;
                indexNode->next->previous = indexNode->previous;
            }
        }
    }

    int Lenght() {
        int count = 1;
        DoublyNode* indexNode = head;
        if (head == nullptr) {
            return 0;
        }
        while (indexNode->next != nullptr)
        {
            indexNode = indexNode->next;
            count++;
        }
        return count;
    }

    void PrintListFromHead() {
        struct DoublyNode* ptr = head;
        while (ptr != nullptr) {
            std::cout << "(" << ptr->data << ")->";
            ptr = ptr->next;
        }
        std::cout << "()" << std::endl;
    }

    void PrintListFromTail() {
        struct DoublyNode* ptr = tail;
        std::cout << "()";
        while (ptr != nullptr) {
            std::cout << "<-(" << ptr->data << ")";
            ptr = ptr->previous;
        }
        std::cout << "" << std::endl;
    }
};

#include <stdio.h>
#include <stdlib.h>

// Двусвязный список для АиСД на С (если нельзя на C)
typedef struct DoublyNode {
    char data;
    struct DoublyNode* next;
    struct DoublyNode* previous;
} DoublyNode;

typedef struct DoublyLinkedListC {
    DoublyNode* head = NULL;
    DoublyNode* tail = NULL;
} DoublyLinkedListC;
    
void InsertBefore(DoublyLinkedListC* list, int index, char data) {
    DoublyNode* newNode = (DoublyNode*)malloc(sizeof(DoublyNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->previous = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        return;
    }

    DoublyNode* indexNode = list->head;

    for (int i = 0; i < index; i++) {
        if (indexNode->next != NULL) {
            indexNode = indexNode->next;
        }
    }

    newNode->next = indexNode;
    if (indexNode->previous == NULL) {
        newNode->previous = NULL;
        indexNode->previous = newNode;
        list->head = newNode;
    }
    else {
        newNode->previous = indexNode->previous;
        indexNode->previous->next = newNode;
        indexNode->previous = newNode;
    }
}

void InsertAfter(DoublyLinkedListC* list, int index, char data) {
    DoublyNode* newNode = (DoublyNode*)malloc(sizeof(DoublyNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->previous = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        return;
    }

    DoublyNode* indexNode = list->head;

    for (int i = 0; i < index; i++) {
        if (indexNode->next != NULL) {
            indexNode = indexNode->next;
        }
    }

    if (indexNode->next == NULL) {
        newNode->next = NULL;
        newNode->previous = indexNode;
        indexNode->next = newNode;
        list->tail = newNode;
    }
    else {
        newNode->next = indexNode->next;
        newNode->previous = indexNode;
        indexNode->next->previous = newNode;
        indexNode->next = newNode;
    }
}

void RemoveAt(DoublyLinkedListC* list, int index) {
    if (list->head == NULL) {
        return;
    }
    if (list->head->next == NULL) {
        list->head = NULL;
        list->tail = NULL;
    }

    DoublyNode* indexNode = list->head;

    for (int i = 0; i < index; i++) {
        if (indexNode->next != NULL) {
            indexNode = indexNode->next;
        }
    }

    if (indexNode->next == NULL) {
        indexNode->previous->next = NULL;
        list->tail = indexNode->previous;
    }
    else {
        if (indexNode->previous == NULL) {
            indexNode->next->previous = NULL;
            list->head = indexNode->next;
        }
        else {
            indexNode->previous->next = indexNode->next;
            indexNode->next->previous = indexNode->previous;
        }
    }
}

int Lenght(DoublyLinkedListC* list) {
    int count = 1;
    DoublyNode* indexNode = list->head;
    if (list->head == NULL) {
        return 0;
    }
    while (indexNode->next != NULL)
    {
        indexNode = indexNode->next;
        count++;
    }
    return count;
}

void InsertBeginning(DoublyLinkedListC* list, char data) {
    DoublyNode* newNode = (DoublyNode*)malloc(sizeof(DoublyNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->previous = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        return;
    }
    else {
        InsertBefore(list, 0, data);
    }
}

void InsertEnd(DoublyLinkedListC* list, char data) {
    DoublyNode* newNode = (DoublyNode*)malloc(sizeof(DoublyNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->previous = NULL;

    if (list->head == NULL) {
        InsertBeginning(list, data);
    }
    else {
        InsertAfter(list, Lenght(list) - 1, data);
    }
}

void PrintListFromHead(DoublyLinkedListC* list) {
    struct DoublyNode* ptr = list->head;
    while (ptr != NULL) {
        printf("(%c)->", ptr->data);
        ptr = ptr->next;
    }
    printf("()\n");
}

void PrintListFromTail(DoublyLinkedListC* list) {
    struct DoublyNode* ptr = list->tail;
    printf("()");
    while (ptr != NULL) {
        printf("<-(%c)", ptr->data);
        ptr = ptr->previous;
    }
    printf("\n");
}



int main()
{
    /* ---   C++ --- */

    /*
    DoublyLinkedListCPP<int> myList;
    myList.InsertBeginning(3);
    myList.InsertBeginning(2);
    myList.InsertBeginning(1);
    myList.InsertEnd(4);
    myList.InsertEnd(5);
    myList.InsertEnd(6);

    myList.PrintListFromHead();

    myList.RemoveAt(4);

    myList.PrintListFromTail();
    */

    /* --- C --- */

    DoublyLinkedListC myList = { NULL, NULL };

    InsertBeginning(&myList, '5');
    InsertEnd(&myList, '10');
    InsertBefore(&myList, 2, '3');
    InsertAfter(&myList, 1, '7');
    RemoveAt(&myList, '2');

    printf("List from head: ");
    PrintListFromHead(&myList);

    printf("List from tail: ");
    PrintListFromTail(&myList);

    return 0;
}
