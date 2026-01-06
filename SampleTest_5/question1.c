#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

typedef struct _List {
    int size;
    int data[MAX];
} List;

void init(List *l) {
    l->size = 0;
}

bool isEmpty(List *l) {
    return l->size == 0;
}

bool isFull(List *l) {
    return l->size >= MAX-1;
}

void insert(List *l, int index, int val) {
    if (isFull(l)) {
        printf("List is full");
    }
    else {
        if (index > l->size || index < 0) {
            printf("Invalid index");
        }
        else {
            for (int i = l->size; i > index; i--) {
                l->data[i] = l->data[i-1];
            }
            l->data[index] = val;
            l->size++;
        }
    }
}

void rm(List *l, int index) {
    if (isEmpty(l)) {
        printf("List is empty");
    }
    else {
        if (index >= l->size || index < 0) {
            printf("Invalid index");
        }
        else {
            for (int i = index; i < l->size - 1; i++) {
                l->data[i] = l->data[i+1];
            }
            l->size--;
        }
    }
}

void swap(List *l, int index1, int index2) {
    int temp = l->data[index1];
    l->data[index1] = l->data[index2];
    l->data[index2] = temp;
}

void display(List *l) {
    for (int i = l->size-1; i >= 0; i--) {
        printf("%d", l->data[i]);
    }
}

List* intToList(int n) {
    List *l = (List*)malloc(sizeof(List));
    init(l);
    while (n > 0) {
        insert(l, l->size, n%10);
        n /= 10;
    }
    return l;
}

//Iteration
int findMinIndexIter(List *l) {
    int minIndex = 0;
    for (int i = 0; i < l->size; i++) {
        if (l->data[i] < l->data[minIndex] && l->data[i] > 0) {
            minIndex = i;
        }
    }
    return minIndex;
}

//Recursion
int findMinIndexRecur(List *l, int start, int minIndex) {
    if (start == l->size-1) {
        return minIndex;
    }
    else {
        if ((l->data[start] < l->data[minIndex] && l->data[start] > 0) || l->data[minIndex] == 0) {
            minIndex = start;
        }
        return findMinIndexRecur(l, start+1, minIndex);
    }
}

List* minFirst(List *l) {
    int minIndex = findMinIndexRecur(l, 0, 0);
    swap(l, minIndex, l->size-1);
    return l;
}

int main() {
    int n = 2411031;
    List *l = intToList(n);
    display(minFirst(l));
}