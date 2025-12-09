#include <stdio.h>

int main() {
    int n = 1234567;       //1
    int a = 0;             //1
    while (n != 0) {       //n
        a += n%10;         //1
        n = n/10;          //1
    }
    printf("%d", a);       //1
}

//int n <- value
//int a <- 0
//while n is not 0, do:
//	add n%10 to a
//	divide n by 10
//print a

//Let n be the number of digit
//The complexity is 2n + 3 ~ O(n)