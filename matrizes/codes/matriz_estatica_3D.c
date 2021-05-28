#include <stdio.h>


int main() {
    int n_slices = 2;
    int n_rows = 2;
    int n_cols = 3;

    // 2 fatias, 2 linhas, 3 colunas
    int m[2][2][3] = {
        // fatia [0]
        {
            {0, 1, 2}, // linha [0]
            {3, 4, 5}  // linha [1]
        },

        // fatia [1]
        {
            {6, 7, 8}, // linha [0]
            {9, 10, 11}  // linha [1]
        }
    };


    printf("&m = %p, m = %p\n\n", &m, m);

    // para cada fatia
    for (int k = 0; k < n_slices; k++) {
        // para cada linha
        for (int i = 0; i < n_rows; i++) {
            // para cada coluna
            for (int j = 0; j < n_cols; j++) {
                printf("&m[%d][%d][%d] = %p, m[%d][%d][%d] = %d\n",
                       k, i, j, &m[k][i][j],
                       k, i, j, m[k][i][j]);
            }
        }
    }


    return 0;
}
