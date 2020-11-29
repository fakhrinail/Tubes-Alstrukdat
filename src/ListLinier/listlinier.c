/*
Nama/NIM : Fakhri Nail Wibowo
Tanggal : 04-11-2020
Topik : Variasi list linier
Deskripsi : Realisasi listlinier.h
*/

#include "../boolean.h"
#include "listlinier.h"
#include "../MesinKarakter-Kata/mesinkar+katafile.h"
#include "../MesinKarakter-Kata/mesinkar+katainput.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (List L)
/* Mengirim true jika list kosong */
{
    return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address AlokasiList (infotype X[])
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address P;
    P = (address) malloc(sizeof(ElmtList));
    if (P != Nil)
    {
        MakeString20Empty(P->info);
        CopyString(P->info,X);
        Next(P) = Nil;
        return P;
    }
    else
    {
        return Nil;
    }
}
void DealokasiList (address *P) //pake * atau ga? di praprak pake
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}


/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
/*
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
/*
{
    address P = First(L);
    if (IsEmptyList(L))
    {
        return Nil;
    }
    else
    {
        boolean isFound = false;
        while (P != Nil && !(isFound))
        {
            if (Info(P) == X)
            {
                isFound = true;
            }
            else
            {
                P = Next(P);
            }
        }
        return P;
    }
}
*/

boolean FSearch (List L, address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
    address Ptemp = First(L);

    if (IsEmptyList(L))
    {
        return false;
    }
    else
    {
        boolean isFound = false;
        while (Ptemp != Nil && !(isFound))
        {
            if (Ptemp == P)
            {
                isFound = true;
            }
            else
            {
                Ptemp = Next(Ptemp);
            }
        }

        if (isFound)
        {
            return isFound;
        }
        else
        {
            return isFound;
        }
    }   
}

address SearchPrec (List L, infotype X)
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
    if (Search(L,X) != Nil)
    {
        address P = First(L);
        address Ptarget = Search(L,X);
        address Prec = Nil;

        while (P != Ptarget)
        {
            Prec = P;
            P = Next(P);
        }
        
        return Prec;
    }
    else
    {
        return Nil;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X[])
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address P = AlokasiList(X);

    if (P != Nil)
    {
        Next(P) = First(*L);
        First(*L) = P;
    }
}
void InsVLast (List *L, infotype X[])
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address P = AlokasiList(X);
    address P2 = First(*L);

    if (P != Nil)
    {
        if (IsEmptyList(*L))
        {
            First(*L) = P;
        }
        else
        {
            while (Next(P2) != Nil)
            {
                P2 = Next(P2);
            }
                Next(P2) = P;
            }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address P = First(*L);
    X = Info(P);
    First(*L) = Next(P);
    Next(P) = Nil;
    DealokasiList(&P);
}
void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address P = First(*L);
    address Ptemp = Nil;

    while (Next(P) != Nil)
    {
        Ptemp = P;
        P = Next(P);
    }
    if (Ptemp == Nil)
    {
        First(*L) = Nil;
    }
    else
    {
        Next(Ptemp) = Nil;
    }
    X = Info(P);
    DealokasiList(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P;

}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    address Ptemp = First(*L);

    while (Ptemp != Prec)
    {
        Ptemp = Next(Ptemp);
    }
    Next(P) = Next(Ptemp);
    Next(Ptemp) = P;
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    address Ptemp = First(*L);
    if (IsEmptyList(*L))
    {
        First(*L) = P;
    }
    else
    {
        while (Next(Ptemp) != Nil)
        {
            Ptemp = Next(Ptemp);
        }
        Next(Ptemp) = P;
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    First(*L) = Next(*P);
    Next(*P) = Nil;
}
void DelP (List *L, infotype X[])
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address Ptemp = Search(*L,*X);
    
    if (Ptemp != Nil)
    {
        if (Ptemp == First(*L))
        {
            First(*L) = Next(Ptemp);
            DealokasiList(&Ptemp);
        }
        else
        {
            address P = First(*L);
            while (Next(P) != Ptemp)
            {
                P = Next(P);
            }
            DelAfter(L,&Ptemp,P);
            DealokasiList(&Ptemp);
        }
    }
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    address Ptemp = First(*L);
    address Ptemp2 = Nil;

    while (Next(Ptemp) != Nil)
    {
        Ptemp2 = Ptemp;
        Ptemp = Next(Ptemp);
    }
    *P = Ptemp;
    if (NbElmt(*L) == 1)
    {
        First(*L) = Nil;
    }
    else
    {
        Next(Ptemp2) = Nil;
    }
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    address P = First(L);
    if (IsEmptyList(L))
    {
        printf("[]\n");
    }
    else
    {
        printf("[");
        while (Next(P) != Nil)
        {
            printf("%s,",Info(P));
            P = Next(P);
        }
        printf("%s]", Info(P));
    }
}
int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    if (IsEmptyList(L))
    {
        return 0;
    }
    else
    {
        address P = First(L);
        int jml = 0;
        while (P != Nil)
        {
            jml++;
            P = Next(P);
        }
        return jml;
    }
}

