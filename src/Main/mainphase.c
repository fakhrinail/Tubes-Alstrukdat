#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Stack/stacklist.h"
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
void DETAIL(MATRIKS M){
    POINT asu = MakePOINT(-1,-1);
    POINT cek = cekWahana(M);
    boolean cond = false;
    if (NEQPoint(asu,cek)){
        while(cond == false){
            int i = 0;
            if (EQPoint(cek,M.arrayWahana[i].lokasi)){
                printf("Nama wahana                 : %d\n",M.arrayWahana[i].namaWahana);
                printf("Harga wahana                : %d\n",M.arrayWahana[i].hargawahana);
                printf("Lokasi wahana               : %d\n",M.arrayWahana[i].lokasi);
                printf("Kondisi                     : %d\n",M.arrayWahana[i].kondisi);
                printf("Riwayat upgrade wahana      : %d\n",M.arrayWahana[i].historyUpgrade);
                printf("Upgrade 1                   : %d\n",M.arrayWahana[i].upgrade1);
                printf("Upgrade 2                   : %d\n",M.arrayWahana[i].upgrade2);
                cond = true;
            }
            i++;
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