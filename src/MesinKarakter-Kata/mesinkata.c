/*
NIM                 13519007
Nama                Muhammad Tito Prakasa
Tanggal             30 September 2020
Topik praktikum     pra-praktikum 6
Deskripsi           Membuat body mesinkata
*/

#include "mesinkata.h"
#include <stdio.h>

boolean EndKata = false;
char CKata[NMax];

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (CC==BLANK){
        ADV();
    }
    if (CC==MARK){
        EndKata=true;
    }
}

void STARTKATA()
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    START();
    IgnoreBlank();
    if (CC==MARK){
        EndKata=true;
    }else{
        SalinKata();
    }
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    IgnoreBlank();
    if (CC==MARK){
        EndKata=true;
    }else{
        SalinKata();
    }
}

int StrToInt(char S[])
{
    int i = 0;
    int value = 0;
    while (S[i]!='\0'){
        value = value*10 + (int)(S[i]) - (int)('0');
        i++;
    }
    return value;
}

void CopyString(char S1[], char S2[])
{
    int i=0;
    while (S2[i]!='\0'){
        S1[i] = S2[i];
        i++;
    }
}

void resetCKata(char kata[]){
    int i=0;
    while (kata[i]!='\0'){
        kata[i]='\0';
        i++;
    }
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    resetCKata(CKata);
    int i=0;
    while (CC!=MARK && CC!=BLANK && i<NMax){
        CKata[i] = CC;
        i+=1;
        ADV();
    }
}


