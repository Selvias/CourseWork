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

    FILE *in;
    FILE *out;

    in = fopen(input, "wb");
    out = fopen(output, "wb");

    if (in == NULL) {
        printf("The input file can't be opened.\n");
        return -1;
    }
    if (out == NULL) {
        printf("The output file can't be opened.\n");
        return -1;
    }

    int n;

    printf("Enter count of elements : ");
    scanf("%d", &n);

    filltxt(in, n);

    
    fclose(in);
    in = fopen(input, "rb");

    int fsize = findsize(in, out);
    printf("SIZE : %d\n", fsize);

    int *tosort = NULL;
    tosort = (int*)calloc(n, sizeof(int));

    if (tosort == NULL) {
        printf("Memory allocation failure\n");
        return -1;
    }

    //Заполнение массива числами из входного файла
    int i = 0;
    fseek(in, 0, SEEK_SET);
    while (1) {
        if (feof(in))
            break;
        fscanf(in, "%d", &tosort[i]);
        i++;
    }

    if (strcmp(type, "mergesort") == 0)
        mergesort(tosort, 0, n - 1);
    else if (strcmp(type, "shellsort") == 0)
        shellsort(tosort, n);

    for (int t = 0; t < n; t++)
        fprintf(out, "%d\n", tosort[t]);

    fclose(in);
    fclose(out);
    free(tosort);

    return 0;
}