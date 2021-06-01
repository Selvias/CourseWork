#include "funclibs.h"

int fillarr(int n, const char *filename, int *tofill) {
    FILE *in;
    in = fopen(filename, "rb");

    if (in == NULL) {
        printf("The input file can't be opened.\n");
        return -1;
    }

    //Заполнение массива числами из входного файла
    fread(tofill, sizeof(int), n, in);

    fclose(in);
    return 0;
}