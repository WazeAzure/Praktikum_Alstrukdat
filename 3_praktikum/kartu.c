#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"
//#include "listdin.c"

#define endl printf("\n")

int main(){
	ListDin l1, l2;
	CreateListDin(&l1, 100000);
	CreateListDin(&l2, 100000);

	readList(&l1);
	readList(&l2);

	//sort(&l1, 1);
	//sort(&l2, 1);

	ListDin l3;
	CreateListDin(&l3, 200000);

	int i=0, j=0;
	while(i<NEFF(l1) && j<NEFF(l2)){
		ElType t1 = ELMT(l1, i);
		ElType t2 = ELMT(l2, j);

		if(t1 >= t2){
			insertLast(&l3, t1);
			i++;
		} else {
			insertLast(&l3, t2);
			j++;
		}
	}

	int k=0;
	if(j < listLength(l2)){
		for(k=j; k<NEFF(l2); k++){
			insertLast(&l3, ELMT(l2, k));
        }
    }
	if(i < listLength(l1)){
        for(k=i; k<NEFF(l1); k++){
            insertLast(&l3, ELMT(l1, k));
        }
	}

	//sort(&l3, 0);
	printList(l3);
	endl;
	return 0;
}
