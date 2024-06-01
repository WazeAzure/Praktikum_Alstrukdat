#include <stdio.h>
#include "stack.h"
// #include "stack.c"


/* Menyortir keranjang S1 menggunakan bantuan S2 */
/* I.S. S1 tidak terurut dan S2 kosong */
/* F.S. S1 kosong dan S2 terurut */
/* Contoh: */
/* TOP */
/* I.S. S1 = [23, 92, 98, 31, 3, 34]; S2 = [] */
/* TOP */
/* I.S. S1 = []; S2 = [3, 23, 31, 34, 92, 98] */

// void printStack(Stack S){
//     for(int i=0; i<10; i++){
//         printf("%d ", S.T[i]);
//     }
//     printf("\n");
// }

void SortirKeranjang(Stack *S1, Stack *S2){
    // int i=0;
    while(!IsEmpty(*S1) ){
        int temp;
        Pop(S1, &temp);
        while (!IsEmpty(*S2) && InfoTop(*S2) > temp){
            int buang;
            Pop(S2, &buang);
            Push(S1, buang);
        }
        Push(S2, temp);
        
        // printStack(*S1);
        // printStack(*S2);
        // i++;
    }
}

// int main(){
//     int s[6] = {23, 92, 98, 31, 3, 34};

//     Stack S1, S2;
//     CreateEmpty(&S1);
//     CreateEmpty(&S2);

//     int i = 0;
//     for(i=0;i<6;i++){
//         Push(&S1, s[i]);
//     }
//     SortirKeranjang(&S1, &S2);

//     printStack(S1);
//     printStack(S2);
    

//     printf("empty? -- %d", IsEmpty(S2));
//     return 0;
// }
/*
void SortirKeranjang (Stack * S1, Stack * S2){
    int arr[100];
    int i=0;
    for(i=0; i<100;i++){
        arr[i] = -1;
    }

    

    i = 0;
    while(!IsEmpty(*S1)){
        Pop(S1, &arr[i]);
        i++;
    }

    int lastIdx = -1;
    for(i=0; i<100;i++){
        if(arr[i] == -1){
            lastIdx = i-1;
            break;
        }
    }

    // sort
    boolean swap = true;
    while(swap){
        swap = false;
        int i=0;
        for(i=0; i<lastIdx; i++){
            if(arr[i] < arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swap = true;
            }
        }
    }

    // for(i=0; i<100;i++){
    //     printf("%d " , arr[i]);
    // }

    for(i=0; i<=lastIdx;i++){
        Push(S2, arr[i]);
    }

    // for(i=0; i<100;i++){
    //     printf("%d " , (S2)->T[i]);
    // }
    // printf("\n%d " , (S2)->TOP);
}
*/

