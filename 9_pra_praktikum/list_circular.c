#include <stdio.h>
#include <stdlib.h>
#include "list_circular.h"

boolean isEmpty(List l){
    return FIRST(l) == NULL;
}

void CreateList(List *l){
    FIRST(*l) = NULL;
}

Address allocate(ElType val){
    Address new = (Address)malloc(sizeof(ElmtList));

    if(new == NULL) return NULL;

    INFO(new) = val;
    NEXT(new) = NULL;

    return new;
}

void deallocate(Address P){
    free(P);
}

Address search(List l, ElType val){
    if(isEmpty(l)) return NULL;

    Address p = FIRST(l);
    while(NEXT(p) != FIRST(l) && INFO(p) != val){
        // printf("%d\n", INFO(p));
        p = NEXT(p);
    }

    if(INFO(p) == val) return p;

    return NULL;
}

boolean addrSearch(List l, Address p){
    if(isEmpty(l)) return false;

    Address pt = FIRST(l);
    while(NEXT(pt) != FIRST(l) && pt != p){
        pt = NEXT(pt);
    }
    return pt == p;
}

void insertFirst(List *l, ElType val){
    Address new = allocate(val);
    if(new != NULL){
        Address p = FIRST(*l);
        if(isEmpty(*l)){
            FIRST(*l) = new;
            NEXT(new) = FIRST(*l);
        } else {
            NEXT(new) = FIRST(*l);
            while(NEXT(p) != FIRST(*l)){
                p = NEXT(p);
            }
            NEXT(p) = new;
            FIRST(*l) = new;
        }
    }
}

void insertLast(List *l, ElType val){
    Address new = allocate(val);

    if(new != NULL){
        Address p = FIRST(*l);

        if(isEmpty(*l)){
            FIRST(*l) = new;
            NEXT(new) = FIRST(*l);
        } else {
            while(NEXT(p) != FIRST(*l)){
                p = NEXT(p);
            }
            NEXT(p) = new;
            NEXT(new) = FIRST(*l);
        }
    }
}

void deleteFirst(List *l, ElType *val){
    Address p = FIRST(*l);
    *val = INFO(p);

    if(NEXT(FIRST(*l)) == FIRST(*l)){
        FIRST(*l) = NULL;
    } else {
        Address last = FIRST(*l);
        while(NEXT(last) != FIRST(*l)){
            last = NEXT(last);
        }
        FIRST(*l) = NEXT(FIRST(*l));
        NEXT(last) = FIRST(*l);
    }
    deallocate(p);
}

void deleteLast(List *l, ElType *val){
    Address p = FIRST(*l);
    if(NEXT(FIRST(*l)) == FIRST(*l)){
        *val = INFO(p);
        FIRST(*l) = NULL;
    } else {
        Address prev = NULL;
        while(NEXT(p) != FIRST(*l)){
            prev = p;
            p = NEXT(p);
        }
        *val = INFO(p);
        NEXT(prev) = FIRST(*l);
    }
    deallocate(p);
}

void displayList(List l){
    if(isEmpty(l)) printf("[]");
    else {
        Address p = FIRST(l);
        printf("[");
        while(NEXT(p) != FIRST(l)){
            printf("%d,", INFO(p));
            p = NEXT(p);
        }
        printf("%d]", INFO(p));
    }
}