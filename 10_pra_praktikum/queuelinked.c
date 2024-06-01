#include <stdio.h>
#include <stdlib.h>

#include "queuelinked.h"

Address newNode(ElType x){
    Address p = (Address)malloc(sizeof(Node));
    if(p == NIL){
        return NIL;
    } else {
        INFO(p) = x;
        NEXT(p) = NIL;
        return p;
    }
}

boolean isEmpty(Queue q){
    return (ADDR_HEAD(q) == NIL) && (ADDR_TAIL(q) == NIL);
}

int length(Queue q){
    int count = 0;
    Address start = ADDR_HEAD(q);
    while(start != NIL){
        start = NEXT(start);
        count++;
    }
    return count;
}

void CreateQueue(Queue *q){
    ADDR_HEAD(*q) = NIL;
    ADDR_TAIL(*q) = NIL;
}

void DisplayQueue(Queue q){
    Address p = ADDR_HEAD(q);


    printf("[");

    if(!isEmpty(q)){
        while(p != ADDR_TAIL(q)){
            printf("%d,", INFO(p));
            p = NEXT(p);
        }
        printf("%d", INFO((p)));
    }
    printf("]");
}

void enqueue(Queue *q, ElType x){
    Address new = newNode(x);

    if(isEmpty(*q)){
        ADDR_HEAD(*q) = new;
        ADDR_TAIL(*q) = new;
    } else {
        Address last = ADDR_TAIL(*q);
        NEXT(last) = new;
        ADDR_TAIL(*q) = new;
    }
}

void dequeue(Queue *q, ElType *x){
    Address first = ADDR_HEAD(*q);
    *x = INFO(first);

    if(NEXT(first) == NIL){
        ADDR_HEAD(*q) = NIL;
        ADDR_TAIL(*q) = NIL;
    } else {
        ADDR_HEAD(*q) = NEXT(first);
    }

    free(first);
}