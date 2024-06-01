#include <stdio.h>
#include "liststatik.h"
// #include "liststatik.c"


int main(){
	ListStatik l1;
	CreateListStatik(&l1);
	readList(&l1);

	ListStatik l2 = l1;
	sortList(&l2, 1);
		
	ElType val = 0;
	scanf("%d", &val);

	float avg = 0;
	int i=0;
	for(i=0;i<listLength(l1);i++){
		avg += ELMT(l1, i);
	}
	avg /= listLength(l1);
	
	printList(l2);
	printf("\n");

	printf("Average: %.2f\n", avg);
	
	IdxType first = indexOf(l2, val);
	if(first == IDX_UNDEF){
		printf("%d tidak ada\n", val);
	} else {
		printf("%d\n", first);
		ElType max = -999999, min = 999999;
		extremeValues(l1, &max, &min);

		ElType median = 0;
		if(listLength(l1) % 2 == 1){
			median = ELMT(l2, (listLength(l2)/2));
		} else {
			median = ELMT(l2, (listLength(l2))/2 - 1);
		}

		if(val == max) printf("X maksimum\n");
		if(val == min) printf("X minimum\n");
		if(val == median) printf("X median\n");
	}

	return 0;
}

