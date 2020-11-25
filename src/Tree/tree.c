#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "tree.h"
#include "../MesinKarakter-Kata/mesinkar+katafile.h"
#include "../MesinKarakter-Kata/mesinkar+katainput.h"


AddressTree Alokasi(WahanaTree X)
{
    AddressTree P = malloc(sizeof(NodeTree));
    if (P!=NULL){
        Left(P) = NULL;
        Right(P) = NULL;
        CopyString(NamaWahana(P),X.nama);
        HargaTiket(P) = X.hargaTiket;
        Kapasitas(P) = X.kapasitas;
        DurasiWahana(P) = X.durasi;
        CopyString(Deskripsi(P),X.deskripsi);
        HargaBangun(P) = X.hargaBangun;
        KayuBangun(P) = X.bahanBangun[0];
        BatuBangun(P) = X.bahanBangun[1];
        MetalBangun(P) = X.bahanBangun[2];
    }
    return P;

}

void Dealokasi(AddressTree P)
{
    free(P);
}

void DaftarWahana(WahanaTree W[])
{
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
        ADVKATAf(); 
        i++;
    }
}

void DaftarTree(AddressTree T[], WahanaTree W[])
{
    int i=0;
    while (i<3){                //karena wahananya hanya ada 3
        T[i] = Alokasi(W[i]);
        i++;
    }
}

void MakeTree(AddressTree Root, AddressTree Left, AddressTree Right)
{
    Left(Root) = Left;
    Right(Root) = Right;
}

boolean Search(char namaWahana[], AddressTree T)
{
    if (T==NULL){
        return false;
    }else{
        if (isSame(namaWahana,NamaWahana(T))){
            return true;
        }else{
            return Search(namaWahana,Left(T)) || Search(namaWahana,Right(T));
        }
    }
}

AddressTree searchTree(char namaWahana[], AddressTree Root)
{
    if (isSame(namaWahana, NamaWahana(Root))){
        return Root;
    }else{
        if (Search(namaWahana,Left(Root))){
            return searchTree(namaWahana,Left(Root));
        }else{
            return searchTree(namaWahana,Right(Root));
        }
    }
}