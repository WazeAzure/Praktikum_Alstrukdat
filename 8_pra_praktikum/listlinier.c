#include <stdlib.h>
#include <stdio.h>
#include "listlinier.h"

Address newNode(ElType val){
    Address p = (Address)malloc(sizeof(Node));
    if(p != NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

void CreateList(List *l){
    FIRST(*l) = NULL;
}

boolean isEmpty(List l){
    return FIRST(l) == NULL;
}

ElType getElmt(List l, int idx){
    int i=0;
    Address p = FIRST(l);
    while(i < idx && NEXT(p) != NULL){
        p = NEXT(p);
        i++;
    }
    if(i == idx) return INFO(p);
}

void setElmt(List *l, int idx, ElType val){
    if(!isEmpty(*l)){
        int i;
        Address p = FIRST(*l);
        for(i=0; i<idx; i++){
            p = NEXT(p);
        }
        INFO(p) = val;
    }
}

int indexOf(List l, ElType val){
    int i = 0;
    Address p = FIRST(l);
    boolean found = false;
    while(p != NULL && !found){
        if (INFO(p) == val){
            found = true;
        } else {
            i++;
            p = NEXT(p);
        }
    }
    if(found) return i;
    else return IDX_UNDEF;
}

void insertFirst(List *l, ElType val){
    Address p = newNode(val);
    
    if(p != NULL){
        if(isEmpty(*l)){
            NEXT(p) = NULL;
        } else {
            NEXT(p) = *l;
        }
        *l = p;
    }
}

void insertLast(List *l, ElType val){
    Address p = newNode(val);
    
    Address x = FIRST(*l);
    if(p != NULL){
        if(isEmpty(*l)){
            *l = p;
        } else {
            while(NEXT(x) != NULL){
                x = NEXT(x);
            }
            NEXT(x) = p;
        }
    }
}

void insertAt(List *l, ElType val, int idx){
    int len = length(*l);
    if(idx == 0){
        insertFirst(l, val);
    } else if(idx == len){
        insertLast(l, val);
    } else {
        Address newVal = newNode(val);
        if(newVal != NULL){
            if(idx < len){
                int i;
                Address p = FIRST(*l);
                for(i=0;i<idx-1;i++){
                    p = NEXT(p);
                }
                Address prev = p;
                p = NEXT(p);
                NEXT(newVal) = p;
                NEXT(prev) = newVal;
            }
        }
    }
    
}

void deleteFirst(List *l, ElType *val){
    if(!isEmpty(*l)){
        Address p = FIRST(*l);
        *l = NEXT(*l);
        *val = INFO(p);
        free(p);
    }
}

void deleteLast(List *l, ElType *val){
    int le = length(*l);
    
    if(le == 1){
        Address p = FIRST(*l);
        *val = INFO(p);
        free(p);
        *l = NULL;
    } else {
        if(!isEmpty(*l)){
        Address p = FIRST(*l);
        int i=0;
        int real_l = length(*l);

        while(i < real_l - 2){
            p = NEXT(p);
            i++;
        }

        Address prev = p;
        p = NEXT(p);
        *val = INFO(p);
        free(p);

        NEXT(prev) = NULL;
    }
    }
    
    
}

void deleteAt(List *l, int idx, ElType *val){
    // if(!isEmpty(*l)){
    //     int len = length(*l);
    //     if(idx == 0){
    //         deleteFirst(l, val);
    //     } else if(idx < len){
    //         Address p = FIRST(*l);
    //         int i=0;
    //         for(i=0;i<idx-1;i++){
    //             p = NEXT(p);
    //         }
    //         Address prev = p;
    //         p = NEXT(p);

    //         *val = INFO(p);
    //         NEXT(prev) = NEXT(p);
    //         free(p);
    //     }
    // }
    if (idx == 0) {
        deleteFirst(l, val);
    } else {
        int counter = 0;
        Address loc = *l;
        while (counter < idx - 1) {
            loc = NEXT(loc);
            counter++;
        }
        Address p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}

void displayList(List l){
    if(isEmpty(l)) printf("[]");
    else {
        printf("[");
        Node *p = FIRST(l);
        while(NEXT(p) != NULL){
            printf("%d,", INFO(p));
            p = NEXT(p);
        }
        printf("%d", INFO(p));
        printf("]");
    }
}

int length(List l){
    if(isEmpty(l)) return 0;
    else{
        int i=0;
        Node *p = FIRST(l);
        while(p != NULL){
            p = NEXT(p);
            i++;
        }
        return i++;
    }
}


List concat(List l1, List l2){
    List l3;
    CreateList(&l3);

    Address p1 = FIRST(l1);
    Address p2 = FIRST(l2);


    while(p1 != NULL){
        insertLast(&l3, INFO(p1));
        p1 = NEXT(p1);
    }
    while(p2 != NULL){
        insertLast(&l3, INFO(p2));
        p2 = NEXT(p2);
    }
    return l3;
}