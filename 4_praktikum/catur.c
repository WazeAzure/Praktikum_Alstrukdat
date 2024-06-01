#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
// #include "matrix.c"

#define endl printf("\n")
int main(){
    Matrix m1;
    createMatrix(8, 8, &m1);

    readMatrix(&m1, 8, 8);
    // displayMatrix(m1);
    // endl; endl;

    IdxType i, j;
    int white=0, black = 0;
    for(i=0; i<ROW_EFF(m1); i++){
        for(j=0; j<COL_EFF(m1); j++){
            if(ELMT(m1, i, j) == 1){
                if((i+j)%2 == 0) black++;
                else white++;
            }
        }
    }
    printf("%d %d\n", black, white);
    return 0;
}