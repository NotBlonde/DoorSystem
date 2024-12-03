#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cardholder.h"



void saveCardholder(const char *cardNumber, const char *cardholderName){
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL){
        printf("Error: unable to open file for writing\n");
        return;
    }
    fprintf(file, "%s %s \n", cardNumber, cardholderName);
    fclose(file);
    printf("File successfully saved. \n");
}

void getCardholderName(const char *cardNumber){
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL){
        printf("Error: Unable to open file for reading.\n");
        return;
    }

    char fileCardNumner[10], fileCardholderName[100];
    int found = 0;


    while (fscanf(file, "%s %99[^\n]", fileCardNumner, fileCardholderName) != EOF){
        if(strcmp(fileCardNumner, cardNumber) == 0) {
            printf("Cardholder Name: %s\n", fileCardholderName);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Error: Cardholder with number %s not found.\n", cardNumber);
    }
    fclose(file);
}