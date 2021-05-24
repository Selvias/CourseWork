#include "funclibs.h"

int findsize(const char *filename) {

    FILE *input;
    input = fopen(filename, "rb");

    int fsize;

    fseek(input, 0, SEEK_END);
    fsize = ftell(input) / sizeof(int);
    fseek(input, 0, SEEK_SET);

    return fsize;
}