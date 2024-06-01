#include <stdio.h>
#include "datetime.h"
#include "datetime.c"
#include "time.c"

int main(){
    DATETIME D;
    CreateDATETIME(&D, 17, 10, 2023, 6, 19, 34);

    D = DATETIMENextNDetik(D, 123456789);
    TulisDATETIME(D);
    return 0;
}