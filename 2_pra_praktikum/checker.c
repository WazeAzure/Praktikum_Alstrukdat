#include <stdio.h>
#include "liststatik.h"
#include "liststatik.c"

int main(){
	ListStatik L1;
	CreateListStatik(&L1);
	readList(&L1);

	printList(L1);
	return 0;
}
