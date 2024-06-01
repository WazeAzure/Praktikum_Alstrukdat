#include <stdio.h>
#include <stdlib.h>

#include "queuelinked.h"
#include "queuelinked.c"

int main(){
    Queue q;
    CreateQueue(&q);

    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    enqueue(&q, 2);
    enqueue(&q, 5);
    enqueue(&q, 3);
    if(isEmpty(q)){
        printf("Queue is empty\n");
    } else {
        printf("queue is not empty\n");
    }
    DisplayQueue(q);
    printf("\n");
    return 0;
}