#include <stdio.h>
#include <stdbool.h>

int smallestPrimeDivisor(int n) {
    for (int i = 2; i < n; i++) {
        if (n%i == 0) {
            return i;
        }
    }
    return n;
}

bool isSphenic(int n) {
    int p = 1;
    int product = 1;
    int number = n;
    for (int i = 0; i < 3; i++) {
        if (smallestPrimeDivisor(number) > p) {
            p = smallestPrimeDivisor(number);
            product *= p;
            number /= p;
        }
        else {
            return false;
        }
    }
    return product == n;
}

void printSphenic(int n) {
    if (n == 30) {
        printf("%d", n);
    }
    else {
        if (isSphenic(n)) {
            printf("%d ", n);
        }
        printSphenic(n-1);
    }
    return;
}

int main() {
    printSphenic(200);
}