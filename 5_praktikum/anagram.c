#include <stdio.h>
#include "wordmachine.h"

#define endl printf("\n")

boolean anagram(Word w1, Word w2){
    int arr1[30];
    int arr2[30];

    int i;
    for(i=0; i<30; i++){
        arr1[i] = 0;
        arr2[i] = 0;
    }

    if(w1.Length != w2.Length){
        return false;
    }

    for(i=0;i<w1.Length;i++){
        arr1[w1.TabWord[i] - 'a']++;
        arr2[w2.TabWord[i] - 'a']++;
    }

    int j = 0;
    while(j < 30){
        if(arr1[j] != arr2[j]){
            return false;
        }
        j++;
    }
    return true;
}

int main(){
    Word w[101];

    STARTWORD();
    int i=0;
    while(!EOP){
        w[i] = currentWord;
        ADVWORD();
        i++;
    }
    w[i] = currentWord;
    int size = i;

    int x;
    // for(x=0;x<=i;x++){
    //     printWord(w[x]);
    //     endl;
    // }

    int j;
    int count = 0;
    for(i=0; i<=size-1;i++){
        for(j=i+1; j<=size;j++){
            if(anagram(w[i], w[j])){
                // printWord(w[i]);
                // endl;
                // printWord(w[j]);
                // endl;
                count++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}