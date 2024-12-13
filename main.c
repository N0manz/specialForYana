#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Publication.h"
#include "list.h"
#include "sort.h"
#include "X.h"

int main(int argc, char* argv[]) {
    DoublyLinkedList list;
    initializeList(&list);

    if (argc > 1) {
        if (strcmp(argv[1], "-g") == 0) { // Generate mode
            if (argc < 4) {
                fprintf(stderr, "Usage: %s -g N -o FILE\n", argv[0]);
                return EXIT_FAILURE;
            }
            int n = atoi(argv[2]);
            generatePublications(&list, n);
            printf("Generated %d publications\n", n);

            if (strcmp(argv[3], "-o") == 0 && argc >= 5) {
                printf("Saving generated data to file: %s\n", argv[4]);
                saveToFile(&list, argv[4]);
            } else {
                fprintf(stderr, "Error: No output file specified\n");
                return EXIT_FAILURE;
            }
        } else if (strcmp(argv[1], "-s") == 0) { // Sort mode
            if (argc < 6 || strcmp(argv[2], "-i") != 0) {
                fprintf(stderr, "Usage: %s -s -i FILE -o FILE [-t A|D]\n", argv[0]);
                return EXIT_FAILURE;
            }

            printf("Loading data from file: %s\n", argv[3]);
            loadFromFile(&list, argv[3]);

            int ascending = 1; // Default sorting order: ascending
            if (argc >= 8 && strcmp(argv[6], "-t") == 0) {
                if (strcmp(argv[7], "D") == 0) {
                    ascending = 0;
                } else if (strcmp(argv[7], "A") != 0) {
                    fprintf(stderr, "Error: Invalid sorting type. Use 'A' or 'D'\n");
                    return EXIT_FAILURE;
                }
            }

            printf("Sorting data in %s order\n", ascending ? "ascending" : "descending");
            if (ascending) {
                insertionSortList(&list, compareByYear);
            } else {
                insertionSortList(&list, compareByYearDescending);
            }

            if (strcmp(argv[4], "-o") == 0 && argc >= 6) {
                printf("Saving sorted data to file: %s\n", argv[5]);
                saveToFile(&list, argv[5]);
            } else {
                fprintf(stderr, "Error: No output file specified\n");
                return EXIT_FAILURE;
            }
        } else if (strcmp(argv[1], "-P") == 0) { // Print mode
            if (argc < 4 || strcmp(argv[2], "-i") != 0) {
                fprintf(stderr, "Usage: %s -P -i FILE\n", argv[0]);
                return EXIT_FAILURE;
            }

            printf("Loading data from file: %s\n", argv[3]);
            loadFromFile(&list, argv[3]);
            printList(&list);
        } else {
            fprintf(stderr, "Unknown command: %s\n", argv[1]);
            return EXIT_FAILURE;
        }
    } else {
        fprintf(stderr, "Usage: %s -g N -o FILE | -s -i FILE -o FILE [-t A|D] | -P -i FILE\n", argv[0]);
        return EXIT_FAILURE;
    }

    clearList(&list);
    return 0;
}