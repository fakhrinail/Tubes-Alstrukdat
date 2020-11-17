#include "matriks.h"
#include <stdio.h>

int main(){
    MATRIKS Map1,Map2,Map3,Map4;
    MakeMAP(&Map1,1);
    MakeMAP(&Map2,2);
    MakeMAP(&Map3,3);
    MakeMAP(&Map4,4);

    TulisMap(Map1);
    printf("\n");
    TulisMap(Map2);
    return 0;
}