#include "funclibs.h"

void filltxt(FILE *input, int n) {
    for (int t = 0; t < n; t++)
        fprintf(input, "%d\n", rand() % 1000);
}