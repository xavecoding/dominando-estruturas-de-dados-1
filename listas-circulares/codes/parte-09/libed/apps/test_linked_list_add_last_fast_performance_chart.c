#include "linked_list.h"
#include "mytime.h"


int main(int argc, const char *argv[]) {
    if (argc != 2) {
        printf("%s <n_elementos_da_lista>\n", argv[0]);
        exit(-1);
    }

    int n_elements = atoi(argv[1]);

    LinkedList *L = LinkedList_create();

    printf("n,time\n");

    for (int n = 0; n < n_elements; n++) {
        timer t1 = tic();
        LinkedList_add_last(L, n);
        timer t2 = tac();

        printf("%d,%f\n", n, comptime(t1, t2));
    }

    return 0;
}
