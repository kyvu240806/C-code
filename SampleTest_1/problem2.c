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

int convI(int n) {
    List *l = (List *)malloc(sizeof(List));
    initList(l);
    int digit;
    while (n != 0) {
        digit = n%2;
        add(l, digit);
        n /= 2;
    }
    for (int i = l->size-1; i >= 0; i--) {
        printf("%d",l->data[i]);
    }
    free(l);
}

void convF(float n, int k) {
    List *l = (List *)malloc(sizeof(List));
    initList(l);
    int digit;
    for (int i = 0; i < k; i ++) {
        digit = floor(2*n);
        n = 2*n - floor(2*n);
        add(l, digit);
    }
    for (int i = 0; i < l->size; i++) {
        printf("%d",l->data[i]);
    }
    free(l);
}

void conv(float n) {
    int i = (int)n;
    float f = n - i;
    convI(i);
    printf(".");
    convF(f,10);
}

int main() {
    conv(4.6);
}