#include "funclibs.h"

void filltxt(int n, const char *filename) {

    FILE *out;
    out = fopen(filename, "wb");

    if (out == NULL) {
        printf("The input file can't be opened.\n");
        exit(-1);
    }

    char *tcase = (char *)malloc(7*sizeof(char));

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
    if (strcmp(tcase, "best") == 0) {
        for (int t = 0; t < n; t++) {
            d = t;
            fwrite(&d, sizeof(int), 1, out);
        }
    }
    if (strcmp(tcase, "worst") == 0) {
        for (int t = 0; t < n; t++) {
            d = n - t;
            fwrite(&d, sizeof(int), 1, out);
        }
    }

    fclose(out);
    free(tcase);
}

void fillarr(int n, const char *filename, int *tofill) {
    FILE *in;
    in = fopen(filename, "rb");

    if (in == NULL) {
        printf("The input file can't be opened.\n");
        exit(-1);
    }

//Заполнение массива числами из входного файла
    // int i = 0;
    // while (!feof(in)) {
    //     if (feof(in))
    //         break;
    //     fscanf(in, "%d", (tofill)[i]);
    //     i++;
    // }

    // for(int i = 0; i < n; i++) {
    //     fscanf(in, "%d", &tofill[i]);
        fread(tofill, sizeof(int), n, in);
        // printf("%d\n", (tofill)[i]);
    // }

    fclose(in);
}