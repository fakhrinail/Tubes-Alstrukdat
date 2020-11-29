#include "../boolean.h"
#include "listlinier.h"
#include "../MesinKarakter-Kata/mesinkar+katafile.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    List L;
    address P;
    char namawahana[] = 'bombomcar';
    P = Alokasi(namawahana);
    InsertFirst(&L, P);
    printf("%s", Info(P));
    return 0;
}