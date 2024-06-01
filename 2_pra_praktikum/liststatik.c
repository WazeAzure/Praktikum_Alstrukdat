#include <stdio.h>
#include "liststatik.h"

void CreateListStatik(ListStatik *l){
	int i;
	for(i = 0; i < CAPACITY; i++){
		ELMT(*l, i) = MARK;
	}
}

int listLength(ListStatik l){
	int i=0;
	while(ELMT(l, i) != MARK && i < CAPACITY){
		i++;
	}
	return i;
}

IdxType getFirstIdx(ListStatik l){
	return IDX_MIN;
}

IdxType getLastIdx(ListStatik l){
	int i=listLength(l);
	return i-1;	
}

boolean isIdxValid(ListStatik l, IdxType i){
	return (i >= 0) && (i < CAPACITY);
}

boolean isIdxEff(ListStatik l, IdxType i){
	return (i >= 0) && (i < listLength(l));
}

boolean isEmpty(ListStatik l){
	return listLength(l) == 0;
}

boolean isFull(ListStatik l){
	return listLength(l) == CAPACITY;
}

void readList(ListStatik *l){
	int n;
	scanf("%d", &n);

	while(n < 0 || n > CAPACITY){
		scanf("%d", &n);
	}

	CreateListStatik(l);

	int i=0;
	for(i=0; i<n; i++){
		int temp;
		scanf("%d", &temp);
		ELMT(*l, i) = temp;
	}
}


// besok kerjain
void printList(ListStatik l){
	int i=0;
	int length = listLength(l);
	if(length == 0) printf("[]");
	else {
		printf("[");
		for(i=0; i<length-1; i++){
			printf("%d,", ELMT(l, i));
		}
		printf("%d]", ELMT(l, length-1));
	}
}

ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus){
	ListStatik l3;
	CreateListStatik(&l3);

	int length = listLength(l1);
	int i = 0;
	for(i=0;i<length;i++){
		if(plus) ELMT(l3, i) = ELMT(l1, i) + ELMT(l2, i);
		else ELMT(l3, i) = ELMT(l1, i) - ELMT(l2, i);
	}

	return l3;
}

boolean isListEqual(ListStatik l1, ListStatik l2){
	int length1 = listLength(l1);
	int length2 = listLength(l2);

	if(length1 != length2) return false;
	
	int i = 0;
	while(i < length1){
		if(ELMT(l1, i) != ELMT(l2, i)) return false;
		i++;
	}
	return true;
}

int indexOf(ListStatik l, ElType val){
	int i = 0;
	int length = listLength(l);
	while(i < length){
		if(ELMT(l, i) == val) return i;
		i++;
	}
	return IDX_UNDEF;
}

void extremeValues(ListStatik l, ElType *max, ElType *min){
	int i = 0;
	int length = listLength(l);
	for(i=0; i<length; i++){
		if(ELMT(l, i) > *max) *max = ELMT(l, i);
		if(ELMT(l, i) < *min) *min = ELMT(l, i);
	}
}

void insertFirst(ListStatik *l, ElType val){
	int idx = getLastIdx(*l);
	int i = 0;
	for(i = idx; i>=0; i--){
		ELMT(*l, i+1) = ELMT(*l, i);
	}
	ELMT(*l, 0) = val;
}

void insertAt(ListStatik *l, ElType val, IdxType idx){
	int end = getLastIdx(*l);
	int i = 0;
	int temp = 0;
	for(i=idx; i<=end+1; i++){
		ElType temp = ELMT(*l, i);
		ELMT(*l, i) = val;
		val = temp;
	}
}

void insertLast(ListStatik *l, ElType val){
	int start = getLastIdx(*l);
	ELMT(*l, start+1) = val;
}

void deleteFirst(ListStatik *l, ElType *val){
	*val = ELMT(*l, 0);
	int end = getLastIdx(*l);
	int i = 0;
	for(i=0;i<=end;i++){
		ELMT(*l, i) = ELMT(*l, i+1);
	}
	ELMT(*l, end) = MARK;
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx){
	*val = ELMT(*l, idx);
	int end = getLastIdx(*l);
	int i=0;
	for(i=idx; i<=end;i++){
		ELMT(*l, i) = ELMT(*l, i+1);
	}
	ELMT(*l, end) = MARK;
}

void deleteLast(ListStatik *l, ElType *val){
	int start = getLastIdx(*l);
	*val = ELMT(*l, start);
	ELMT(*l, start) = MARK;
}

void sortList(ListStatik *l, boolean asc){
	// bubble sort
	boolean x = true;
	int len = listLength(*l);
	if(asc){
		while(x){
			int i=0;
			x = false;
			for(i=0; i<len-1; i++){
				if(ELMT(*l, i) > ELMT(*l, i+1)){
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

