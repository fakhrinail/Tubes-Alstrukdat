#include <stdio.h>
#include <stdlib.h>
#include "../Point/point.h"

/* Buy */

/* Variabel listbahan gue apus biar langsung dimasukkin di main.c aja */

typedef struct{
    int uang;
    int jmlbahan[3];
    int waktu;
} VarBuy;

typedef struct{
    char namabahan[10];
    int hargabahan;
} BahanBangunan;

void DaftarBahan(BahanBangunan listbahan[]);

VarBuy* Buy(BahanBangunan listbahan[], int uangPengguna, JAM J);

/* Build */

typedef struct{
    POINT lokasi;
    int hargaBangun;
    int bahanBangun[3];
    int waktu;
}VarBuild;

VarBuild* Build();

VarUpgrade* Buy(BahanBangunan listbahan[], int uangPengguna, JAM J);

/* Upgrade */

typedef struct{
    POINT lokasi;
    int hargaBangun;
    int bahanBangun[3];
    int waktu;
}VarUpgrade; 

VarUpgrade* Upgrade();
