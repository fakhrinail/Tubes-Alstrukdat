#include "../MesinKarakter-Kata/mesinkar+katafile.h"
#include "../MesinKarakter-Kata/mesinkar+katainput.h"
#include "../Point/point.h"
#include "../boolean.h"

#ifndef _LISTARRAY_H
#define _LISTARRAY_H

typedef struct{
    char namabahan[20];
    int hargabahan;
}BahanBangunan;

typedef struct{
   char namaWahana[20];
   POINT lokasi;
   int hargawahana; //tiket 
   char deskripsi[100]; 
   int kapasitas;
   //TO DO history upgrade
   int waktuwahana;
   boolean kondisi;
}WahanaMatriks;

void DaftarBahan(BahanBangunan listbahan[]);

#endif