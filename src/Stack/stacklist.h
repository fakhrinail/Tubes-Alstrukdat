/* File : stacklist.h */
#ifndef _STACKLIST_H
#define _STACKLIST_H

#include "boolean.h"
#include <stdlib.h>

/* Konstanta */
#define Nil NULL

/* Deklarasi infotype */
typedef int infotype;

/* Stack dengan representasi berkait dengan pointer */
typedef struct tElmtStack * address;
typedef struct tElmtStack {
	infotype command; //1 build, 2 upgrade, 3 buy
	infotype uang;
    infotype jmlbahan[3];
    infotype waktu;
	address Next; 
} ElmtStack; 

/* Type stack dengan ciri TOP : */
typedef struct { 
	address TOP;  /* alamat TOP: elemen puncak */
} Stack;

/* Selektor */
#define Top(S) (S).TOP
#define InfoTop(S) (S).TOP->ElmtStack; 
#define Next(P) (P)->Next
#define Command(P) (P)->command
#define Uang(P) (P)->uang
#define JmlBahan(P) (P)->jmlbahan[3]
#define Waktu(P) (P)->waktu

/* Prototype manajemen memori */
void Alokasi (address *P, infotype cmd, infotype uang, infotype jml[3], infotype waktu);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void Dealokasi (address P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */ 

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmpty (Stack S);
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
void CreateEmpty (Stack * S);
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack S yang kosong */
void Push (Stack * S, infotype cmd, infotype uang, infotype jml[3], infotype waktu);
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
void Pop (Stack * S, infotype * cmd, infotype * uang, infotype * jml[3], infotype * waktu);
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */

#endif