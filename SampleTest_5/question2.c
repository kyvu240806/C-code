#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define MAX 100

typedef struct _Vector {
    float x, y, z;
} Vector;

typedef struct _List {
    int size;
    Vector* data[MAX];
} List;

typedef struct _Row {
    int size;
    float data[MAX];
} Row;

typedef struct _Matrix {
    int size;
    Row* data[MAX];
} Matrix;

void initVec(Vector *v, float x, float y, float z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

void initRow(Row *r) {
    r->size = 0;
}

void initMat(Matrix *m) {
    m->size = 0;
}

void initList(List *l) {
    l->size = 0;
}

bool isFull(List *l) {
    return l->size >= MAX-1;
}

void insert(List *l, int index, Vector *vec) {
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
            l->data[index] = vec;
            l->size++;
        }
    }
}

void addNumToRow(Row *r, float val) {
    r->data[r->size] = val;
    r->size++;
}

void addRowToMat(Matrix *m, Row *r) {
    m->data[m->size] = r;
    m->size++;
}

void displayRow(Row *r) {
    for (int i = 0; i < r->size; i++) {
        printf("%f ", r->data[i]);
    }
}

void displayMat(Matrix *m) {
    for (int i = 0; i < m->size; i++) {
        displayRow(m->data[i]);
        printf("\n");
    }
}

float distance(Vector *v1, Vector *v2) {
    float dx = v1->x - v2->x;
    float dy = v1->y - v2->y;
    float dz = v1->z - v2->z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

Matrix* distanceMatrix(List *l) {
    Matrix *m = (Matrix*)malloc(sizeof(Matrix));
    initMat(m);
    for (int i = 0; i < l->size; i++) {
        Row *r = (Row*)malloc(sizeof(Row));
        initRow(r);
        for (int j = 0; j < l->size; j++) {
            addNumToRow(r, distance(l->data[i], l->data[j]));
        }
        addRowToMat(m, r);
    }
    return m;
}

int main() {
    Vector* v1 = (Vector*)malloc(sizeof(Vector));
    Vector* v2 = (Vector*)malloc(sizeof(Vector));
    Vector* v3 = (Vector*)malloc(sizeof(Vector));
    List *l = (List*)malloc(sizeof(List));
    initVec(v1, 0, 0, 1);
    initVec(v2, 0, 1, 0);
    initVec(v3, 1, 0, 0);
    initList(l);
    insert(l, 0, v1);
    insert(l, 0, v2);
    insert(l, 0, v3);
    Matrix *m = distanceMatrix(l);
    displayMat(m);
}