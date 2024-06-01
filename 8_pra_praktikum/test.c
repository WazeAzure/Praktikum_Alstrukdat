#include <stdlib.h>
#include <stdio.h>
#include "listlinier.h"
#include "listlinier.c"

#define endl printf("\n")

int main(){
    List l;
    CreateList(&l);

    insertAt(&l, 1, 0);
    insertAt(&l, 3, 1);
    insertAt(&l, 2, 1);
    displayList(l);
    endl;
    return 0;
}
