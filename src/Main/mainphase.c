#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../PrioQueue/prioqueuechar.h"
#include "../Matriks/matriks.h"
#include "../MesinKarakter-Kata/mesinkar+katafile.h"
#include "../MesinKarakter-Kata/mesinkar+katainput.h"

void GeneratePengunjung(MATRIKS M, PrioQueueChar *Q)
{
    MakeEmpty(Q, 5); //5 jml maks pengunjung
    
    srand(time(0));
    int jmlpengunjung;
    jmlpengunjung = rand() % 6; //random antara 0-5
    while (jmlpengunjung == 0) //ulang kalo 0
    {
        jmlpengunjung = rand() % 6;
    }

    int totalwahana;
    int i = 0;
    while (!(isNil(M.arrayWahana[i].lokasi)))
    {
        totalwahana++;
    }
    
    int jmlwahana; //jml wahana yg ingin dikunjungi
    int j = 0;
    for (int i = 0; i < jmlpengunjung; i++)
    {
        jmlwahana = rand() % totalwahana+1;
        Enqueue(&Q, );
    }
}

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