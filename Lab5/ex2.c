#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define CAPACITY 100

int findMaxPosition(int arr[CAPACITY], int n) {
    int max = arr[0];
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

void flip(int arr[CAPACITY], int start, int end) {
    if (start == end) {
        return;
    }
    else if (start + 1 == end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
    }
    else {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
        flip(arr, start, end);
    }
}

void printArray(int arr[CAPACITY], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

void sort(int arr[CAPACITY], int end) {
    if (end == 0) {
        return;
    }
    else {
        int maxIndex = findMaxPosition(arr, end+1);
        flip(arr, 0, maxIndex);
        flip(arr, 0, end);
        end--;
        sort(arr, end);
    }
}

int intToArray(int arr[CAPACITY], int n) {
    int pos = 0;
    while (n > 0) {
        arr[pos] = n%10;
        n /= 10;
        pos++;
    }
    return pos;
}

int main() {
    int n = 2041;
    int arr[CAPACITY];
    int len = intToArray(arr, n);
    sort(arr, len-1);
    flip(arr, 0, len-1);
    printArray(arr, len);
}