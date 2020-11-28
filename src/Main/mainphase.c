#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../PrioQueue/prioqueuechar.h"
#include "../Matriks/matriks.h"
#include "../MesinKarakter-Kata/mesinkar+katafile.h"

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

    int jmlwahana; //jml wahana yg ingin dikunjungi
    for (int i = 0; i < jmlpengunjung; i++)
    {
        
    }
}