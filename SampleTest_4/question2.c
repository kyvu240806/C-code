#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Node {
    int data;
    struct _Node* pnext;
} Node;

typedef struct _Stack {
    Node* pHead;
    int top;
} Stack;

Node* initNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = val;
    n->pnext = NULL;
    return n;
}

void init(Stack *s) {
    s->pHead = NULL;
    s->top = -1;
    return;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, Node *p) {
    if (isEmpty(s)) {
        s->top++;
        s->pHead = p;
        return;
    }
    p->pnext = s->pHead;
    s->pHead = p;
    s->top++;
    return;
}

void pop(Stack *s) {
    if (isEmpty(s)) {
        return;
    }
    s->pHead = s->pHead->pnext;
    return;
}

void display(Stack *s) {
    Node* q = (Node*)malloc(sizeof(Node));
    q = s->pHead;
    while (q != NULL) {
        printf("%d ", q->data);
        q = q->pnext;    
    }
    free(q);
    return;
}

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    else if (n == 2 || n == 3) {
        return true;
    }
    else {
        for (int i = 2; i < n; i++) {
            if (n%i == 0) {
                return false;
            }
        }
        return true;
    }
}

Stack* listPrime(int n) {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    init(s);
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            push(s, initNode(i));
        }
    }
    return s;
}

void listSphenic(int n) {
    Stack *prime = (Stack*)malloc(sizeof(Stack));
    prime = listPrime(n);
    Node *p1 = (Node*)malloc(sizeof(Node));
    Node *p2 = (Node*)malloc(sizeof(Node));
    Node *p3 = (Node*)malloc(sizeof(Node));
    p1 = prime->pHead;
    while (p1->pnext->pnext != NULL) {
        p2 = p1->pnext;
        while (p2->pnext != NULL) {
            p3 = p2->pnext;
            while (p3 != NULL) {
                if (p1->data*p2->data*p3->data <= n) {
                    printf("%d ", p1->data*p2->data*p3->data);
                }
                p3 = p3->pnext;
            }
            p2 = p2->pnext;
        }
        p1 = p1->pnext;
    }
    free(prime);
    free(p1);
    free(p2);
    free(p3);
    return;
}

int main() {
    listSphenic(165);
}