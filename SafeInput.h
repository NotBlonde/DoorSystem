#ifndef SAFEINPUT_H
#define SAFEINPUT_H

typedef enum {
    INPUT_RESULT_OK,
    INPUT_RESULT_TOO_LONG,
    INPUT_RESULT_NO_INPUT
} INPUT_RESULT;

INPUT_RESULT GetInput(char *prompt, char *buff, int maxSize);

#endif // SAFEINPUT_H
