#include "matriks.h"
#include <stdio.h>

int main(){
    MATRIKS Map1,Map2,Map3,Map4;
    MakeMAP(&Map1,"../../doc/map1.txt");
    MakeMAP(&Map2,"../../doc/map2.txt");
    
    
    TulisMap(Map2);
    printf("\n");
    
    return 0;
}