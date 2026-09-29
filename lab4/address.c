#include <stdio.h>
#include <stdlib.h>

int global_var = 150;        // Data segment
int bss_var;                 // BSS segment

int main() {
    int local_var = 30;                 // Stack
    static int local_static = 20;       // Data segment

    int *heap_var = (int *)malloc(sizeof(int));  // Heap
    *heap_var = 500;

    printf(".......Variable Addresses.......\n\n");
    printf("main():        %p (Text/Code)\n", (void *)main);
    printf("global_var:    %p (Data)\n", (void *)&global_var);
    printf("local_static:  %p (Data)\n", (void *)&local_static);
    printf("bss_var:       %p (BSS)\n", (void *)&bss_var);
    printf("*heap_var:     %p (Heap - data)\n", (void *)heap_var);
    printf("heap_var ptr:  %p (Stack - pointer)\n", (void *)&heap_var);
    printf("local_var:     %p (Stack)\n", (void *)&local_var);

    free(heap_var);
    return 0;
}
