#include "funclibs.h"

int command(const char *input, const char *output, const char *type) {

    clock_t start, stop;
    double progtime;
    int flag = 0;

    int fsize = findsize(input);

    printf("Size of file : %d\n", fsize);

    int *tosort = NULL;
    tosort = (int*)calloc(fsize, sizeof(int));
    if (tosort == NULL) {
        printf("Memory allocation failure\n");
        return -1;
    }

    flag = fillarr(fsize, input, tosort);
    if (flag == -1) {
        free(tosort);
        return -1;
    }

    if (strcmp(type, "mergesort") == 0) {
        start = clock();
        mergesort(tosort, 0, fsize - 1);
        stop = clock();
        progtime = (double)(stop - start) / CLOCKS_PER_SEC;
        printf("Merge Sort Time : %.4f\n", progtime);
    }
    else if (strcmp(type, "shellsort") == 0) {
        start = clock();
        shellsort(tosort, fsize);
        stop = clock();
        progtime = (double)(stop - start) / CLOCKS_PER_SEC;
        printf("Shell Sort Time : %.4f\n", progtime);
    }

    flag = writefile(fsize, output, &tosort);
    if (flag == -1) {
        free(tosort);
        return -1;
    }

    int cflag = checkrez(fsize, tosort);

    if (cflag == 0)
        printf("Sorting complete\n");
    else if (cflag == -1)
        printf("Sorting works incorrectly\n");

    free(tosort);

    return 0;
}