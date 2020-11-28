#include "../MesinKarakter-Kata/mesinkar+katafile.h"
#include "../MesinKarakter-Kata/mesinkar+katainput.h"
#include "../Point/point.h"

#ifndef _LISTARRAY_H
#define _LISTARRAY_H

typedef struct{
    char namabahan[20];
    int hargabahan;
}BahanBangunan;

typedef struct{
   char namaWahana[20];
   POINT lokasi;
}WahanaMatriks;

void DaftarBahan(BahanBangunan listbahan[]);

#endif