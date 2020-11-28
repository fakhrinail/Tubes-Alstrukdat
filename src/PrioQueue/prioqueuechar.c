#include <stdio.h>
#include <stdlib.h>
#include "prioqueuechar.h"

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}

boolean IsFull (PrioQueueChar Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return (NBElmt(Q) == MaxEl(Q));
}

int NBElmt (PrioQueueChar Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if (IsEmpty(Q)) {
        return 0;
    } else {
        if (Tail(Q) >= Head(Q)) {
            return (Tail(Q)-Head(Q)+1);
        } else {
            return (MaxEl(Q)+Tail(Q)-Head(Q)+1);
        }
    }
}

/* *** Kreator *** */
void MakeEmpty (PrioQueueChar * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    (*Q).T = (infotype *) malloc (Max * sizeof(infotype));

    if ((*Q).T != NULL) {
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        MaxEl(*Q) = 0;
    }
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    MaxEl(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueChar * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
{
    if(Head(*Q) == Nil)   Head(*Q) = 0;
    Tail(*Q) = (Tail(*Q) + 1) % MaxEl(*Q);
    InfoTail(*Q) = X;
    int a1 = Tail(*Q);
    int a2 = (a1 + MaxEl(*Q) - 1)% MaxEl(*Q);
    infotype temp;
    while (a1 != Head(*Q) && Prio(Elmt(*Q, a1)) < Prio(Elmt(*Q, a2))){
        temp = Elmt(*Q, a1);
        Elmt(*Q, a1) = Elmt(*Q, a2);
        Elmt(*Q, a2) = temp;
        a1 = a2;
        a2 = (a1 + MaxEl(*Q) - 1)% MaxEl(*Q);
    }
}

void Dequeue (PrioQueueChar * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    *X= InfoHead(*Q);
    if (NBElmt(*Q) == 1) {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else {
        Head(*Q)++;
        Head(*Q) %= MaxEl(*Q);
    }
}

/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
{
    int temp;
    for (int i = 0; i < NBElmt(Q);i++){
        temp = (Head(Q)+i+MaxEl(Q)) % MaxEl(Q);
        printf("%d %c\n", Elmt(Q,temp).prio,Elmt(Q,temp).info);
    }

    printf("#\n");
}