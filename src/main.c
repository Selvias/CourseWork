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

    //Use fseek() to find size of file (count of elsements) (1 pos ~ 4 bytes for integer)

    FILE *in;
    FILE *out;

    in = fopen(input, "r");
    out = fopen(output, "w");

    if (in == NULL) {
        printf("The input file can't be opened.\n");
        return -1;
    }
    if (out == NULL) {
        printf("The output file can't be opened.\n");
        return -1;
    }

    //Нахождения размера файла (Для общего случая, когда тип int занимает 4 байта (txt файл использует кодировку UTF-8, можно использовать другой тип файлов))
    //ftell возвращает смещение относительно начала файла (в байтах)
    fseek(in, 0, SEEK_END);
    int fsize = ftell(in) / 4 - ftell(in) % 4;

    int *tosort = NULL;
    tosort = (int*)calloc(fsize, sizeof(int));

    if (tosort == NULL) {
        printf("Memory allocation failure\n");
        return -1;
    }

    fseek(in, 0, SEEK_SET);
    //Заполнение массива числами из входного файла
    int i = 0;
    while (!feof(in)) {
        fscanf(in, "%d", &tosort[i]);
        i++;
    }

    // printf("BEFORE SORTING :\n");
    // for (int j = 0; j < fsize; j++) {
    //     printf("arr[%d] = %d\n", j, tosort[j]);
    // }

    if (strcmp(type, "mergesort") == 0)
        mergesort(tosort, 0, fsize - 1);
    else if (strcmp(type, "shellsort") == 0)
        shellsort(tosort, fsize);

    // printf("AFTER SORTING :\n");
    // for (int j = 0; j < fsize; j++) {
    //     printf("arr[%d] = %d\n", j, tosort[j]);
    // }

    for (int t = 0; t < fsize; t++)
        fprintf(out, "%d\n", tosort[t]);

    fclose(in);
    fclose(out);
    free(tosort);

    return 0;
}