#include "funclibs.h"

void filltxt(int n, const char *filename) {

    FILE *in;
    in = fopen(filename, "wb");

    // printf("%s\n", filename);

    if (in == NULL) {
        printf("The input file can't be opened.\n");
        exit(-1);
    }

    char *tcase = (char *)malloc(7*sizeof(char));

    getchar();

    printf("Enter type of case (best, worst, middle) : ");
    fscanf(stdin, "%s", tcase);

    if (strcmp(tcase, "middle") == 0) {
        for (int t = 0; t < n; t++)
            fprintf(in, "%d\n", rand() % 1000);
    }
    if (strcmp(tcase, "best") == 0) {
        for (int t = 0; t < n; t++)
            fprintf(in, "%d\n", t);
    }
    if (strcmp(tcase, "worst") == 0) {
        for (int t = 0; t < n; t++)
            fprintf(in, "%d\n", n - t);
    }

    fclose(in);
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
    for(int i = 0; i < n; i++) {
        fscanf(in, "%d", &tofill[i]);
        // printf("%d\n", (tofill)[i]);
    }
    fclose(in);
}