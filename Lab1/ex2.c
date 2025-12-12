#include <stdio.h>
#include <stdlib.h>

void findMax(int *max, int a) {
    if (a > *max) {
        *max = a;
    }
}

int main() {
    int *max = (int*)malloc(sizeof(int));
    *max = 0;
    findMax(max, 7);
    printf("%d", *max);
    free(max);
}