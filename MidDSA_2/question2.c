#include <stdio.h>
#include <math.h>

void palindromic(int n) {
    if (0 <= n && n <= 9) {
        printf("True");
    }
    else if (10 <= n && n <= 99) {
        if (n%10 == n/10) {
            printf("True");
        }
        else {
            printf("False");
        }
    }
    else {
        int len = (int)log10(n);
        int k = pow(10, len);
        int first = n/k;
        int last = n%10;
        int mid = (n%k)/10;
        if (first != last) {
            printf("False");
        }
        else {
            palindromic(mid);
        }
    }
}

/*
Let S(k) be the complexity of the algorithm with k is the length of the number (or k ~ log10(n))
The complexity of the condition is c1
The complexity of the else block is c2 + S(k-2)
Let c1 + c2 = c
So we have the recursive relationship: S(k) = c + S(k-2) = c.k/2 ~ O(k) ~ O(log(n))
*/

int main() {
    palindromic(1314131);
}

/*
This is a better method

void palindromic(int n) {
    int ori = n;
    int rev = 0;

    while (ori > rev) {
        rev = rev*10 + ori%10;
        ori = ori/10;
    }

    if (rev == ori || rev/10 == ori) {
        printf("True");
    }
    else {
        printf("False");
    }
}
*/