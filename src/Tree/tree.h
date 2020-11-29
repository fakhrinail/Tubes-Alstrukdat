#ifndef Tree_H
#define Tree_H

#include "../boolean.h"


typedef struct {
    //untuk detail di office
    char nama[20];  
    int hargaTiket;
    POINT lokasi[10];
    char deskripsi[100];
    int kapasitas;
    int durasi;  

    //untuk report di office
    int totalDinaiki;
    int totalPenghasilan;
    int oneDayDinaiki;
    int oneDayPenghasilan;

    //biaya membangun
    int hargaBangun;
    int bahanBangun[3];    
} WahanaTree;

typedef struct tNodeTree *AddressTree;
typedef struct tNodeTree{
    AddressTree Left;
    AddressTree Right;
    WahanaTree detail;
} NodeTree;


#define Left(T) (T)->Left
#define Right(T) (T)->Right
#define Detail(T) (T)->detail

#define NamaWahana(T) (T)->detail.nama
#define HargaTiket(T) (T)->detail.hargaTiket
#define Kapasitas(T) (T)->detail.kapasitas
#define DurasiWahana(T) (T)->detail.durasi
#define Deskripsi(T) (T)->detail.deskripsi
#define HargaBangun(T) (T)->detail.hargaBangun
#define KayuBangun(T) (T)->detail.bahanBangun[0]
#define BatuBangun(T) (T)->detail.bahanBangun[1]
#define MetalBangun(T) (T)->detail.bahanBangun[2]

AddressTree Alokasi(WahanaTree X);

void Dealokasi(AddressTree X);

void DaftarWahana(WahanaTree W[]);
/* Intinya dari file diubah ke WahanaTree */

void DaftarTree(AddressTree T[], WahanaTree W[]);
/* Intinya ngubah dari WahanaTree ke AddressTree */

void MakeTree(AddressTree Root, AddressTree Left, AddressTree Right);

AddressTree searchTree(char namaWahana[], AddressTree RootUtama);

#endif