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
void TulisPOINT (POINT P)
{
    printf("(%d,%d)\n",(int)Baris(P),(int)Kolom(P));
}

boolean isNil(POINT P){
    return Baris(P)==-1 && Kolom(P)==-1;
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQPoint (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : baris dan kolomnya sama */
{
    return Baris(P1)==Baris(P2) && Kolom(P1)==Kolom(P2);
}
boolean NEQPoint (POINT P1, POINT P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
    return Baris(P1)!=Baris(P2) || Kolom(P1)!=Kolom(P2);
}

boolean isSebelah (POINT P1, POINT P2)
{
    if (Baris(P1)-Baris(P2)==0 && Kolom(P1)-Kolom(P2)==1){
        return true;
    }else if (Baris(P1)-Baris(P2)==1 && Kolom(P1)-Kolom(P2)==0){
        return true;
    }else if (Baris(P1)-Baris(P2)==0 && Kolom(P1)-Kolom(P2)==-1){
        return true;
    }else if (Baris(P1)-Baris(P2)==-1 && Kolom(P1)-Kolom(P2)==0){
        return true;
    }else{
        return false;
    }
}

