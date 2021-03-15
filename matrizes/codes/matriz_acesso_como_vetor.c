#include <stdio.h>
#include <stdlib.h>


int main() {
    int nrows = 100000;
    int ncols = 20000;
    int nelems = nrows * ncols;

    int *m = (int *) calloc(nelems, sizeof(int));


    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            int p = (i *  ncols) + j;
            m[p] = (i + j) % 2;
        }
    }

 
    return 0;
}

