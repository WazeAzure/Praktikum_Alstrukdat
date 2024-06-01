#include <stdio.h>
#include "matrix.h"
// #include "matrix.c"

#define endl printf("\n")

Matrix identityMatrix2x2;
Matrix mKali;

Matrix PangkatMatrix (Matrix m, int pangkat){
    // displayMatrix(m);
    // printf("------------\n");
    if (pangkat == 0) return identityMatrix2x2;
    else if (pangkat == 1) return m;
    else {
        Matrix m2 = PangkatMatrix(m,pangkat/2);
        Matrix mulMatrix = multiplyMatrixWithMod(m2,m2, 2003);

        if (pangkat % 2 == 1){
            mulMatrix = multiplyMatrixWithMod(mulMatrix,m, 2003);
        }
        return mulMatrix;
    }
}

   
    
int main(){
    ROW_EFF(identityMatrix2x2) = 2;
    COL_EFF(identityMatrix2x2) = 2;
    ELMT(identityMatrix2x2, 0, 0) = 1;
    ELMT(identityMatrix2x2, 0, 1) = 0;
    ELMT(identityMatrix2x2, 1, 0) = 0;
    ELMT(identityMatrix2x2, 1, 1) = 1;

    ROW_EFF(mKali) = 2;
    COL_EFF(mKali) = 2;
    ELMT(mKali, 0, 0) = 1;
    ELMT(mKali, 0, 1) = 1;
    ELMT(mKali, 1, 0) = 1;
    ELMT(mKali, 1, 1) = 0;

    int k;
    scanf("%d", &k);
    Matrix temp = PangkatMatrix(mKali, k);

    printf("%d\n", ELMT(temp, 0, 1));
    return 0;
}