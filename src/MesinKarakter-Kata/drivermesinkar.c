#include "mesinkar.h"
#include <stdio.h>

int main(){

    START();
    printf("%c", CC);
    while (!EOP){
        ADV();
        printf("%c", CC);
    }

    return 0;
}