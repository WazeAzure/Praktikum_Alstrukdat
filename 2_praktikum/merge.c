#include <stdio.h>
#include "liststatik.h"
//#include "liststatik.c"

int main(){
	int a, b;
	ListStatik l1, l2;

	CreateListStatik(&l1);
	CreateListStatik(&l2);
	
	readList(&l1);
	readList(&l2);

	sortList(&l1, 1);
	sortList(&l2, 1);

	// printList(l1);
	// printList(l2);

	ListStatik l3;
	CreateListStatik(&l3);

	int len1 = listLength(l1);
	int len2 = listLength(l2);

	int i=0;
	int j=0;
	while(i < len1 && j < len2){
		ElType t1 = ELMT(l1, i);
		ElType t2 = ELMT(l2, j);

		if(t1 < t2){
			insertLast(&l3, t1);
			i++;
		} else {
			insertLast(&l3, t2);
			j++;
		}
	}
	int k = 0;
	
	if(j < listLength(l2)){
		for(k=j; k<listLength(l2); k++){
			insertLast(&l3, ELMT(l2, k));
		}
	}
	if(i < listLength(l1)){
		for(k=i; k<listLength(l1); k++){
			insertLast(&l3, ELMT(l1, k));
		}
	}


	printList(l3);
	printf("\n");
	return 0;
}
