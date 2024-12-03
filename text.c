#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>



int main (){
    char options;
    char cNum[20];
    
    printf("1. \n");
    printf("2. \n");

    scanf("%c", &options);

    switch (options)
    {
    case '1':
        printf("Enter card: ");
        getchar();
        if (fgets(cNum, sizeof (cNum), stdin) != NULL){
            //cNum[strcpn(cNum, "\n")] = '\0';
            printf("You entered: %s\n", cNum);
        }
        break;

    case 2:
    
    default:
        break;
    }




}