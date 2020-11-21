#include "../Matriks/matriks.h"
#include "../MesinKarakter-Kata/mesinkar+katainput.h"
#include <stdio.h>

int main(){
    MATRIKS MAP1;
    MakeMAP(&MAP1,1);       //membuat isi kosongan dari map1
    TulisMap(MAP1);
    printf("\n");

    STARTKATAi();
    while(!isEOP(CKataI)){
        GerakPlayer(&MAP1,CKataI);
        isiMap(&MAP1);
        TulisMap(MAP1);
        printf("\n");
        ADVKATAi();
    }

    return 0;
}