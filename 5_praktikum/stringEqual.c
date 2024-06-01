#include <stdio.h>
#include "wordmachine.h"

void printWord(Word word) {
   int i;
   for (i = 0; i < word.Length; i++) {
      printf("%c", word.TabWord[i]);
   }
}


int main(){
    int t;
    scanf("%d", &t);

    STARTWORD();
    // printWord(currentWord);
    // printf("%c\n", currentWord.TabWord[4]);
    if(currentWord.TabWord[4] == 'U'){
        printf("Moving %d square upwards\n", t);
    } else if(currentWord.TabWord[4] == 'D'){
        printf("Moving %d square downwards\n", t);
    } else if(currentWord.TabWord[4] == 'L'){
        printf("Moving %d square leftwards\n", t);
    } else if(currentWord.TabWord[4] == 'R'){
        printf("Moving %d square rightwards\n", t);
    }

    return 0;
}