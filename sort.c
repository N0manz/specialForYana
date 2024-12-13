#include "sort.h"
#include <stddef.h>
#include <stdlib.h>

void insertionSort(Publication* array, size_t size, int (*comparator)(const void*, const void*)) {
    for (size_t i = 1; i < size; i++) {
        Publication key = array[i];
        ssize_t j = i - 1;
        while (j >= 0 && comparator(&array[j], &key) > 0) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

int compareByYear(const void* a, const void* b) {
    const Publication* pa = (const Publication*)a;
    const Publication* pb = (const Publication*)b;
    return pa->year - pb->year;
}

int compareByYearDescending(const void* a, const void* b) {
    const Publication* pa = (const Publication*)a;
    const Publication* pb = (const Publication*)b;
    return pb->year - pa->year;
}

void insertionSortList(DoublyLinkedList* list, int (*comparator)(const void*, const void*)) {
    Publication* array = listToArray(list);
    insertionSort(array, list->size, comparator);
    arrayToList(list, array, list->size);
    free(array);
}
