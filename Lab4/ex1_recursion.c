#include <stdio.h>

int sumDigit(int n) {
    if (n >= 0 && n <= 9) {             //2
        return n;                       //1
    }
    else {                              //2
        return n%10 + sumDigit(n/10);   //2 + S(n-1)
    }
}

//Let n be the number of digit, S(n) is the complexity of the algorithm with an n digits number
//The complexity is S(n) = S(n-1) + 4 = 4(n-1) + S(1) ~ O(n)

int main() {
    int a = sumDigit(1234567);
    printf("%d", a);
}