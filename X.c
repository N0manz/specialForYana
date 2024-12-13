#include "X.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generatePublications(DoublyLinkedList* list, int count) {
    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        Publication pub;
        snprintf(pub.nameOfPublication, sizeof(pub.nameOfPublication), "Publication%d", i);
        snprintf(pub.Surname, sizeof(pub.Surname), "Author%d", i);
        snprintf(pub.Initials, sizeof(pub.Initials), "A%d", i);
        snprintf(pub.nameOfMagazine, sizeof(pub.nameOfMagazine), "Magazine%d", i);
        pub.year = 2000 + rand() % 23;
        snprintf(pub.volumeOfMagazine, sizeof(pub.volumeOfMagazine), "Vol%d", i);
        pub.isInPINC = rand() % 2;
        pub.numberOfPages = rand() % 500 + 1;
        pub.numberOfQuotes = rand() % 100;
        addToEnd(list, pub);
    }
}

void printList(DoublyLinkedList* list) {
    Node* current = list->head;
    printf("%-20s %-20s %-10s %-20s %-6s %-10s %-4s %-6s %-6s\n",
           "Name", "Surname", "Initials", "Magazine", "Year", "Volume", "PINC", "Pages", "Quotes");
    printf("===================================================================================================\n");
    while (current) {
        printf("%-20s %-20s %-10s %-20s %-6d %-10s %-4s %-6d %-6d\n",
               current->data.nameOfPublication, current->data.Surname, current->data.Initials,
               current->data.nameOfMagazine, current->data.year, current->data.volumeOfMagazine,
               current->data.isInPINC ? "YES" : "NO", current->data.numberOfPages, current->data.numberOfQuotes);
        current = current->next;
    }
}

void saveToFile(DoublyLinkedList* list, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file for writing");
        return;
    }
    Node* current = list->head;
    while (current) {
        fprintf(file, "%s,%s,%s,%s,%d,%s,%d,%d,%d\n",
                current->data.nameOfPublication, current->data.Surname, current->data.Initials,
                current->data.nameOfMagazine, current->data.year, current->data.volumeOfMagazine,
                current->data.isInPINC, current->data.numberOfPages, current->data.numberOfQuotes);
        current = current->next;
    }
    printf("Saving to file: %s\n", filename);

    fclose(file); // Закрываем файл
}

void loadFromFile(DoublyLinkedList* list, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file for reading");
        return;
    }
    initializeList(list);
    char buffer[512];
    while (fgets(buffer, sizeof(buffer), file)) {
        Publication pub;
        sscanf(buffer, "%99[^,],%99[^,],%2[^,],%49[^,],%d,%9[^,],%d,%d,%d",
               pub.nameOfPublication, pub.Surname, pub.Initials, pub.nameOfMagazine, &pub.year,
               pub.volumeOfMagazine, (int*)&pub.isInPINC, &pub.numberOfPages, &pub.numberOfQuotes);
        addToEnd(list, pub);
    }
    fclose(file);
}

void readFromStdin(DoublyLinkedList* list) {
    initializeList(list);
    printf("Enter publication details (Name,Surname,Initials,Magazine,Year,Volume,PINC,Pages,Quotes):\n");
    char buffer[512];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        Publication pub;
        sscanf(buffer, "%99[^,],%99[^,],%2[^,],%49[^,],%d,%9[^,],%d,%d,%d",
               pub.nameOfPublication, pub.Surname, pub.Initials, pub.nameOfMagazine, &pub.year,
               pub.volumeOfMagazine, (int*)&pub.isInPINC, &pub.numberOfPages, &pub.numberOfQuotes);
        addToEnd(list, pub);
    }
}