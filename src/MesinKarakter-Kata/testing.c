#include "mesinkar+katafile.h"
#include <stdio.h>

int main(){

    STARTKATAf("test.txt");
    printf("%s", CKataF);
    ADVKATAf();
    

    STARTKATAf("test1.txt");
    printf("%s", CKataF);
    ADVKATAf();
    

    return 0;
}