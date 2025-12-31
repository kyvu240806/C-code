#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Node {
    int data;
    struct _Node* pnext;
} Node;

typedef struct _List {
    Node* pHead;
    int size;
} List;

Node* initNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = val;
    n->pnext = NULL;
    return n;
}

void init(List *l) {
    l->pHead = NULL;
    l->size = 0;
    return;
}

bool isEmpty(List *l) {
    return l->size == 0;
}

void insertFirst(List *l, Node* p) {
    l->size++;
    l->pHead = p;
    return;
}

void insert(List *l, Node *p) {
    p->pnext = l->pHead;
    l->pHead = p;
    l->size++;
    return;
}

void display(List *l) {
    Node* q = (Node*)malloc(sizeof(Node));
    q = l->pHead;
    while (q != NULL) {
        printf("%d ", q->data);
        q = q->pnext;    
    }
    free(q);
    return;
}

int gcd(int a, int b) {
    if (a == b) {
        return a;
    }
    else {
        if (a > b) {
            return gcd(a-b, b);
        }
        else {
            return gcd(a, b-a);
        }
    }
}

bool coPrime(int a, int b) {
    return gcd(a, b) == 1;
}

void printCoPrime(List *l) {
    Node *p = (Node*)malloc(sizeof(Node));
    p = l->pHead;
    Node *q = (Node*)malloc(sizeof(Node));
    while (p->pnext != NULL) {
        q = p->pnext;
        while (q != NULL) {
            if (coPrime(p->data, q->data)) {
                printf("(%d, %d) ", p->data, q->data);
            }
            q = q->pnext;
        }
        p = p->pnext;
    }
    free(p);
    free(q);
}

int main() {
    List* l = (List*)malloc(sizeof(List));
    init(l);
    insertFirst(l, initNode(50));
    insert(l, initNode(49));
    insert(l, initNode(26));
    insert(l, initNode(5));
    insert(l, initNode(45));
    insert(l, initNode(90));
    insert(l, initNode(13));
    insert(l, initNode(27));
    insert(l, initNode(10));
    insert(l, initNode(2));
    printCoPrime(l);
}