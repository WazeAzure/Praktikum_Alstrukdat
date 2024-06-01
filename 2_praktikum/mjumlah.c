#include <stdio.h>
#include "liststatik.h"
// #include "liststatik.c"

int main(){
	ListStatik l1, l2;
	CreateListStatik(&l1);
	CreateListStatik(&l2);

	readList(&l1);
	readList(&l2);

	ElType len1 = listLength(l1);
	ElType len2 = listLength(l2);

	int i = 0;
	if(len1 < len2){
		for(i=0;i<len2-len1;i++){
			insertFirst(&l1, 0);
		}
	} else if(len1 > len2){
		for(i=0; i<len1-len2; i++){
			insertFirst(&l2, 0);
		}
	}

	ListStatik l3 = plusMinusList(l1, l2, 1);
	ElType temp = 0;
	
	for(i=listLength(l1)-1; i>=0; i--){
		ELMT(l3, i) += temp;
		temp = ELMT(l3, i) / 10;
		ELMT(l3, i) = ELMT(l3, i) % 10;
	}
	while(temp > 0){
		insertFirst(&l3, temp%10);
		temp /= 10;
	}

	printList(l3);
	printf("\n");
	return 0;
}
