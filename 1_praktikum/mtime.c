#include <stdio.h>
#include "time.h"
// #include "../1_pra_praktikum/time.c"


int main(){
	int n;
	scanf("%d", &n);
	
	int i;
	TIME T0, T3;
	CreateTime(&T0, 23, 59, 59);
	CreateTime(&T3, 0, 0, 0);
	for(i=0; i<n; i++){
		printf("[%d]\n", i+1);
		TIME T1, T2;
		BacaTIME(&T1);
		BacaTIME(&T2);

		if (TLT(T1, T0)) T0 = T1;
		if (TGT(T1, T3)) T3 = T1;
		
		if (TLT(T2, T0)) T0 = T2;
		if (TGT(T2, T3)) T3 = T2;


		if(TLT(T1, T2)){
			printf("%ld\n", (Durasi(T1, T2)));
		} else {
			printf("%ld\n", (Durasi(T2, T1)));
		}
	}
	TulisTIME(T0);
	printf("\n");
	TulisTIME(T3);
	printf("\n");
	

	return 0;
}
