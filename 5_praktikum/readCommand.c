#include <stdio.h>
#include "wordmachine.h"

// void printWord(Word word) {
//    int i;
//    for (i = 0; i < word.Length; i++) {
//       printf("%c", word.TabWord[i]);
//    }
// }

// static FILE *pita;
int main(){
    // pita = stdin;
    // fscanf(pita, "%c", &currentChar);
    // char arr[100];

    // printf("%c\n", currentChar);
    // arr[0] = currentChar;
    // int idx_first_a =0;
    // int current_idx = 0;
    // while(currentChar == ' '){
    //     current_idx++;
    //     fscanf(pita, "%c", arr[current_idx]);
    // }

    // printf("%d %s\n",current_idx, arr);

    START();
    IgnoreBlanks();
    int i=0;
    while(currentChar != '.' && i < NMax){
        currentWord.TabWord[i] = currentChar;
        i++;
        currentWord.Length++;
        ADV();
        // printf("hello -- \n");
        // printWord(currentWord);
        // printf("+ asd\n");
    }
    currentWord.Length = i;
    printWord(currentWord);
    printf("\n%d\n", currentWord.Length);
    return 0;
}