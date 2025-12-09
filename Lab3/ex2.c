#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define CAPACITY 100
#define MAX 100

typedef struct _Web {
    char url[MAX];
    char title[MAX];
} Web;

typedef struct _List {
    int size;
    Web listWeb[CAPACITY];
} List;

typedef struct _Stack {
    int top;
    Web * listWeb[CAPACITY];
} Stack;

void initWeb(Web *w, char *url, char *title) {
    strcpy(w->url, url);
    strcpy(w->title, title);
}

void initStack(Stack *s) {
    s->top = -1;
}

bool isFull(Stack *s) {
    return s->top >= CAPACITY - 1;
}

bool isEmpty(Stack *s) {
    return s->top <= - 1;
}

bool isAlmostEmpty(Stack *s) {
    return s->top <= 0;
}

int push(Stack *s, Web *w) {
    if (isFull(s)) {
        printf("Stack is full\n");
        return 0;
    }
    else {
        s->top++;
        s->listWeb[s->top] = w;
        return 1;
    }
}

Web* pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return NULL;
    }
    else {
        s->top--;
        return s->listWeb[s->top+1];
    }
}

void displayWeb(Web *w) {
    printf("Url: %s\n", w->url);
    printf("Title: %s\n=========\n", w->title);
}

void goBW(Stack *b, Stack *f) {
    if (isAlmostEmpty(b)) {
        printf("Can not go backward anymore!\n=========\n");
        return;
    }
    Web *w = pop(b);
    push(f, w);
    displayWeb(b->listWeb[b->top]);
}

void goFW(Stack *b, Stack *f) {
    if (isEmpty(f)) {
        printf("Can not go forward anymore!\n=========\n");
        return;
    }
    Web *w = pop(f);
    push(b, w);
    displayWeb(b->listWeb[b->top]);
}

int main() {
    Web *w1 = (Web*)malloc(sizeof(Web));
    Web *w2 = (Web*)malloc(sizeof(Web));
    Web *w3 = (Web*)malloc(sizeof(Web));
    Web *w4 = (Web*)malloc(sizeof(Web));
    Web *w5 = (Web*)malloc(sizeof(Web));
    initWeb(w1, "youtube.com", "Youtube");
    initWeb(w2, "facebook.com", "Facebook");
    initWeb(w3, "instagram.com", "Instagram");
    initWeb(w4, "tiktok.com", "Tiktok");
    initWeb(w5, "gmail.com", "Gmail");
    
    Stack *fw = (Stack*)malloc(sizeof(Stack));
    Stack *bw = (Stack*)malloc(sizeof(Stack));
    initStack(fw);
    initStack(bw);
    push(bw, w1);
    push(bw, w2);
    push(bw, w3);
    push(bw, w4);
    push(bw, w5);

    goBW(bw, fw);
    goBW(bw, fw);
    goBW(bw, fw);
    goBW(bw, fw);
    goBW(bw, fw);
    goFW(bw, fw);
    goFW(bw, fw);
    goFW(bw, fw);
    goFW(bw, fw);
    goFW(bw, fw);

    return 0;
}