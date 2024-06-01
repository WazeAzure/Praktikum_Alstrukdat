#include <stdio.h>
#include <stdlib.h>

#include "stacklinked.h"

Address newNode(ElType x){
    Address n = (Address)malloc(sizeof(Node));
    if(n == NIL) return NIL;
    
    INFO(n) = x;
    return n;
}

boolean isEmpty(Stack s){
    return ADDR_TOP(s) == NIL;
}

int length(Stack s){
    if(isEmpty(s)) return 0;

    Stack temp;
    CreateStack(&temp);

    ElType x;
    int count = 0;
    while(!isEmpty(s)){
        pop(&s, &x);
        push(&temp, x);
        count++;
    }

    int i;
    for(i=0; i<count; i++){
        pop(&temp, &x);
        push(&s, x);
    }
    return count;
}

void CreateStack(Stack *s){
    ADDR_TOP(*s) = NIL;
}

void DisplayStack(Stack s){
    Stack Temp;
    CreateStack(&Temp);

    ElType x;
    printf("[");
    
    if(ADDR_TOP(s) != NIL){
        while(NEXT(ADDR_TOP(s)) != NIL){
            pop(&s, &x);
            push(&Temp, x);
            printf("%d,", x);
        }

        printf("%d", TOP(s));

        while(!isEmpty(Temp)){
            pop(&Temp, &x);
            push(&s, x);
        }
    }

    
    printf("]");
}

void push(Stack *s, ElType x){
    Address n = newNode(x);

    if(n == NIL) return ;

    if(!isEmpty(*s)){
        NEXT(n) = ADDR_TOP(*s);
    }
    ADDR_TOP(*s) = n;
}

void pop(Stack *s, ElType *x){
    Address top = ADDR_TOP(*s);
    *x = TOP(*s);

    if(NEXT(ADDR_TOP(*s)) == NIL){
        ADDR_TOP(*s) = NIL;
    } else {
        ADDR_TOP(*s) = NEXT(top);
    }

    free(top);
}