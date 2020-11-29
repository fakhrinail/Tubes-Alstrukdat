#include "stacklist.h"
#include <stdio.h>

int main(){
    
    WahanaTree W[3];
    AddressTree T[3];
    DaftarWahana(W);

    BahanBangunan listBangunan[3];
    DaftarBahan(listBangunan);
    for (int i = 0; i < 3; i++)
    {
        printf("%d. %s %d\n", i+1, listBangunan[i].namabahan, listBangunan[i].hargabahan);
    }
    
    int uangPengguna = 1000;
    JAM Waktu = MakeJAM(1,0);
    
    

    DaftarTree(T,W);
    MakeTree(T[0],T[1],T[2]);

    Stack S;
    CreateEmptyStackList(&S);
    STARTKATAi();
    Buy(&S,listBangunan,uangPengguna,Waktu);
    
    int bahanPengguna[3];
    bahanPengguna[0] = 50;
    bahanPengguna[1] = 50;
    bahanPengguna[2] = 50;

    printf("%s", NamaWahana(T[0]));
    Build(&S,bahanPengguna,uangPengguna,Waktu,T[0],MakePOINT(2,2));
    
    return 0;
}