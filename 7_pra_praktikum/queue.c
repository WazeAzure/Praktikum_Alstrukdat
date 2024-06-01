#include <stdio.h>
#include "queue.h"

void CreateQueue(Queue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q){
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}

boolean isFull(Queue q){
    return ((IDX_TAIL(q) + 100 - IDX_HEAD(q)) % 100) + 1 == CAPACITY; 
}
// 100
// 0 .. 99
//  tail head
//    0   1
//    10  11
// head tail
// 0     99
// -1   -1

int length(Queue q){
    if (isEmpty(q)) return 0;
    return ((IDX_TAIL(q) + 100 - IDX_HEAD(q)) % 100) + 1;
}
// 0 .. 99
//  tail head
//    0   5
//    10  11
// head tail
// 0     3
// -1   -1

void enqueue(Queue *q, ElType val){
    if(isEmpty(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        TAIL(*q) = val;
    } else {
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
        TAIL(*q) = val;
    }
}

void dequeue(Queue *q, ElType *val){
    *val = HEAD(*q);
    if(IDX_HEAD(*q) == IDX_TAIL(*q)){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
        IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
    }
}

void displayQueue(Queue q){
    int i = IDX_HEAD(q);
    printf("[");
    while(i != IDX_TAIL(q)){
        printf("%d,", q.buffer[i]);
        i = (i + 1) % CAPACITY;
    }
    if(!isEmpty(q)) printf("%d", q.buffer[i]);
    printf("]\n");
}