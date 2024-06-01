#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "matrix.c"

#define endl printf("\n")
int main(){
	Matrix m1, m2;
	createMatrix(4, 4, &m1);
	readMatrix(&m1, 4, 4);

	printf("%d\n", isIdentity(m1));
	printf("%d\n", isSymmetric(m1));
	isSparse(m1);
	pTranspose(&m1);
	displayMatrix(m1);
	m2 = multiplyByConst(m1, -1);

	endl;
	displayMatrix(m2);

	return 0;
}

