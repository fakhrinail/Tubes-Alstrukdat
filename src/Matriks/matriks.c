/*
NIM               13519007
Nama              Muhammad Tito Prakasa
Tanggal           22 September 2020
Topik praktikum   Pra-praktikum 5
Deskripsi         Membuat body ADT Matriks
*/

#include <stdio.h>
#include "matriks.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMAP (MATRIKS * M, int map)
/* Membentuk Map kosong sesuai dengan penempatan map keberapa*/
/* I.S. Matriks tidak terdefinisi */
/* F.S. Jika map==1, Player inisialisasi pada point (10,10) dan office (15,15). Selain map==1, Player dan office akan diinisiasi (-1,-1). Selain itu basic bintang (*) dan pagar (#) kecuali Gerbang yang akan disesuaikan oleh map keberapa */
{
   if (map==1){   //map kiri atas
      Player(*M) = MakePOINT(10,10);
      Office(*M) = MakePOINT(15,15);
      Antrian(*M) = MakePOINT(1,1);
      (*M).Gerbang[0] = MakePOINT(10,19);
      (*M).Gerbang[1] = MakePOINT(19,10);
   }else{
      Player(*M) = MakePOINT(-1,-1);
      Office(*M) = MakePOINT(-1,-1);
      Antrian(*M) = MakePOINT(-1,-1);

      if (map==2){   //map kanan atas
         (*M).Gerbang[0] = MakePOINT(10,0);
         (*M).Gerbang[1] = MakePOINT(19,10);
      }else if(map==3){    //map kanan bawah
         (*M).Gerbang[0] = MakePOINT(0,10);
         (*M).Gerbang[1] = MakePOINT(10,0);
      }else if(map==4){    //map kiri bawah
         (*M).Gerbang[0] = MakePOINT(0,10);
         (*M).Gerbang[1] = MakePOINT(10,19);
      }   
   }
   isiMap(M);
}

void isiMem (MATRIKS* M, int i, int j){
   POINT temp = MakePOINT(i,j);
   if (Baris(temp)==0 || Kolom(temp)==0 || Baris(temp)==19 || Kolom(temp)==19){
      if (EQPoint(temp, (*M).Gerbang[0]) || EQPoint(temp,(*M).Gerbang[1])){
         (*M).Mem[Baris(temp)][Kolom(temp)] = 'G';                //bernilai gerbang
      }else{
         (*M).Mem[Baris(temp)][Kolom(temp)] = '#';                //bernilai pagar lahan
      }
   }else{
      if (EQPoint(temp,Player(*M))){
         (*M).Mem[Baris(temp)][Kolom(temp)] = 'P';                //bernilai pemain
      }else if (EQPoint(temp,Office(*M))){
         (*M).Mem[Baris(temp)][Kolom(temp)] = 'O';                //bernilai Office
      }else if (EQPoint(temp,Antrian(*M))){
         (*M).Mem[Baris(temp)][Kolom(temp)] = 'A';                //bernilai Antrian
      }else{
         (*M).Mem[Baris(temp)][Kolom(temp)] = '-';                //bernilai tempat kosong
      }
   }
}

void isiMap (MATRIKS* M){
   int i;
   for (i=0;i<=BrsMax;i++){
      int j;
      for (j=0;j<=KolMax;j++){
         isiMem(M,i,j);
      }
   }
}

void CopyMap (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
   Player(*MHsl) = Player(MIn);
   Office(*MHsl) = Player(MIn);
   Antrian(*MHsl) = Antrian(MIn);
   (*MHsl).Gerbang[0] = MIn.Gerbang[0];
   (*MHsl).Gerbang[1] = MIn.Gerbang[1];
   
   int i,j;
   for (i=0;i<=BrsMax;i++){
      for (j=0;j<=KolMax;j++){
         (*MHsl).Mem[i][j] = MIn.Mem[i][j];
      }
   }
}

void TulisMap (MATRIKS M)
{
   int i,j;
   for (i=0;i<=BrsMax;i++){
      for (j=0;j<=KolMax;j++){
         printf("%c", M.Mem[i][j]);
      }
      printf("\n");
   }
}




