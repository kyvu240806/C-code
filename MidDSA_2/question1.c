#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#define CAPACITY 100

typedef struct _List {
    int size;
    int data[CAPACITY];
} List;

void init(List *l, int n) {
    l->size = n-1;
    for (int i = 0; i < l->size; i++) {
        l->data[i] = i + 2;
    }
}

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    else if (n == 2 || n == 3) {
        return true;
    }
    else {
        for (int i = 2; i < sqrt(n) + 1; i++) {
            if (n%i == 0) {
                return false;
            }
        }
        return true;
    }
}

/*
The complexity of isPrime() is c1.sqrt(n) + c2
*/

void set(List *l) {
    for (int i = 0; i < l->size; i++) {
        if (!isPrime(l->data[i])) {
            l->data[i] = 0;
        }
        else {
            int p = 2;
            while (p*l->data[i] < l->size+1) {
                l->data[(i+2)*p-2] = 0;
                p++;
            }
        }
    }
}

/*
The complexity of the else block is c3.n/(i+2) + c4
The complexity of the if else condition is c1.sqrt(i) + c2
The total complexity is the sigma sum of c1.sqrt(i) + c2 + c3.n/(i+2) + c4 for i from 0 to n-2
Let f(n) = sigma sum of c1.sqrt(i) for i from 0 to n-2, f(n) is O(n.sqrt(n))
Let g(n) = sigma sum of c3.n/(i+2) for i from 0 to n-2, g(n) is O(n.log(n))
Let h(n) = sigma sum of c2 + c4 for i from 0 to n-2, h(n) is O(n)
So the total complexity if O(n.sqrt(n))
*/

void display(List *l) {
    for (int i = 0; i < l->size; i++) {
        if (l->data[i] != 0) {
            printf("%d ", l->data[i]);
        }   
    }
}

int main() {
    List *l = (List*)malloc(sizeof(List));
    init(l, 97);
    set(l);
    display(l);
    free(l);
}