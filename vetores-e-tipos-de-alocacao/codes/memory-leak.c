#include <stdio.h>
#include <stdlib.h>


int main() {
    char *v;

    for (int i = 0; i < 1000000000; i++) {
        v = (char *) calloc(10, sizeof(char));
        free(v);
    }

    return 0;
}
