#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define CAPACITY 100

typedef struct _Stack {
    int top;
    int data[CAPACITY];
} Stack;

void init(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return s->top < 0;
}

bool isFull(Stack *s) {
    return s->top >= CAPACITY - 1;
}

void push(Stack *s, int val) {
    if (isFull(s)) {
        printf("Stack is full!\n");
    }
    else {
        s->top++;
        s->data[s->top] = val;
    }
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    else {
        int val = s->data[s->top];
        s->top--;
        return val;
    }
}

void display(Stack *s) {
    for (int i = s->top; i >= 0; i--) {
        printf("%d", s->data[i]);
    }
}

void convert(int n) {
    Stack *r = (Stack*)malloc(sizeof(Stack));
    init(r);

    while (n > 0) {
        push(r, n%2);
        n = n/2;
    }

    display(r);
    free(r);
}

int main() {
    convert(37);
}

/*
I will analyze the complexity line by line

void convert(int n) {
    Stack *r = (Stack*)malloc(sizeof(Stack));   : c1 (which is a constant)
    init(r);                                    : c2

    while (n > 0) {                             : log(n), because n can devide by 2 maximum log(n) time before it become 0
        push(r, n%2);                           : c3
        n = n/2;                                : c4
    }

    display(r);                                 : c5
    free(r);                                    : c6
}

So the total complexity is (c3+c4)log(n) + (c1+c2+c5+c6) = a.log(n) + b ~ O(log(n))
*/