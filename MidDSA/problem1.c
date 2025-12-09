#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#define CAPACITY 100

typedef struct _List {
    int size;
    int data[CAPACITY];
} List;

void initList(List *l) {
    l->size = 0;
}

bool isFull(List *l) {
    return l->size >= CAPACITY;
}

void add(List *l, int val) {
    if (isFull(l)) {
        printf("List is full");
    }
    else {
        l->data[l->size] = val;
        l->size++;
    }
}

int conv(int n) {
    List *l = (List *)malloc(sizeof(List));
    initList(l);
    int digit;
    int binary = 0;
    while (n != 0) {
        digit = n%2;
        add(l, digit);
        n /= 2;
    }
    for (int i = l->size-1; i >= 0; i--) {
        binary += l->data[i]*pow(10, i);
    }
    free(l);
    return binary;
}

int main() {
    printf("%d", conv(16));
}