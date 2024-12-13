#pragma once
#define X_H

#include "list.h"

void generatePublications(DoublyLinkedList* list, int count);
void printList(DoublyLinkedList* list);
void saveToFile(DoublyLinkedList* list, const char* filename);
void loadFromFile(DoublyLinkedList* list, const char* filename);
void readFromStdin(DoublyLinkedList* list);

