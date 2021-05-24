#include "funclibs.h"

int checkrez(int n, int *sorted) {
    for (int i = 0; i < n - 1; i++) {
        if (sorted[i] > sorted[i + 1]) {
            return -1;
        }
    }
    return 0;
}