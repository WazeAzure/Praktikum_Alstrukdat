#include <stdio.h>
#include "liststatik.h"
// #include "liststatik.c"

#define endl printf("\n")

int main(){
	ListStatik rumah, perjalanan;
	CreateListStatik(&rumah);
	CreateListStatik(&perjalanan);

	readList(&rumah);
	readList(&perjalanan);
	insertFirst(&perjalanan, 0);
	
	// besi kertas gelas
	// 1    2      3
	
	int i=0;
	for(i=1; i<listLength(perjalanan); i++){
		ELMT(perjalanan, i) = ELMT(perjalanan, i) + ELMT(perjalanan, i-1);
	}

	ElType t1=0, t2=0, t3=0;
	IdxType idx1=0, idx2=0, idx3=0;
	for(i=0; i < listLength(rumah); i++){
		if(ELMT(rumah, i) == 0) continue;
		else if(ELMT(rumah, i) == 1){
			t1 += 1;
			idx1 = i;
		} else if(ELMT(rumah, i) == 2){
			t2 += 1;
			idx2 = i;
		} else if(ELMT(rumah, i) == 3){
			t3 += 1;
			idx3 = i;
		}
	}
	t1 += ELMT(perjalanan, idx1)*2;
	t2 += ELMT(perjalanan, idx2)*2;
	t3 += ELMT(perjalanan, idx3)*2;

	// printList(rumah);
	// endl;
	// printList(perjalanan);
	// endl;
	// printf("%d %d %d\n", t1, t2, t3);
	printf("%d\n", t1 + t2 + t3);
	
	return 0;
}
