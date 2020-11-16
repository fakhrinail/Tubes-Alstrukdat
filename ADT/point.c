#include"point.h"
#include<math.h>
#include<stdio.h>

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
    /* KAMUS */
    POINT P;
    /* ALGORITMA */
    Baris(P) = X;
    Kolom(P) = Y;
    return P;
}

boolean isNil(POINT P){
    return Baris(P)==-1 && Kolom(P)==-1;
}

boolean isBersebelahan(POINT P1, POINT P2){
    int selisihBaris = Baris(P1)-Baris(P2);
    int selisihKolom = Kolom(P1)-Kolom(P2);
    return (selisihBaris==0 && selisihKolom!=0) || (selisihBaris!=0 && selisihKolom==0);
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQPoint (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : baris dan kolomnya sama */
{
    return Baris(P1)==Baris(P2) && Kolom(P1)==Kolom(P2);
}
boolean NEQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
    return Baris(P1)!=Baris(P2) || Kolom(P1)!=Kolom(P2);
}

