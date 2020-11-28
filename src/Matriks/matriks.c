/*
NIM               13519007
Nama              Muhammad Tito Prakasa
Tanggal           22 September 2020
Topik praktikum   Pra-praktikum 5
Deskripsi         Membuat body ADT Matriks
*/

#include <stdio.h>
#include "../MesinKarakter-Kata/mesinkar+katafile.h"
#include "matriks.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMAP (MATRIKS * M, char path[])
/* Membentuk Map kosong sesuai dengan penempatan map keberapa*/
/* I.S. Matriks tidak terdefinisi */
/* F.S. matriks Map.mem terisi dengan simbol-simbol yang sesuai pada map.txt*/
{
   STARTKATAf(path);
   
   int i=0;
   while (!EndFile){
      CopyString((*M).Mem[i],CKataF);
      ADVKATAf();
      i++;
   }
   isiMap(M);     //untuk mengisi point player,office,antrian,dll.
   
}

POINT SearchIndeks(MATRIKS M, char jenis)
/* Fungsi antara untuk membantu mencari lokasi simbol ('A','P','O').
   Jika lokasi ditemukan maka akan mereturn Point lokasi tersebut. Jika tidak 
   ditemukan maka akan mereturn Point (-1,-1).*/
{
   boolean found = false;
   int i=0;
   int j=0;
   while (!found && i<20){
      j=0;
      while (!found && j<20){
         if (M.Mem[i][j]==jenis){
            found = true;
         }else{
            j++;        //kalo udh nemu indeksnya gaperlu nambah indeks
         }
      }
      if (!found){      //kalo udh nemu indeksnya gaperlu nambah indeks
         i++;
      }
   }

   if (found){
      return MakePOINT(i,j);
   }else{
      return MakePOINT(-1,-1);
   }
      
}

void isiMap (MATRIKS* M)
/* I.S.  : point lokasi player, office, dan antrian tidak terdefinisi
   F.S.  : point lokasi player, office, dan antrian terdefinisi
   proses: SearchIndeks */
{
   Player(*M) = SearchIndeks(*M,'P');
   Office(*M) = SearchIndeks(*M,'O');
   Antrian(*M) = SearchIndeks(*M,'A');
   
   //gerbang
   int i;
   int j;
   int indeksGerbang=0;
   for (i=0;i<20;i++){
      for (j=0;j<20;j++){
         if ((*M).Mem[i][j]=='G'){
            (*M).Gerbang[indeksGerbang] = MakePOINT(i,j);
            indeksGerbang++;
         }
      }
   }

   //Wahana 

}

void TulisMap (MATRIKS M)
/* I.S.  : Sembarang
   F.S.  : Ditampilkan isi matriks M.mem
   proses: iterasi printf*/
{
   int i,j;
   for (i=0;i<=BrsMax;i++){
      for (j=0;j<=KolMax;j++){
         printf("%c", M.Mem[i][j]);
      }
      printf("\n");
   }
}

void GerakPlayer (MATRIKS *M, char arah[])
/* I.S.  : Point Player lama
   F.S.  : Point Player ditambah/dikurangi sesuai arah namun ada batasnya yaitu <20 dan
   >-1.
   proses: if else*/
{
   if (arah[0]=='w'){
      Baris(Player(*M)) -= 1; 
   }else if(arah[0]=='a'){
      Kolom(Player(*M)) -= 1;
   }else if(arah[0]=='s'){
      Baris(Player(*M)) += 1;
   }else if(arah[0]=='d'){
      Kolom(Player(*M)) += 1;
   }
   if (Baris(Player(*M))==19){
      Baris(Player(*M)) -= 1;
   }else if (Kolom(Player(*M))==19){
      Kolom(Player(*M)) -= 1;
   }else if (Baris(Player(*M))==0){
      Kolom(Player(*M)) += 1;
   }else if (Kolom(Player(*M))==0){
      Kolom(Player(*M)) += 1;
   }
}

void updateMap(MATRIKS *M)
{
   int i;
   int j;
   for (i=0;i<20;i++){
      for (j=0;j<20;j++){
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
   }
}

