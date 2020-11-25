/* 
Nama/NIM : Fakhri Nail Wibowo/13519035
Tanggal : 21-11-2020
Topik : Variasi list linier
Deskripsi : Realisasi stacklist.h
*/

#include "stacklist.h"
#include "boolean.h"
#include <stdlib.h>

/* Prototype manajemen memori */
void Alokasi (address *P, infotype cmd, infotype uang, infotype jml[3], infotype waktu)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
{
    *P = (address) (malloc(sizeof(ElmtStack)));
    if (*P != Nil)
    {
        Command(*P) = cmd;
        Uang(*P) = uang;
        JmlBahan(*P) = jml[3];
        Waktu(*P) = waktu;
        Next(*P) = Nil;
    }
    
}
void Dealokasi (address P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */ 
{
    free(P);
}

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmpty (Stack S)
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
{
    return Top(S) == Nil;
}
void CreateEmpty (Stack * S)
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack S yang kosong */
{
    Top(*S) = Nil;
}
void Push (Stack * S, infotype cmd, infotype uang, infotype jml[3], infotype waktu)
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
{
    address P;
    Alokasi(&P,cmd,uang,&jml[3],waktu);
    if (P != Nil)
    {
        Next(P) = Top(*S);
        Top(*S) = P;
    }
}
void Pop (Stack * S, infotype * cmd, infotype * uang, infotype * jml[3], infotype * waktu)
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */
{
    *cmd = Command(Top(*S));
    *uang = Uang(Top(*S));
    *jml[3] = JmlBahan(Top(*S));
    *waktu = Waktu(Top(*S));
    address P = Top(*S);
    Top(*S) = Next(P);
    Dealokasi(P);
}