#include <stdio.h>
#include <stdlib.h>

typedef struct _Result {
    int quotient;
    int remainder;
} Result;

void init(Result *r) {
    r->quotient = 0;    //1
    r->remainder = 0;   //1
}

void print(Result *r) {
    printf("Quotient: %d\nRemainder: %d", r->quotient, r->remainder);   //1
}

void divi(int a, int b, Result *r) {    //S(n) with n = a/b
    if (a < b) {            //1
        r->remainder = a;   //1
        print(r);           //1
    }
    else {                  //1
        r->quotient += 1;   //1
        divi(a-b, b, r);    //S(n-1)
    }
}

//S(n) = S(n-1) + 2 = 2n + 1 ~ O(n)

int main() {
    Result *r = (Result*)malloc(sizeof(Result)); //1
    init(r);    //1
    divi(19, 5, r); //2n + 1
}

//The time complexity of the algorithm is O(n)