#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

void CreateListDin(ListDin *l, int capacity){
	BUFFER(*l) = (ElType *)malloc(capacity * sizeof(ElType));
	CAPACITY(*l) = capacity;
	NEFF(*l) = 0;
}

void dealocateList(ListDin *l){
	NEFF(*l) = 0;
	CAPACITY(*l) = 0;
	free(BUFFER(*l));
}

int listLength(ListDin l){
	if(NEFF(l) == 0) return 0;
	return NEFF(l);
}

IdxType getFirstIdx(ListDin l){
	return IDX_MIN;
}

IdxType getLastIdx(ListDin l){
	return NEFF(l)-1;
}

boolean isIdxValid(ListDin l, IdxType i){
	return (i < CAPACITY(l)) && (i >= 0);
}

boolean isIdxEff(ListDin l, IdxType i){
	return (i < NEFF(l)) && (i >= 0);
}

boolean isEmpty(ListDin l){
	return (NEFF(l) == 0);
}

boolean isFull(ListDin l){
	return (NEFF(l) == CAPACITY(l));
}

void readList(ListDin *l){
	int n;
	scanf("%d", &n);

	while(n > CAPACITY(*l) || n < 0){
		scanf("%d", &n);
	}

	NEFF(*l) = n;

	int i=0;
	for(i=0;i<n;i++){
		int temp;
		scanf("%d", &temp);
		ELMT(*l, i) = temp;
	}
}

void printList(ListDin l){
	if(NEFF(l) == 0) printf("[]");
	else{
		printf("[");
		int i=0;
		for(i=0; i<NEFF(l)-1; i++){
			printf("%d,", ELMT(l, i));
		}
		printf("%d]", ELMT(l, NEFF(l)-1));
	}
}

ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
	ListDin l3;
	CreateListDin(&l3, CAPACITY(l1));
	NEFF(l3) = NEFF(l1);

	int i=0;
	for(i=0; i<NEFF(l1); i++){
		if(plus) ELMT(l3, i) = ELMT(l2, i) + ELMT(l1, i);
		else ELMT(l3, i) = ELMT(l1, i) - ELMT(l2, i);
	}
	return l3;
}

boolean isListEqual(ListDin l1, ListDin l2){
	if(NEFF(l1) == NEFF(l2)){
		IdxType i=0;
		i = 0;
		for(i=0; i<NEFF(l1); i++){
			if(ELMT(l1, i) != ELMT(l2, i)) return false;
		}
		return true;
	}
	return false;
}

IdxType indexOf(ListDin l, ElType val){
	IdxType i=0;
	for(i=0;i<NEFF(l);i++){
		if(ELMT(l, i) == val) return i;
	}
	return IDX_UNDEF;
}

void extremeValues(ListDin l, ElType *max, ElType *min){
	// ini aga curiga -----
	*max = -99999999;
	*min = 99999999;
	IdxType i = 0;
	for(i=0;i<NEFF(l);i++){
		if(ELMT(l, i) > *max) *max = ELMT(l, i);
		if(ELMT(l, i) < *min) *min = ELMT(l, i);
	}
}


void copyList(ListDin lIn, ListDin *lOut){
	CreateListDin(lOut, CAPACITY(lIn));
	NEFF(*lOut) = NEFF(lIn);

	IdxType i=0;
	for(i=0;i<NEFF(lIn);i++){
		ELMT(*lOut, i) = ELMT(lIn, i);
	}
}

ElType sumList(ListDin l){
	int sum = 0;

	IdxType i=0;
	for(i=0;i<NEFF(l);i++){
		sum += ELMT(l, i);
	}
	return sum;
}

int countVal(ListDin l, ElType val){
	int count = 0;
	IdxType i=0;
	for(i=0;i<NEFF(l);i++){
		if(ELMT(l, i) == val) count++;
	}
	return count;
}

void sort(ListDin *l, boolean asc){
	boolean x = true;
	int len = NEFF(*l);

	if(asc){
		while(x){
			int i=0;
			x = false;
			for(i=0;i<len-1;i++){
				if((ELMT(*l, i) > ELMT(*l, i+1))){
					ElType temp = ELMT(*l, i+1);
					ELMT(*l, i+1) = ELMT(*l, i);
					ELMT(*l, i) = temp;
					x = true;
				}
			}
		}
	} else {
		while(x){
			int i=0;
			x = false;
			for(i=0; i<len-1; i++){
				if(ELMT(*l, i) < ELMT(*l, i+1)){
					ElType temp = ELMT(*l, i);
					ELMT(*l, i) = ELMT(*l, i+1);
					ELMT(*l, i+1) = temp;
					x = true;
				}
			}
		}
	}
}

void insertLast(ListDin *l, ElType val){
	ELMT(*l, NEFF(*l)) = val;
	NEFF(*l) = NEFF(*l) + 1;
}

void deleteLast(ListDin *l, ElType *val){
	*val = ELMT(*l, NEFF(*l)-1);
	NEFF(*l) = NEFF(*l) - 1;
}

void expandList(ListDin *l, int num){
	ListDin l2;
	CreateListDin(&l2, CAPACITY(*l) + num);
	NEFF(l2) = NEFF(*l);

	IdxType i=0;
	for(i=0; i<NEFF(*l); i++){
		ELMT(l2, i) = ELMT(*l, i);
	}
	dealocateList(l);
	*l = l2;
}

void shrinkList(ListDin *l, int num){
	ListDin l2;
	CreateListDin(&l2, CAPACITY(*l)-num);

	NEFF(l2) = NEFF(*l);

	IdxType i=0;
	for(i=0;i<NEFF(*l);i++){
		ELMT(l2, i) = ELMT(*l, i);
	}
	dealocateList(l);
	*l = l2;
}

void compressList(ListDin *l){
	CAPACITY(*l) = NEFF(*l);
}
