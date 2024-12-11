#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cardholder.h"
#include "SafeInput.h"

#ifdef _WIN32
#include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#else
#include <unistd.h>
#endif

void initializeCardSystem(CardSystem *system) {
    system->cards = NULL;
    system->count = 0;
    system->capacity = 0;
}

void freeCardSystem(CardSystem *system) {
    free(system->cards);
    system->cards = NULL;
    system->count = 0;
    system->capacity = 0;
}

void loadCardholders(CardSystem *system) {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No existing cardholder data found.\n");
        return;
    }

    char cardNumber[10], cardHolderName[100], dateAdded[20];
    int hasAccess;

    while (fscanf(file, "%s %99s %d %19s", cardNumber, cardHolderName, &hasAccess, dateAdded) == 4) {
        if (system->count == system->capacity) {
            system->capacity = (system->capacity == 0) ? 1 : system->capacity * 2;
            system->cards = realloc(system->cards, system->capacity * sizeof(Card));
        }

        strcpy(system->cards[system->count].cardNumber, cardNumber);
        strcpy(system->cards[system->count].cardHolderName, cardHolderName);
        system->cards[system->count].hasAccess = hasAccess;
        strcpy(system->cards[system->count].dateAdded, dateAdded);
        system->count++;
    }

    fclose(file);
}

void saveCardholders(CardSystem *system) {
    FILE *file = fopen(FILE_NAME, "w");
    if (!file) {
        printf("Error: Unable to save cardholder data.\n");
        return;
    }

    for (size_t i = 0; i < system->count; ++i) {
        fprintf(file, "%s %s %d %s\n",
                system->cards[i].cardNumber,
                system->cards[i].cardHolderName,
                system->cards[i].hasAccess,
                system->cards[i].dateAdded);
    }

    fclose(file);
}

void addRemoveAccess(CardSystem *system) {
    char cardNumber[10], cardHolderName[100];
    int access;

    printf("Enter card number: ");
    if (GetInput("Card Number: ", cardNumber, sizeof(cardNumber)) != INPUT_RESULT_OK) {
        printf("Invalid input.\n");
        return;
    }

    printf("Enter cardholder name: ");
    if (GetInput("Cardholder Name: ", cardHolderName, sizeof(cardHolderName)) != INPUT_RESULT_OK) {
        printf("Invalid input.\n");
        return;
    }

    printf("Grant access? (1 = Yes, 0 = No): ");
    scanf("%d", &access);
    getchar(); // Clear trailing newline

    for (size_t i = 0; i < system->count; ++i) {
        if (strcmp(system->cards[i].cardNumber, cardNumber) == 0) {
            system->cards[i].hasAccess = access;
            printf("Updated access for card %s.\n", cardNumber);
            return;
        }
    }

    if (system->count == system->capacity) {
        system->capacity = (system->capacity == 0) ? 1 : system->capacity * 2;
        system->cards = realloc(system->cards, system->capacity * sizeof(Card));
    }

    strcpy(system->cards[system->count].cardNumber, cardNumber);
    strcpy(system->cards[system->count].cardHolderName, cardHolderName);
    system->cards[system->count].hasAccess = access;

    time_t t = time(NULL);
    strftime(system->cards[system->count].dateAdded, sizeof(system->cards[system->count].dateAdded), "%Y-%m-%d", localtime(&t));

    system->count++;
    printf("Added card %s.\n", cardNumber);
}

void listAllCards(const CardSystem *system) {
    printf("Card Number\tAccess\tDate Added\tCardholder Name\n");
    printf("--------------------------------------------------------\n");
    for (size_t i = 0; i < system->count; ++i) {
        printf("%s\t\t%s\t%s\t%s\n",
               system->cards[i].cardNumber,
               system->cards[i].hasAccess ? "Yes" : "No",
               system->cards[i].dateAdded,
               system->cards[i].cardHolderName);
    }
}

void remoteOpenDoor(const CardSystem *system) {
    char cardNumber[10], cardHolderName[100];

    printf("Enter card number: ");
    if (GetInput("Card Number: ", cardNumber, sizeof(cardNumber)) != INPUT_RESULT_OK) {
        printf("Invalid input.\n");
        return;
    }

    printf("Enter cardholder name: ");
    if (GetInput("Cardholder Name: ", cardHolderName, sizeof(cardHolderName)) != INPUT_RESULT_OK) {
        printf("Invalid input.\n");
        return;
    }

    for (size_t i = 0; i < system->count; ++i) {
        if (strcmp(system->cards[i].cardNumber, cardNumber) == 0 &&
            strcmp(system->cards[i].cardHolderName, cardHolderName) == 0) {
            if (system->cards[i].hasAccess) {
                printf("CURRENTLY LAMP IS: GREEN\n");
                sleep(3);
                return;
            } else {
                printf("CURRENTLY LAMP IS: RED (No Access)\n");
                return;
            }
        }
    }
    printf("Card not found.\n");
}

void fakeCardScan(const CardSystem *system, const char *cardNumber, const char *cardHolderName) {
    for (size_t i = 0; i < system->count; ++i) {
        if (strcmp(system->cards[i].cardNumber, cardNumber) == 0 &&
            strcmp(system->cards[i].cardHolderName, cardHolderName) == 0) {
            if (system->cards[i].hasAccess) {
                printf("CURRENTLY LAMP IS: GREEN\n");
                return;
            } else {
                printf("CURRENTLY LAMP IS: RED\n");
                return;
            }
        }
    }
    printf("Card not found.\n");
}
