#include <stdio.h>
#include "matrix.h"
// #include "matrix.c"
#include <math.h>

#define endl printf("\n")

int getAreaSum(Matrix m, int pR, int pC, int row, int col){
    // pR = pivotR
    // pC = pivotC

    if((pR + row > ROW_EFF(m)) || (pC + col > COL_EFF(m))){
        return 0;
    }

    int sum = 0;
    int i, j;
    for(i=pR; i<pR + row; i++){
        for(j=pC; j<pC + col; j++){
            sum += ELMT(m, i, j);
        }
    }
    return sum;
}

int main(){
    Matrix m;

    int row, col, area;
    scanf("%d %d %d", &row, &col, &area);

    readMatrix(&m, row, col);

    // displayMatrix(m);

    int faktor;
    int ans = 0;
    for(faktor=1; faktor<area;faktor++){
        if(area % faktor != 0) continue;

        int faktor2 =  area / faktor;

        int r = faktor;
        int c = faktor2;

        int i, j;
        for(i=0; i<ROW_EFF(m); i++){
            for(j=0; j < COL_EFF(m); j++){
                int sumTemp = getAreaSum(m, i, j, r, c);
                if(sumTemp > ans) {
                    ans = sumTemp;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}