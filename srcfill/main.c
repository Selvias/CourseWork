#include "addlib.h"

int main(int argc, char **argv) {

    const char *input= argv[1];

    if (input == NULL) {
        printf("Usage :\nfill <input-file-name>\n");
        return -1;
    }

    command(input);

    return 0;
}