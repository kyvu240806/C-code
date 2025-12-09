#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define CAPACITY 100
#define MAXNAME 10

typedef struct _Item {
    char name[MAXNAME];
    int quantity;
    float price;
} Item;

typedef struct _Customer {
    char name[MAXNAME];
    char nameProduct[MAXNAME];
    int numProduct;
} Customer;

typedef struct _Queue {
    int front, back;
    Customer* listCustomers[CAPACITY];
} Queue;

typedef struct _List {
    int size;
    Item* listItems[CAPACITY];
} List;

void initItem(Item *item, char name[MAXNAME], int quantity, float price) {
    for (int i = 0; i < 10; i++) {
        item->name[i] = name[i];
    }
    item->quantity = quantity;
    item->price = price;
}

void initCustomer(Customer *customer, char name[MAXNAME], char nameProduct[MAXNAME], int numProduct) {
    for (int i = 0; i < 10; i++) {
        customer->name[i] = name[i];
        customer->nameProduct[i] = nameProduct[i];
    }
    customer->numProduct = numProduct;
}

void initQueue(Queue *queue) {
    queue->front = 0;
    queue->back = -1;
}

void initList(List *list) {
    list->size = 0;
}

bool queueIsEmpty(Queue *queue) {
    return queue->back == -1;
}

bool queueIsFull(Queue *queue) {
    return (queue->back - queue->front == CAPACITY - 1);
}

int enqueue(Queue *queue, Customer *customer) {
    if (queueIsFull(queue)) {
        return 0;
    }
    else {
        queue->listCustomers[queue->back+1] = customer;
        queue->back++;
        return 1;
    }
}

Customer* dequeue(Queue *queue) {
    if (queueIsEmpty(queue)) {
        return NULL;
    }
    else {
        Customer *c = queue->listCustomers[queue->front];
        for (int i = 1; i <= queue->back; i++) {
            queue->listCustomers[i-1] = queue->listCustomers[i];
        }
        queue->back--;
        return c;
    }
}

bool listIsEmpty(List *list) {
    return list->size == 0;
}

bool listIsFull(List *list) {
    return list->size == CAPACITY;
}

int addToList(List *list, Item *item) {
    if (listIsFull(list)) {
        return 0;
    }
    else {
        list->listItems[list->size] = item;
        list->size++;
        return 1;
    }
}

bool toBuy(Customer *customer, Item *item) {
    for (int i = 0; i < 10; i++) {
        if (customer->nameProduct[i] != item->name[i]) {
            return false;
        }
    }
    return true;
}

void printPurchase(Customer *customer, Item *item) {
    printf("%s bought %d %s\n", customer->name, customer->numProduct, item->name);
}

void printNotPurchase(Customer *customer, Item *item) {
    printf("Not enough %s for %s to buy\n", item->name, customer->name);
}

int purchase(Customer *customer, List *list) {
    for (int i = 0; i < list->size; i++) {
        if (toBuy(customer, list->listItems[i])) {
            if (customer->numProduct <= list->listItems[i]->quantity) {
                list->listItems[i]->quantity -= customer->numProduct;
                printPurchase(customer, list->listItems[i]);
                return 1;
            }
            else {
                printNotPurchase(customer, list->listItems[i]);
                return 0;
            }
        }
    }
    return 0;
}

int main() {
    Item *i1 = (Item*)malloc(sizeof(Item));
    Item *i2 = (Item*)malloc(sizeof(Item));
    Item *i3 = (Item*)malloc(sizeof(Item));
    initItem(i1, "banhmisua", 10, 4);
    initItem(i2, "suaongtho", 5, 30);
    initItem(i3, "duongphen", 7, 25);
    List *items = (List*)malloc(sizeof(List));
    initList(items);
    addToList(items, i1);
    addToList(items, i2);
    addToList(items, i3);

    Customer *c1 = (Customer*)malloc(sizeof(Customer));
    Customer *c2 = (Customer*)malloc(sizeof(Customer));
    Customer *c3 = (Customer*)malloc(sizeof(Customer));
    Customer *c4 = (Customer*)malloc(sizeof(Customer));
    initCustomer(c1, "customer1", "banhmisua", 5);
    initCustomer(c2, "customer2", "suaongtho", 4);
    initCustomer(c3, "customer3", "duongphen", 3);
    initCustomer(c4, "customer4", "banhmisua", 6);
    Queue *customers = (Queue*)malloc(sizeof(Queue));
    initQueue(customers);
    enqueue(customers, c1);
    enqueue(customers, c2);
    enqueue(customers, c3);
    enqueue(customers, c4);

    while (queueIsEmpty(customers) != true) {
        Customer *cus = dequeue(customers);
        purchase(cus, items);
    }
}