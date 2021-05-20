#include "funclibs.h"

int main(int argc, char **argv) {

    const char *input= argv[1];
    const char *output = argv[2];
    const char *type = argv[3];

    if (input == NULL || output == NULL || type == NULL) {
        printf("Usage :\nappsort <input-file-name> <output-file-name> <sorting-type>\n");
        return -1;
    } 
    else if (strcmp(type, "shellsort") != 0 && strcmp(type, "mergesort") != 0) {
        printf("Usage :\n<shellsort> or <mergesort>\n");
        return -1;
    }

    command(input, output, type);

    return 0;
}