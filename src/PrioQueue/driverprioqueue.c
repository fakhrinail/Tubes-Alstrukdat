#include "prioqueuechar.h"
#include "../boolean.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    PrioQueueChar Q;
    MakeEmpty(&Q,1);
    infotype uhuy;
    uhuy.info = 'a';
    uhuy.prio = 1;
    Enqueue(&Q,uhuy);
    if (IsFull(Q))
    {
        printf("penuh\n");
    }
    printf("%d\n", NBElmt(Q));
    PrintPrioQueueChar(Q);
    infotype X;
    Dequeue(&Q,&X);
    if (IsEmpty(Q))
    {
        printf("kosong\n");
    }
    PrintPrioQueueChar(Q);
    return 0;
}