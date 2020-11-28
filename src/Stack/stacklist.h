/* File : stacklist.h */
#ifndef _STACKLIST_H
#define _STACKLIST_H

#include "boolean.h"
#include "../Point/point.h"
#include "../Jam/jam.h"
#include "../ListArray/listarray.h"
#include "../MesinKarakter-Kata/mesinkar+katafile.h"
#include "../MesinKarakter-Kata/mesinkar+katainput.h"
#include "../Tree/tree.h"
#include "../Matriks/matriks.h"
#include <stdio.h>
#include <stddef.h>

/* Deklarasi infotype */
typedef int infotype;

/* Stack dengan representasi berkait dengan pointer */
typedef struct tElmtStack* addressStack;
typedef struct tElmtStack {
	infotype command; 			//1 build, 2 upgrade, 3 buy
	infotype uang;
    infotype kayu;
	infotype batu;
	infotype metal;
    infotype waktu;				//disepakatin dalam menit
	POINT lokasi;
	char namaWahana[20];
	addressStack Next; 
} ElmtStack; 

/* Type stack dengan ciri TOP : */
typedef struct { 
	addressStack TOP;  /* alamat TOP: elemen puncak */
} Stack;

/* Selektor */
#define Top(S) (S).TOP
#define InfoCommandTop(S) (S).TOP->command
#define InfoUangTop(S) (S).TOP->uang
#define InfoKayuTop(S) (S).TOP->kayu
#define InfoBatuTop(S) (S).TOP->batu
#define InfoMetalTop(S) (S).TOP->metal
#define InfoWaktuTop(S) (S).TOP->waktu
#define InfoLokasiTop(S) (S).TOP->lokasi
#define Next(P) (P)->Next
#define Command(P) (P)->command
#define Uang(P) (P)->uang
#define Waktu(P) (P)->waktu

/* Prototype manajemen memori */
addressStack AlokasiStack (infotype cmd, infotype uang, infotype jml[], infotype waktu, POINT lokasi, char namaWahana[]);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void DealokasiStack (addressStack P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */ 

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmpty (Stack S);
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
void CreateEmptyStackList (Stack * S);
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack S yang kosong */
void Push (Stack * S, addressStack P);
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
void Pop (Stack* S, int* uangPengguna, JAM* jamPengguna, int bahanPengguna[], MATRIKS* Map);
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */

void Buy(Stack *S, BahanBangunan listbahan[], int uangPengguna, JAM waktu);

void Build(Stack *S, int bahanPengguna[], int uangPengguna, JAM waktu, AddressTree T, POINT posisiPlayer);

#endif