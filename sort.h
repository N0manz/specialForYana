#pragma once
#include "Publication.h"
#include "list.h"
#include <string.h>
#define SORT_H

void insertionSort(Publication* array, size_t size, int (*comparator)(const void*, const void*));
int compareByYear(const void* a, const void* b);
int compareByYearDescending(const void* a, const void* b);
void insertionSortList(DoublyLinkedList* list, int (*comparator)(const void*, const void*));