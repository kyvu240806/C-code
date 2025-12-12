#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int fn_1;
    int fn_2;
} FibPair;

void init(FibPair *f) {
    f->fn_1 = 0;
    f->fn_2 = 1;
}

int calculate(FibPair *f, int n) {
    if (n == 0) {
        return n;
    }
    else if (n == 1) {
        return f->fn_1 + f->fn_2;
    }
    else {
        int temp = f->fn_1;
        f->fn_1 += f->fn_2;
        f->fn_2 = temp;
        return calculate(f, n-1);
    }
}

void display(FibPair *f, int n) {
    int fib;
    for (int i = 0; i <= n; i++) {
        init(f);
        fib = calculate(f, i);
        printf("%d ",fib);
    }
}

int main() {
    FibPair *f = (FibPair*)malloc(sizeof(FibPair));
    init(f);
    display(f,8);
    free(f);
}

/*
I will analyze the complexity line by line

Let S(n) be the complextity of the algorithm with n is the position of the Fibonacci number

int calculate(FibPair *f, int n) {      : S(n)
    if (n == 0) {                       : c1 (which is a constant)
        return n;                       : c2
    }
    else if (n == 1) {                  
        return f->fn_1 + f->fn_2;       : c3
    }
    else {
        int temp = f->fn_1;             : c4
        f->fn_1 += f->fn_2;             : c5
        f->fn_2 = temp;                 : c6
        return calculate(f, n-1);       : S(n-1)
    }
}

So the total complexity is S(n) = c1 + c4 + c5 + c6 + S(n-1) = S(n-1) + c
The general formular of S(n) is: S(n) = c(n-1) + S(1) ~ O(n)
*/