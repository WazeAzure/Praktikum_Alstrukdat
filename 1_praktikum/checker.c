#include <stdio.h>
#include "garis.h"
#include "garis.c"

int main(){
	GARIS L1;
	BacaGARIS(&L1);

	TulisGARIS(L1);

	printf("panjang garis - %f", PanjangGARIS(L1));
	printf("gradien %f", Gradien(L1));

	GeserGARIS(&L1, 2, 3);
	TulisGARIS(L1);

	return 0;
}
