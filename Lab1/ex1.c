#include <stdio.h>
#include <math.h>

int swap(int a) {
    if (0 <= a && a <= 9) {
        return a;
    }
    else {
        int len = (int)log10(a);
        int n = pow(10, len);
        int first = a/n;
        int last = a%10;
        int mid = (a%n)/10;
        return last*n + mid*10 + first;
    }
}

int main() {
    printf("%d", swap(10897));
}

/*
int swap (int a):
    if 0 <= a <= 9:
        return a;
    else:
        int len <- floor(log10(a))
        int n <- 10^len
        int first <- a/n
        int last <- a%10
        int mid <- (a%n)/10
        return last*n + mid*10 + first
*/