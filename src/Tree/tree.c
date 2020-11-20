#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "tree.h"


AddressTree Alokasi(WahanaTree X){
    AddressTree P = malloc(sizeof(NodeTree));
    if (P!=NULL){
        Left(P) = NULL;
        Right(P) = NULL;
        CopyString(NamaWahana(P),X.nama);
        HargaTiket(P) = X.hargaTiket;
        Kapasitas(P) = X.kapasitas;
        Durasi(P) = X.durasi;
        CopyString(Deskripsi(P),X.deskripsi);
        HargaBangun(P) = X.hargaBangun;
        KayuBangun(P) = X.bahanBangun[0];
        BatuBangun(P) = X.bahanBangun[1];
        MetalBangun(P) = X.bahanBangun[2];
    }
    return P;

}

AddressTree Dealokasi(AddressTree P){
    free(P);
}

