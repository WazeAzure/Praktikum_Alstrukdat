#include <stdio.h>
#include "queue.h"
#include "queue.c"

int main(){
    Queue q;
    
    CreateQueue(&q);
    for(int i=0; i<100; i++){
        enqueue(&q, i);
    }
    printf("%d\n", isFull(q));
    return 0;
}