#include <stdio.h>
#include <stdlib.h>
#include "malloc.h"
static int outerArray[5];



void monoArray(){
    static int monoArray[5];
    *monoArray = malloc(10 * sizeof (monoArray));
    *monoArray = malloc(sizeof(int *) * 10);
    for (int i=0; i <= 10; ++i) {
        int newValue = rand() % 100;
        monoArray[i] = &newValue;
    }
    free(monoArray);

}

void pointerArray(){
    static int pointerArray[5];
    *pointerArray = malloc(10 * sizeof (pointerArray));
    *pointerArray = malloc(sizeof(int *) * 10);
    for (int i=0; i <= 10; ++i) {
        int newValue = rand() % 100;
        int *newPoint = &newValue;
        pointerArray[i] = &newPoint;
    }
    free(pointerArray);

}

struct node {
    int value;
    long next;
};
void linkedList() {
    struct node a;
    struct node b;
    struct node c;

    a.value = 5;
    a.next = &b;

    b.value = 6;
    b.next = &c;

    c.value = 7;

}

int main() {
    static int innerArray[5];
    int n = 0;
    int t = 0;
    for (int i = 0; i < 5; i++) {
        outerArray[i] = rand() % 100;
        n++;
        printf("item: %d\n", outerArray[i]);
        printf("n: %d\n", n);
    }

    for (int i = 0; i < 5; i++) {
        innerArray[i] = rand() % 100;
        t++;
        printf("item: %d\n", innerArray[i]);
        printf("n: %d\n", n);
    }

    monoArray();
    pointerArray();
    linkedList();
    return 0;
}
