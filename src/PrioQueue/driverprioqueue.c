#include "prioqueuechar.h"
#include "../ListLinier/listlinier.h"
#include "../MesinKarakter-Kata/mesinkar+katafile.h"
#include "../MesinKarakter-Kata/mesinkar+katainput.h"
#include "../boolean.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    PrioQueueChar Q;
    List L;
    MakeEmpty(&Q,5);
    infotypeQ uhuy;
    uhuy.sabar = 5;
    uhuy.prio = 1;
    uhuy.daftarwahana = L;
    First(L) = Nil;
    char test[4];
    test[1] = 't';
    test[2] = 'e';
    test[3] = 's';
    test[4] = 't';
    char test1[4];
    test1[1] = 't';
    test1[2] = 'e';
    test1[3] = 's';
    test1[4] = 't';
    InsVLast(&L, &test[4]);
    InsVLast(&L, &test1[4]);
    Enqueue(&Q,uhuy);
    if (IsFull(Q))
    {
        printf("penuh\n");
    }
    printf("%d\n", NBElmt(Q));
    //PrintPrioQueueChar(Q);
    infotypeQ X;
    Dequeue(&Q,&X);
    if (IsEmpty(Q))
    {
        printf("kosong\n");
    }
    //PrintPrioQueueChar(Q);
    return 0;
}