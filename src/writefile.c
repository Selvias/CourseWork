#include "funclibs.h"

int writefile(int n, const char *filename, int **towrite) {
    FILE *out;

    out = fopen(filename, "wb");

    if (out == NULL) {
        printf("The output file can't be opened.\n");
        return -1;
    }

    for (int t = 0; t < n; t++)
        fprintf(out, "%d\n", (*towrite)[t]);

    fclose(out);
    return 0;
}