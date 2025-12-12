#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define CAPACITY 100

int smallestPrimeDivisor(int n) {
	for (int i = 2; i < sqrt(n)+1; i++) {
		if (n % i == 0) {
			return i;
		}
	}
	return n;
}

void isSphenic(int n) {
    if (n < 30) {
        printf("False");
    }
    else {
        int product = 1;
	    int p = 1;
    	int number = n;
	    for (int i = 0; i < 3; i++) {
            int spd = smallestPrimeDivisor(number);
		    if (spd > p) {
			    p = spd;
			    product *= p;
			    number /= p;
		    }
		    else {
			    printf("False");
                break;
		    }
	    }
	    if (n == product) {
            printf("True");
        }
    }
}

int main() {
	int n = 385;
	isSphenic(n);
}

/*
int smallestPrimeDivisor(int n):
    for i from 2 to sqrt(n):
        if n%i = 0:
            return i
    end for
    return n

#The complexity of smallestPrimeDivisor is c1.sqrt(n) + c2

void isSphenic(int n):
    if n < 30:
        print "False"
    else:
        int product <- 1
        int p <- 1
        int number <- n
        for i from 0 to 2:
            int spd = smallestPrimeDivisor(number)
            if spd > p:
                p <- spd
                product = product * p
                number = number / p
            else:
                print False
                end for
        end for
        if n = product:
            print True

#The complexity of isSphenic is c1.sqrt(n) + c2 ~ O(sqrt(n))
*/