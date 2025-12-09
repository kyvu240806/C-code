#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define CAPACITY 100
typedef struct List{
    int size;
    int data[CAPACITY];
} List;

void init(List *l) {
    l->size =0;
}
bool isEmpty(List *l) {
    return l->size == 0;
}
void insert(List *l, int index, int value) {
    if(l->size == CAPACITY) {
        printf("Cannot add more");
        return;
    } 
    if(index<0 || index > l->size) {
        printf("Cannot do");
        return;
    } else {
        for(int i=l->size-1; i>=index; i--) {
            l->data[i+1]=l->data[i];
        }
        l->data[index]=value;
        l->size++;
    }
}

void removeIndex(List *l,int index) {
     if(index<0 || index >= l->size) {
        printf("Cannot do");
        return;
    } else {
    for(int i=index; i<l->size-1;i++) {
        l->data[i] = l->data[i+1];
    }
    
    l->size--;
}

}
void display(List *l) {
    if(l->data[0]==-1) {
        printf("-");
    } else if(l->data[0]==1) {
        
    } else {
        printf("Error");
        return;
    }
    for(int i=1; i<l->size;i++) {

        printf("%d",l->data[i]);    

    }
    printf("\n");
}
void sumDigits(List *l) {
    int sum=0;
    for(int i=1;i<l->size;i++) {
        sum +=l->data[i];
    }
    printf("Sum of all digits: %d",sum);
}
int main() {
    List *l= (List*)malloc(sizeof(List));
    init(l);
    l->data[0]=-1;
    l->data[1]=2;
    l->data[2]=4;
    l->data[3]=0;
    l->data[4]=8;
    l->size =5;
    display(l);
    insert(l,2,5);
    display(l);
    removeIndex(l,1);
    display(l);
    sumDigits(l);
}