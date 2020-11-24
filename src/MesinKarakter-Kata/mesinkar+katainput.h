/* File: mesinkar.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "../boolean.h"

#define NMaxINPUT 50
#define MARK '\n'
#define BLANK ' '

extern char CC;
//EndKata untuk input ditiadakan karena menurut gue gaperlu, toh tiap ada spasi bakal 
//diskip.
extern boolean EOP;           //variabel ini berguna untuk jika inputan nanti bernilai
                              //"exit" maka EOP true dan pita diclose.
extern char CKataI[NMaxINPUT];

void STARTi();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. */

void ADVi();
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = CC sembarang
   F.S. : CC adalah karakter berikutnya dari CC yang lama, 
          CC mungkin = MARK, CC mungkin = BLANK. */

void STARTKATAi();
/* I.S. : CC sembarang 
   F.S. : CC = MARK atau CC = BLANK.
   proses: SalinKata*/

void IgnoreBlankAndMARKi();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */

void ADVKATAi();
/* I.S. : kemungkinan CC adalah MARK atau CC adalah BLANK
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC kembali menjadi MARK atau BLANK.  
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKatai();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi. */

boolean isEOP(char kata[]);
/* Fungsi antara yang berguna mengecek suatu CKata apakah dia EOP atau bukan,
jika dia EOP (exit) maka akan mengclose kan pita dan mengembalikan true. */

boolean isSame(char kata1[], char kata2[]);

#endif
