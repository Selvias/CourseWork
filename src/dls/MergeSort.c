#include "funclibs.h"

void mergesort(int *source, int low, int high) {

    int mid = low + (high - low) / 2;

    if (low == high) 
        return;
    else if (low < high) {
        if (high - low == 1) {
            if (source[low] > source[high])
            {
                int temp = source[low];
                source[low] = source[high];
                source[high] = temp;
            }
        }
        mergesort(source, low, mid);
        mergesort(source, mid + 1, high);
        merge(source, low, high);
    }
}

void merge(int *src, int low, int high) {
    int i = low, k = 0;
    int mid = low + ((high - low) / 2);
    int j = mid + 1;
    int len = high - low + 1;

    int *dest = NULL;
    dest = (int*)calloc(len, sizeof(int));
    if (dest == NULL) {
        printf("ERROR\n");
        return;
    }

    while (i <= mid && j <= high)
    {
        if (src[i] <= src[j])
        {
            dest[k] = src[i];
            i++;
        }
        else {
            dest[k] = src[j];
            j++;
        }
        k++;
    }

    //Запись оставшихся не записанных элементов (если таковые имеются)
    while (i <= mid)
    {
        dest[k] = src[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        dest[k] = src[j];
        j++;
        k++;
    }

    //Перезапись в исходный массив отсортированного
    for (i = 0; i < k; i++)
        src[low + i] = dest[i];

    free(dest);
}
