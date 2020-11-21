/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "mesinkar+katainput.h"
#include "mesinkar+katafile.h"
#include <stdio.h>

char CC;
//EndKata ditiadakan, lihat di .h penjelasannya.
boolean EOP = false;       
char CKataI[NMaxINPUT];

static FILE * pita;
static int retval;

void STARTi() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. */

	/* Algoritma */
	pita = stdin;
	ADVi();
}

void ADVi() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = CC sembarang
   F.S. : CC adalah karakter berikutnya dari CC yang lama, 
          CC mungkin = MARK, CC mungkin = BLANK. */

	/* Algoritma */
	retval = fscanf(pita,"%c",&CC);
}

void STARTKATAi()
/* I.S. : CC sembarang 
   F.S. : CC = MARK atau CC = BLANK.
   proses: SalinKata*/
{
    STARTi();
    if (CC!=MARK){
        SalinKatai();
    }
}

void IgnoreBlankAndMARKi()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (CC==BLANK || CC==MARK){
        ADVi();
    }
}

void ADVKATAi()
/* I.S. : kemungkinan CC adalah MARK atau CC adalah BLANK
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC kembali menjadi MARK atau BLANK.  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    IgnoreBlankAndMARKi();
    SalinKatai();
}

void SalinKatai()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi. */
{
    resetCKata(CKataI);
    int i=0;
    while (CC!=MARK && i<NMaxINPUT){
        CKataI[i] = CC;
        i+=1;
        ADVi();
    }
}

boolean isEOP(char kata[])
/* Fungsi antara yang berguna mengecek suatu CKata apakah dia EOP atau bukan,
jika dia EOP (exit) maka akan mengclose kan pita dan mengembalikan true. */
{
       if (kata[0]=='e' && kata[1]=='x' && kata[2]=='i' && kata[3]=='t'){
              fclose(pita);
              return true;
       }else{
              return false;
       }
}