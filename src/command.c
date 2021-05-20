#include "funclibs.h"

int command(const char *input, const char *output, const char *type) {

    clock_t start, stop;
    double progtime;

    printf("Enter count of elements : ");
    int n = scannum();

    filltxt(n, input);

    int fsize = findsize(input);

    int *tosort = NULL;
    tosort = (int*)calloc(fsize, sizeof(int));
    if (tosort == NULL) {
        printf("Memory allocation failure\n");
        return -1;
    }

    fillarr(fsize, input, tosort);

    if (strcmp(type, "mergesort") == 0) {
        start = clock();
        mergesort(tosort, 0, n - 1);
        stop = clock();
        progtime = (double)(stop - start) / CLOCKS_PER_SEC;
        printf("Merge Sort Time : %.4f\n", progtime);
    }
    else if (strcmp(type, "shellsort") == 0) {
        start = clock();
        shellsort(tosort, n);
        stop = clock();
        progtime = (double)(stop - start) / CLOCKS_PER_SEC;
        printf("Shell Sort Time : %.4f\n", progtime);
    }

    writefile(fsize, output, &tosort);

    int cflag = checkrez(fsize, tosort);

    if (cflag == 0)
        printf("Sorting complete\n");
    else if (cflag == -1)
        printf("Sorting works incorrectly\n");

    free(tosort);

    return 0;
}