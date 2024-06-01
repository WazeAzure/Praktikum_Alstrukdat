#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"
//#include "listdin.c"

#define endl printf("\n")

int main(){
	ListDin l1;
	
	int n, q;
	scanf("%d", &n);
	scanf("%d", &q);

	CreateListDin(&l1, n);

	int i;
	for(i=0;i<q;i++){
		int a;
		scanf("%d", &a);

		if(a == 1){
			int x;
			scanf("%d", &x);
		
			//printf("called\n");	
			//printf("NEFF: %d\tCAPCITY: %d\n", NEFF(l1), CAPACITY(l1));
			
			if(isEmpty(l1)) insertLast(&l1, x);
			else{
			boolean temp = true;
			while(temp){
				int catch = 0;
				int idx = getLastIdx(l1);	
				if(ELMT(l1, idx) < x){
					deleteLast(&l1, &catch);
				} else {
					temp = false;
				}
			}
			//printf("NEFF: %d\tCAPACITY: %d\n", NEFF(l1), CAPACITY(l1));
			if(NEFF(l1) < 0) NEFF(l1) = 0;
			insertLast(&l1, x);
			//printList(l1);
			//endl;
			}
		} else if(a == 2){
			printf("%d\n", NEFF(l1));
			printList(l1);
			endl;
		}
	}
	return 0;
}
