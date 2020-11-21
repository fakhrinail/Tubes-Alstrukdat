#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "tree.h"
#include "../MesinKarakter-Kata/mesinkar+katafile.h"

int main(){

    WahanaTree W1;
    STARTKATAf("../../doc/wahana.txt");
    CopyString(W1.nama,CKataF);
    ADVKATAf();
    W1.hargaTiket = StrToInt(CKataF);
    ADVKATAf();
    W1.kapasitas = StrToInt(CKataF);
    ADVKATAf();
    W1.durasi = StrToInt(CKataF);
    ADVKATAf();
    CopyString(W1.deskripsi,CKataF);          
    ADVKATAf();
    W1.hargaBangun = StrToInt(CKataF);
    ADVKATAf();
    W1.bahanBangun[0] = StrToInt(CKataF);
    ADVKATAf();
    W1.bahanBangun[1] = StrToInt(CKataF);
    ADVKATAf();
    W1.bahanBangun[2] = StrToInt(CKataF);
    


    printf("%s\n", W1.nama);
    printf("%d\n", W1.hargaTiket);
    printf("%d\n",W1.kapasitas);
    printf("%d\n",W1.durasi);
    printf("%s\n", W1.deskripsi);
    printf("%d\n",W1.hargaBangun);
    printf("%d\n",W1.bahanBangun[0]);
    printf("%d\n",W1.bahanBangun[1]);
    printf("%d\n",W1.bahanBangun[2]);


    return 0;
}
