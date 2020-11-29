#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../PrioQueue/prioqueuechar.h"
#include "../Matriks/matriks.h"
#include "../MesinKarakter-Kata/mesinkar+katafile.h"
#include "../MesinKarakter-Kata/mesinkar+katainput.h"

/* dipanggil di awal mainphase */
void GeneratePengunjung(MATRIKS M, PrioQueueChar *Q)
{
    MakeEmpty(Q, 5); //5 jml maks pengunjung
    
    /* random jml pengunjung */
    srand(time(0));
    int jmlpengunjung;
    jmlpengunjung = rand() % 6; //random antara 0-5
    while (jmlpengunjung == 0) //ulang kalo 0
    {
        jmlpengunjung = rand() % 6;
    }

    /* itung total wahana */
    int totalwahana;
    int i = 0;
    while (!(isNil(M.arrayWahana[i].lokasi)))
    {
        totalwahana++;
        i++;
    }
    
    for (int i = 0; i < jmlpengunjung; i++)
    {
        /* ngitung jml wahana yg bakal dikunjungi per pengunjung */
        int jmlwahana; //jml wahana yg ingin dikunjungi
        jmlwahana = rand() % totalwahana+1; //jmlwahana antar 1-totalwahana
        while (jmlwahana == 0)
        {
            jmlwahana = rand() % totalwahana+1;
        }
        
        /* isi daftar wahana tiap pengunjung */
        infotypeQ daftar;
        List listwahana;
        daftar.sabar = 5;
        daftar.daftarwahana = listwahana;
        char namawahana[20];
        CopyString(namawahana[20], M.arrayWahana[0].namaWahana);
        InsVLast(&daftar, namawahana[20]);

        /* kalau jml wahana lebih dari 1 */
        for (int j = 1; j < jmlwahana; j++)
        {
            CopyString(namawahana[20], M.arrayWahana[1].namaWahana);
            InsVLast(&daftar, namawahana[20]);
        }
        
        /* tambah queue */
        Enqueue(&Q, daftar);
    }
}

/* dipanggil kalo input command serve */
void Serve(MATRIKS M, PrioQueueChar *Q)
{
    printf("Masukkan nama wahana yang ingin dilayani: ");
    ADVKATAi();
    if (isSame('bombomcar', CKataI))
    {
        
    }
    else if (isSame('halilintar', CKataI))
    {
        
    }
    else if (isSame('kora-kora', CKataI))
    {
        
    }
    else
    {
        printf("Tidak ada wahana dengan nama tersebut\n");
    }
}


void REPAIR();
void DETAIL(MATRIKS* M){
    Player(*M) = SearchIndeks(*M,'P');
    for (int i = Baris(Player(*M))-1; i <= Baris(Player(*M))+1;i++){
        for (int j = Kolom(Player(*M))-1; j <= Kolom(Player(*M))+1; j++){
            if ((*M).Mem[i][j] != '-' && (*M).Mem[i][j] != '#' ){
                //Print disini
            }
        }
    }
}
void OFFICE();
void PREPARE(PrioQueueChar *Q){
    infotypeQ *X;
    while(!IsEmpty(*Q)){
        Dequeue(&Q,X);
    }
    DeAlokasi(&Q);
    //panggil preparation phase disini
}