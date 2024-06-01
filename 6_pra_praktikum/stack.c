#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void CreateEmpty(Stack *S){
    Top(*S) = Nil;
}

boolean IsEmpty(Stack S){
    return Top(S) == Nil;
}

boolean IsFull(Stack S){
    return Top(S) == MaxEl-1;
}

void Push(Stack *S, infotype x){
    if(IsEmpty(*S)){
        Top(*S) = 0;
    } else {
        Top(*S) += 1;
    }
    InfoTop(*S) = x;
}

void Pop(Stack *S, infotype* x){
    *x = InfoTop(*S);
    Top(*S) -= 1;
}