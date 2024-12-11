#include <stdio.h>
#include "cardholder.h"
#include "SafeInput.h"

int main() {
    CardSystem system;
    initializeCardSystem(&system);
    loadCardholders(&system);

    int choice;
    while (1) {
        printf("\nADMIN MENU:\n");
        printf("1. Remote open door\n");
        printf("2. Add/Remove access\n");
        printf("3. List all cards\n");
        printf("4. Fake card scan\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            while (getchar() != '\n'); // Clear invalid input
            continue;
        }
        getchar(); // Clear trailing newline

        switch (choice) {
            case 1:
                remoteOpenDoor(&system);
                break;
            case 2:
                addRemoveAccess(&system);
                break;
            case 3:
                listAllCards(&system);
                break;
            case 4: {
                char cardNumber[10], cardHolderName[100];
                printf("Enter card number: ");
                GetInput("Card Number: ", cardNumber, sizeof(cardNumber));
                printf("Enter cardholder name: ");
                GetInput("Cardholder Name: ", cardHolderName, sizeof(cardHolderName));
                fakeCardScan(&system, cardNumber, cardHolderName);
                break;
            }
            case 5:
                saveCardholders(&system);
                freeCardSystem(&system);
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
