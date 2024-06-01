#include <stdio.h>
#include "wordmachine.h"

#define endl printf("\n")

void printWord(Word word) {
   int i;
   for (i = 0; i < word.Length; i++) {
      printf("%c", word.TabWord[i]);
   }
}


int wg(Word w1, Word w2){
    // printf("called2\n");
    int small = w2.Length;
    if(w1.Length < w2.Length) small = w1.Length;
    
    int i=0;
    boolean loop = true;
    while (i < small && loop) {
        // printf("loop %d\n", i);
        if(w1.TabWord[i] > w2.TabWord[i]){
            return true;
        } else if(w1.TabWord[i] == w2.TabWord[i]){
            i++;
            continue;
        } else {
            return false;
        }
        i++;
    }
    if(w1.Length <= w2.Length) return false;
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
    int size = i+1;

    boolean loop = true;
    int count = size;
    while(loop){
        // printf("Called\n");
        loop = false;
        for(i=0; i<count-1; i++){
            if(wg(w[i], w[i+1])){
                Word temp = w[i];
                w[i] = w[i+1];
                w[i+1] = temp;
                loop = true;
            }
        }
        // int x;
        // for(x=0;x<=i;x++){
        //     printWord(w[x]);
        //     printf(" ");
        // }
        // endl;
        count --;
    }


    int x;
    for(x=0;x<=size-1;x++){
        printWord(w[x]);
        endl;
    }
    return 0;
}