#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"
#include "bintree.c"

int main(){
    BinTree bt;
    CreateTree(1, NULL, NULL, &bt);
    printf("%d\n", bt->info);

    Address p = newTreeNode(5);
    insertNode(p, bt);
    p = newTreeNode(10);
    insertNode(p, bt);
    p = newTreeNode(15);
    insertNode(p, bt);
    p = newTreeNode(20);
    insertNode(p, bt);
    // p = newTreeNode(25);
    // insertNode(p, bt);

    printPreorder(bt);
    printf("\n");
    printInorder(bt);
    printf("\n");
    printPostorder(bt);
    printf("\n");
    printTree(bt, 2);
    // printf("\n");
    return 0;
}