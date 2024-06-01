#include <stdio.h>
#include "listdin.c"

#define endl printf("\n")

int main(){
	ListDin l1, l2, lx;
	CreateListDin(&l1, 20);
	CreateListDin(&l2, 10);
	CreateListDin(&lx, 10);

	readList(&l1);
	copyList(l1, &l2);
	readList(&lx);

	ListDin l3;
	// CreateListDin(&l3, 20);
	l3 = plusMinusList(l1, l2, 1);

	printList(l1);
	endl;
	printList(l2);
	endl;
	printList(l3);
	endl;
	printList(lx)
	endl;

	printf("list length l1 - %d\n", listLength(l1));
	printf("first index l1 - %d\n", getFirstIdx(l1));
	printf("last index l1 - %d\n", getLastIdx(l1));
	printf("%d\n", isIdxValid(l1, 100));
	printf("%d\n", isIdxEff(l1, 5));
	printf("%d\n", isListEqual(l1, l2));
	printf("%d\n", indexOf(l1, 5));
	printf("%d\n", indexOf(l1, 100));

	int max = 0;
	int min = 0;
	extremeValues(l3, &max, &min);
	printf("min: %d\tmax: %d\n", min, max);

	int sum = sumList(l3);
	int count = countVal(l1, 2);
	printf("sum: %d\tcount: %d\n", sum, count);

	sort(&l3, 0);
	sort(&l2, 1);
	sort(&l1, 0);
	printList(l3);
	endl;

	insertLast(&l3, 100);
	printList(l3);
	endl;
	int val = 0;
	deleteLast(&l3, &val);
	endl;
	printf("deleted: %d\n", val);

	expandList(&l3, 30);
	shrinkList(&l2, 3);
	compressList(&l3);

	printList(l1);
	endl;
	printList(l2);
	endl;
	printList(l3);
	endl;

	dealocateList(&l1);
	dealocateList(&l2);
	dealocateList(&l3);
	dealocateList(&lx);
	return 0;
}
