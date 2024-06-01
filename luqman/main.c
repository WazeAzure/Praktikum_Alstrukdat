#include <stdio.h>
#include <stdlib.h>

struct node {
  int data; // ini elemen
  struct node *next; // ini pointer to next element
};

int main(){
    printf("ini dari array\n");
    printf("alamat  isi\n");
    int array[5] = {1, 2, 3, 4, 5};
                //  0  1  2  3  4 - index
    for(int i=0; i<5; i++)
        printf("%x %d\n", &array[i], array[i]);
    

    printf("Ini dari linked list\n");
    printf("alamat  isi\n");
    struct node* one = malloc(sizeof(struct node));
    struct node *two = malloc(sizeof(struct node));
    struct node* three = malloc(sizeof(struct node));

    one->data = 1;
    two->data = 2;
    three->data = 3;

    one->next = two;
    two->next = three;
    three->next = NULL;

    struct node* ptr = one;

    while(ptr != NULL){
        printf("%x %d\n", ptr, ptr->data);

        ptr = ptr->next;
    }

    ptr = one;
    for(int i=0; i<1; i++){
        ptr = ptr->next;
    }
    printf("%x %d\n", ptr, ptr->data);


    return 0;

    // SARAN GW
    // HAPALIN JAWABAN KATING AOWKWAOK
}
