#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"
// #include "listdin.c"

int main(){
	ListDin l1;
	CreateListDin(&l1, 110);
	readList(&l1);
	sort(&l1, 1);

	ElType a = ELMT(l1, getFirstIdx(l1));
	ElType b = ELMT(l1, getLastIdx(l1));
	
	if(NEFF(l1) == 1) printf("0\n");
	else printf("%d\n", b-a+1);
	return 0;
}
