#include <stdio.h>
#include "point.h"
// #include "point.c"

int main(){
    POINT p1, p2, p3;
    BacaPOINT(&p1);
    BacaPOINT(&p2);
    BacaPOINT(&p3);

    int a = (Absis(p1) * (Ordinat(p3) - Ordinat(p2)) + Absis(p2) * (Ordinat(p1) - Ordinat(p3)) + Absis(p3) * (Ordinat(p2) - Ordinat(p1))) / ((Absis(p1) - Absis(p2)) * (Absis(p1) - Absis(p3)) * (Absis(p2) - Absis(p3)));
    // printf("%f\n", a);
    int b = ((Ordinat(p2) - Ordinat(p1)) / (Absis(p2) - Absis(p1))) - (a * (Absis(p1) + Absis(p2)));
    // printf("%f\n", b);
    int c = Ordinat(p1) - (a * Absis(p1) * Absis(p1)) - (b * Absis(p1));
    printf("%d\n", c);
    return 0;
}