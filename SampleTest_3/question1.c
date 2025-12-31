#include <stdio.h>
#include <stdbool.h>

int gcd(int a, int b) {
    while (a != b) {
        if (a > b) {
            a = a-b;
        }
        else {
            b = b-a;
        }
    }
    return a;
}

bool coPrime(int a, int b) {
    return gcd(a, b) == 1;
}

int main() {
    int arr[10] = {2, 10, 27, 13, 90, 45, 5, 26, 49, 50};
    for (int i = 0; i < 9; i++) {
        for (int j = i+1; j < 10; j++) {
            if (coPrime(arr[i], arr[j])) {
                printf("(%d, %d) ", arr[i], arr[j]);
            }
        }
    }
}