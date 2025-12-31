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

/*
All case ~ O(n)
*/

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

/*
All case ~ O(n)
*/

void printArray(int arr[CAPACITY], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

/*
All case ~ O(n)
*/

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

/*
All case ~ O(n^2)
*/

int main() {
    int arr[CAPACITY] = {3, 5, 1, 4, 2};
    sort(arr, 4);
    printArray(arr, 5);
}
