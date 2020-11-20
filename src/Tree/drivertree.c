#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "tree.h"
#include "../MesinKarakter-Kata/mesinkata.h"

int main(){

    WahanaTree W1;
    STARTKATA();
    CopyString(W1.nama,CKata);
    ADVKATA();
    W1.hargaTiket = StrToInt(CKata);
    ADVKATA();
    W1.kapasitas = StrToInt(CKata);
    ADVKATA();
    W1.durasi = StrToInt(CKata);
    ADVKATA();
    CopyString(W1.deskripsi,CKata);          
    ADVKATA();
    W1.hargaBangun = StrToInt(CKata);
    ADVKATA();
    W1.bahanBangun[0] = StrToInt(CKata);
    ADVKATA();
    W1.bahanBangun[1] = StrToInt(CKata);
    ADVKATA();
    W1.bahanBangun[2] = StrToInt(CKata);
    


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
