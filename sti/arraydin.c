#include "arraydin.h"
#include <stdlib.h>

ArrayDin MakeArrayDin(){
    ArrayDin array;
    array.A = (ElType*) malloc(InitialSize*sizeof(ElType));
    array.Capacity = InitialSize;
    array.Neff = 0;
    return array;
}

void DeallocateArrayDin(ArrayDin *array){
    free(array);
    (*array).Capacity=0;
    (*array).Neff =0;
}

boolean IsEmpty(ArrayDin array){
    return(array.Neff==0);
}

int Length(ArrayDin array){
    return(array.Neff);
}

ElType Get(ArrayDin array, IdxType i){
    return (array.A)[i];
}

int GetCapacity(ArrayDin array){
    return array.Capacity;
}

void InsertAt(ArrayDin *array, ElType el, IdxType i){
    int idx;
    for (idx = (*array).Neff -1 ; idx>=i;idx--){
        (*array).A[idx+1]= (*array).A[idx];
    }
    (*array).A[i] = el;
    (*array).Neff ++;
}

void DeleteAt(ArrayDin *array, IdxType i){
    int idx;
    for(idx = i;idx<(*array).Neff;idx++){
        (*array).A[idx]= (*array).A[idx+1];
    }    
    (*array).Neff --;
}
