#ifndef _LISTARRAY_H
#define _LISTARRAY_H

#include "../MesinKarakter-Kata/mesinkar+katafile.h"
#include "../MesinKarakter-Kata/mesinkar+katainput.h"
#include "../Point/point.h"
#include "../boolean.h"
#include "../ListLinier/listlinier.h"

typedef struct{
    char namabahan[20];
    int hargabahan;
}BahanBangunan;

typedef struct{
   char namaWahana[20];
   POINT lokasi;
   int hargawahana;     //tiket 
   char upgrade1[20];   //upgrade kiri pohon
   char upgrade2[20];   //upgrade kanan pohon
   List historyUpgrade;
   boolean kondisi;
}WahanaMatriks;

void DaftarBahan(BahanBangunan listbahan[]);

#endif