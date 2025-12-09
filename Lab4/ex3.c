#include <stdio.h>

float pi(int n) {
    if (n == 0) {
        return 4.0/1 - 4.0/3;
    }
    else {
        return 4.0/(4*n+1) - 4.0/(4*n+3) + pi(n-1);
    }
}

//The complexity of the above function is S(n) = c + S(n-1) = c(n-1) + S(0) ~ O(n)

int main() {
    printf("%f", pi(10));
}