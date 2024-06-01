#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listdin.h"
//#include "listdin.c"

#define endl printf("\n")

int main(){
	int q;
	scanf("%d", &q);

	ListDin l;
	CreateListDin(&l, 0);

	int i=0;
	for(i=0;i<q;i++){
		int tipe;
		scanf("%d",&tipe);

		if(tipe==1){
		  	int x;
			scanf("%d",&x);

			if(isFull(l)){
				expandList(&l, CAPACITY(l));
			}
			if(CAPACITY(l) == 0){
				CAPACITY(l) = 1;
			}

			insertLast(&l, x);
			//printList(l);
		}else if(tipe==2){
			int temp = 0;
			deleteLast(&l, &temp);
			if(NEFF(l) <= round(CAPACITY(l)/2)){
				CAPACITY(l) = round(CAPACITY(l)/2);
			}
		}else{
			printf("%d ", CAPACITY(l));
			printList(l);
			endl;
		}
	}
	return 0;
}
