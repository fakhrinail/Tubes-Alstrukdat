/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#ifndef MATRIKS_H
#define MATRIKS_H

#include "../boolean.h"
#include "../Point/point.h"
#include "../ListArray/listarray.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 0
#define BrsMax 19
#define KolMin 0
#define KolMax 19

typedef int indeks; /* indeks baris, kolom */
typedef char ElType; 
typedef struct MATRIKS *addressMatriks;
typedef struct { 
	ElType Mem[BrsMax+1][KolMax+1];
   POINT Player;
   POINT Gerbang[2];
   POINT Office;
   POINT Antrian;
   WahanaMatriks arrayWahana[30];
   addressMatriks graph;
} MATRIKS;



/* *** Selektor *** */
#define Player(M) (M).Player
#define Office(M) (M).Office
#define Antrian(M) (M).Antrian

void MakeMAP (MATRIKS * M, char path[]);
/* Membentuk Map kosong sesuai dengan penempatan map keberapa*/
/* I.S. Matriks tidak terdefinisi */
/* F.S. matriks Map.mem terisi dengan simbol-simbol yang sesuai pada map.txt*/

POINT SearchIndeks(MATRIKS M, char jenis);
/* Fungsi antara untuk membantu mencari lokasi simbol ('A','P','O').
   Jika lokasi ditemukan maka akan mereturn Point lokasi tersebut. Jika tidak 
   ditemukan maka akan mereturn Point (-1,-1).*/

void isiMap (MATRIKS* M);
/* I.S.  : point lokasi player, office, dan antrian tidak terdefinisi
   F.S.  : point lokasi player, office, dan antrian terdefinisi
   proses: SearchIndeks */

void TulisMap (MATRIKS M);
/* I.S.  : Sembarang
   F.S.  : Ditampilkan isi matriks M.mem
   proses: iterasi printf*/

void GerakPlayer (MATRIKS *M, char arah[]);
/* I.S.  : Point Player lama
   F.S.  : Point Player ditambah/dikurangi sesuai arah namun ada batasnya yaitu <20 dan
   >-1.
   proses: if else*/

void updateMap (MATRIKS *M);

#endif