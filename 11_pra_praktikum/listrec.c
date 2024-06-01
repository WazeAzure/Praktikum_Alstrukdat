#include <stdio.h>
#include <stdlib.h>

#include "listrec.h"

Address newNode(ElType x){
    Address p = (Address)malloc(sizeof(ElType));
    if(p == NULL) return NULL;

    INFO(p) = x;
    NEXT(p) = NULL;
    return p;
}

boolean isEmpty(List l){
    return l == NULL;
}

boolean isOneElmt(List l){
    return !isEmpty(l) && NEXT(l) == NULL;
}

ElType head(List l){
    return INFO(l);
}

List tail(List l){
    return NEXT(l);
}

List konso(List l, ElType e){
    Address new_el = newNode(e);
    if(new_el == NULL){
        return l;
    } else {
        NEXT(new_el) = l;
        return new_el;
    }
}

List konsb(List l, ElType e){
    if(isEmpty(l)){
        return newNode(e);
    } else {
        NEXT(l) = konsb(tail(l), e);
        return l;
    }   
}

List copy(List l){
    if(isEmpty(l)){
        return NULL;
    } else {
        return konso(copy(tail(l)), head(l));
    }
}

List concat(List l1, List l2){
    if(isEmpty(l1)){
        return copy(l2);
    } else {
        return konso(concat(tail(l1), l2), head(l1));
    }
}

int length(List l){
    if(isEmpty(l)){
        return 0;
    } else {
        return 1 + length(tail(l));
    }
}

boolean isMember(List l, ElType x){
    if(isEmpty(l)){
        return false;
    } else if(INFO(l) == x){
        return true;
    } else {
        return isMember(tail(l), x);
    }
}

void displayList(List l){
    if(!isEmpty(l)){
        printf("%d\n", INFO(l));
        displayList(tail(l));
    }
}