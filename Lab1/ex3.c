#include <stdio.h>
#include <stdlib.h>

typedef struct _Comp {
    float r;
    float i;
} Comp;

void init(Comp *c, float r, float i) {
    c->r = r;
    c->i = i;
}

void display(Comp *c) {
    if (c->r != 0 && c->i != 0) {
        if (c->i > 0) {
            printf("%f + %fi\n", c->r, c->i);
        }
        else {
            printf("%f - %fi\n", c->r, -c->i);
        }
    }
    else if (c->r == 0 && c->i != 0) {
        printf("%fi\n", c->i);
    }
    else if (c->r != 0 && c->i == 0) {
        printf("%f\n", c->r);
    }
    else {
        printf("0\n");
    }
}

Comp add(Comp c1, Comp c2) {
    Comp c3;
    c3.r = c1.r + c2.r;
    c3.i = c1.i + c2.i;
    return c3;
}

Comp mul(Comp c1, Comp c2) {
    Comp c3;
    c3.r = c1.r*c2.r - c1.i*c2.i;
    c3.i = c1.r*c2.i + c1.i*c2.r;
    return c3;
}

int main() {
    Comp a, b;
    init(&a, 2, -1);
    init(&b, 3, -2);
    Comp sum = add(a, b);
    Comp product = mul(a, b);
    display(&sum);
    display(&product);
}