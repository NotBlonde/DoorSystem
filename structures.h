#ifndef STRUCTURES_H
#define STRUCTURES_H

#define FILE_NAME "cardholders.txt"

typedef struct {
    char cardNumber[10];
    char cardHolderName[100];
    int hasAccess;       // 1 for access, 0 for no access
    char dateAdded[20];  // Format: YYYY-MM-DD
} Card;

typedef struct {
    Card *cards;
    size_t count;        // Number of cards
    size_t capacity;     // Current allocated size
} CardSystem;

#endif // STRUCTURES_H
