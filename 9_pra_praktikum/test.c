#include <stdio.h>
#include "list_circular.h"
#include "list_circular.c"

#define endl printf("\n")

int main(){
    List l, l2;
    CreateList(&l);
    CreateList(&l2);

    if(isEmpty(l)) printf("List is empty\n");

    int arr[] = {5, 7, 2, 3};

    for(int i=0; i< (sizeof(arr)/sizeof(arr[0])); i++){
        insertFirst(&l, arr[i]);
    }
    int temp;
    insertLast(&l, 5);
    deleteLast(&l, &temp);
    insertFirst(&l, 1000);
    deleteFirst(&l, &temp);
    
    displayList(l);
    endl;
    displayList(l2);
    endl;
    printf("temp - %d\n", temp);

    printf("isi x - %d\n", INFO(search(l, 5)));
    return 0;
}