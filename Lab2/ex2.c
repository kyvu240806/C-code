#include <stdio.h>
#include <stdlib.h>

typedef struct Car{
    int capacity;
    int numPas;
    char id[3];
    struct Car *pnext;
} Car;
typedef struct Train{
    int size;
    Car *pHead;
} Train;

void initTrain(Train *t) {
    t->size=0;
    t->pHead = NULL;
}
void initCar(Car *c,int capacity, int numPas, char id[3]) {
    c->capacity=capacity;
    c->numPas=numPas;
    for(int i=0;i<3;i++) {
        c->id[i] = id[i];
    }
    c->pnext = NULL;
    
}
void addFirst(Train *t, Car *c) {
    t->size++;
    t->pHead=c;
}
void addCar(Train *t, Car *c, Car *new) {
   new->pnext = c->pnext;
   c->pnext = new;
   t->size++;
}

void displayCar(Car *c) {
    printf("Capacity: %d\n",c->capacity);
    printf("Number of passengers:%d\n",c->numPas );
    printf("ID:");
    for(int i=0;i<3;i++) {
        printf("%c",c->id[i]);
    }
}
void displayTrain(Train *t) {
    Car *c = t->pHead;
    while(c!=NULL) {
        displayCar(c);
        c=c->pnext;
        printf("\n");
    }
    printf("========\n");
}

void removeEmpty(Train *t) {
    if (t->pHead->numPas ==0) {
        Car *temp = t->pHead;
        t->pHead = temp->pnext;
        free(temp);
        t->size--;
    }
    Car *c = t->pHead;
    while(c->pnext!=NULL) {
        if(c->pnext->numPas==0) {
            Car *temp= c->pnext;
            c->pnext=temp->pnext;
            t->size--;
            free(temp);
        } else {
            c= c->pnext;
        }
    }
}
int main() {
    Car *c1 = (Car*)malloc(sizeof(Car));
    Car *c2 = (Car*)malloc(sizeof(Car));
    Car *c3 = (Car*)malloc(sizeof(Car));
    initCar(c1,4,2,"VN1");
    initCar(c2,3,2,"VN2");
    initCar(c3,4,0,"VN3");
    Train *t = (Train*)malloc(sizeof(Train));
    initTrain(t);
    addFirst(t,c1);
    addCar(t,c1,c2);
    addCar(t,c2,c3);
    displayTrain(t);
    removeEmpty(t);
    displayTrain(t);
}
