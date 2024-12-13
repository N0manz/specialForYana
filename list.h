#pragma once
#include "Publication.h"
#include <stddef.h>

typedef struct Node {
    Publication data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    size_t size;
} DoublyLinkedList;

void initializeList(DoublyLinkedList* list);
Node* createNode(Publication data);
void addToEnd(DoublyLinkedList* list, Publication data);
void clearList(DoublyLinkedList* list);
Publication* listToArray(DoublyLinkedList* list);
void arrayToList(DoublyLinkedList* list, Publication* array, size_t size);