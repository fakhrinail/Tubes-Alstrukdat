#ifndef Tree_H
#define Tree_H

#include "../boolean.h"
#include "../MesinKarakter-Kata/mesinkar+katafile.h"

typedef struct tNodeTree *AddressTree;
typedef struct {
    char nama[20];  
    int hargaTiket;
    int kapasitas;
    int durasi;
    char deskripsi[100];  
    int hargaBangun;
    int bahanBangun[3];    
} WahanaTree;

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
#define Durasi(T) (T)->detail.durasi
#define Deskripsi(T) (T)->detail.deskripsi
#define HargaBangun(T) (T)->detail.hargaBangun
#define KayuBangun(T) (T)->detail.bahanBangun[0]
#define BatuBangun(T) (T)->detail.bahanBangun[1]
#define MetalBangun(T) (T)->detail.bahanBangun[2]

AddressTree Alokasi(WahanaTree X);

AddressTree Dealokasi(AddressTree X);


#endif