/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "mesinkar+katafile.h"
#include <stdio.h>

char CCF;
boolean EndLine = false;
boolean EndFile = false;
char CKataF[NMaxFILE];

static FILE * pitaFile;
static int retvalFile;

void STARTf(char path[]) {   // variabel path digunakan untuk menyimpan path file
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EndLine akan padam (false).
       Jika CC = MARK maka EndLine akan menyala (true) */

	/* Algoritma */
	pitaFile = fopen(path, "r");
	ADVf();
}

void ADVf() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = 
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama, 
          CC mungkin = MARK.
	       Jika  CC = MARK maka EndLine akan menyala (true) 
              CC mungkin = EOF.
              Jika CC = EOF maka pembacaan file berhenti.*/

	/* Algoritma */
	retvalFile = fscanf(pitaFile,"%c",&CCF);
	EndLine = CCF==MARK;

	if (retvalFile==EOF) {
        EndFile = true;
        fclose(pitaFile);
 	}
}

void IgnoreBlankAndMARKf()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (CCF==BLANK || CCF==MARK){
        ADVf();
    }
}

void STARTKATAf(char path[])
/* I.S. : CC sembarang 
   F.S. : CC mungkin MARK, CC mungkin BLANK
          CKata mungkin terisi kata yang sudah diakusisi
          atau juga mungkin tidak terisi apa-apa (file kosong).*/
{
    EndLine = false;
    EndFile = false;
    STARTf(path);
    IgnoreBlankAndMARKf();
    if (CCF==MARK){
        EndLine = true;
    }else{
        SalinKataf();
    }
}

void ADVKATAf()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndLine = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    if (!EndFile){
        IgnoreBlankAndMARKf();
        if (CCF==MARK){
        EndLine=true;
        }else{
        SalinKataf();
        }
    }
}

int StrToInt(char S[])
/* Fungsi antara yang berguna untuk mengubah struktur data
   dari string ke integer. */
{
    int i = 0;
    int value = 0;
    while (S[i]>= '0' && S[i] <= '9'){
        value = value*10 + (int)(S[i]) - (int)('0');
        i++;
    }
    return value;
}

void CopyString(char S1[], char S2[])
/* I.S. : S1 sembarang, S2 berisi string yang ingin dicopy
   F.S. : S1 terisi string yang sama dengan yang ada di S2
   proses: tiap-tiap char yang ada di S1 diassign dengan char
           yang ada di S2. */
{
    int i=0;
    while (S2[i]!='\0'){
        S1[i] = S2[i];
        i++;
    }

}

void resetCKata(char kata[])
/* I.S. : kata sembarang
   F.S. : kata "kosong" kembali alias berisi '\0' 
   proses: tiap-tiap char yang ada di kata diassign dengan '\0' */
{
    int i;
    for (i=0;i<100;i++){
        kata[i] = '\0';
    }
}

void SalinKataf()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi. */
{
    resetCKata(CKataF);
    int i=0;
    while (CCF!=MARK && CCF!=BLANK && i<NMaxFILE){
        CKataF[i] = CCF;
        i+=1;
        ADVf();
    }
}