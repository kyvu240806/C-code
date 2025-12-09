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

bool isSphenic(int n) {
	int product = 1;
	int p = 1;
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
	return n == product;
}

void listSphenic(int n) {
	if (n < 30) {
		printf("No sphenic number from 1 to %d\n", n);
	}
	else if (n == 30) {
		printf("%d\n", n);
	}
	else {
		if (isSphenic(n)) {
			printf("%d ", n);
		}
		listSphenic(n-1);
	}
}

int main() {
	printf("Input a number: ");
	int n;
	scanf("%d", &n);
	listSphenic(n);
}
