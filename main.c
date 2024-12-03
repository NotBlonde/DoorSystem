#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "cardholder.c"
#include "cardholder.h"
#include "SafeInput.h"


int main(){
    int choice;
    char cardNumber[10];
    char cardHolderNumber[100];

    while(1){
        printf("\nADMIN MENU:\n");

        printf("1. Remote open door\n");
        
        printf("2. Add Card/Remove card\n");
        printf("3. Acesss Cards\n");
        printf("4. Exit\n");
        
        printf("9. FAKE TEST SCAN CARD\n");

        GetInputInt("Enter Number:", &choice);


        
        
        
        

        switch (choice)
        {
        case 1:
            printf("Currently LAMP is: GREEN\n");


        case 2: // Adds cardholder
            printf("Enter a 4-digit card number: ");
            if (fgets(cardNumber, sizeof(cardNumber), stdin) != NULL){
                cardNumber[strcspn(cardNumber, "\n")] = '\0';

                printf("Enter cardholder's name: ");

                if(fgets(cardHolderNumber, sizeof(cardHolderNumber), stdin) != NULL){
                    cardHolderNumber[strcspn(cardHolderNumber, "\n")] = '\0';
                    saveCardholder(cardNumber, cardHolderNumber);
                }
            }
            break;

        case 3: // List all cards
            printf("Card numbers: \t Card Names: ");
            
            break;
        
        default:
            break;
        }
    }
}




