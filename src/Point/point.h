#ifndef POINT_H
#define POINT_H

#include "../boolean.h"

typedef struct {
	int baris;     /* representasi baris di matriks */
	int kolom;     /* representasi kolom di matriks */
} POINT;

/* *** Notasi Akses: Selektor POINT *** */
#define Baris(P) (P).baris
#define Kolom(P) (P).kolom

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y);
/* Membentuk sebuah POINT dari komponen-komponennya */

boolean isNil(POINT P);
/* Mengembalikan true jika Baris P = -1 dan Kolom P = -1.*/

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQPoint (POINT P1, POINT P2);
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
boolean NEQPoint (POINT P1, POINT P2);
/* Mengirimkan true jika P1 tidak sama dengan P2 */

boolean isSebelah(POINT P1, POINT P2);
/* Mengirimkan true jika P1 bersebelahan dengan P2 */





#endif