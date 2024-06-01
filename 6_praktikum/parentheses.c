#include <stdio.h>
#include "stack.h"
// #include "stack.c"

#include "charmachine.h"
#include "wordmachine.h"


void readWord(Word *input) {
    int i;
    START();
    IgnoreBlanks();

    (*input).Length = 0;
    i = 0;

    while ((currentChar != MARK) && (i < NMax)) {
        (*input).TabWord[i] = currentChar;
        ADV();
        i++;
    }

    (*input).Length = i;

    (*input).TabWord[i] = '\0';
}

void printWord(Word word) {

   int i;

   for (i = 0; i < word.Length; i++) {

      printf("%c", word.TabWord[i]);

   }

}

int main(){
    Word W;
    readWord(&W);
    // printWord(W);

    Stack C;
    CreateEmpty(&C);
    int i;

    int ans = 1;
    int depth = -1;
    for (i = 0; i < W.Length; i++) {
        // printf("masuk sini2\n");
        if(W.TabWord[i] == '('){
            Push(&C, '(');
        } else if(W.TabWord[i] == ')'){
            if(IsEmpty(C)){
                // printf("masuk sini\n");
                ans = -1;
                break;
            } else {
                char temp = '.';
                Pop(&C, &temp);
            }
        }
        // printf("size -- %d\n", C.TOP);
        if(C.TOP > depth){
            // printf("masuk sini3\n");
            depth = C.TOP;
        }
    }
    // printf("%d ans\n", ans);
    if(IsEmpty(C) && ans != -1){
        ans = 1;
    } else {
        ans = -1;
    }

    // printf("w0 -- %c", W.TabWord[0]);
    if(W.Length == 0){
        ans = -1;
    }
    // printf("%d ans\n", ans);
    if(ans == -1){
        printf("%d\n", ans);
    } else {
        printf("%d\n", depth+1);
    }
    
    return 0;
}