#include "matriks.h"
#include <stdio.h>

int main(){
    MATRIKS Map1,Map2,Map3,Map4;
    MakeMAP(&Map1,"../../doc/map1.txt");
    
    
    TulisMap(Map1);
    printf("\n");
    
    return 0;
}