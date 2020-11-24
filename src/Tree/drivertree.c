#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "tree.h"
#include "../MesinKarakter-Kata/mesinkar+katafile.h"

int main(){

    WahanaTree W[3];
    AddressTree T[3];
    
    STARTKATAf("../../doc/wahana.txt");
    int i=0;
    while (!EndFile){
        while(!EndLine){
            CopyString(W[i].nama,CKataF);
            ADVKATAf();
            W[i].hargaTiket = StrToInt(CKataF);
            ADVKATAf();
            W[i].kapasitas = StrToInt(CKataF);
            ADVKATAf();
            W[i].durasi = StrToInt(CKataF);
            ADVKATAf();
            CopyString(W[i].deskripsi,CKataF);          
            ADVKATAf();
            W[i].hargaBangun = StrToInt(CKataF);
            ADVKATAf();
            W[i].bahanBangun[0] = StrToInt(CKataF);
            ADVKATAf();
            W[i].bahanBangun[1] = StrToInt(CKataF);
            ADVKATAf();
            W[i].bahanBangun[2] = StrToInt(CKataF);
        }
        printf("%s\n", W[i].nama);
        printf("%d\n", W[i].hargaTiket);
        printf("%d\n",W[i].kapasitas);
        printf("%d\n",W[i].durasi);
        printf("%s\n", W[i].deskripsi);
        printf("%d\n",W[i].hargaBangun);
        printf("%d\n",W[i].bahanBangun[0]);
        printf("%d\n",W[i].bahanBangun[1]);
        printf("%d\n",W[i].bahanBangun[2]);
        printf("\n");
        T[i] = Alokasi(W[i]);
        ADVKATAf(); 
        i++;
    }
    MakeTree(T[0],T[1],T[2]);
    printf("%s", NamaWahana(T[1]));
    printf("%d", HargaTiket(T[1]));
    printf("%d", KayuBangun(T[1]));

    return 0;
}
