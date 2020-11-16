/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#ifndef MATRIKS_H
#define MATRIKS_H

#include "boolean.h"
#include "point.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 0
#define BrsMax 19
#define KolMin 0
#define KolMax 19

typedef int indeks; /* indeks baris, kolom */
typedef char ElType; 
typedef struct { 
	ElType Mem[BrsMax+1][KolMax+1];
   POINT Player;
   POINT Gerbang[2];
   POINT Office;
   POINT Antrian;
} MATRIKS;
/* NBrsEff >= 1 dan NKolEff >= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* *** Selektor *** */
#define Player(M) (M).Player
#define Office(M) (M).Office
#define Antrian(M) (M).Antrian

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMAP (MATRIKS * M, int map); 
/* Membentuk Map kosong sesuai dengan penempatan map keberapa*/
/* I.S. Matriks tidak terdefinisi */
/* F.S. Jika map==1, Player inisialisasi pada point (10,10) dan office (15,15). Selain map==1, Player dan office akan diinisiasi (-1,-1). Selain itu basic bintang (*) dan pagar (#) kecuali Gerbang yang akan disesuaikan oleh map keberapa */

void isiMem (MATRIKS* M, int i, int j);

void isiMap (MATRIKS* M);

void CopyMap (MATRIKS MIn, MATRIKS * MHsl);


void TulisMap (MATRIKS M);




#endif