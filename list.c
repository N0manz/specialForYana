#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void initializeList(DoublyLinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

Node* createNode(Publication data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        perror("Failed to allocate memory for node");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void addToEnd(DoublyLinkedList* list, Publication data) {
    Node* newNode = createNode(data);
    if (list->tail) {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    } else {
        list->head = newNode;
        list->tail = newNode;
    }
    list->size++;
}

void clearList(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

Publication* listToArray(DoublyLinkedList* list) {
    Publication* array = (Publication*)malloc(list->size * sizeof(Publication));
    if (!array) {
        perror("Failed to allocate memory for array");
        exit(EXIT_FAILURE);
    }
    Node* current = list->head;
    for (size_t i = 0; i < list->size; i++) {
        array[i] = current->data;
        current = current->next;
    }
    return array;
}

void arrayToList(DoublyLinkedList* list, Publication* array, size_t size) {
    initializeList(list);
    for (size_t i = 0; i < size; i++) {
        addToEnd(list, array[i]);
    }
}