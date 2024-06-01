#include <stdio.h>
#include "garis.h"
// #include "garis.c"

int main(){
	int b;
	scanf("%d", &b);

	GARIS L;
	BacaGARIS(&L);

	int n; // jumlah biri-biri
	scanf("%d", &n);

	int save = 0;
	int i;
	for(i = 0; i < n; i++){
		POINT P;
		BacaPOINT(&P);

		if(JarakGARIS(L, P) <= b) save++;
	}
	printf("%d\n", save);
	return 0;
}
