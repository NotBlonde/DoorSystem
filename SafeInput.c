#include <stdio.h>
#include <string.h>
#include "SafeInput.h"

INPUT_RESULT GetInput(char *prompt, char *buff, int maxSize) {
    if (prompt) {
        printf("%s", prompt);
    }

    if (fgets(buff, maxSize, stdin) == NULL) {
        return INPUT_RESULT_NO_INPUT;
    }

    size_t len = strlen(buff);
    if (buff[len - 1] != '\n') {
        // Buffer overflow, flush input
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
        return INPUT_RESULT_TOO_LONG;
    }

    // Remove the newline
    buff[len - 1] = '\0';
    return INPUT_RESULT_OK;
}
