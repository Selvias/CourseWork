#include "addlib.h"

int command(const char *input) {

    int flag = 0;

    printf("Enter count of elements : ");
    int n = scannum();

    flag = filltxt(n, input);
    if (flag == -1) {
        return -1;
    }

    return 0;
}