#pragma once
#define PUBLICATION_H
#include <stdbool.h>
typedef struct {
    char nameOfPublication[100];
    char Surname[100];
    char Initials[3];
    char nameOfMagazine[50];
    int year;
    char volumeOfMagazine[10];
    bool isInPINC;
    int numberOfPages;
    int numberOfQuotes;
} Publication;