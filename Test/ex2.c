#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Element {
    int data;
    int priority;
} Element;

typedef struct _Queue {
    int size;
    Element data[100];
} Queue;

void initElement(Element *e, int data, int priority) {
    e->data = data;
    e->priority = priority;
}

void initQueue(Queue *q) {
    q->size = 0;
}

bool larger(Element e1, Element e2) {
    return e1.priority > e2.priority;
}

void enqueueFirst(Queue *q, Element e) {
    q->data[0] = e;
    q->size++;
}

bool isEmpty(Queue *q) {
    return q->size == 0;
}

void enqueue(Queue *q, Element e) {
    if (isEmpty(q)) {
        q->data[0] = e;
        q->size++;
    }
    else {
        q->data[q->size] = e;
        int pos = q->size;
        q->size++;
        Element temp;
        while (larger(e, q->data[pos - 1]) && pos >= 1) {
            temp = q->data[pos - 1];
            q->data[pos - 1] = e;
            q->data[pos] = temp;
            pos--;
        }
    }
}

void printElement(Element e) {
    printf("Data: %d\nPriority: %d\n=====\n", e.data, e.priority);
}

void printQueue(Queue *q) {
    for (int i = 0; i < q->size; i++) {
        printElement(q->data[i]);
    }
}
int main() {
    Element e1;
    initElement(&e1, 7, 5);
    Element e2;
    initElement(&e2, 3, 3);
    Element e3;
    initElement(&e3, 2, 4);
    Element e4;
    initElement(&e4, 9, 1);
    Element e5;
    initElement(&e5, 6, 6);
    Element e6;
    initElement(&e6, 1, 2);

    Queue *q = (Queue*)malloc(sizeof(Queue));
    initQueue(q);

    enqueue(q, e1);
    enqueue(q, e2);
    enqueue(q, e3);
    enqueue(q, e4);
    enqueue(q, e5);
    enqueue(q, e6);

    printQueue(q);
}