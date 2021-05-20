#include "funclibs.h"

int findsize(const char *filename) {

    FILE *input;
    input = fopen(filename, "rb");

    int fsize = 0, temp;

    if (input == NULL) {
        printf("The input file can't be opened.\n");
        return -1;
    }

    fseek(input, 0, SEEK_SET);
    while (!feof(input)) {
        fscanf(input, "%d", &temp);

        if (feof(input))
            break;

        fsize++;
    }
    fseek(input, 0, SEEK_SET);
    return fsize;
}