/****************** PROSES TERHADAP LIST ******************/
void DelAll (List *L)
/* Delete semua elemen list dan alamat elemen di-dealokasi */
{
    address P;

    if (!(IsEmptyList(*L)))
    {
        while (!(IsEmptyList(*L)))
        {
            DelFirst(L,&P);
            DealokasiList(&P);
        }
    }
}

void InversList (List *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
    address P = First(*L);
    address Prec = Nil;

    while (P != Nil)
    {
        Next(P) = Prec;
        Prec = P;
        P = Next(Prec);
    }
}

List FInversList (List L)
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
    List Linv;
    CreateEmpty(&Linv);
    CopyList(&L,&Linv);
    InversList(&Linv);

    return Linv;
}

void CopyList (List *L1, List *L2)
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
{
    CreateEmpty(L2);
    First(*L2) = First(*L1);
}

List FCopyList (List L)
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
    if (!(IsEmptyList(L)))
    {
        List Lcopy;
        CreateEmpty(&Lcopy);
        address P = First(L);
        address Pcopy = Nil;

        while (P != Nil)
        {
            Pcopy = AlokasiList(Info(P));

            if (Pcopy == Nil)
            {
                DelAll(&Lcopy);
            }
            else
            {
                InsertLast(&Lcopy, Pcopy);
            }

            P = Next(P);
        }

        return Lcopy;
    }
    else
    {
        List Lcopy;
        CreateEmpty(&Lcopy);

        return Lcopy;
    }
}

void CpAlokList (List Lin, List *Lout)
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */
{
    CreateEmpty(Lout);
    address P = First(Lin);
    address Pcopy = Nil;
    boolean isFailed = false;

    while (P != Nil && !(isFailed))
    {
        Pcopy = AlokasiList(Info(P));

        if (Pcopy == Nil)
        {
            isFailed = true;
            DelAll(Lout);
        }
        else
        {
            InsertLast(Lout, Pcopy);
        }

        P = Next(P);
    }
}

void Konkat (List L1, List L2, List * L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang "baru" */
/* Elemen L3 adalah hasil alokasi elemen yang “baru”. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */
{
    List L3copy;
    CreateEmpty(&L3copy);
    CpAlokList(L1,L3);

    if (!(IsEmptyList(*L3)))
    {
        CpAlokList(L2,&L3copy);
        if (!(IsEmptyList(*L3)))
        {
            address Plast = First(L3copy);
            InsertLast(L3,Plast);
        }
    }
}

void PecahList (List *L1, List *L2, List L)
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */
{
    CreateEmpty(L1);
    CreateEmpty(L2);

    if (!(IsEmptyList(L)))
    {
        if (NbElmt(L)%2 == 0)
        {
            int i = 1;
            int setengah = NbElmt(L)/2;
            address P = First(L);
            address Pcopy = Nil;

            while (i != NbElmt(L))
            {
                if (i <= setengah)
                {
                    Pcopy = AlokasiList(Info(P));
                    InsertLast(L1,Pcopy);
                }
                else
                {
                    Pcopy = AlokasiList(Info(P));
                    InsertLast(L2,Pcopy);
                }
                P = Next(P);
            }
        }
        else
        {
            int i = 1;
            div_t output = div(NbElmt(L),2);
            int setengah = output.quot;
            address P = First(L);
            address Pcopy = Nil;

            while (i != NbElmt(L))
            {
                if (i <= setengah)
                {
                    Pcopy = AlokasiList(Info(P));
                    InsertLast(L1,Pcopy);
                }
                else
                {
                    Pcopy = AlokasiList(Info(P));
                    InsertLast(L2,Pcopy);
                }
                P = Next(P);
            }
        }
    }
}

void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    First(*L3) = First(*L1);
    InsertLast(L3,First(*L2));
    First(*L1) = Nil;
    First(*L2) = Nil;
}
