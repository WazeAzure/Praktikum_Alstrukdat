#include <stdio.h>
#include <stdlib.h>

// void add_2(int* x){
    // *x = x + 2;
    // 123 + 2 = 125
    // *x = *x + 2;
    // 10 + 2 = 12
// }

int add_2(int x){
    x = x + 2;

    return x;
}

int main(){
    int x = 10;

    x = add_2(x);

    char str[] = "mama";

    char c;
    int i = 0;
    while(c != '\0'){
        c = str[i];
        printf("%c", c);
        i++;
    }
    printf("\n");

    printf("%s\n", str);
    printf("panjang %d\n", sizeof(str) / sizeof(str[0]));

    // add_2(&x);
    // add_2(x);

    return 0;
}