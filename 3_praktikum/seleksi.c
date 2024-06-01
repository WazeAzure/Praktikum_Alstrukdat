#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"
//#include "listdin.c"

#define endl printf("\n")

int main(){

	int cap, q;
	scanf("%d %d", &cap, &q);

	ListDin l1;
	CreateListDin(&l1, cap);

	int i;
	for(i=0;i<q;i++){
		int temp;
		scanf("%d", &temp);

		if(temp == 1){
			int x;
			scanf("%d", &x);
			
			boolean check = true;
			while(check){
				if(isEmpty(l1)) {
					insertLast(&l1, x);
					check=false;
				}else{
					int idx = getLastIdx(l1);
					int catch = 0;

					if(ELMT(l1, idx) < x) deleteLast(&l1, &catch);
					else {
						insertLast(&l1, x);
						check = false;
					}
					//printf("NEFF: %d\n", NEFF(l1));
				}
			}

		} else if(temp == 2){
			printf("%d\n", NEFF(l1));
			//printf("NEFF: %d\n", NEFF(l1));
			printList(l1);
			endl;
		}
	}
	return 0;
}
