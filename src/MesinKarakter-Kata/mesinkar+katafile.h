/* File: mesinkar.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KARFILE_H_
#define __MESIN_KARFILE_H_

#include "../boolean.h"



#define MARK '\n'
#define NMaxFILE 100
#define BLANK ' '

/* State Mesin Kata */
extern boolean EndLine;       //boolean ini berguna buat bedain per line tiap file
extern boolean EndFile;       //boolean ini berguna untuk menandakan file telah selesai dibaca
extern char CKataF[NMaxFILE];
extern char CCF;

void STARTf(char path[]);      // variabel path digunakan untuk menyimpan path file
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EndLine akan padam (false).
       Jika CC = MARK maka EndLine akan menyala (true) */

void ADVf();
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = 
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama, 
          CC mungkin = MARK.
	       Jika  CC = MARK maka EndLine akan menyala (true) 
              CC mungkin = EOF.
              Jika CC = EOF maka pembacaan file berhenti.*/


void IgnoreBlankAndMARKf();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATAf(char path[]);
/* I.S. : CC sembarang 
   F.S. : CC mungkin MARK, CC mungkin BLANK
          CKata mungkin terisi kata yang sudah diakusisi
          atau juga mungkin tidak terisi apa-apa (file kosong).*/

void ADVKATAf();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndLine = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */

int StrToInt(char S[]);
/* Fungsi antara yang berguna untuk mengubah struktur data
   dari string ke integer. */

void CopyString(char S1[], char S2[]);
/* I.S. : S1 sembarang, S2 berisi string yang ingin dicopy
   F.S. : S1 terisi string yang sama dengan yang ada di S2
   proses: tiap-tiap char yang ada di S1 diassign dengan char
           yang ada di S2. */

void resetCKata(char kata[]);
/* I.S. : kata sembarang
   F.S. : kata "kosong" kembali alias berisi '\0' 
   proses: tiap-tiap char yang ada di kata diassign dengan '\0' */

void SalinKataf();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi. */

#endif
