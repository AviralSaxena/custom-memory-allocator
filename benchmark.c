#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ALLOCATIONS 10000
#define BLOCK_SIZE 1000

int main() {
    void *ptrs[NUM_ALLOCATIONS];
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    for (int i = 0; i < NUM_ALLOCATIONS; i++) {
        ptrs[i] = malloc(BLOCK_SIZE);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for allocating %d blocks of size %d bytes each: %f seconds\n", NUM_ALLOCATIONS, BLOCK_SIZE, cpu_time_used);

    free(ptrs[NUM_ALLOCATIONS - 1]);

    start = clock();
    void *small_ptr = malloc(BLOCK_SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for allocating a one more block after freeing %d blocks: %f seconds\n", BLOCK_SIZE-1, cpu_time_used);
    for (int i = 0; i < NUM_ALLOCATIONS - 1; i++) {
        free(ptrs[i]);
    }

    free(small_ptr);
    return 0;
}