#include "../Matriks/matriks.h"
#include "../MesinKarakter-Kata/mesinkar+katainput.h"
#include <stdio.h>

int main(){
    MATRIKS MAP1;
    MakeMAP(&MAP1, "../../doc/map1.txt");       //membuat isi kosongan dari map1
    TulisMap(MAP1);
    printf("\n");

    STARTKATAi();
    while(!isEOP(CKataI)){
        GerakPlayer(&MAP1,CKataI);
        updateMap(&MAP1);
        TulisMap(MAP1);
        printf("\n");
        ADVKATAi();
    }

    return 0;
}