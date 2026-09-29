#include <stdio.h>
#include <stdlib.h>

int global_var = 150;       // Data segment
int global_bss;             // BSS segment

int main() {

    int local_var = 30;     // Stack

    int *heap_var = (int *)malloc(sizeof(int));   // Heap
    *heap_var = 500;

    printf("Memory Segment Addresses\n\n");

    printf("Text (main function): %p\n", (void *)main);
    printf("Global initialized (Data): %p\n", (void *)&global_var);
    printf("Global uninitialized (BSS): %p\n", (void *)&global_bss);
    printf("Local variable (Stack): %p\n", (void *)&local_var);
    printf("Heap variable (Heap): %p\n", (void *)heap_var);

    printf("\nAddress Difference (Stack - Heap): %ld bytes\n",
           (char *)&local_var - (char *)heap_var);

    free(heap_var);

    return 0;
}
