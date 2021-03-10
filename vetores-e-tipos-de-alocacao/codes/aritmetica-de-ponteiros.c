#include <stdio.h>

int main() {
    int v[5] = {10, 5, 4, 16, 1};

    printf("&v = %p, v = %p\n\n", &v, v);

    for (int i = 0; i < 5; i++) {
        printf("&v[%d] = %p, v[%d] = %d\n", i, &v[i], i, v[i]);
        printf("(v + %d) = %p, *(v + %d) = %d\n\n", i, (v + i), i, *(v + i));
    }

    return 0;
}


