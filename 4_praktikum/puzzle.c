#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
// #include "matrix.c"

#define endl printf("\n")

boolean findArr(Matrix m1, Matrix m2){

    // displayMatrix(m2);
    // endl; endl;

    IdxType i, j;
    for(i=0;i<ROW_EFF(m1);i++){
        for(j=0;j<COL_EFF(m1);j++){
            boolean temp = true;
            if(ELMT(m1, i, j) == ELMT(m2, 0, 0)){
                IdxType k, l;

                for(k=0;k<ROW_EFF(m2);k++){
                    for(l=0;l<COL_EFF(m2);l++){
                        if(ELMT(m2, k, l) != ELMT(m1, i+k, j+l)){
                            temp = false;
                            break;
                        }
                    }
                    if(!temp) break;
                }
                if(temp) return true;
            }
        }
    }
    return false;
}

int main(){
    Matrix m1;
    ElType row, col;
    scanf("%d %d", &row, &col);

    createMatrix(row, col, &m1);
    readMatrix(&m1, row, col);

    ElType tc;
    scanf("%d", &tc);

    IdxType t, i, j;

    boolean ans = true;

    for(t=0; t<tc;t++){
        ElType row2, col2;
        scanf("%d %d", &row2, &col2);

        Matrix m2;
        createMatrix(row2, col2, &m2);
        readMatrix(&m2, row2, col2);

        ans = ans & findArr(m1, m2);
        // printf("called tc-%d ans-%d\n", t, ans);
        if(!ans) break;
    }

    if(ans){
        printf("Puzzle dapat diselesaikan.\n");
    } else {
        printf("Puzzle tidak dapat diselesaikan.\n");
    }
    return 0;
}