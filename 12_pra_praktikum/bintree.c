#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

BinTree NewTree(ElType root, BinTree left_tree, BinTree right_tree){
    BinTree p = (BinTree)malloc(sizeof(TreeNode));
    if(p == NULL){
        return NULL;
    }
    ROOT(p) = root;
    LEFT(p) = left_tree;
    RIGHT(p) = right_tree;

    return p;
}

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p){
    BinTree newP = NewTree(root, left_tree, right_tree);

    if(newP == NULL){
        *p = NULL;
    } else {
        *p = newP;
    }
}

Address newTreeNode(ElType val){
    Address p = (Address)malloc(sizeof(TreeNode));

    if(p == NULL){
        return NULL;
    }

    ROOT(p) = val;
    LEFT(p) = NULL;
    RIGHT(p) = NULL;

    return p;
}

void deallocTreeNode(Address p){
    free(p);
}

boolean isTreeEmpty(BinTree p){
    return p == NULL;
}

boolean isOneElmt(BinTree p){
    return !isTreeEmpty(p) && LEFT(p) == NULL && RIGHT(p) == NULL;
}

boolean isUnerLeft(BinTree p){
    return !isTreeEmpty(p) && LEFT(p) != NULL && RIGHT(p) == NULL; 
}

boolean isUnerRight(BinTree p){
    return !isTreeEmpty(p) && LEFT(p) == NULL && RIGHT(p) != NULL; 
}

boolean isBinary(BinTree p){
    return !isTreeEmpty(p) && LEFT(p) != NULL && RIGHT(p) != NULL;
}

void printPreorder(BinTree p){

    if(isTreeEmpty(p)){
        printf("()");
        return;
    }

    // int i;
    // for(i=0; i < level; i++){
    //     printf("\t");
    // }
    printf("(");

    printf("%d", ROOT(p));

    printPreorder(LEFT(p));

    // for(i=0; i < level; i++){
    //     printf("\t");
    // }

    

    printPreorder(RIGHT(p));

    // for(i=0; i < level; i++){
    //     printf("\t");
    // }
    printf(")");
}

void printInorder(BinTree p){

    if(isTreeEmpty(p)){
        printf("()");
        return;
    }

    // int i;
    // for(i=0; i < level; i++){
    //     printf("\t");
    // }
    printf("(");


    printInorder(LEFT(p));

    // for(i=0; i < level; i++){
    //     printf("\t");
    // }

    printf("%d", ROOT(p));
    

    printInorder(RIGHT(p));

    // for(i=0; i < level; i++){
    //     printf("\t");
    // }
    printf(")");
}

void printPostorder(BinTree p){

    if(isTreeEmpty(p)){
        printf("()");
        return;
    }

    // int i;
    // for(i=0; i < level; i++){
    //     printf("\t");
    // }
    printf("(");

    printPostorder(LEFT(p));

    // for(i=0; i < level; i++){
    //     printf("\t");
    // }

    printPostorder(RIGHT(p));


    printf("%d", ROOT(p));

    // for(i=0; i < h; i++){
    //     printf("\t");
    // }
    printf(")");
}

void printTreeNew(BinTree p, int h, int level){
    int i, j;
    if(isTreeEmpty(p)){
        return;
    }
    
    // printf("\n");

    for(i=0; i < level; i++){
        for(j=0; j<h; j++){
            printf(" ");
        }
    }

    printf("%d\n", ROOT(p));    


    printTreeNew(LEFT(p), h, level+1);
    

    printTreeNew(RIGHT(p), h, level+1);

}

void printTree(BinTree p, int h){
    printTreeNew(p, h, 0);
}

void insertNode(Address node, BinTree tree){
    if(isTreeEmpty(LEFT(tree))){
        LEFT(tree) = node;
    } else if(isTreeEmpty(RIGHT(tree))){
        RIGHT(tree) = node;
    } else {
        insertNode(node, LEFT(tree));
    }
}