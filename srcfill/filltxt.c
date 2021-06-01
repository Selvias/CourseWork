#include "addlib.h"

int filltxt(int n, const char *filename) {

    FILE *out;
    out = fopen(filename, "wb");

    if (out == NULL) {
        printf("The input file can't be opened.\n");
        exit(-1);
    }

    char *tcase = (char *)malloc(7*sizeof(char));
    if (tcase == NULL) {
        printf("Memory allocation failure.\n");
        return -1;
    }

    getchar();

    printf("Enter type of case (best, worst, middle) : ");
    fscanf(stdin, "%s", tcase);

    int d;

    if (strcmp(tcase, "middle") == 0) {
        for (int t = 0; t < n; t++) {
            d = rand () % 10000;
            fwrite(&d, sizeof(int), 1, out);
        }
    }
    else if (strcmp(tcase, "best") == 0) {
        for (int t = 0; t < n; t++) {
            d = t;
            fwrite(&d, sizeof(int), 1, out);
        }
    }
    else if (strcmp(tcase, "worst") == 0) {
        for (int t = 0; t < n; t++) {
            d = n - t;
            fwrite(&d, sizeof(int), 1, out);
        }
    }
    else 
        return -1;

    fclose(out);
    free(tcase);
    return 0;
}