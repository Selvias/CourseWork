#include "funclibs.h"

int findsize(FILE *input, FILE *output) {
    fseek(input, 0, SEEK_END);
    return ftell(input);
}