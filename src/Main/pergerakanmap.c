#include "../Matriks/matriks.h"
#include "../MesinKarakter-Kata/mesinkar.h"
#include <stdio.h>

int main(){
    MATRIKS MAP1;
    MakeMAP(&MAP1,1);       //membuat isi kosongan dari map1
    TulisMap(MAP1);
    printf("\n");

    START();
    while(CC!=MARK){
        if (CC!='\n'){
            
            isiMap(&MAP1);
            TulisMap(MAP1);
            printf("\n");
        }
        ADV();
    }

    return 0;
}