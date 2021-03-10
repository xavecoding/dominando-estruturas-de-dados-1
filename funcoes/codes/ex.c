#include <stdio.h>

void func(int *px, int *py) {
    px = py;
    *py = (*py) * (*px);
    *px = *px + 2;
}


int main() {
    int x = 10;
    int y = 20;
    
    func(&x, &y);
    printf("x = %d, y = %d\n", x, y);

    return 0;
}
